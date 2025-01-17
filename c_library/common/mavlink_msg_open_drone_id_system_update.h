//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_H
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_H


//----------------------------------------
//-- Message OPEN_DRONE_ID_SYSTEM_UPDATE
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_open_drone_id_system_update_t {
    int32_t operator_latitude;
    int32_t operator_longitude;
    float operator_altitude_geo;
    uint32_t timestamp;
    uint8_t target_system;
    uint8_t target_component;
}) fmav_open_drone_id_system_update_t;


#define FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE  12919

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX  18
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_CRCEXTRA  7

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FLAGS  3
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_TARGET_SYSTEM_OFS  16
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_TARGET_COMPONENT_OFS  17

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FRAME_LEN_MAX  43



#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_OPERATOR_LATITUDE_OFS  0
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_OPERATOR_LONGITUDE_OFS  4
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_OPERATOR_ALTITUDE_GEO_OFS  8
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_TIMESTAMP_OFS  12
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_TARGET_SYSTEM_OFS  16
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_FIELD_TARGET_COMPONENT_OFS  17


//----------------------------------------
//-- Message OPEN_DRONE_ID_SYSTEM_UPDATE pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t operator_latitude, int32_t operator_longitude, float operator_altitude_geo, uint32_t timestamp,
    fmav_status_t* _status)
{
    fmav_open_drone_id_system_update_t* _payload = (fmav_open_drone_id_system_update_t*)_msg->payload;

    _payload->operator_latitude = operator_latitude;
    _payload->operator_longitude = operator_longitude;
    _payload->operator_altitude_geo = operator_altitude_geo;
    _payload->timestamp = timestamp;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE;
    _msg->target_sysid = target_system;
    _msg->target_compid = target_component;
    _msg->crc_extra = FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_system_update_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_system_update_pack(
        _msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->operator_latitude, _payload->operator_longitude, _payload->operator_altitude_geo, _payload->timestamp,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t operator_latitude, int32_t operator_longitude, float operator_altitude_geo, uint32_t timestamp,
    fmav_status_t* _status)
{
    fmav_open_drone_id_system_update_t* _payload = (fmav_open_drone_id_system_update_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->operator_latitude = operator_latitude;
    _payload->operator_longitude = operator_longitude;
    _payload->operator_altitude_geo = operator_altitude_geo;
    _payload->timestamp = timestamp;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_system_update_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_system_update_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->operator_latitude, _payload->operator_longitude, _payload->operator_altitude_geo, _payload->timestamp,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t operator_latitude, int32_t operator_longitude, float operator_altitude_geo, uint32_t timestamp,
    fmav_status_t* _status)
{
    fmav_open_drone_id_system_update_t _payload;

    _payload.operator_latitude = operator_latitude;
    _payload.operator_longitude = operator_longitude;
    _payload.operator_altitude_geo = operator_altitude_geo;
    _payload.timestamp = timestamp;
    _payload.target_system = target_system;
    _payload.target_component = target_component;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_system_update_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_system_update_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message OPEN_DRONE_ID_SYSTEM_UPDATE decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_open_drone_id_system_update_decode(fmav_open_drone_id_system_update_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_open_drone_id_system_update_get_field_operator_latitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_open_drone_id_system_update_get_field_operator_longitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_open_drone_id_system_update_get_field_operator_altitude_geo(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[8]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_open_drone_id_system_update_get_field_timestamp(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[12]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_system_update_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[16]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_system_update_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[17]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE  12919

#define mavlink_open_drone_id_system_update_t  fmav_open_drone_id_system_update_t

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE_LEN  18
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE_MIN_LEN  18
#define MAVLINK_MSG_ID_12919_LEN  18
#define MAVLINK_MSG_ID_12919_MIN_LEN  18

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SYSTEM_UPDATE_CRC  7
#define MAVLINK_MSG_ID_12919_CRC  7




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_system_update_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t target_system, uint8_t target_component, int32_t operator_latitude, int32_t operator_longitude, float operator_altitude_geo, uint32_t timestamp)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_open_drone_id_system_update_pack(
        _msg, sysid, compid,
        target_system, target_component, operator_latitude, operator_longitude, operator_altitude_geo, timestamp,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_system_update_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t operator_latitude, int32_t operator_longitude, float operator_altitude_geo, uint32_t timestamp)
{
    return fmav_msg_open_drone_id_system_update_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        target_system, target_component, operator_latitude, operator_longitude, operator_altitude_geo, timestamp,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_open_drone_id_system_update_decode(const mavlink_message_t* msg, mavlink_open_drone_id_system_update_t* payload)
{
    fmav_msg_open_drone_id_system_update_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_OPEN_DRONE_ID_SYSTEM_UPDATE_H
