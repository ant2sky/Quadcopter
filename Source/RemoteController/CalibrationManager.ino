/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Calibration Manager
  Description : 
    This module is for remote controller calibration function. This include two sides calibration. 
    One is retome controller calibration. It calibrates joysticks function.
    The other is helicopter side calibration. It calibrates moto, gyroscope, accelerometer.
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial
  2013/09/27 -[Alen Chen] - Add Joystick calibration

*/

RET_TYPE CalM_startCalibration()
{
	// Joystick calibration
	CalM_calibrateJoystick();
}

RET_TYPE CalM_calibrateJoystick()
{
	JS_VALUE_TYPE js_value = 0;
	int calibrationIndex = 0;
	
	for(int js_index = 0; js_index < JS_TOTAL_NUMBER; js_index++)
	{
		for(int range_index = 0; range_index < JS_ADC_RANGE_TOTAL; range_index++)
		{
			// Display calibration mode
			DM_set(calibrationIndex, 0);
			
			while(1)
			{

				delay(100);
				//if(BN_PUSH == BN_get_status(BN_FUNCTION))
				//	break;
				if(BN_PUSH == BN_get_status(BN_OK))
				{
					// TODO: Need to check if the calibration value is correct.
					
					JS_read_real(js_index, &js_value);
					JS_set_real_adc_range(js_index, range_index, js_value);
					
					break;
				}
			}
			calibrationIndex++;
		}
	}

}
