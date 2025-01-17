//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_H
#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_H


//----------------------------------------
//-- Message ICAROUS_HEARTBEAT
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_icarous_heartbeat_t {
    uint8_t status;
}) fmav_icarous_heartbeat_t;


#define FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT  42000

#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX  1
#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_CRCEXTRA  227

#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_FLAGS  0
#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_FRAME_LEN_MAX  26



#define FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_FIELD_STATUS_OFS  0


//----------------------------------------
//-- Message ICAROUS_HEARTBEAT pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t status,
    fmav_status_t* _status)
{
    fmav_icarous_heartbeat_t* _payload = (fmav_icarous_heartbeat_t*)_msg->payload;

    _payload->status = status;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_icarous_heartbeat_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_icarous_heartbeat_pack(
        _msg, sysid, compid,
        _payload->status,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t status,
    fmav_status_t* _status)
{
    fmav_icarous_heartbeat_t* _payload = (fmav_icarous_heartbeat_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->status = status;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_icarous_heartbeat_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_icarous_heartbeat_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->status,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t status,
    fmav_status_t* _status)
{
    fmav_icarous_heartbeat_t _payload;

    _payload.status = status;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_icarous_heartbeat_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_icarous_heartbeat_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_ICAROUS_HEARTBEAT,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message ICAROUS_HEARTBEAT decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_icarous_heartbeat_decode(fmav_icarous_heartbeat_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_icarous_heartbeat_get_field_status(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_ICAROUS_HEARTBEAT  42000

#define mavlink_icarous_heartbeat_t  fmav_icarous_heartbeat_t

#define MAVLINK_MSG_ID_ICAROUS_HEARTBEAT_LEN  1
#define MAVLINK_MSG_ID_ICAROUS_HEARTBEAT_MIN_LEN  1
#define MAVLINK_MSG_ID_42000_LEN  1
#define MAVLINK_MSG_ID_42000_MIN_LEN  1

#define MAVLINK_MSG_ID_ICAROUS_HEARTBEAT_CRC  227
#define MAVLINK_MSG_ID_42000_CRC  227




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_icarous_heartbeat_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t status)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_icarous_heartbeat_pack(
        _msg, sysid, compid,
        status,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_icarous_heartbeat_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t status)
{
    return fmav_msg_icarous_heartbeat_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        status,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_icarous_heartbeat_decode(const mavlink_message_t* msg, mavlink_icarous_heartbeat_t* payload)
{
    fmav_msg_icarous_heartbeat_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_ICAROUS_HEARTBEAT_H
