/*
  Project : 
    Arduino Helicopter - Helicopter
  Module :
    Accelerator
  Description : 
    The physical driver of accelerator
    
Version 0.1 :
  2013/05/21 -[Alen Chen] - Initial
  2013/06/02 -[Alen Chen] - Add LIS3LV02DQ setup, getValue function

*/

#define LIS3LV02DQ_I2C_ADDR 0x1D

void LIS3LV02DQSetup(void)
{
  Wire.beginTransmission(LIS3LV02DQ_I2C_ADDR);
  Wire.write(0x20);                    // CTRL_REG1 20h
  // 11: device on, 01: decimate by 128, 0: normal mode, 111: all axis enabled
  Wire.write(0x87);                    // device on, 40Hz, normal mode, all axis' enabled
  Wire.endTransmission();
}

void getLIS3LV02DQValues(int *xAccel, int *yAccel, int* zAccel )
{
  byte bytearray[6]; // low, high;
  int cnt;

  Wire.beginTransmission(LIS3LV02DQ_I2C_ADDR);
  Wire.write(0x28|0x80);
  Wire.endTransmission();
 
  // now do a transfer reading all six bytes
  Wire.requestFrom(LIS3LV02DQ_I2C_ADDR,6);
 
  cnt=0;
  while(cnt<6)
  {  
    if(Wire.available())
    {
      bytearray[cnt]=Wire.read();
      cnt++;
    }
  }

  if (xAccel != NULL)
  {
    *xAccel = (bytearray[1] << 8) + bytearray[0];
  }
  
  if (yAccel != NULL)
  {
    *yAccel = (bytearray[3] << 8) + bytearray[2];
  }
 
  if (zAccel != NULL)
  {
    *zAccel = (bytearray[5] << 8) + bytearray[4];
  }

}

