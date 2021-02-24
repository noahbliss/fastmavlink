//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_gps_global_origin_t {
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
    uint64_t time_usec;
}) fmav_gps_global_origin_t;


#define FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN  49


#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MIN  12
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX  20
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN  20
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA  39

#define FASTMAVLINK_MSG_ID_49_LEN_MIN  12
#define FASTMAVLINK_MSG_ID_49_LEN_MAX  20
#define FASTMAVLINK_MSG_ID_49_LEN  20
#define FASTMAVLINK_MSG_ID_49_CRCEXTRA  39



#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FLAGS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)msg->payload;

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack(
        msg, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gps_global_origin_decode(fmav_gps_global_origin_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN  49

#define mavlink_gps_global_origin_t  fmav_gps_global_origin_t

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN  20
#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN  12
#define MAVLINK_MSG_ID_49_LEN  20
#define MAVLINK_MSG_ID_49_MIN_LEN  12

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC  39
#define MAVLINK_MSG_ID_49_CRC  39




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gps_global_origin_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_gps_global_origin_pack(
        msg, sysid, compid,
        latitude, longitude, altitude, time_usec,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gps_global_origin_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        latitude, longitude, altitude, time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_gps_global_origin_decode(const mavlink_message_t* msg, mavlink_gps_global_origin_t* payload)
{
    fmav_msg_gps_global_origin_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H