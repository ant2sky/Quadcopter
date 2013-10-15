/*
  Project : 
    Arduino Helicopter - Helicopter
  Module :
    Gyroscope sensor
  Description : 
    Physical driver of gyroscope.
    
Version 0.1 :
  2013/05/21 -[Alen Chen] - Initial
  2013/06/05 -[Alen Chen] - Add L3G4200 setup, read, write and getValue function

*/

// Command Definition
#define L3G4200_CTRL_REG01 0x20
#define L3G4200_CTRL_REG02 0x21
#define L3G4200_CTRL_REG03 0x22
#define L3G4200_CTRL_REG04 0x23
#define L3G4200_I2C_ADD 0x69

// Initial L3G4200 device
void L3G4200Setup(void)
{
 // Wire.beginTransmission(L3G4200_I2C_ADD);
  L3G4200Write(L3G4200_CTRL_REG01, 0x1F);    // Turn on all axes, disable power down
  L3G4200Write(L3G4200_CTRL_REG03, 0x08);    // Enable control ready signal
  L3G4200Write(L3G4200_CTRL_REG04, 0x80);    // Set scale (500 deg/sec)
}

int L3G4200Read (byte regAddr) 
{
    Wire.beginTransmission(L3G4200_I2C_ADD);
    Wire.write(regAddr);                 // Register address to read
    Wire.endTransmission();             // Terminate request
    Wire.requestFrom(L3G4200_I2C_ADD, 1);          // Read a byte
    while(!Wire.available()) { };       // Wait for receipt
    return(Wire.read());             // Get result
}

void L3G4200Write (byte regAddr, byte val) 
{
    Wire.beginTransmission(L3G4200_I2C_ADD);
    Wire.write(regAddr);
    Wire.write(val);
    Wire.endTransmission();
}

void getL3G4200Values (int * valX, int *valY, int * valZ) 
{
  byte MSB, LSB;

  if (valX != NULL)
  { 
    MSB = L3G4200Read(0x29);
    LSB = L3G4200Read(0x28);
    *valX = ((MSB << 8) | LSB);
  }

  if (valY != NULL)
  {
    MSB = L3G4200Read(0x2B);
    LSB = L3G4200Read(0x2A);
    *valY = ((MSB << 8) | LSB);
  }

  if (*valZ != 0)
  {
    MSB = L3G4200Read(0x2D);
    LSB = L3G4200Read(0x2C);
    *valZ = ((MSB << 8) | LSB);
  }
}

