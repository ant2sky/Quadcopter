/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Communication Manager
  Description : 
    This module implement how to send/receive data to/from remote side by RF module.
    
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial

*/

void CM_setup()
{
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.println("Initialize communication manager");
#endif

#if CM_MODULE == ENABLE
  CM_PORT.begin(CM_BAUD_RATE);
#endif
}

RET_TYPE CM_send(uint8_t * buffer, int bufferSize)
{
  int loopCount = 0;

#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.print("CM send size:[ ");
  DEBUG_PORT.print(bufferSize);
  DEBUG_PORT.print("] data:[ ");
  for( loopCount = 0; loopCount < bufferSize; loopCount++)
  {
    if(buffer[loopCount] < 16)
      DEBUG_PORT.print("0");
    DEBUG_PORT.print(buffer[loopCount], HEX);
  }
  DEBUG_PORT.println(" ]");
#endif

 #if CM_MODULE == ENABLE
   if(CM_PORT.write(buffer, bufferSize) != bufferSize)
   {
     return RET_ERROR;
   }
 #endif
  return RET_OK;
}

RET_TYPE CM_read()
{
#if CM_MODULE == ENABLE
#endif
  return RET_OK;
}

