//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_H
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_H


//----------------------------------------
//-- Message OPEN_DRONE_ID_MESSAGE_PACK
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_open_drone_id_message_pack_t {
    uint8_t target_system;
    uint8_t target_component;
    uint8_t single_message_size;
    uint8_t msg_pack_size;
    uint8_t messages[250];
}) fmav_open_drone_id_message_pack_t;


#define FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK  12915


#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MIN  254
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX  254
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN  254
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_CRCEXTRA  62

#define FASTMAVLINK_MSG_ID_12915_LEN_MIN  254
#define FASTMAVLINK_MSG_ID_12915_LEN_MAX  254
#define FASTMAVLINK_MSG_ID_12915_LEN  254
#define FASTMAVLINK_MSG_ID_12915_CRCEXTRA  62

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_FIELD_MESSAGES_LEN  250

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_FLAGS  3
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_TARGET_COMPONENT_OFS  1


//----------------------------------------
//-- Message OPEN_DRONE_ID_MESSAGE_PACK packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_message_pack_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t single_message_size, uint8_t msg_pack_size, const uint8_t* messages,
    fmav_status_t* _status)
{
    fmav_open_drone_id_message_pack_t* _payload = (fmav_open_drone_id_message_pack_t*)msg->payload;

    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->single_message_size = single_message_size;
    _payload->msg_pack_size = msg_pack_size;
    memcpy(&(_payload->messages), messages, sizeof(uint8_t)*250);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_message_pack_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_message_pack_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_message_pack_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->single_message_size, _payload->msg_pack_size, _payload->messages,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_message_pack_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t single_message_size, uint8_t msg_pack_size, const uint8_t* messages,
    fmav_status_t* _status)
{
    fmav_open_drone_id_message_pack_t* _payload = (fmav_open_drone_id_message_pack_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->single_message_size = single_message_size;
    _payload->msg_pack_size = msg_pack_size;
    memcpy(&(_payload->messages), messages, sizeof(uint8_t)*250);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_message_pack_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_message_pack_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_message_pack_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->single_message_size, _payload->msg_pack_size, _payload->messages,
        _status);
}


//----------------------------------------
//-- Message OPEN_DRONE_ID_MESSAGE_PACK unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_open_drone_id_message_pack_decode(fmav_open_drone_id_message_pack_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK  12915

#define mavlink_open_drone_id_message_pack_t  fmav_open_drone_id_message_pack_t

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_LEN  254
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_MIN_LEN  254
#define MAVLINK_MSG_ID_12915_LEN  254
#define MAVLINK_MSG_ID_12915_MIN_LEN  254

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_CRC  62
#define MAVLINK_MSG_ID_12915_CRC  62

#define MAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_FIELD_MESSAGES_LEN 250


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_message_pack_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint8_t single_message_size, uint8_t msg_pack_size, const uint8_t* messages)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_open_drone_id_message_pack_pack(
        msg, sysid, compid,
        target_system, target_component, single_message_size, msg_pack_size, messages,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_message_pack_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t single_message_size, uint8_t msg_pack_size, const uint8_t* messages)
{
    return fmav_msg_open_drone_id_message_pack_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, single_message_size, msg_pack_size, messages,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_open_drone_id_message_pack_decode(const mavlink_message_t* msg, mavlink_open_drone_id_message_pack_t* payload)
{
    fmav_msg_open_drone_id_message_pack_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_H
