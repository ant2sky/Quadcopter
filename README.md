Quadcopter
==========

This project is for Quadcopter with Atmega328.
I use arduino IDE to development and create CmProtocol library.
The CmProtocol library handle communication protocol between remote controller and helicopter.



Porject: Quadcopter
Initial Day : 2012/05/18
---------------------------
2013-03-21
	- Create three folders for this project.
	
		- Helicopter : for helicopter side.
		
		- Protocol : for communication protocol definition
		
		- RemoteController : for controller side
		
	- Remove Helicopter.ino

2012-09-21
    - [Helicopter] Implement L3G4200D and LIS3LV02DQ driver (initial, read value)
	
2013-03-13
	- [Remote controller] Initial Remote Controller software architecture
	
2013-03-23
	- [CmProtocol] Create android library framework
	
2013-04-17
	- [Remote controller] Implement handleJoystick function to read joystick's ADC and remap it beas on different control
	
2013-04-23
	- [CmProtocol] CM:get_command_info, get_payload_int. RC:reveiceCommandData
	
	- [CmProtocol] CM:set_payload_int, speed, turn, direction(left, right, front, back)
	
2013-05-21
	- [Helicopter] Initial Helicopter software architecture

2013-06-05
	- [Helicopter] Add L3G4200[Gyro] and LIS3LV02DQ[Accelerator] driver and sample code
	
2013-06-02
	- [Helicopter] Add LIS3LV02DQ setup, getValue function

2013-09-21
	- [Remote controller] Initial button function
	
2013-09-27
	- [Remote controller] Implement Led, Display Manager, Button, Calibration
	
2013-09-30
	- [Remote controller] Extend LED number from 8 to 16 and add middle range for joystick
	
	- [Remote controller] Enable the third shift register and fixed led don't work when the number is over 16