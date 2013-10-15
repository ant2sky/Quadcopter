
// ensure this library description is only included once
#ifndef __CM_PROTOCOL_H__
#define __CM_PROTOCOL_H__

// include types & constants of Wiring core API
#include <Arduino.h>

#include "CmpType.h"

class CmProtocol
{
private:
	int set_payload_int(uint8_t commandIndex, int value, uint8_t * buffer, int bufferSize);
	int get_payload_int(uint8_t * commandBuffer, int payloadSize, int * value);
	
public:
	// Constructor 
	CmProtocol();

	//CMP_SYSTEM_RESET
	int send_system_reset(int value, uint8_t * buffer, int bufferSize);
	int handle_system_reset(int * value, uint8_t * buffer, int bufferSize);
	
	// CMP_SET_SYNCHRONOUS_TIME
	int send_synchronous_time(int syncTime, uint8_t * buffer, int bufferSize);
	int handle_synchronous_time(int * syncTime, uint8_t * buffer, int bufferSize);
	
	// CMP_SYNCHRONOUS_DATA
	int send_synchronous_data(char *syncData, int dataSize, uint8_t * buffer, int bufferSize);
	int handle_synchronous_date(char *syncData, int dataSize, uint8_t * buffer, int bufferSize);
	
	// CMP_AUTOMATIC_CHECKING
	int send_automatic_checking(int index, uint8_t * buffer, int bufferSize);
	int handle_automatic_checking(int * index, uint8_t * buffer, int bufferSize);
	
	// CMP_HARDWARE_CHECKING
	int send_hardware_checking(int moduleIndex, uint8_t * buffer, int bufferSize);
	int handle_hardware_checking(int * moduleIndex, uint8_t * buffer, int bufferSize);
	
	// CMP_FUNCTION_CHECKING
	int send_function_checking(int funIndex, uint8_t * buffer, int bufferSize);
	int handle_function_checking(int * funIndex, uint8_t * buffer, int bufferSize);
	
	// CMP_READ_CALIBRATION
	int send_read_calibration(int calibrationIndex, uint8_t * buffer, int bufferSize);
	int handle_read_calibration(int calibrationIndex, int calibrationValue);
	
	// CMP_WRITE_CALIBRATION
	int send_write_calibration(int calibrationIndex, int calibrationValue, uint8_t * buffer, int bufferSize);
	int handle_write_calibration(int * calibrationIndex, int * calibrationValue, uint8_t * buffer, int bufferSize);
	
	// CMP_HARDWARE_CALIBRATION
	int send_hardware_calibration(int moduleIndex, uint8_t * buffer, int bufferSize);
	int handle_hardware_calibration(int * moduleIndex, uint8_t * buffer, int bufferSize);
	
	// CMP_FUNCTION_CALIBRATION
	int send_function_calibration(int funIndex, uint8_t * buffer, int bufferSize);
	int handle_function_calibration(int * funIndex, uint8_t * buffer, int bufferSize);
	
	// CMP_DIR_FRONT
	int send_dir_front(int value, uint8_t * buffer, int bufferSize);
	int handle_dir_front(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_DIR_BACK
	int send_dir_back(int value, uint8_t * buffer, int bufferSize);
	int handle_dir_back(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_DIR_LEFT
	int send_dir_left(int value, uint8_t * buffer, int bufferSize);
	int handle_dir_left(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_DIR_RIGHT
	int send_dir_right(int value, uint8_t * buffer, int bufferSize);
	int handle_dir_right(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_SPEED
	int send_speed(int value, uint8_t * buffer, int bufferSize);
	int handle_speed(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_TURN_LEFT
	int send_turn_left(int value, uint8_t * buffer, int bufferSize);
	int handle_turn_left(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_TURN_RIGHT
	int send_turn_right(int value, uint8_t * buffer, int bufferSize);
	int handle_turn_right(int * value, uint8_t * buffer, int payloadSize);
	
	// CMP_AUTOCONTROL
	int send_autocontrol(int enable, uint8_t * buffer, int bufferSize);
	int handle_autocontrol(int * enable, uint8_t * buffer, int bufferSize);
	
	// CMP_SET_MODE
	int send_set_mode(int mode, uint8_t * buffer, int bufferSize);
	int handle_set_mode(int * mode, uint8_t * buffer, int bufferSize);
	
	// CMP_PERIODIC_TIME
	int send_periodic_time(int time, uint8_t * buffer, int bufferSize);
	int handle_periodic_time(int * time, uint8_t * buffer, int bufferSize);

	// Get command information
	int get_command_info(uint8_t * commandBuffer, int bufferSize, int * commandIndex, int * payloadSize);
	
};

#endif
