//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_DATA96_H
#define FASTMAVLINK_MSG_DATA96_H


//----------------------------------------
//-- Message DATA96
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_data96_t {
    uint8_t type;
    uint8_t len;
    uint8_t data[96];
}) fmav_data96_t;


#define FASTMAVLINK_MSG_ID_DATA96  172


#define FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MIN  98
#define FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX  98
#define FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN  98
#define FASTMAVLINK_MSG_DATA96_CRCEXTRA  22

#define FASTMAVLINK_MSG_ID_172_LEN_MIN  98
#define FASTMAVLINK_MSG_ID_172_LEN_MAX  98
#define FASTMAVLINK_MSG_ID_172_LEN  98
#define FASTMAVLINK_MSG_ID_172_CRCEXTRA  22

#define FASTMAVLINK_MSG_DATA96_FIELD_DATA_LEN  96

#define FASTMAVLINK_MSG_DATA96_FLAGS  0
#define FASTMAVLINK_MSG_DATA96_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_DATA96_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message DATA96 packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data96_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_data96_t* _payload = (fmav_data96_t*)msg->payload;

    _payload->type = type;
    _payload->len = len;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*96);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_DATA96;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_DATA96_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data96_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_data96_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_data96_pack(
        msg, sysid, compid,
        _payload->type, _payload->len, _payload->data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data96_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_data96_t* _payload = (fmav_data96_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->type = type;
    _payload->len = len;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*96);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_DATA96;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_DATA96 >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_DATA96 >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DATA96_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_data96_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_data96_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_data96_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->type, _payload->len, _payload->data,
        _status);
}


//----------------------------------------
//-- Message DATA96 unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_data96_decode(fmav_data96_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_DATA96_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_DATA96  172

#define mavlink_data96_t  fmav_data96_t

#define MAVLINK_MSG_ID_DATA96_LEN  98
#define MAVLINK_MSG_ID_DATA96_MIN_LEN  98
#define MAVLINK_MSG_ID_172_LEN  98
#define MAVLINK_MSG_ID_172_MIN_LEN  98

#define MAVLINK_MSG_ID_DATA96_CRC  22
#define MAVLINK_MSG_ID_172_CRC  22

#define MAVLINK_MSG_DATA96_FIELD_DATA_LEN 96


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_data96_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t type, uint8_t len, const uint8_t* data)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_data96_pack(
        msg, sysid, compid,
        type, len, data,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_data96_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t type, uint8_t len, const uint8_t* data)
{
    return fmav_msg_data96_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        type, len, data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_data96_decode(const mavlink_message_t* msg, mavlink_data96_t* payload)
{
    fmav_msg_data96_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_DATA96_H
