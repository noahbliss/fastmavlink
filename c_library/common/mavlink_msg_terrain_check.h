//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_TERRAIN_CHECK_H
#define FASTMAVLINK_MSG_TERRAIN_CHECK_H


//----------------------------------------
//-- Message TERRAIN_CHECK
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_terrain_check_t {
    int32_t lat;
    int32_t lon;
}) fmav_terrain_check_t;


#define FASTMAVLINK_MSG_ID_TERRAIN_CHECK  135


#define FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MIN  8
#define FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX  8
#define FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN  8
#define FASTMAVLINK_MSG_TERRAIN_CHECK_CRCEXTRA  203

#define FASTMAVLINK_MSG_ID_135_LEN_MIN  8
#define FASTMAVLINK_MSG_ID_135_LEN_MAX  8
#define FASTMAVLINK_MSG_ID_135_LEN  8
#define FASTMAVLINK_MSG_ID_135_CRCEXTRA  203



#define FASTMAVLINK_MSG_TERRAIN_CHECK_FLAGS  0
#define FASTMAVLINK_MSG_TERRAIN_CHECK_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_TERRAIN_CHECK_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message TERRAIN_CHECK packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_terrain_check_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    int32_t lat, int32_t lon,
    fmav_status_t* _status)
{
    fmav_terrain_check_t* _payload = (fmav_terrain_check_t*)msg->payload;

    _payload->lat = lat;
    _payload->lon = lon;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_TERRAIN_CHECK;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_TERRAIN_CHECK_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_terrain_check_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_terrain_check_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_terrain_check_pack(
        msg, sysid, compid,
        _payload->lat, _payload->lon,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_terrain_check_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    int32_t lat, int32_t lon,
    fmav_status_t* _status)
{
    fmav_terrain_check_t* _payload = (fmav_terrain_check_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->lat = lat;
    _payload->lon = lon;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_TERRAIN_CHECK;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_TERRAIN_CHECK >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_TERRAIN_CHECK >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_TERRAIN_CHECK_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_terrain_check_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_terrain_check_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_terrain_check_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->lat, _payload->lon,
        _status);
}


//----------------------------------------
//-- Message TERRAIN_CHECK unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_terrain_check_decode(fmav_terrain_check_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_TERRAIN_CHECK_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_TERRAIN_CHECK  135

#define mavlink_terrain_check_t  fmav_terrain_check_t

#define MAVLINK_MSG_ID_TERRAIN_CHECK_LEN  8
#define MAVLINK_MSG_ID_TERRAIN_CHECK_MIN_LEN  8
#define MAVLINK_MSG_ID_135_LEN  8
#define MAVLINK_MSG_ID_135_MIN_LEN  8

#define MAVLINK_MSG_ID_TERRAIN_CHECK_CRC  203
#define MAVLINK_MSG_ID_135_CRC  203




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_terrain_check_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    int32_t lat, int32_t lon)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_terrain_check_pack(
        msg, sysid, compid,
        lat, lon,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_terrain_check_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    int32_t lat, int32_t lon)
{
    return fmav_msg_terrain_check_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        lat, lon,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_terrain_check_decode(const mavlink_message_t* msg, mavlink_terrain_check_t* payload)
{
    fmav_msg_terrain_check_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_TERRAIN_CHECK_H