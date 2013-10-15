/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Display Manager
  Description : 
    This is display manager. It control how to display information in remote controller, ex. Level LED or Screen.
    
    
Version 0.1 :
  2013/03/13 -[Alen Chen] - Initial
  2013/09/27 -[Alen Chen] - Add calibration mode, status mode, monitor mode and RF mode

*/

void DM_setup()
{

#if DM_MODULE == ENABLE

#if DM_LEVEL_LED == ENABLE
	LED_setup();
#endif

#endif
}

void DM_set(DM_DISPLAY_INDEX_TYPE index, int value)
{
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.print("Set Display Index [");
  DEBUG_PORT.print(index);
  DEBUG_PORT.println("]");
#endif

#if DM_MODULE == ENABLE

	if((index > DM_DISPLAY_TOTAL) && (index < 0))
		return;

	switch(index)
	{
	// Calibration 
	case DM_DISPLAY_CALIBRATION_SPEED_MIN:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_speed_min(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_SPEED_MAX:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_speed_max(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_TURN_LEFT:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_turn_left(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_TURN_RIGHT:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_turn_right(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_STRAIGHT_BACK:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_straight_back(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_STRAIGHT_FRONT:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_straight_front(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_TRANSECTION_LEFT:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_transection_left(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATION_TRANSECTION_RIGHT:
#if DM_LEVEL_LED == ENABLE
		LED_calibration_transection_right(value);
#endif
		break;
		
	// Remote controller mode
	case DM_DISPLAY_BOOTING_MODE:
#if DM_LEVEL_LED == ENABLE
		LED_booting_mode(value);
#endif
		break;
	case DM_DISPLAY_CALIBRATING_MODE:
#if DM_LEVEL_LED == ENABLE
		LED_calibrating_mode(value);
#endif
		break;
	case DM_DISPLAY_NORMAL_MODE:
#if DM_LEVEL_LED == ENABLE
		LED_normal_mode(value);
#endif
		break;
	case DM_DISPLAY_WRONGING_MODE:
#if DM_LEVEL_LED == ENABLE
		LED_wronging_mode(value);
#endif
		break;

	// Helicopter Status
	case DM_DISPLAY_TARGET_SPEED:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_TARGET_TURN:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_TARGET_STRAIGHT:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_TARGET_TRANSECTION:
#if DM_LEVEL_LED == ENABLE
#endif
		break;

	// RF status
	case DM_DISPLAY_RF_OFF:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_RF_ON:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_RF_ASSOCIATED:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	case DM_DISPLAY_RF_RSSI:
#if DM_LEVEL_LED == ENABLE
#endif
		break;
	}
	
#endif
}
