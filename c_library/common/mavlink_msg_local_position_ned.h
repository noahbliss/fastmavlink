//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_LOCAL_POSITION_NED_H
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_H


//----------------------------------------
//-- Message LOCAL_POSITION_NED
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_local_position_ned_t {
    uint32_t time_boot_ms;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
}) fmav_local_position_ned_t;


#define FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED  32

#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX  28
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_CRCEXTRA  185

#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FLAGS  0
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FRAME_LEN_MAX  53



#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_TIME_BOOT_MS_OFS  0
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_X_OFS  4
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_Y_OFS  8
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_Z_OFS  12
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_VX_OFS  16
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_VY_OFS  20
#define FASTMAVLINK_MSG_LOCAL_POSITION_NED_FIELD_VZ_OFS  24


//----------------------------------------
//-- Message LOCAL_POSITION_NED pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz,
    fmav_status_t* _status)
{
    fmav_local_position_ned_t* _payload = (fmav_local_position_ned_t*)_msg->payload;

    _payload->time_boot_ms = time_boot_ms;
    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->vx = vx;
    _payload->vy = vy;
    _payload->vz = vz;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_LOCAL_POSITION_NED_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_local_position_ned_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_local_position_ned_pack(
        _msg, sysid, compid,
        _payload->time_boot_ms, _payload->x, _payload->y, _payload->z, _payload->vx, _payload->vy, _payload->vz,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz,
    fmav_status_t* _status)
{
    fmav_local_position_ned_t* _payload = (fmav_local_position_ned_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_boot_ms = time_boot_ms;
    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->vx = vx;
    _payload->vy = vy;
    _payload->vz = vz;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_local_position_ned_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_local_position_ned_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->time_boot_ms, _payload->x, _payload->y, _payload->z, _payload->vx, _payload->vy, _payload->vz,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz,
    fmav_status_t* _status)
{
    fmav_local_position_ned_t _payload;

    _payload.time_boot_ms = time_boot_ms;
    _payload.x = x;
    _payload.y = y;
    _payload.z = z;
    _payload.vx = vx;
    _payload.vy = vy;
    _payload.vz = vz;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_local_position_ned_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_local_position_ned_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_LOCAL_POSITION_NED,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOCAL_POSITION_NED_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message LOCAL_POSITION_NED decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_local_position_ned_decode(fmav_local_position_ned_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_LOCAL_POSITION_NED_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_local_position_ned_get_field_time_boot_ms(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_x(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[4]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_y(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[8]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_z(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[12]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_vx(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[16]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_vy(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[20]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_local_position_ned_get_field_vz(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[24]), sizeof(float));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_LOCAL_POSITION_NED  32

#define mavlink_local_position_ned_t  fmav_local_position_ned_t

#define MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN  28
#define MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN  28
#define MAVLINK_MSG_ID_32_LEN  28
#define MAVLINK_MSG_ID_32_MIN_LEN  28

#define MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC  185
#define MAVLINK_MSG_ID_32_CRC  185




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_local_position_ned_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_local_position_ned_pack(
        _msg, sysid, compid,
        time_boot_ms, x, y, z, vx, vy, vz,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_local_position_ned_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz)
{
    return fmav_msg_local_position_ned_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        time_boot_ms, x, y, z, vx, vy, vz,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_local_position_ned_decode(const mavlink_message_t* msg, mavlink_local_position_ned_t* payload)
{
    fmav_msg_local_position_ned_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_LOCAL_POSITION_NED_H
