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

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_gps_global_origin_t {
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
    uint64_t time_usec;
}) fmav_gps_global_origin_t;


#define FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN  49

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX  20
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA  39

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FLAGS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FRAME_LEN_MAX  45



#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_LATITUDE_OFS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_LONGITUDE_OFS  4
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_ALTITUDE_OFS  8
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_TIME_USEC_OFS  12


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)_msg->payload;

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack(
        _msg, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t _payload;

    _payload.latitude = latitude;
    _payload.longitude = longitude;
    _payload.altitude = altitude;
    _payload.time_usec = time_usec;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gps_global_origin_decode(fmav_gps_global_origin_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_latitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_longitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_altitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_gps_global_origin_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[12]), sizeof(uint64_t));
    return r;
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
    mavlink_message_t* _msg,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_gps_global_origin_pack(
        _msg, sysid, compid,
        latitude, longitude, altitude, time_usec,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gps_global_origin_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        (uint8_t*)_buf,
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
