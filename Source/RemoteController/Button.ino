/*
  Project : 
    Arduino Helicopter - Remote Controller
  Module :
    Button
  Description : 
    This module implement all button function.
    
Version 0.1 :
  2013/09/21 -[Alen Chen] - Initial, BN_setup, BN_get_status

*/
BN_TYPE BN_ButtonStatus[TOTAL_BN];

// Button initialization function
void BN_setup()
{
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.println("Initialize button");
#endif
	for(int index = 0; index < TOTAL_BN; index++)
	{
		BN_ButtonStatus[index] = BN_RELEASE_STATUS;
	}

	pinMode(BN_FUNCTION_PIN, INPUT);
	pinMode(BN_OK, INPUT);
}

BN_STATUS_TYPE BN_get_status(BN_TYPE keyIndex)
{
	BN_STATUS_TYPE ret = BN_RELEASE;
	int	buttonPin = 0;

	switch(keyIndex)
	{
	case BN_FUNCTION:
		buttonPin = BN_FUNCTION_PIN;
		break;
	case BN_OK:
		buttonPin = BN_OK_PIN;
		break;
	default:
		return ret;
	}
	
	int currentStatus = digitalRead(buttonPin);

	if((currentStatus != BN_ButtonStatus[keyIndex]) &&
		(currentStatus == BN_RELEASE_STATUS))
	{
		ret = BN_PUSH;
#if DEBUG_LOG == ENABLE
  // Print the debug information
  DEBUG_PORT.print("Push Key [");
  DEBUG_PORT.print(keyIndex);
  DEBUG_PORT.println("]");
#endif
	}
	
	BN_ButtonStatus[keyIndex] = currentStatus;

	return ret;
}

