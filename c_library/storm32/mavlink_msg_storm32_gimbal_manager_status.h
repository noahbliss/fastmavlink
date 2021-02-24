//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_H
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_H


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_STATUS
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_storm32_gimbal_manager_status_t {
    uint16_t device_flags;
    uint16_t manager_flags;
    uint8_t gimbal_id;
    uint8_t supervisor;
    uint8_t profile;
}) fmav_storm32_gimbal_manager_status_t;


#define FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS  60011


#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MIN  7
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX  7
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN  7
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_CRCEXTRA  183

#define FASTMAVLINK_MSG_ID_60011_LEN_MIN  7
#define FASTMAVLINK_MSG_ID_60011_LEN_MAX  7
#define FASTMAVLINK_MSG_ID_60011_LEN  7
#define FASTMAVLINK_MSG_ID_60011_CRCEXTRA  183



#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_FLAGS  0
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_TARGET_COMPONENT_OFS  0


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_STATUS packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_status_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t gimbal_id, uint8_t supervisor, uint16_t device_flags, uint16_t manager_flags, uint8_t profile,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_status_t* _payload = (fmav_storm32_gimbal_manager_status_t*)msg->payload;

    _payload->device_flags = device_flags;
    _payload->manager_flags = manager_flags;
    _payload->gimbal_id = gimbal_id;
    _payload->supervisor = supervisor;
    _payload->profile = profile;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_status_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_status_pack(
        msg, sysid, compid,
        _payload->gimbal_id, _payload->supervisor, _payload->device_flags, _payload->manager_flags, _payload->profile,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_status_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t gimbal_id, uint8_t supervisor, uint16_t device_flags, uint16_t manager_flags, uint8_t profile,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_status_t* _payload = (fmav_storm32_gimbal_manager_status_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->device_flags = device_flags;
    _payload->manager_flags = manager_flags;
    _payload->gimbal_id = gimbal_id;
    _payload->supervisor = supervisor;
    _payload->profile = profile;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_status_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_status_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->gimbal_id, _payload->supervisor, _payload->device_flags, _payload->manager_flags, _payload->profile,
        _status);
}


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_STATUS unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_storm32_gimbal_manager_status_decode(fmav_storm32_gimbal_manager_status_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS  60011

#define mavlink_storm32_gimbal_manager_status_t  fmav_storm32_gimbal_manager_status_t

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS_LEN  7
#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS_MIN_LEN  7
#define MAVLINK_MSG_ID_60011_LEN  7
#define MAVLINK_MSG_ID_60011_MIN_LEN  7

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_STATUS_CRC  183
#define MAVLINK_MSG_ID_60011_CRC  183




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_status_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t gimbal_id, uint8_t supervisor, uint16_t device_flags, uint16_t manager_flags, uint8_t profile)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_storm32_gimbal_manager_status_pack(
        msg, sysid, compid,
        gimbal_id, supervisor, device_flags, manager_flags, profile,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_status_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t gimbal_id, uint8_t supervisor, uint16_t device_flags, uint16_t manager_flags, uint8_t profile)
{
    return fmav_msg_storm32_gimbal_manager_status_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        gimbal_id, supervisor, device_flags, manager_flags, profile,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_storm32_gimbal_manager_status_decode(const mavlink_message_t* msg, mavlink_storm32_gimbal_manager_status_t* payload)
{
    fmav_msg_storm32_gimbal_manager_status_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_STATUS_H