/*
  Project : 
    Arduino Helicopter - Helicopter
  Module :
    Sensor Manager
  Description : 
    Implement logic sensor controlling.
    
Version 0.1 :
  2013/05/21 -[Alen Chen] - Initial

*/

void SM_Setup()
{
	// join i2c bus (address optional for master)
	Wire.begin(); 

	// Initial Gyroscope
	SETUP_GYRO();

	// Initial Accelerometer
	SETUP_ACCEL();

}


