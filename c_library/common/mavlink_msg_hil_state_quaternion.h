//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_HIL_STATE_QUATERNION_H
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_H


//----------------------------------------
//-- Message HIL_STATE_QUATERNION
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_hil_state_quaternion_t {
    uint64_t time_usec;
    float attitude_quaternion[4];
    float rollspeed;
    float pitchspeed;
    float yawspeed;
    int32_t lat;
    int32_t lon;
    int32_t alt;
    int16_t vx;
    int16_t vy;
    int16_t vz;
    uint16_t ind_airspeed;
    uint16_t true_airspeed;
    int16_t xacc;
    int16_t yacc;
    int16_t zacc;
}) fmav_hil_state_quaternion_t;


#define FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION  115

#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX  64
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_CRCEXTRA  4

#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FLAGS  0
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FRAME_LEN_MAX  89

#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_NUM  4 // number of elements in array
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_LEN  16 // length of array = number of bytes

#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_TIME_USEC_OFS  0
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_OFS  8
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ROLLSPEED_OFS  24
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_PITCHSPEED_OFS  28
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_YAWSPEED_OFS  32
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_LAT_OFS  36
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_LON_OFS  40
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ALT_OFS  44
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_VX_OFS  48
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_VY_OFS  50
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_VZ_OFS  52
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_IND_AIRSPEED_OFS  54
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_TRUE_AIRSPEED_OFS  56
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_XACC_OFS  58
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_YACC_OFS  60
#define FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ZACC_OFS  62


//----------------------------------------
//-- Message HIL_STATE_QUATERNION pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, const float* attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc,
    fmav_status_t* _status)
{
    fmav_hil_state_quaternion_t* _payload = (fmav_hil_state_quaternion_t*)_msg->payload;

    _payload->time_usec = time_usec;
    _payload->rollspeed = rollspeed;
    _payload->pitchspeed = pitchspeed;
    _payload->yawspeed = yawspeed;
    _payload->lat = lat;
    _payload->lon = lon;
    _payload->alt = alt;
    _payload->vx = vx;
    _payload->vy = vy;
    _payload->vz = vz;
    _payload->ind_airspeed = ind_airspeed;
    _payload->true_airspeed = true_airspeed;
    _payload->xacc = xacc;
    _payload->yacc = yacc;
    _payload->zacc = zacc;
    memcpy(&(_payload->attitude_quaternion), attitude_quaternion, sizeof(float)*4);

    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_HIL_STATE_QUATERNION_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_hil_state_quaternion_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_hil_state_quaternion_pack(
        _msg, sysid, compid,
        _payload->time_usec, _payload->attitude_quaternion, _payload->rollspeed, _payload->pitchspeed, _payload->yawspeed, _payload->lat, _payload->lon, _payload->alt, _payload->vx, _payload->vy, _payload->vz, _payload->ind_airspeed, _payload->true_airspeed, _payload->xacc, _payload->yacc, _payload->zacc,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, const float* attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc,
    fmav_status_t* _status)
{
    fmav_hil_state_quaternion_t* _payload = (fmav_hil_state_quaternion_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_usec = time_usec;
    _payload->rollspeed = rollspeed;
    _payload->pitchspeed = pitchspeed;
    _payload->yawspeed = yawspeed;
    _payload->lat = lat;
    _payload->lon = lon;
    _payload->alt = alt;
    _payload->vx = vx;
    _payload->vy = vy;
    _payload->vz = vz;
    _payload->ind_airspeed = ind_airspeed;
    _payload->true_airspeed = true_airspeed;
    _payload->xacc = xacc;
    _payload->yacc = yacc;
    _payload->zacc = zacc;
    memcpy(&(_payload->attitude_quaternion), attitude_quaternion, sizeof(float)*4);

    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_hil_state_quaternion_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_hil_state_quaternion_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->time_usec, _payload->attitude_quaternion, _payload->rollspeed, _payload->pitchspeed, _payload->yawspeed, _payload->lat, _payload->lon, _payload->alt, _payload->vx, _payload->vy, _payload->vz, _payload->ind_airspeed, _payload->true_airspeed, _payload->xacc, _payload->yacc, _payload->zacc,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, const float* attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc,
    fmav_status_t* _status)
{
    fmav_hil_state_quaternion_t _payload;

    _payload.time_usec = time_usec;
    _payload.rollspeed = rollspeed;
    _payload.pitchspeed = pitchspeed;
    _payload.yawspeed = yawspeed;
    _payload.lat = lat;
    _payload.lon = lon;
    _payload.alt = alt;
    _payload.vx = vx;
    _payload.vy = vy;
    _payload.vz = vz;
    _payload.ind_airspeed = ind_airspeed;
    _payload.true_airspeed = true_airspeed;
    _payload.xacc = xacc;
    _payload.yacc = yacc;
    _payload.zacc = zacc;
    memcpy(&(_payload.attitude_quaternion), attitude_quaternion, sizeof(float)*4);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_hil_state_quaternion_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_HIL_STATE_QUATERNION,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIL_STATE_QUATERNION_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message HIL_STATE_QUATERNION decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_hil_state_quaternion_decode(fmav_hil_state_quaternion_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_HIL_STATE_QUATERNION_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_hil_state_quaternion_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint64_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_hil_state_quaternion_get_field_rollspeed(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[24]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_hil_state_quaternion_get_field_pitchspeed(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[28]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_hil_state_quaternion_get_field_yawspeed(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[32]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_hil_state_quaternion_get_field_lat(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[36]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_hil_state_quaternion_get_field_lon(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[40]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_hil_state_quaternion_get_field_alt(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[44]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_vx(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[48]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_vy(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[50]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_vz(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[52]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_get_field_ind_airspeed(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[54]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_hil_state_quaternion_get_field_true_airspeed(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[56]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_xacc(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[58]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_yacc(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[60]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_hil_state_quaternion_get_field_zacc(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[62]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float* fmav_msg_hil_state_quaternion_get_field_attitude_quaternion_ptr(const fmav_message_t* msg)
{
    return (float*)&(msg->payload[8]);
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_hil_state_quaternion_get_field_attitude_quaternion(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_NUM) return 0;
    return ((float*)&(msg->payload[8]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION  115

#define mavlink_hil_state_quaternion_t  fmav_hil_state_quaternion_t

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_LEN  64
#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_MIN_LEN  64
#define MAVLINK_MSG_ID_115_LEN  64
#define MAVLINK_MSG_ID_115_MIN_LEN  64

#define MAVLINK_MSG_ID_HIL_STATE_QUATERNION_CRC  4
#define MAVLINK_MSG_ID_115_CRC  4

#define MAVLINK_MSG_HIL_STATE_QUATERNION_FIELD_ATTITUDE_QUATERNION_LEN 4


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_hil_state_quaternion_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint64_t time_usec, const float* attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_hil_state_quaternion_pack(
        _msg, sysid, compid,
        time_usec, attitude_quaternion, rollspeed, pitchspeed, yawspeed, lat, lon, alt, vx, vy, vz, ind_airspeed, true_airspeed, xacc, yacc, zacc,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_hil_state_quaternion_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, const float* attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc)
{
    return fmav_msg_hil_state_quaternion_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        time_usec, attitude_quaternion, rollspeed, pitchspeed, yawspeed, lat, lon, alt, vx, vy, vz, ind_airspeed, true_airspeed, xacc, yacc, zacc,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_hil_state_quaternion_decode(const mavlink_message_t* msg, mavlink_hil_state_quaternion_t* payload)
{
    fmav_msg_hil_state_quaternion_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_HIL_STATE_QUATERNION_H
