//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_RAW_PRESSURE_H
#define FASTMAVLINK_MSG_RAW_PRESSURE_H


//----------------------------------------
//-- Message RAW_PRESSURE
//----------------------------------------

// fields are ordered, as they appear on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_raw_pressure_t {
    uint64_t time_usec;
    int16_t press_abs;
    int16_t press_diff1;
    int16_t press_diff2;
    int16_t temperature;
}) fmav_raw_pressure_t;


#define FASTMAVLINK_MSG_ID_RAW_PRESSURE  28

#define FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX  16
#define FASTMAVLINK_MSG_RAW_PRESSURE_CRCEXTRA  67

#define FASTMAVLINK_MSG_RAW_PRESSURE_FLAGS  0
#define FASTMAVLINK_MSG_RAW_PRESSURE_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_RAW_PRESSURE_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_RAW_PRESSURE_FRAME_LEN_MAX  41



#define FASTMAVLINK_MSG_RAW_PRESSURE_FIELD_TIME_USEC_OFS  0
#define FASTMAVLINK_MSG_RAW_PRESSURE_FIELD_PRESS_ABS_OFS  8
#define FASTMAVLINK_MSG_RAW_PRESSURE_FIELD_PRESS_DIFF1_OFS  10
#define FASTMAVLINK_MSG_RAW_PRESSURE_FIELD_PRESS_DIFF2_OFS  12
#define FASTMAVLINK_MSG_RAW_PRESSURE_FIELD_TEMPERATURE_OFS  14


//----------------------------------------
//-- Message RAW_PRESSURE pack,encode routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature,
    fmav_status_t* _status)
{
    fmav_raw_pressure_t* _payload = (fmav_raw_pressure_t*)_msg->payload;

    _payload->time_usec = time_usec;
    _payload->press_abs = press_abs;
    _payload->press_diff1 = press_diff1;
    _payload->press_diff2 = press_diff2;
    _payload->temperature = temperature;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_RAW_PRESSURE;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_RAW_PRESSURE_CRCEXTRA;
    _msg->payload_max_len = FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX;

    return fmav_finalize_msg(_msg, _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_raw_pressure_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_raw_pressure_pack(
        _msg, sysid, compid,
        _payload->time_usec, _payload->press_abs, _payload->press_diff1, _payload->press_diff2, _payload->temperature,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature,
    fmav_status_t* _status)
{
    fmav_raw_pressure_t* _payload = (fmav_raw_pressure_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_usec = time_usec;
    _payload->press_abs = press_abs;
    _payload->press_diff1 = press_diff1;
    _payload->press_diff2 = press_diff2;
    _payload->temperature = temperature;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_RAW_PRESSURE;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_RAW_PRESSURE >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_RAW_PRESSURE >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RAW_PRESSURE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_raw_pressure_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_raw_pressure_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->time_usec, _payload->press_abs, _payload->press_diff1, _payload->press_diff2, _payload->temperature,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature,
    fmav_status_t* _status)
{
    fmav_raw_pressure_t _payload;

    _payload.time_usec = time_usec;
    _payload.press_abs = press_abs;
    _payload.press_diff1 = press_diff1;
    _payload.press_diff2 = press_diff2;
    _payload.temperature = temperature;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_RAW_PRESSURE,
        FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RAW_PRESSURE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_raw_pressure_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_raw_pressure_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_RAW_PRESSURE,
        FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RAW_PRESSURE_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message RAW_PRESSURE decode routines, for receiving
//----------------------------------------
// For these functions to work correctly, the msg payload must be zero filled.
// Call the helper fmav_msg_zerofill() if needed, or set FASTMAVLINK_ALWAYS_ZEROFILL to 1
// Note that the parse functions do zerofill the msg payload, but that message generator functions
// do not. This means that for the msg obtained from parsing the below functions can safely be used,
// but that this is not so for the msg obtained from pack/encode functions.

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_raw_pressure_decode(fmav_raw_pressure_t* payload, const fmav_message_t* msg)
{
#if FASTMAVLINK_ALWAYS_ZEROFILL
    if (msg->len < FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        // ensure that returned payload is zero filled
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX - msg->len);
    } else {
		// note: msg->len can be larger than PAYLOAD_LEN_MAX if the message has unknown extensions
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX);
    }
#else
    // this requires that msg payload had been zero filled before
    memcpy(payload, msg->payload, FASTMAVLINK_MSG_RAW_PRESSURE_PAYLOAD_LEN_MAX);
#endif
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_raw_pressure_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint64_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_raw_pressure_get_field_press_abs(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_raw_pressure_get_field_press_diff1(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[10]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_raw_pressure_get_field_press_diff2(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[12]), sizeof(int16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_raw_pressure_get_field_temperature(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[14]), sizeof(int16_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_RAW_PRESSURE  28

#define mavlink_raw_pressure_t  fmav_raw_pressure_t

#define MAVLINK_MSG_ID_RAW_PRESSURE_LEN  16
#define MAVLINK_MSG_ID_RAW_PRESSURE_MIN_LEN  16
#define MAVLINK_MSG_ID_28_LEN  16
#define MAVLINK_MSG_ID_28_MIN_LEN  16

#define MAVLINK_MSG_ID_RAW_PRESSURE_CRC  67
#define MAVLINK_MSG_ID_28_CRC  67




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_raw_pressure_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_raw_pressure_pack(
        _msg, sysid, compid,
        time_usec, press_abs, press_diff1, press_diff2, temperature,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_raw_pressure_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature)
{
    return fmav_msg_raw_pressure_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        time_usec, press_abs, press_diff1, press_diff2, temperature,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_raw_pressure_decode(const mavlink_message_t* msg, mavlink_raw_pressure_t* payload)
{
    fmav_msg_raw_pressure_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_RAW_PRESSURE_H
