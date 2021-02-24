//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_VISION_POSITION_DELTA_H
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_H


//----------------------------------------
//-- Message VISION_POSITION_DELTA
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_vision_position_delta_t {
    uint64_t time_usec;
    uint64_t time_delta_usec;
    float angle_delta[3];
    float position_delta[3];
    float confidence;
}) fmav_vision_position_delta_t;


#define FASTMAVLINK_MSG_ID_VISION_POSITION_DELTA  11011


#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MIN  44
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX  44
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN  44
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_CRCEXTRA  106

#define FASTMAVLINK_MSG_ID_11011_LEN_MIN  44
#define FASTMAVLINK_MSG_ID_11011_LEN_MAX  44
#define FASTMAVLINK_MSG_ID_11011_LEN  44
#define FASTMAVLINK_MSG_ID_11011_CRCEXTRA  106

#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_FIELD_ANGLE_DELTA_LEN  3
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_FIELD_POSITION_DELTA_LEN  3

#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_FLAGS  0
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_VISION_POSITION_DELTA_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message VISION_POSITION_DELTA packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_vision_position_delta_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint64_t time_delta_usec, const float* angle_delta, const float* position_delta, float confidence,
    fmav_status_t* _status)
{
    fmav_vision_position_delta_t* _payload = (fmav_vision_position_delta_t*)msg->payload;

    _payload->time_usec = time_usec;
    _payload->time_delta_usec = time_delta_usec;
    _payload->confidence = confidence;
    memcpy(&(_payload->angle_delta), angle_delta, sizeof(float)*3);
    memcpy(&(_payload->position_delta), position_delta, sizeof(float)*3);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_VISION_POSITION_DELTA;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_VISION_POSITION_DELTA_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_vision_position_delta_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_vision_position_delta_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_vision_position_delta_pack(
        msg, sysid, compid,
        _payload->time_usec, _payload->time_delta_usec, _payload->angle_delta, _payload->position_delta, _payload->confidence,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_vision_position_delta_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint64_t time_delta_usec, const float* angle_delta, const float* position_delta, float confidence,
    fmav_status_t* _status)
{
    fmav_vision_position_delta_t* _payload = (fmav_vision_position_delta_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_usec = time_usec;
    _payload->time_delta_usec = time_delta_usec;
    _payload->confidence = confidence;
    memcpy(&(_payload->angle_delta), angle_delta, sizeof(float)*3);
    memcpy(&(_payload->position_delta), position_delta, sizeof(float)*3);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_VISION_POSITION_DELTA;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_VISION_POSITION_DELTA >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_VISION_POSITION_DELTA >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_VISION_POSITION_DELTA_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_vision_position_delta_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_vision_position_delta_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_vision_position_delta_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->time_usec, _payload->time_delta_usec, _payload->angle_delta, _payload->position_delta, _payload->confidence,
        _status);
}


//----------------------------------------
//-- Message VISION_POSITION_DELTA unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_vision_position_delta_decode(fmav_vision_position_delta_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_VISION_POSITION_DELTA_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_VISION_POSITION_DELTA  11011

#define mavlink_vision_position_delta_t  fmav_vision_position_delta_t

#define MAVLINK_MSG_ID_VISION_POSITION_DELTA_LEN  44
#define MAVLINK_MSG_ID_VISION_POSITION_DELTA_MIN_LEN  44
#define MAVLINK_MSG_ID_11011_LEN  44
#define MAVLINK_MSG_ID_11011_MIN_LEN  44

#define MAVLINK_MSG_ID_VISION_POSITION_DELTA_CRC  106
#define MAVLINK_MSG_ID_11011_CRC  106

#define MAVLINK_MSG_VISION_POSITION_DELTA_FIELD_ANGLE_DELTA_LEN 3
#define MAVLINK_MSG_VISION_POSITION_DELTA_FIELD_POSITION_DELTA_LEN 3


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_vision_position_delta_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint64_t time_usec, uint64_t time_delta_usec, const float* angle_delta, const float* position_delta, float confidence)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_vision_position_delta_pack(
        msg, sysid, compid,
        time_usec, time_delta_usec, angle_delta, position_delta, confidence,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_vision_position_delta_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint64_t time_delta_usec, const float* angle_delta, const float* position_delta, float confidence)
{
    return fmav_msg_vision_position_delta_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        time_usec, time_delta_usec, angle_delta, position_delta, confidence,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_vision_position_delta_decode(const mavlink_message_t* msg, mavlink_vision_position_delta_t* payload)
{
    fmav_msg_vision_position_delta_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_VISION_POSITION_DELTA_H