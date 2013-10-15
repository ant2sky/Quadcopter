/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Calibration Manager
  Description : 
    This module implement how to display information by led.
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial
  2013/09/27 -[Alen Chen] - Add calibration mode function

*/

#define LED_MAX_NUM 24
#define LED_SHIFT_WIDTH	3		// 2^x
#define LED_SET_ONE_BIT(data,index) (data |= ((uint32_t)1 << index))

//  0       7 8       15        23        31
// |---- ----|---- ----|---- ----|---- ----|

// Calibration Indication Bit[0-7]
#define LED_CALIBRATION_MASK				0x000000FF
#define LED_CLEAR_CALIBRATION(x)			(x &= ~LED_CALIBRATION_MASK);
#define LED_CALIBRATION_SPEED_MIN			0
#define LED_CALIBRATION_SPEED_MAX			1
#define LED_CALIBRATION_TURN_LEFT 			2
#define LED_CALIBRATION_TURN_RIGHT			3
#define LED_CALIBRATION_STRAIGHT_BACK		4
#define LED_CALIBRATION_STRAIGHT_FRONT		5
#define LED_CALIBRATION_TRANSECTION_LEFT	6
#define LED_CALIBRATION_TRANSECTION_RIGHT	7

// Controller Mode Bit[8-11]
	// Remote controller mode
#define LED_CONTROLLER_MODE_MASK			0x00F00000
#define LED_CLEAR_CONTROLLER_MODE(x)			(x &= ~LED_CONTROLLER_MODE_MASK);
#define LED_BOOTING_MODE		20
#define LED_CALIBRATING_MODE	21
#define LED_NORMAL_MODE			22
#define LED_WRONGING_MODE		23



// Helicopter Status Bit[0-7]
	// Helicopter Status
#define LED_TARGET_MODE_MASK		0x000000FF
#define LED_CLEAR_TARGET_MODE(x)			(x &= ~LED_TARGET_MODE_MASK);
#define LED_TARGET_SPEED_MIN		0
#define LED_TARGET_SPEED_MAX		1
#define LED_TARGET_TURN_MIN			2
#define LED_TARGET_TURN_MAX			3
#define LED_TARGET_STRAIGHT_MIN		4
#define LED_TARGET_STRAIGHT_MAX		5
#define LED_TARGET_TRANSECTION_MIN	6
#define LED_TARGET_TRANSECTION_MAX	7


// RF Status Bit[12-15]
	// RF status
#define LED_RF_MODE_MASK		0x0000FF00
#define LED_CLEAR_RF_MODE(x)			(x &= ~LED_RF_MODE_MASK);
#define LED_RF_OFF				12
#define LED_RF_ON				13
#define LED_RF_ASSOCIATED		14
#define LED_RF_RSSI				15

uint32_t ledStatus = 0; // the max led number is 32.

void LED_send_data(uint32_t data)
{
	
	digitalWrite(LED_LATCH_PIN, LOW);
	for(int index = 0; index < (LED_MAX_NUM >> LED_SHIFT_WIDTH); index++)
	{
		shiftOut(LED_DATA_PIN, LED_CLOCK_PIN, MSBFIRST, (data >> (((LED_MAX_NUM >> LED_SHIFT_WIDTH) - index - 1) << LED_SHIFT_WIDTH)));
	}
	digitalWrite(LED_LATCH_PIN, HIGH);
}

void LED_setup()
{
	pinMode(LED_DATA_PIN, OUTPUT);
	pinMode(LED_LATCH_PIN, OUTPUT);
	pinMode(LED_CLOCK_PIN, OUTPUT);

	ledStatus = 0xFFFFFFFF;
	
	LED_send_data(ledStatus);

	delay(100);
	
	ledStatus = 0;

	LED_send_data(ledStatus);
	
}

void LED_calibration_speed_min(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_SPEED_MIN);
	LED_send_data(ledStatus);
}

void LED_calibration_speed_max(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_SPEED_MAX);
	LED_send_data(ledStatus);
}

void LED_calibration_turn_left(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_TURN_LEFT);
	LED_send_data(ledStatus);
}

void LED_calibration_turn_right(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_TURN_RIGHT);
	LED_send_data(ledStatus);
}

void LED_calibration_straight_back(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_STRAIGHT_BACK);
	LED_send_data(ledStatus);
}

void LED_calibration_straight_front(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_STRAIGHT_FRONT);
	LED_send_data(ledStatus);
}

void LED_calibration_transection_left(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_TRANSECTION_LEFT);
	LED_send_data(ledStatus);
}

void LED_calibration_transection_right(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATION_TRANSECTION_RIGHT);
	LED_send_data(ledStatus);
}

void LED_booting_mode(int data)
{
	LED_CLEAR_CONTROLLER_MODE(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_BOOTING_MODE);
	LED_send_data(ledStatus);
}

void LED_calibrating_mode(int data)
{
	LED_CLEAR_CONTROLLER_MODE(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_CALIBRATING_MODE);
	LED_send_data(ledStatus);
}

void LED_normal_mode(int data)
{
	LED_CLEAR_CALIBRATION(ledStatus);

	LED_CLEAR_CONTROLLER_MODE(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_NORMAL_MODE);
	LED_send_data(ledStatus);
}

void LED_wronging_mode(int data)
{
	LED_CLEAR_CONTROLLER_MODE(ledStatus);
	LED_SET_ONE_BIT(ledStatus, LED_WRONGING_MODE);
	LED_send_data(ledStatus);
}

void LED_target_speed(int data)
{
	LED_CLEAR_TARGET_MODE(ledStatus);
}

void LED_target_turn(int data)
{
	LED_CLEAR_TARGET_MODE(ledStatus);
}

void LED_target_straight(int data)
{
	LED_CLEAR_TARGET_MODE(ledStatus);
}

void LED_target_transection(int data)
{
	LED_CLEAR_TARGET_MODE(ledStatus);
}

void LED_rf_off(int data)
{
	LED_CLEAR_RF_MODE(ledStatus);
}

void LED_rf_on(int data)
{
	LED_CLEAR_RF_MODE(ledStatus);
}

void LED_rf_associated(int data)
{
	LED_CLEAR_RF_MODE(ledStatus);
}

void LED_rf_rssi(int data)
{
	LED_CLEAR_RF_MODE(ledStatus);
}


