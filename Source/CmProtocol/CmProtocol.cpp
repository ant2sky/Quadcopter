// include core Wiring API
#include <Arduino.h>

// include this library's description file
#include "CmProtocol.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

int CmProtocol::set_payload_int(uint8_t commandIndex, int value, uint8_t * buffer, int bufferSize)
{
  // [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  if(bufferSize > (CMP_START_BYTE + CMP_COMMAND_BYTE + CMP_LENGTH_BYTE + CMP_INT_LENGTH))
  {
    int commandSize = 0;
    
    buffer[commandSize++] = CMP_START_TAG1;
    buffer[commandSize++] = CMP_START_TAG2;
    buffer[commandSize++] = commandIndex;
    buffer[commandSize++] = CMP_INT_LENGTH;
    buffer[commandSize++] = (value & 0xFF00) >> 8;
    buffer[commandSize++] = (value & 0x00FF);

    return commandSize;

  }
  else
  {
    return CMP_RET_BUFFER_ERROR;
  }
}

int CmProtocol::get_payload_int(uint8_t * commandBuffer, int payloadSize, int * value)
{
  int payloadOffset = CMP_START_BYTE + CMP_COMMAND_BYTE + CMP_LENGTH_BYTE;
  
  // [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  if(CMP_INT_LENGTH != payloadSize)
  {
    return CMP_RET_VALUE_ERROR;
  }

  * value = ((commandBuffer[payloadOffset] & 0x00FF) << 8) | (commandBuffer[payloadOffset + 1] & 0x00FF);
  
  return CMP_RET_OK;
}

CmProtocol::CmProtocol()
{
}

//CMP_SYSTEM_RESET
int CmProtocol::send_system_reset(int value, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_system_reset(int * value, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_SET_SYNCHRONOUS_TIME
int CmProtocol::send_synchronous_time(int syncTime, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_synchronous_time(int * syncTime, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_SYNCHRONOUS_DATA
int CmProtocol::send_synchronous_data(char *syncData, int dataSize, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_synchronous_date(char *syncData, int dataSize, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_AUTOMATIC_CHECKING
int CmProtocol::send_automatic_checking(int index, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_automatic_checking(int * index, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_HARDWARE_CHECKING
int CmProtocol::send_hardware_checking(int moduleIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_hardware_checking(int * moduleIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_FUNCTION_CHECKING
int CmProtocol::send_function_checking(int funIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_function_checking(int * funIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_READ_CALIBRATION
int CmProtocol::send_read_calibration(int calibrationIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_read_calibration(int calibrationIndex, int calibrationValue)
{
	return CMP_RET_OK;
}


// CMP_WRITE_CALIBRATION
int CmProtocol::send_write_calibration(int calibrationIndex, int calibrationValue, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_write_calibration(int * calibrationIndex, int * calibrationValue, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_HARDWARE_CALIBRATION
int CmProtocol::send_hardware_calibration(int moduleIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_hardware_calibration(int * moduleIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_FUNCTION_CALIBRATION
int CmProtocol::send_function_calibration(int funIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_function_calibration(int * funIndex, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_DIR_FRONT
int CmProtocol::send_dir_front(int value, uint8_t * buffer, int bufferSize)
{
  // front direction command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_DIR_FRONT, value, buffer, bufferSize);
}

int CmProtocol::handle_dir_front(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_DIR_BACK
int CmProtocol::send_dir_back(int value, uint8_t * buffer, int bufferSize)
{
  // back direction command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_DIR_BACK, value, buffer, bufferSize);
}

int CmProtocol::handle_dir_back(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_DIR_LEFT
int CmProtocol::send_dir_left(int value, uint8_t * buffer, int bufferSize)
{
  // turn left command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_DIR_LEFT, value, buffer, bufferSize);
}

int CmProtocol::handle_dir_left(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_DIR_RIGHT
int CmProtocol::send_dir_right(int value, uint8_t * buffer, int bufferSize)
{
  // turn right command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_DIR_RIGHT, value, buffer, bufferSize);
}

int CmProtocol::handle_dir_right(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_SPEED
int CmProtocol::send_speed(int value, uint8_t * buffer, int bufferSize)
{
  // Speed command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_SPEED, value, buffer, bufferSize);
}

int CmProtocol::handle_speed(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_TURN_LEFT
int CmProtocol::send_turn_left(int value, uint8_t * buffer, int bufferSize)
{
  // turn left command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_TURN_LEFT, value, buffer, bufferSize);
}

int CmProtocol::handle_turn_left(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_TURN_RIGHT
int CmProtocol::send_turn_right(int value, uint8_t * buffer, int bufferSize)
{
  // turn right command : [TAG1|TAG2|CMD|LEN|VAL(2)] => 6 byte
  return set_payload_int(CMP_TURN_RIGHT, value, buffer, bufferSize);
}

int CmProtocol::handle_turn_right(int * value, uint8_t * buffer, int payloadSize)
{
  // Command format : [TAG1|TAG2|CMD|LEN|VAL(2)]
  return get_payload_int(buffer, payloadSize, value);
}


// CMP_AUTOCONTROL
int CmProtocol::send_autocontrol(int enable, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_autocontrol(int * enable, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_SET_MODE
int CmProtocol::send_set_mode(int mode, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_set_mode(int * mode, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}


// CMP_PERIODIC_TIME
int CmProtocol::send_periodic_time(int time, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

int CmProtocol::handle_periodic_time(int * time, uint8_t * buffer, int bufferSize)
{
	return CMP_RET_OK;
}

// Get command index and payload size from command buffer which receive from 
int CmProtocol::get_command_info(uint8_t * commandBuffer, int bufferSize, int * commandIndex, int * payloadSize)
{
	// Check if the buffer size is enought
	if((CMP_START_BYTE + CMP_COMMAND_BYTE + CMP_LENGTH_BYTE) >= bufferSize)
	{
		return CMP_RET_BUFFER_ERROR;
	}
	
	// Check if the command buffer is legal
	if((CMP_START_TAG1 != commandBuffer[0]) || (CMP_START_TAG2 != commandBuffer[1]))
	{
		return CMP_RET_TAG_ERROR;
	}

	// Get command index from command buffer
	* commandIndex = commandBuffer[0 + CMP_START_BYTE] & 0x00FF;

	// Get payload size from command buffer
	* payloadSize = commandBuffer[0 + CMP_START_BYTE + CMP_COMMAND_BYTE] & 0x00FF;

	return CMP_RET_OK;
}
