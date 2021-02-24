//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_DEBUG_H
#define FASTMAVLINK_MSG_DEBUG_H


//----------------------------------------
//-- Message DEBUG
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_debug_t {
    uint32_t time_boot_ms;
    float value;
    uint8_t ind;
}) fmav_debug_t;


#define FASTMAVLINK_MSG_ID_DEBUG  254


#define FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MIN  9
#define FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX  9
#define FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN  9
#define FASTMAVLINK_MSG_DEBUG_CRCEXTRA  46

#define FASTMAVLINK_MSG_ID_254_LEN_MIN  9
#define FASTMAVLINK_MSG_ID_254_LEN_MAX  9
#define FASTMAVLINK_MSG_ID_254_LEN  9
#define FASTMAVLINK_MSG_ID_254_CRCEXTRA  46



#define FASTMAVLINK_MSG_DEBUG_FLAGS  0
#define FASTMAVLINK_MSG_DEBUG_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_DEBUG_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message DEBUG packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_debug_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, uint8_t ind, float value,
    fmav_status_t* _status)
{
    fmav_debug_t* _payload = (fmav_debug_t*)msg->payload;

    _payload->time_boot_ms = time_boot_ms;
    _payload->value = value;
    _payload->ind = ind;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_DEBUG;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_DEBUG_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_debug_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_debug_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_debug_pack(
        msg, sysid, compid,
        _payload->time_boot_ms, _payload->ind, _payload->value,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_debug_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, uint8_t ind, float value,
    fmav_status_t* _status)
{
    fmav_debug_t* _payload = (fmav_debug_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_boot_ms = time_boot_ms;
    _payload->value = value;
    _payload->ind = ind;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_DEBUG;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_DEBUG >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_DEBUG >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DEBUG_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_debug_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_debug_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_debug_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->time_boot_ms, _payload->ind, _payload->value,
        _status);
}


//----------------------------------------
//-- Message DEBUG unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_debug_decode(fmav_debug_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_DEBUG_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_DEBUG  254

#define mavlink_debug_t  fmav_debug_t

#define MAVLINK_MSG_ID_DEBUG_LEN  9
#define MAVLINK_MSG_ID_DEBUG_MIN_LEN  9
#define MAVLINK_MSG_ID_254_LEN  9
#define MAVLINK_MSG_ID_254_MIN_LEN  9

#define MAVLINK_MSG_ID_DEBUG_CRC  46
#define MAVLINK_MSG_ID_254_CRC  46




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_debug_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint32_t time_boot_ms, uint8_t ind, float value)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_debug_pack(
        msg, sysid, compid,
        time_boot_ms, ind, value,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_debug_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, uint8_t ind, float value)
{
    return fmav_msg_debug_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        time_boot_ms, ind, value,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_debug_decode(const mavlink_message_t* msg, mavlink_debug_t* payload)
{
    fmav_msg_debug_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_DEBUG_H