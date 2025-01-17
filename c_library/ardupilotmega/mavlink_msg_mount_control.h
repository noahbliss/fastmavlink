//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_MOUNT_CONTROL_H
#define FASTMAVLINK_MSG_MOUNT_CONTROL_H


//----------------------------------------
//-- Message MOUNT_CONTROL
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_mount_control_t {
    int32_t input_a;
    int32_t input_b;
    int32_t input_c;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t save_position;
}) fmav_mount_control_t;


#define FASTMAVLINK_MSG_ID_MOUNT_CONTROL  157

#define FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX  15
#define FASTMAVLINK_MSG_MOUNT_CONTROL_CRCEXTRA  21

#define FASTMAVLINK_MSG_MOUNT_CONTROL_FLAGS  3
#define FASTMAVLINK_MSG_MOUNT_CONTROL_TARGET_SYSTEM_OFS  12
#define FASTMAVLINK_MSG_MOUNT_CONTROL_TARGET_COMPONENT_OFS  13

#define FASTMAVLINK_MSG_MOUNT_CONTROL_FRAME_LEN_MAX  40



#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_INPUT_A_OFS  0
#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_INPUT_B_OFS  4
#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_INPUT_C_OFS  8
#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_TARGET_SYSTEM_OFS  12
#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_TARGET_COMPONENT_OFS  13
#define FASTMAVLINK_MSG_MOUNT_CONTROL_FIELD_SAVE_POSITION_OFS  14


//----------------------------------------
//-- Message MOUNT_CONTROL pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t input_a, int32_t input_b, int32_t input_c, uint8_t save_position,
    fmav_status_t* _status)
{
    fmav_mount_control_t* _payload = (fmav_mount_control_t*)_msg->payload;

    _payload->input_a = input_a;
    _payload->input_b = input_b;
    _payload->input_c = input_c;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->save_position = save_position;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_MOUNT_CONTROL;
    _msg->target_sysid = target_system;
    _msg->target_compid = target_component;
    _msg->crc_extra = FASTMAVLINK_MSG_MOUNT_CONTROL_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_mount_control_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_mount_control_pack(
        _msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->input_a, _payload->input_b, _payload->input_c, _payload->save_position,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t input_a, int32_t input_b, int32_t input_c, uint8_t save_position,
    fmav_status_t* _status)
{
    fmav_mount_control_t* _payload = (fmav_mount_control_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->input_a = input_a;
    _payload->input_b = input_b;
    _payload->input_c = input_c;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->save_position = save_position;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_MOUNT_CONTROL;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_MOUNT_CONTROL >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_MOUNT_CONTROL >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MOUNT_CONTROL_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_mount_control_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_mount_control_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->input_a, _payload->input_b, _payload->input_c, _payload->save_position,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t input_a, int32_t input_b, int32_t input_c, uint8_t save_position,
    fmav_status_t* _status)
{
    fmav_mount_control_t _payload;

    _payload.input_a = input_a;
    _payload.input_b = input_b;
    _payload.input_c = input_c;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.save_position = save_position;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_MOUNT_CONTROL,
        FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MOUNT_CONTROL_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mount_control_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_mount_control_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_MOUNT_CONTROL,
        FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MOUNT_CONTROL_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message MOUNT_CONTROL decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_mount_control_decode(fmav_mount_control_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_MOUNT_CONTROL_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_mount_control_get_field_input_a(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_mount_control_get_field_input_b(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_mount_control_get_field_input_c(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_mount_control_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[12]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_mount_control_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[13]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_mount_control_get_field_save_position(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[14]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_MOUNT_CONTROL  157

#define mavlink_mount_control_t  fmav_mount_control_t

#define MAVLINK_MSG_ID_MOUNT_CONTROL_LEN  15
#define MAVLINK_MSG_ID_MOUNT_CONTROL_MIN_LEN  15
#define MAVLINK_MSG_ID_157_LEN  15
#define MAVLINK_MSG_ID_157_MIN_LEN  15

#define MAVLINK_MSG_ID_MOUNT_CONTROL_CRC  21
#define MAVLINK_MSG_ID_157_CRC  21




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_mount_control_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t target_system, uint8_t target_component, int32_t input_a, int32_t input_b, int32_t input_c, uint8_t save_position)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_mount_control_pack(
        _msg, sysid, compid,
        target_system, target_component, input_a, input_b, input_c, save_position,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_mount_control_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, int32_t input_a, int32_t input_b, int32_t input_c, uint8_t save_position)
{
    return fmav_msg_mount_control_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        target_system, target_component, input_a, input_b, input_c, save_position,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_mount_control_decode(const mavlink_message_t* msg, mavlink_mount_control_t* payload)
{
    fmav_msg_mount_control_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_MOUNT_CONTROL_H
