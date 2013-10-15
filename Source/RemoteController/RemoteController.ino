/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Remote Controller Manager
  Description : 
    This is main module in remote controller. This module control all functions in remote controller and
    base on config file to use relational module.
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial
  2013/09/27 -[Alen Chen] - Add Joystick calibration function and display manager's initial function
  2013/09/30 -[Alen Chen] - Add Middle range for Joystick (turn, straight, transection)

*/
#include "Config.h"
#include <CmProtocol.h>

CmProtocol myProtocol;

// keep last joystick value to determine if remote controller need to send control command to target.
// The initial value is -1. This value is for note that the remote controller is geting the value first time.
int RC_lastJsValue[JS_TOTAL_NUMBER] = { -1, -1, -1, -1};

// initial function
void setup()
{
   	// setup Display module
	DM_setup();
	
	// Do not print any debug information befor this.
	// setup debug module
#if DEBUG_LOG == ENABLE
	// Initialize debug serial and set the baud rate
	DEBUG_PORT.begin(DEBUG_BAUD_RATE);
	// Wait for debug serial port to connet
	while(!DEBUG_PORT) {;} 
	DEBUG_PORT.println("Hardware initialization");
#endif

	// setup communication module
	CM_setup();
   
	// setup Joystick module
	JS_setup();

	BN_setup();
	
	DM_set(DM_DISPLAY_CALIBRATING_MODE, 0);
	
	// Start Calibration
	CalM_startCalibration();

	DM_set(DM_DISPLAY_NORMAL_MODE, 0);
}


// main loop
void loop()
{
  // check if it need to do calibration
  
  // get joystick current value and send it to target
  handleJoystick();

  // check button status and send new setting to target

  // refresh display status 
  
  delay(100);
}

//======================================
// This function is Joystick handler.
// - check every joystick's controller
// - keep joystick value
// - send new value to target
//======================================
void handleJoystick()
{
  // Declare some variable for joystick
  JS_CON_TYPE js_num = 0;
  JS_VALUE_TYPE js_value = 0;
  
  // Read joystick value
  for(js_num = JS_CON1; js_num < JS_TOTAL_NUMBER; js_num++)
  {
    // send the joystick value if the function call is successful
    if( RET_OK == JS_read(js_num, &js_value))
    //if( RET_OK == JS_read_real(js_num, &js_value))
    {
      //if(RC_lastJsValue[js_num] != js_value)
      if((RC_lastJsValue[js_num] > (js_value + JS_ADC_SENSITIVITY)) || (RC_lastJsValue[js_num] < (js_value - JS_ADC_SENSITIVITY)))
      {
      	int commandIndex = CMP_NULL_CMD;
      	int sendingValue = 0;
      	int commandSize = 0;
      	uint8_t commandBuffer[CMP_MAX_COMMAND_LENGTH];

#if DEBUG_LOG == ENABLE
        // Print the debug information
        DEBUG_PORT.print("JS [ ");DEBUG_PORT.print(js_num, HEX);DEBUG_PORT.print(" ] ==> [ ");DEBUG_PORT.print(js_value, HEX);DEBUG_PORT.println(" ]");
#endif

      	switch(js_num)
      	{
      	case JS_CON1: // JS_SPEED
      	  // set speed command
          commandIndex = CMP_SPEED;
          // translate normal ADC to speed value
          sendingValue = map(js_value, JS_ADC_MIN, JS_ADC_MAX, JS_SPEED_ADC_MIN, JS_SPEED_ADC_MAX);
   	      // Transfer data to communication protocol
          commandSize = myProtocol.send_speed(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  break;
      	case JS_CON2: // JS_TURN:
      	  // Check which command need to send
      	  if(((JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE) <= js_value) &&
      	  	((JS_ADC_MIDDLE + JS_ADC_MIDDLE_RANGE) >= js_value))
      	  {
      	    // set turn left command
      	    commandIndex = CMP_TURN_LEFT;
      	    // calculate turn left value
      	    sendingValue = 0;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_turn_left(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else if(JS_ADC_MIDDLE >= js_value)
      	  {
      	    // set turn left command
      	    commandIndex = CMP_TURN_LEFT;
      	    // calculate turn left value
      	    sendingValue = JS_ADC_MIDDLE - js_value - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_turn_left(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else
      	  {
      	    // set turn right command
      	    commandIndex = CMP_TURN_RIGHT;
      	    // calculate turn right value
      	    sendingValue = js_value - JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_turn_right(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  break;
      	case JS_CON3: // JS_STRAIGHT:
      	  // Check which command need to send
      	  if(((JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE) <= js_value) &&
      	  	((JS_ADC_MIDDLE + JS_ADC_MIDDLE_RANGE) >= js_value))
      	  {
      	    // set turn left command
      	    commandIndex = CMP_DIR_BACK;
      	    // calculate turn left value
      	    sendingValue = 0;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_turn_left(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else if(JS_ADC_MIDDLE >= js_value)
      	  {
      	    // set backing command
      	    commandIndex = CMP_DIR_BACK;
      	    // calculate backing value
      	    sendingValue = JS_ADC_MIDDLE - js_value - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_dir_back(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else
      	  {
      	    // set fronting command
      	    commandIndex = CMP_DIR_FRONT;
      	    // calculate fronting value
      	    sendingValue = js_value - JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_dir_front(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  break;
      	case JS_CON4: // JS_TRANSECTION:
      	  // Check which command need to send
      	  if(((JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE) <= js_value) &&
      	  	((JS_ADC_MIDDLE + JS_ADC_MIDDLE_RANGE) >= js_value))
      	  {
      	    // set turn left command
      	    commandIndex = CMP_DIR_LEFT;
      	    // calculate turn left value
      	    sendingValue = 0;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_turn_left(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else if(JS_ADC_MIDDLE >= js_value)
      	  {
      	    // set left direction command
      	    commandIndex = CMP_DIR_LEFT;
      	    // calculate left direction value
      	    sendingValue = JS_ADC_MIDDLE - js_value - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_dir_left(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  else
      	  {
      	    // set right direction command
      	    commandIndex = CMP_DIR_RIGHT;
      	    // calculate right direction value
      	    sendingValue = js_value - JS_ADC_MIDDLE - JS_ADC_MIDDLE_RANGE;
     	    // Transfer data to communication protocol
            commandSize = myProtocol.send_dir_right(sendingValue, commandBuffer, CMP_MAX_COMMAND_LENGTH);
      	  }
      	  break;
      	}

      	if(commandSize != 0)
      	{
          // Send JS information to target by RF
          if(RET_OK == CM_send(commandBuffer, commandSize))
          {
    
            // Keep current value
            RC_lastJsValue[js_num] = js_value;
          }
	    }
	    
      }

    }
  }
}

int handleReceivingCommandData(int commandIndex, int payloadSize, uint8_t * commandBuffer)
{
  int ret = CMP_RET_OK;
  int value = 0;
  
  // paseing command and payload
  switch(commandIndex)
  {
  case CMP_DIR_FRONT:
    ret = myProtocol.handle_dir_front(&value, commandBuffer, payloadSize);
  break;
  case CMP_DIR_BACK:
    ret = myProtocol.handle_dir_back(&value, commandBuffer, payloadSize);
  break;
  case CMP_DIR_LEFT:
    ret = myProtocol.handle_dir_left(&value, commandBuffer, payloadSize);
  break;
  case CMP_DIR_RIGHT:
    ret = myProtocol.handle_dir_right(&value, commandBuffer, payloadSize);
  break;
  case CMP_SPEED:
    ret = myProtocol.handle_speed(&value, commandBuffer, payloadSize);
  break;
  case CMP_TURN_LEFT:
    ret = myProtocol.handle_turn_left(&value, commandBuffer, payloadSize);
  break;
  case CMP_TURN_RIGHT:
    ret = myProtocol.handle_turn_right(&value, commandBuffer, payloadSize);
  break;
  default:
    return CMP_RET_COMMAND_NOT_SUPPORT;
  }

  if(CMP_RET_OK != ret)
  {
    // Get error data and skip it.
    return ret;
  }
  
#if DEBUG_LOG == ENABLE
    // Print the debug information
    DEBUG_PORT.print("Receive command. index[ ");DEBUG_PORT.print(commandIndex);DEBUG_PORT.println(" ]");
    DEBUG_PORT.print("value[ ");DEBUG_PORT.print(value);DEBUG_PORT.println(" ]");
#endif

  // push command and data to hanling queue

  return CMP_RET_OK;
}

void receiveCommandData(uint8_t * commandBuffer, int bufferSize)
{
  int commandIndex = CMP_NULL_CMD;
  int payloadSize = 0;
  int retValue = CMP_RET_OK;
  
  // Get command information from command buffer
  retValue = myProtocol.get_command_info(commandBuffer, bufferSize, &commandIndex, &payloadSize);
  if(CMP_RET_OK != retValue)
  {
#if DEBUG_LOG == ENABLE
    // Print the debug information
    DEBUG_PORT.print("Receive data failed!!! ret[ ");DEBUG_PORT.print(retValue);DEBUG_PORT.println(" ]");
#endif
    // Get error data and skip it.
    return;
  }

  // parsing command and payload, and enqueue
  retValue = handleReceivingCommandData(commandIndex, payloadSize, commandBuffer);
  if(CMP_RET_OK != retValue)
  {
#if DEBUG_LOG == ENABLE
    // Print the debug information
    DEBUG_PORT.print("Handle receiving data failed!!! ret[ ");DEBUG_PORT.print(retValue);DEBUG_PORT.println(" ]");
#endif
    // Get error data and skip it.
    return;
  }
}

