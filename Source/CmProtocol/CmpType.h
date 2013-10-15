// ensure this library description is only included once
#ifndef __CMP_TYPE_H__
#define __CMP_TYPE_H__

// Communication command define : 
// start[2 (0xAAAA)] + command[1] + Length[1] + Value[x]
// The Max command length is 255
#define CMP_START_BYTE					2
#define CMP_COMMAND_BYTE				1
#define CMP_LENGTH_BYTE					1
#define CMP_MAX_COMMAND_LENGTH 			16

// Result index
// Error result need be negative
#define CMP_RET_OK						0
#define CMP_RET_ERROR					-1
#define CMP_RET_COMMAND_ERROR			-2
#define CMP_RET_VALUE_ERROR				-3
#define CMP_RET_BUFFER_ERROR			-4
#define CMP_RET_TAG_ERROR				-5
#define CMP_RET_COMMAND_NOT_SUPPORT		-6

// 
#define CMP_NULL_CMD                    -1

// communication protocol tag
#define CMP_START_TAG1					0xAA
#define CMP_START_TAG2					0xAA

#define CMP_BYTE_LENGTH					1
#define CMP_INT_LENGTH					2
#define CMP_LONG_LENGTH					4

// System Command (0x00 ~ 0x0F)
#define CMP_SYSTEM_RESET				0x00
#define CMP_SET_SYNCHRONOUS_TIME		0x01
#define CMP_SYNCHRONOUS_DATA			0x02

// Checking Command (0x10 ~ 0x1F)
#define CMP_AUTOMATIC_CHECKING			0x10
#define CMP_HARDWARE_CHECKING			0x11
#define CMP_FUNCTION_CHECKING			0x12

// Calibration Command (0x20 ~ 0x2F)
#define CMP_READ_CALIBRATION			0x20
#define CMP_WRITE_CALIBRATION			0x21
#define CMP_HARDWARE_CALIBRATION		0x22
#define CMP_FUNCTION_CALIBRATION		0x23

// Control (0x40 ~ 0x8F)
#define CMP_DIR_FRONT					0x40
#define CMP_DIR_BACK					0x41
#define CMP_DIR_LEFT					0x42
#define CMP_DIR_RIGHT					0x43

#define CMP_SPEED						0x50

#define CMP_TURN_LEFT					0x60
#define CMP_TURN_RIGHT					0x61

#define CMP_AUTOCONTROL					0x70

#define CMP_SET_MODE					0x80
#define CMP_PERIODIC_TIME				0x81

#endif