/*
  Project : 
    Arduino Helicopter - Helicopter
  Module :
    Config.h
  Description : 
    This file defines all helicopter's configuration. All pins defines, function or componment should be defined
    in this file and all module should include this file.
    
Version 0.1 :
  2013/05/21 -[Alen Chen] - Initial

*/

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

#define CM_PORT Serial
//#define CM_PORT Serial1
//#define CM_PORT Serial2
//#define CM_PORT Serial3

//====================================

//====================================
// Sensor Manager configuration
//------------------------------------

//====================================

//====================================

//====================================
// Gyroscope configuration
//------------------------------------
#define SETUP_GYRO  L3G4200Setup
#define READ_GYRO  getL3G4200Values

//====================================

//====================================
// Accelerometer configuration
//------------------------------------
#define SETUP_ACCEL  LIS3LV02DQSetup
#define READ_ACCEL  getLIS3LV02DQValues

//====================================


#define DELAY_TIME  100


