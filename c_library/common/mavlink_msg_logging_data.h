//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_LOGGING_DATA_H
#define FASTMAVLINK_MSG_LOGGING_DATA_H


//----------------------------------------
//-- Message LOGGING_DATA
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_logging_data_t {
    uint16_t sequence;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t length;
    uint8_t first_message_offset;
    uint8_t data[249];
}) fmav_logging_data_t;


#define FASTMAVLINK_MSG_ID_LOGGING_DATA  266

#define FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX  255
#define FASTMAVLINK_MSG_LOGGING_DATA_CRCEXTRA  193

#define FASTMAVLINK_MSG_LOGGING_DATA_FLAGS  3
#define FASTMAVLINK_MSG_LOGGING_DATA_TARGET_SYSTEM_OFS  2
#define FASTMAVLINK_MSG_LOGGING_DATA_TARGET_COMPONENT_OFS  3

#define FASTMAVLINK_MSG_LOGGING_DATA_FRAME_LEN_MAX  280

#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_DATA_NUM  249 // number of elements in array
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_DATA_LEN  249 // length of array = number of bytes

#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_SEQUENCE_OFS  0
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_TARGET_SYSTEM_OFS  2
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_TARGET_COMPONENT_OFS  3
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_LENGTH_OFS  4
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_FIRST_MESSAGE_OFFSET_OFS  5
#define FASTMAVLINK_MSG_LOGGING_DATA_FIELD_DATA_OFS  6


//----------------------------------------
//-- Message LOGGING_DATA pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t sequence, uint8_t length, uint8_t first_message_offset, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_logging_data_t* _payload = (fmav_logging_data_t*)_msg->payload;

    _payload->sequence = sequence;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->length = length;
    _payload->first_message_offset = first_message_offset;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*249);

    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_LOGGING_DATA;
    _msg->target_sysid = target_system;
    _msg->target_compid = target_component;
    _msg->crc_extra = FASTMAVLINK_MSG_LOGGING_DATA_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_logging_data_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_logging_data_pack(
        _msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->sequence, _payload->length, _payload->first_message_offset, _payload->data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t sequence, uint8_t length, uint8_t first_message_offset, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_logging_data_t* _payload = (fmav_logging_data_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->sequence = sequence;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->length = length;
    _payload->first_message_offset = first_message_offset;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*249);

    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_LOGGING_DATA;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_LOGGING_DATA >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_LOGGING_DATA >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOGGING_DATA_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_logging_data_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_logging_data_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->sequence, _payload->length, _payload->first_message_offset, _payload->data,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t sequence, uint8_t length, uint8_t first_message_offset, const uint8_t* data,
    fmav_status_t* _status)
{
    fmav_logging_data_t _payload;

    _payload.sequence = sequence;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.length = length;
    _payload.first_message_offset = first_message_offset;
    memcpy(&(_payload.data), data, sizeof(uint8_t)*249);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_LOGGING_DATA,
        FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOGGING_DATA_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_logging_data_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_LOGGING_DATA,
        FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_LOGGING_DATA_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message LOGGING_DATA decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_logging_data_decode(fmav_logging_data_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_LOGGING_DATA_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_logging_data_get_field_sequence(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_logging_data_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[2]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_logging_data_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[3]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_logging_data_get_field_length(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_logging_data_get_field_first_message_offset(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[5]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_logging_data_get_field_data_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[6]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_logging_data_get_field_data(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_LOGGING_DATA_FIELD_DATA_NUM) return 0;
    return ((uint8_t*)&(msg->payload[6]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_LOGGING_DATA  266

#define mavlink_logging_data_t  fmav_logging_data_t

#define MAVLINK_MSG_ID_LOGGING_DATA_LEN  255
#define MAVLINK_MSG_ID_LOGGING_DATA_MIN_LEN  255
#define MAVLINK_MSG_ID_266_LEN  255
#define MAVLINK_MSG_ID_266_MIN_LEN  255

#define MAVLINK_MSG_ID_LOGGING_DATA_CRC  193
#define MAVLINK_MSG_ID_266_CRC  193

#define MAVLINK_MSG_LOGGING_DATA_FIELD_DATA_LEN 249


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_logging_data_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t target_system, uint8_t target_component, uint16_t sequence, uint8_t length, uint8_t first_message_offset, const uint8_t* data)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_logging_data_pack(
        _msg, sysid, compid,
        target_system, target_component, sequence, length, first_message_offset, data,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_logging_data_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t sequence, uint8_t length, uint8_t first_message_offset, const uint8_t* data)
{
    return fmav_msg_logging_data_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        target_system, target_component, sequence, length, first_message_offset, data,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_logging_data_decode(const mavlink_message_t* msg, mavlink_logging_data_t* payload)
{
    fmav_msg_logging_data_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_LOGGING_DATA_H
