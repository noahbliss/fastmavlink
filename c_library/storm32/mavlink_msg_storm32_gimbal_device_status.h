//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_H
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_H


//----------------------------------------
//-- Message STORM32_GIMBAL_DEVICE_STATUS
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_storm32_gimbal_device_status_t {
    uint32_t time_boot_ms;
    float q[4];
    float angular_velocity_x;
    float angular_velocity_y;
    float angular_velocity_z;
    float yaw_absolute;
    uint16_t flags;
    uint16_t failure_flags;
    uint8_t target_system;
    uint8_t target_component;
}) fmav_storm32_gimbal_device_status_t;


#define FASTMAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS  60001


#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MIN  42
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX  42
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN  42
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_CRCEXTRA  186

#define FASTMAVLINK_MSG_ID_60001_LEN_MIN  42
#define FASTMAVLINK_MSG_ID_60001_LEN_MAX  42
#define FASTMAVLINK_MSG_ID_60001_LEN  42
#define FASTMAVLINK_MSG_ID_60001_CRCEXTRA  186

#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_FIELD_Q_LEN  4

#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_FLAGS  3
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_TARGET_SYSTEM_OFS  40
#define FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_TARGET_COMPONENT_OFS  41


//----------------------------------------
//-- Message STORM32_GIMBAL_DEVICE_STATUS packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_device_status_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t time_boot_ms, uint16_t flags, const float* q, float angular_velocity_x, float angular_velocity_y, float angular_velocity_z, float yaw_absolute, uint16_t failure_flags,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_device_status_t* _payload = (fmav_storm32_gimbal_device_status_t*)msg->payload;

    _payload->time_boot_ms = time_boot_ms;
    _payload->angular_velocity_x = angular_velocity_x;
    _payload->angular_velocity_y = angular_velocity_y;
    _payload->angular_velocity_z = angular_velocity_z;
    _payload->yaw_absolute = yaw_absolute;
    _payload->flags = flags;
    _payload->failure_flags = failure_flags;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    memcpy(&(_payload->q), q, sizeof(float)*4);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_device_status_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_device_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_device_status_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->time_boot_ms, _payload->flags, _payload->q, _payload->angular_velocity_x, _payload->angular_velocity_y, _payload->angular_velocity_z, _payload->yaw_absolute, _payload->failure_flags,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_device_status_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t time_boot_ms, uint16_t flags, const float* q, float angular_velocity_x, float angular_velocity_y, float angular_velocity_z, float yaw_absolute, uint16_t failure_flags,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_device_status_t* _payload = (fmav_storm32_gimbal_device_status_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_boot_ms = time_boot_ms;
    _payload->angular_velocity_x = angular_velocity_x;
    _payload->angular_velocity_y = angular_velocity_y;
    _payload->angular_velocity_z = angular_velocity_z;
    _payload->yaw_absolute = yaw_absolute;
    _payload->flags = flags;
    _payload->failure_flags = failure_flags;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    memcpy(&(_payload->q), q, sizeof(float)*4);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_device_status_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_device_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_device_status_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->time_boot_ms, _payload->flags, _payload->q, _payload->angular_velocity_x, _payload->angular_velocity_y, _payload->angular_velocity_z, _payload->yaw_absolute, _payload->failure_flags,
        _status);
}


//----------------------------------------
//-- Message STORM32_GIMBAL_DEVICE_STATUS unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_storm32_gimbal_device_status_decode(fmav_storm32_gimbal_device_status_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS  60001

#define mavlink_storm32_gimbal_device_status_t  fmav_storm32_gimbal_device_status_t

#define MAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS_LEN  42
#define MAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS_MIN_LEN  42
#define MAVLINK_MSG_ID_60001_LEN  42
#define MAVLINK_MSG_ID_60001_MIN_LEN  42

#define MAVLINK_MSG_ID_STORM32_GIMBAL_DEVICE_STATUS_CRC  186
#define MAVLINK_MSG_ID_60001_CRC  186

#define MAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_FIELD_Q_LEN 4


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_device_status_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint32_t time_boot_ms, uint16_t flags, const float* q, float angular_velocity_x, float angular_velocity_y, float angular_velocity_z, float yaw_absolute, uint16_t failure_flags)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_storm32_gimbal_device_status_pack(
        msg, sysid, compid,
        target_system, target_component, time_boot_ms, flags, q, angular_velocity_x, angular_velocity_y, angular_velocity_z, yaw_absolute, failure_flags,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_device_status_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t time_boot_ms, uint16_t flags, const float* q, float angular_velocity_x, float angular_velocity_y, float angular_velocity_z, float yaw_absolute, uint16_t failure_flags)
{
    return fmav_msg_storm32_gimbal_device_status_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, time_boot_ms, flags, q, angular_velocity_x, angular_velocity_y, angular_velocity_z, yaw_absolute, failure_flags,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_storm32_gimbal_device_status_decode(const mavlink_message_t* msg, mavlink_storm32_gimbal_device_status_t* payload)
{
    fmav_msg_storm32_gimbal_device_status_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_STORM32_GIMBAL_DEVICE_STATUS_H
