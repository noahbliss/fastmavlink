//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_H
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_H


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_osd_param_show_config_t {
    uint32_t request_id;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t osd_screen;
    uint8_t osd_index;
}) fmav_osd_param_show_config_t;


#define FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG  11035

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX  8
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_CRCEXTRA  128

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FLAGS  3
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_TARGET_SYSTEM_OFS  4
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_TARGET_COMPONENT_OFS  5

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FRAME_LEN_MAX  33



#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FIELD_REQUEST_ID_OFS  0
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FIELD_TARGET_SYSTEM_OFS  4
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FIELD_TARGET_COMPONENT_OFS  5
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FIELD_OSD_SCREEN_OFS  6
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_FIELD_OSD_INDEX_OFS  7


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t request_id, uint8_t osd_screen, uint8_t osd_index,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_t* _payload = (fmav_osd_param_show_config_t*)_msg->payload;

    _payload->request_id = request_id;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->osd_screen = osd_screen;
    _payload->osd_index = osd_index;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG;
    _msg->target_sysid = target_system;
    _msg->target_compid = target_component;
    _msg->crc_extra = FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_osd_param_show_config_pack(
        _msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->request_id, _payload->osd_screen, _payload->osd_index,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t request_id, uint8_t osd_screen, uint8_t osd_index,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_t* _payload = (fmav_osd_param_show_config_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->request_id = request_id;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->osd_screen = osd_screen;
    _payload->osd_index = osd_index;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_osd_param_show_config_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->request_id, _payload->osd_screen, _payload->osd_index,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t request_id, uint8_t osd_screen, uint8_t osd_index,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_t _payload;

    _payload.request_id = request_id;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.osd_screen = osd_screen;
    _payload.osd_index = osd_index;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_osd_param_show_config_decode(fmav_osd_param_show_config_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_osd_param_show_config_get_field_request_id(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_osd_param_show_config_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_osd_param_show_config_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[5]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_osd_param_show_config_get_field_osd_screen(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[6]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_osd_param_show_config_get_field_osd_index(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[7]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG  11035

#define mavlink_osd_param_show_config_t  fmav_osd_param_show_config_t

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_LEN  8
#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_MIN_LEN  8
#define MAVLINK_MSG_ID_11035_LEN  8
#define MAVLINK_MSG_ID_11035_MIN_LEN  8

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_CRC  128
#define MAVLINK_MSG_ID_11035_CRC  128




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_osd_param_show_config_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t target_system, uint8_t target_component, uint32_t request_id, uint8_t osd_screen, uint8_t osd_index)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_osd_param_show_config_pack(
        _msg, sysid, compid,
        target_system, target_component, request_id, osd_screen, osd_index,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_osd_param_show_config_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint32_t request_id, uint8_t osd_screen, uint8_t osd_index)
{
    return fmav_msg_osd_param_show_config_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        target_system, target_component, request_id, osd_screen, osd_index,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_osd_param_show_config_decode(const mavlink_message_t* msg, mavlink_osd_param_show_config_t* payload)
{
    fmav_msg_osd_param_show_config_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_H
