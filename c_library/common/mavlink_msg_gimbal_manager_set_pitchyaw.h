//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_H
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_H


//----------------------------------------
//-- Message GIMBAL_MANAGER_SET_PITCHYAW
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_gimbal_manager_set_pitchyaw_t {
    uint32_t flags;
    float pitch;
    float yaw;
    float pitch_rate;
    float yaw_rate;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t gimbal_device_id;
}) fmav_gimbal_manager_set_pitchyaw_t;


#define FASTMAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW  287


#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MIN  23
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX  23
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN  23
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_CRCEXTRA  1

#define FASTMAVLINK_MSG_ID_287_LEN_MIN  23
#define FASTMAVLINK_MSG_ID_287_LEN_MAX  23
#define FASTMAVLINK_MSG_ID_287_LEN  23
#define FASTMAVLINK_MSG_ID_287_CRCEXTRA  1



#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_FLAGS  3
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_TARGET_SYSTEM_OFS  20
#define FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_TARGET_COMPONENT_OFS  21


//----------------------------------------
//-- Message GIMBAL_MANAGER_SET_PITCHYAW packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_manager_set_pitchyaw_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t flags, uint8_t gimbal_device_id, float pitch, float yaw, float pitch_rate, float yaw_rate,
    fmav_status_t* _status)
{
    fmav_gimbal_manager_set_pitchyaw_t* _payload = (fmav_gimbal_manager_set_pitchyaw_t*)msg->payload;

    _payload->flags = flags;
    _payload->pitch = pitch;
    _payload->yaw = yaw;
    _payload->pitch_rate = pitch_rate;
    _payload->yaw_rate = yaw_rate;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_device_id = gimbal_device_id;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_manager_set_pitchyaw_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gimbal_manager_set_pitchyaw_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gimbal_manager_set_pitchyaw_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->flags, _payload->gimbal_device_id, _payload->pitch, _payload->yaw, _payload->pitch_rate, _payload->yaw_rate,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_manager_set_pitchyaw_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t flags, uint8_t gimbal_device_id, float pitch, float yaw, float pitch_rate, float yaw_rate,
    fmav_status_t* _status)
{
    fmav_gimbal_manager_set_pitchyaw_t* _payload = (fmav_gimbal_manager_set_pitchyaw_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->flags = flags;
    _payload->pitch = pitch;
    _payload->yaw = yaw;
    _payload->pitch_rate = pitch_rate;
    _payload->yaw_rate = yaw_rate;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_device_id = gimbal_device_id;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_manager_set_pitchyaw_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gimbal_manager_set_pitchyaw_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gimbal_manager_set_pitchyaw_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->flags, _payload->gimbal_device_id, _payload->pitch, _payload->yaw, _payload->pitch_rate, _payload->yaw_rate,
        _status);
}


//----------------------------------------
//-- Message GIMBAL_MANAGER_SET_PITCHYAW unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gimbal_manager_set_pitchyaw_decode(fmav_gimbal_manager_set_pitchyaw_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW  287

#define mavlink_gimbal_manager_set_pitchyaw_t  fmav_gimbal_manager_set_pitchyaw_t

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW_LEN  23
#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW_MIN_LEN  23
#define MAVLINK_MSG_ID_287_LEN  23
#define MAVLINK_MSG_ID_287_MIN_LEN  23

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_PITCHYAW_CRC  1
#define MAVLINK_MSG_ID_287_CRC  1




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gimbal_manager_set_pitchyaw_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint32_t flags, uint8_t gimbal_device_id, float pitch, float yaw, float pitch_rate, float yaw_rate)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_gimbal_manager_set_pitchyaw_pack(
        msg, sysid, compid,
        target_system, target_component, flags, gimbal_device_id, pitch, yaw, pitch_rate, yaw_rate,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gimbal_manager_set_pitchyaw_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t flags, uint8_t gimbal_device_id, float pitch, float yaw, float pitch_rate, float yaw_rate)
{
    return fmav_msg_gimbal_manager_set_pitchyaw_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, flags, gimbal_device_id, pitch, yaw, pitch_rate, yaw_rate,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_gimbal_manager_set_pitchyaw_decode(const mavlink_message_t* msg, mavlink_gimbal_manager_set_pitchyaw_t* payload)
{
    fmav_msg_gimbal_manager_set_pitchyaw_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_GIMBAL_MANAGER_SET_PITCHYAW_H