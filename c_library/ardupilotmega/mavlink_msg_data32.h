//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_DATA32_H
#define FASTMAVLINK_MSG_DATA32_H


//----------------------------------------
//-- Message DATA32
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_data32_t {
    uint8_t type;
    uint8_t len;
    uint8_t data[32];
}) fmav_data32_t;


#define FASTMAVLINK_MSG_ID_DATA32  170

#define FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX  34
#define FASTMAVLINK_MSG_DATA32_CRCEXTRA  73

#define FASTMAVLINK_MSG_DATA32_FLAGS  0
#define FASTMAVLINK_MSG_DATA32_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_DATA32_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_DATA32_FRAME_LEN_MAX  59

#define FASTMAVLINK_MSG_DATA32_FIELD_DATA_NUM  32 // number of elements in array
#define FASTMAVLINK_MSG_DATA32_FIELD_DATA_LEN  32 // length of array = number of bytes

#define FASTMAVLINK_MSG_DATA32_FIELD_TYPE_OFS  0
#define FASTMAVLINK_MSG_DATA32_FIELD_LEN_OFS  1
#define FASTMAVLINK_MSG_DATA32_FIELD_DATA_OFS  2


//----------------------------------------
//-- Message DATA32 pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_data32_t* _payload = (fmav_data32_t*)_msg->payload;

    _payload->type = type;
    _payload->len = len;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*32);

    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_DATA32;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_DATA32_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_data32_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_data32_pack(
        _msg, sysid, compid,
        _payload->type, _payload->len, _payload->data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_data32_t* _payload = (fmav_data32_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->type = type;
    _payload->len = len;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*32);

    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_DATA32;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_DATA32 >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_DATA32 >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DATA32_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_data32_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_data32_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->type, _payload->len, _payload->data,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_data32_t _payload;

    _payload.type = type;
    _payload.len = len;
    memcpy(&(_payload.data), data, sizeof(uint8_t)*32);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_DATA32,
        FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DATA32_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data32_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_data32_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_DATA32,
        FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DATA32_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message DATA32 decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_data32_decode(fmav_data32_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_DATA32_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_data32_get_field_type(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_data32_get_field_len(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[1]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_data32_get_field_data_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[2]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_data32_get_field_data(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_DATA32_FIELD_DATA_NUM) return 0;
    return ((uint8_t*)&(msg->payload[2]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_DATA32  170

#define mavlink_data32_t  fmav_data32_t

#define MAVLINK_MSG_ID_DATA32_LEN  34
#define MAVLINK_MSG_ID_DATA32_MIN_LEN  34
#define MAVLINK_MSG_ID_170_LEN  34
#define MAVLINK_MSG_ID_170_MIN_LEN  34

#define MAVLINK_MSG_ID_DATA32_CRC  73
#define MAVLINK_MSG_ID_170_CRC  73

#define MAVLINK_MSG_DATA32_FIELD_DATA_LEN 32


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_data32_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t type, uint8_t len, const uint8_t* data)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_data32_pack(
        _msg, sysid, compid,
        type, len, data,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_data32_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data)
{
    return fmav_msg_data32_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        type, len, data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_data32_decode(const mavlink_message_t* msg, mavlink_data32_t* payload)
{
    fmav_msg_data32_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_DATA32_H
