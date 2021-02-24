//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_MANUAL_CONTROL_H
#define FASTMAVLINK_MSG_MANUAL_CONTROL_H


//----------------------------------------
//-- Message MANUAL_CONTROL
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_manual_control_t {
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t r;
    uint16_t buttons;
    uint8_t target;
}) fmav_manual_control_t;


#define FASTMAVLINK_MSG_ID_MANUAL_CONTROL  69


#define FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MIN  11
#define FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX  11
#define FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN  11
#define FASTMAVLINK_MSG_MANUAL_CONTROL_CRCEXTRA  243

#define FASTMAVLINK_MSG_ID_69_LEN_MIN  11
#define FASTMAVLINK_MSG_ID_69_LEN_MAX  11
#define FASTMAVLINK_MSG_ID_69_LEN  11
#define FASTMAVLINK_MSG_ID_69_CRCEXTRA  243



#define FASTMAVLINK_MSG_MANUAL_CONTROL_FLAGS  1
#define FASTMAVLINK_MSG_MANUAL_CONTROL_TARGET_SYSTEM_OFS  10
#define FASTMAVLINK_MSG_MANUAL_CONTROL_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message MANUAL_CONTROL packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_manual_control_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons,
    fmav_status_t* _status)
{
    fmav_manual_control_t* _payload = (fmav_manual_control_t*)msg->payload;

    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->r = r;
    _payload->buttons = buttons;
    _payload->target = target;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_MANUAL_CONTROL;

    msg->target_sysid = target;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_MANUAL_CONTROL_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_manual_control_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_manual_control_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_manual_control_pack(
        msg, sysid, compid,
        _payload->target, _payload->x, _payload->y, _payload->z, _payload->r, _payload->buttons,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_manual_control_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons,
    fmav_status_t* _status)
{
    fmav_manual_control_t* _payload = (fmav_manual_control_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->r = r;
    _payload->buttons = buttons;
    _payload->target = target;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_MANUAL_CONTROL;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_MANUAL_CONTROL >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_MANUAL_CONTROL >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MANUAL_CONTROL_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_manual_control_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_manual_control_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_manual_control_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target, _payload->x, _payload->y, _payload->z, _payload->r, _payload->buttons,
        _status);
}


//----------------------------------------
//-- Message MANUAL_CONTROL unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_manual_control_decode(fmav_manual_control_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_MANUAL_CONTROL_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_MANUAL_CONTROL  69

#define mavlink_manual_control_t  fmav_manual_control_t

#define MAVLINK_MSG_ID_MANUAL_CONTROL_LEN  11
#define MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN  11
#define MAVLINK_MSG_ID_69_LEN  11
#define MAVLINK_MSG_ID_69_MIN_LEN  11

#define MAVLINK_MSG_ID_MANUAL_CONTROL_CRC  243
#define MAVLINK_MSG_ID_69_CRC  243




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_manual_control_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_manual_control_pack(
        msg, sysid, compid,
        target, x, y, z, r, buttons,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_manual_control_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons)
{
    return fmav_msg_manual_control_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target, x, y, z, r, buttons,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_manual_control_decode(const mavlink_message_t* msg, mavlink_manual_control_t* payload)
{
    fmav_msg_manual_control_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_MANUAL_CONTROL_H