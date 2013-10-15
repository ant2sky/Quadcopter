/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Joystick
  Description : 
    This module implement all joystick function.
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial

*/
// Joystick pin map array for JS_CONx_PORT to physical pin
int JS_PinMap[JS_TOTAL_NUMBER] = {JS_CON1_PORT, JS_CON2_PORT, JS_CON3_PORT, JS_CON4_PORT};
// Calibration array to adjust ADC value which read from ADC pin
int JS_CalibrationMap[JS_TOTAL_NUMBER] = { 0, 0, 0, 0};
int JS_RealAdcRange[JS_TOTAL_NUMBER][JS_ADC_RANGE_TOTAL] = 
	{{JS_ADC_MIN, JS_ADC_MAX}, {JS_ADC_MIN, JS_ADC_MAX}, {JS_ADC_MIN, JS_ADC_MAX}, {JS_ADC_MIN, JS_ADC_MAX}};


// Joystick initialization function
void JS_setup()
{
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.println("Initialize joystick");
#endif

}

// Read joystick ADC value and transfer it for we want, the value had calibrated
RET_TYPE JS_read(JS_CON_TYPE num, JS_VALUE_TYPE * value)
{
	int adcValue = 0;

	adcValue = analogRead(JS_PinMap[num]);
	
	* value = map(adcValue, 
  			JS_RealAdcRange[num][JS_ADC_RANGE_MIN_INDEX], JS_RealAdcRange[num][JS_ADC_RANGE_MAX_INDEX],
  			JS_ADC_MIN, JS_ADC_MAX) + JS_CalibrationMap[num];

  	return RET_OK;
}

// Read real joystick ADC value
RET_TYPE JS_read_real(JS_CON_TYPE num, JS_VALUE_TYPE * value)
{
	* value = analogRead(JS_PinMap[num]);
	
  	return RET_OK;
}

// Set real ADC to range table
RET_TYPE JS_set_real_adc_range(JS_CON_TYPE num, int index, int value)
{
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.print("Set Real ADC [");
  DEBUG_PORT.print(num);
  DEBUG_PORT.print("] [");
  DEBUG_PORT.print(index);
  DEBUG_PORT.print("] [");
  DEBUG_PORT.print(value, HEX);
  DEBUG_PORT.println("]");
#endif

	JS_RealAdcRange[num][index] = value;

	return RET_OK;
}


