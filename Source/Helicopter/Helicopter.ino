/*
  Project : 
    Arduino Helicopter - Helicopter
  Module :
    Helicopter
  Description : 
    The entry module of helicopter side
    
Version 0.1 :
  2013/05/21 -[Alen Chen] - Initial
  2013/06/05 -[Alen Chen] - Add cyro and accel setup and status read function

*/

#include "Config.h"
#include <Wire.h>

void setup()
{
#if DEBUG_LOG == ENABLE
	// Initialize debug serial and set the baud rate
	DEBUG_PORT.begin(DEBUG_BAUD_RATE);
	// Wait for debug serial port to connet
	while(!DEBUG_PORT) {;} 
	DEBUG_PORT.println("Hardware initialization");
#endif

	// Initial Sensor Manager
	SM_Setup();
	
	delay(100);
}

void loop()
{
	int gyroX = 0, gyroY = 0, gyroZ = 0;
	int accelX = 0, accelY = 0, accelZ = 0;

	READ_GYRO(&gyroX, &gyroY, &gyroZ);
	delay(DELAY_TIME);
	READ_ACCEL(&accelX, &accelY, &accelZ);
	delay(DELAY_TIME);

#if 1
	Serial.print("GYRO[ ");
	Serial.print(gyroX/114);
	Serial.print(", ");
	Serial.print(gyroY/114);
	Serial.print(", ");
	Serial.print(gyroZ/114);
	Serial.print("] ");

	Serial.print("ACCEL[ ");
	Serial.print(accelX);
	Serial.print(", ");
	Serial.print(accelY);
	Serial.print(", ");
	Serial.print(accelZ);
	Serial.println("]");
#endif
}


