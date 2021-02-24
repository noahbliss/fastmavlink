//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_NAMED_VALUE_INT_H
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_H


//----------------------------------------
//-- Message NAMED_VALUE_INT
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_named_value_int_t {
    uint32_t time_boot_ms;
    int32_t value;
    char name[10];
}) fmav_named_value_int_t;


#define FASTMAVLINK_MSG_ID_NAMED_VALUE_INT  252


#define FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MIN  18
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX  18
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN  18
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_CRCEXTRA  44

#define FASTMAVLINK_MSG_ID_252_LEN_MIN  18
#define FASTMAVLINK_MSG_ID_252_LEN_MAX  18
#define FASTMAVLINK_MSG_ID_252_LEN  18
#define FASTMAVLINK_MSG_ID_252_CRCEXTRA  44

#define FASTMAVLINK_MSG_NAMED_VALUE_INT_FIELD_NAME_LEN  10

#define FASTMAVLINK_MSG_NAMED_VALUE_INT_FLAGS  0
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_NAMED_VALUE_INT_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message NAMED_VALUE_INT packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_named_value_int_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const char* name, int32_t value,
    fmav_status_t* _status)
{
    fmav_named_value_int_t* _payload = (fmav_named_value_int_t*)msg->payload;

    _payload->time_boot_ms = time_boot_ms;
    _payload->value = value;
    memcpy(&(_payload->name), name, sizeof(char)*10);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_NAMED_VALUE_INT;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_NAMED_VALUE_INT_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_named_value_int_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_named_value_int_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_named_value_int_pack(
        msg, sysid, compid,
        _payload->time_boot_ms, _payload->name, _payload->value,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_named_value_int_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const char* name, int32_t value,
    fmav_status_t* _status)
{
    fmav_named_value_int_t* _payload = (fmav_named_value_int_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_boot_ms = time_boot_ms;
    _payload->value = value;
    memcpy(&(_payload->name), name, sizeof(char)*10);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_NAMED_VALUE_INT;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_NAMED_VALUE_INT >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_NAMED_VALUE_INT >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_NAMED_VALUE_INT_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_named_value_int_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_named_value_int_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_named_value_int_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->time_boot_ms, _payload->name, _payload->value,
        _status);
}


//----------------------------------------
//-- Message NAMED_VALUE_INT unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_named_value_int_decode(fmav_named_value_int_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_NAMED_VALUE_INT_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_NAMED_VALUE_INT  252

#define mavlink_named_value_int_t  fmav_named_value_int_t

#define MAVLINK_MSG_ID_NAMED_VALUE_INT_LEN  18
#define MAVLINK_MSG_ID_NAMED_VALUE_INT_MIN_LEN  18
#define MAVLINK_MSG_ID_252_LEN  18
#define MAVLINK_MSG_ID_252_MIN_LEN  18

#define MAVLINK_MSG_ID_NAMED_VALUE_INT_CRC  44
#define MAVLINK_MSG_ID_252_CRC  44

#define MAVLINK_MSG_NAMED_VALUE_INT_FIELD_NAME_LEN 10


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_named_value_int_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint32_t time_boot_ms, const char* name, int32_t value)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_named_value_int_pack(
        msg, sysid, compid,
        time_boot_ms, name, value,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_named_value_int_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const char* name, int32_t value)
{
    return fmav_msg_named_value_int_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        time_boot_ms, name, value,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_named_value_int_decode(const mavlink_message_t* msg, mavlink_named_value_int_t* payload)
{
    fmav_msg_named_value_int_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_NAMED_VALUE_INT_H
