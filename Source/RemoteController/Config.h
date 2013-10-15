/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Config.h
  Description : 
    This file defines all remote controller configuration. All pins defines, function or componment should be defined
    in this file and all module should include this file.
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial

*/
#include "Def.h"

//====================================
// Debug configuration
//------------------------------------
#define DEBUG_LOG    ENABLE
//#define DEBUG_LOG    DISABLE

// UART Baud Rate
//#define DEBUG_BAUD_RATE  9600
#define DEBUG_BAUD_RATE  115200

// UART port for Debug
#define DEBUG_PORT    Serial
//#define DEBUG_PORT    Serial1
//#define DEBUG_PORT    Serial2
//#define DEBUG_PORT    Serial3

//====================================

//====================================
// Communication configuration
//------------------------------------
//#define CM_MODULE  ENABLE
#define CM_MODULE  DISABLE

//#define CM_BAUD_RATE  9600
#define CM_BAUD_RATE  115200

//#define CM_PORT Serial
#define CM_PORT Serial1
//#define CM_PORT Serial2
//#define CM_PORT Serial3

//====================================

//====================================
// Joystick configuration
//------------------------------------
#define JS_CON_TYPE        int
#define JS_CON1            0
#define JS_CON2            1
#define JS_CON3            2
#define JS_CON4            3
#define JS_TOTAL_NUMBER    4

// Joystick ADC Range defination
#define JS_ADC_RANGE_MIN_INDEX	0
#define JS_ADC_RANGE_MAX_INDEX	1
#define JS_ADC_RANGE_TOTAL		2

// Joystick ADC sensitivity
#define JS_ADC_SENSITIVITY  2

// JS_CON1 is for speed control
#define  JS_CON1_PORT      A0
#define  JS_SPEED          JS_CON1_PORT
// JS_CON2 is for turn around control
#define  JS_CON2_PORT      A1
#define  JS_TURN           JS_CON2_PORT
// JS_CON3 is for front or back control
#define  JS_CON3_PORT      A2
#define  JS_STRAIGHT       JS_CON3_PORT
// JS_CON4 is for right or left control
#define  JS_CON4_PORT      A3
#define  JS_TRANSECTION    JS_CON4_PORT

// The control range for joystick's ADC value for speed
// From 0xF8 ~ 0x30, the total step are 200
#define JS_SPEED_ADC_MIN	0x30
#define JS_SPEED_ADC_MAX	0xF8

// The normal ADC value for joystick
#define JS_ADC_MIN          0
#define JS_ADC_MAX          0x150
#define JS_ADC_MIDDLE       ((JS_ADC_MIN + JS_ADC_MAX) / 2)
#define JS_ADC_MIDDLE_RANGE	3 // (-JS_ADC_MIDDLE_RANGE ~ JS_ADC_MIDDLE_RANGE)

//====================================

//====================================
// Display Manager configuration
//------------------------------------
#define DM_MODULE  ENABLE
//#define DM_MODULE  DISABLE

#define DM_LEVEL_LED	ENABLE
//#define DM_LEVEL_LED	DISABLE

#define DM_DISPLAY_INDEX_TYPE int

enum
{
	// Calibration 
	DM_DISPLAY_CALIBRATION_SPEED_MIN = (int) 0,
	DM_DISPLAY_CALIBRATION_SPEED_MAX,
	DM_DISPLAY_CALIBRATION_TURN_LEFT,
	DM_DISPLAY_CALIBRATION_TURN_RIGHT,
	DM_DISPLAY_CALIBRATION_STRAIGHT_BACK,
	DM_DISPLAY_CALIBRATION_STRAIGHT_FRONT,
	DM_DISPLAY_CALIBRATION_TRANSECTION_LEFT,
	DM_DISPLAY_CALIBRATION_TRANSECTION_RIGHT,

	// Remote controller mode
	DM_DISPLAY_BOOTING_MODE,
	DM_DISPLAY_CALIBRATING_MODE,
	DM_DISPLAY_NORMAL_MODE,
	DM_DISPLAY_WRONGING_MODE,

	// Helicopter Status
	DM_DISPLAY_TARGET_SPEED,
	DM_DISPLAY_TARGET_TURN,
	DM_DISPLAY_TARGET_STRAIGHT,
	DM_DISPLAY_TARGET_TRANSECTION,

	// RF status
	DM_DISPLAY_RF_OFF,
	DM_DISPLAY_RF_ON,
	DM_DISPLAY_RF_ASSOCIATED,
	DM_DISPLAY_RF_RSSI,

	DM_DISPLAY_TOTAL
	
};


//====================================

//====================================
// Led pin configuration
//------------------------------------
#define LED_DATA_PIN	2
#define LED_LATCH_PIN	3
#define LED_CLOCK_PIN	4

//====================================

//====================================
// Button configuration
//------------------------------------
enum
{
	BN_FUNCTION	= (int) 0,
	BN_OK,

	TOTAL_BN
};

#define BN_TYPE int

#define BN_OK_PIN			7
#define BN_FUNCTION_PIN		8

#define BN_PUSH_STATUS		LOW
#define BN_RELEASE_STATUS	HIGH

#define BN_STATUS_TYPE        int
#define BN_RELEASE			0
#define BN_PUSH				1

//====================================

