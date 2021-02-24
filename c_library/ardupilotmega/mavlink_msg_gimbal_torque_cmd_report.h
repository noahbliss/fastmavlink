//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_H
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_H


//----------------------------------------
//-- Message GIMBAL_TORQUE_CMD_REPORT
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_gimbal_torque_cmd_report_t {
    int16_t rl_torque_cmd;
    int16_t el_torque_cmd;
    int16_t az_torque_cmd;
    uint8_t target_system;
    uint8_t target_component;
}) fmav_gimbal_torque_cmd_report_t;


#define FASTMAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT  214


#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MIN  8
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX  8
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN  8
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_CRCEXTRA  69

#define FASTMAVLINK_MSG_ID_214_LEN_MIN  8
#define FASTMAVLINK_MSG_ID_214_LEN_MAX  8
#define FASTMAVLINK_MSG_ID_214_LEN  8
#define FASTMAVLINK_MSG_ID_214_CRCEXTRA  69



#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_FLAGS  3
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_TARGET_SYSTEM_OFS  6
#define FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_TARGET_COMPONENT_OFS  7


//----------------------------------------
//-- Message GIMBAL_TORQUE_CMD_REPORT packing routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_torque_cmd_report_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int16_t rl_torque_cmd, int16_t el_torque_cmd, int16_t az_torque_cmd,
    fmav_status_t* _status)
{
    fmav_gimbal_torque_cmd_report_t* _payload = (fmav_gimbal_torque_cmd_report_t*)msg->payload;

    _payload->rl_torque_cmd = rl_torque_cmd;
    _payload->el_torque_cmd = el_torque_cmd;
    _payload->az_torque_cmd = az_torque_cmd;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_torque_cmd_report_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gimbal_torque_cmd_report_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gimbal_torque_cmd_report_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->rl_torque_cmd, _payload->el_torque_cmd, _payload->az_torque_cmd,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_torque_cmd_report_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int16_t rl_torque_cmd, int16_t el_torque_cmd, int16_t az_torque_cmd,
    fmav_status_t* _status)
{
    fmav_gimbal_torque_cmd_report_t* _payload = (fmav_gimbal_torque_cmd_report_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->rl_torque_cmd = rl_torque_cmd;
    _payload->el_torque_cmd = el_torque_cmd;
    _payload->az_torque_cmd = az_torque_cmd;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_CRCEXTRA,
        _status);
}

    
FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gimbal_torque_cmd_report_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gimbal_torque_cmd_report_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gimbal_torque_cmd_report_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->rl_torque_cmd, _payload->el_torque_cmd, _payload->az_torque_cmd,
        _status);
}


//----------------------------------------
//-- Message GIMBAL_TORQUE_CMD_REPORT unpacking routines
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gimbal_torque_cmd_report_decode(fmav_gimbal_torque_cmd_report_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT  214

#define mavlink_gimbal_torque_cmd_report_t  fmav_gimbal_torque_cmd_report_t

#define MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT_LEN  8
#define MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT_MIN_LEN  8
#define MAVLINK_MSG_ID_214_LEN  8
#define MAVLINK_MSG_ID_214_MIN_LEN  8

#define MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT_CRC  69
#define MAVLINK_MSG_ID_214_CRC  69




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gimbal_torque_cmd_report_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, int16_t rl_torque_cmd, int16_t el_torque_cmd, int16_t az_torque_cmd)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_gimbal_torque_cmd_report_pack(
        msg, sysid, compid,
        target_system, target_component, rl_torque_cmd, el_torque_cmd, az_torque_cmd,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gimbal_torque_cmd_report_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int16_t rl_torque_cmd, int16_t el_torque_cmd, int16_t az_torque_cmd)
{
    return fmav_msg_gimbal_torque_cmd_report_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, rl_torque_cmd, el_torque_cmd, az_torque_cmd,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_gimbal_torque_cmd_report_decode(const mavlink_message_t* msg, mavlink_gimbal_torque_cmd_report_t* payload)
{
    fmav_msg_gimbal_torque_cmd_report_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_GIMBAL_TORQUE_CMD_REPORT_H