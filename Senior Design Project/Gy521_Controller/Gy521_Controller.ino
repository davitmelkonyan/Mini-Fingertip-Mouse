#include "Wire.h"  //allows communication with I2C devices

const int GY_ADDR = 0x68;

int16_t accelerometer_x, accelerometer_y, accelerometer_z;
int16_t gyroscope_x, gyroscope_y, gyroscope_z;
int16_t temperature;

char* convert_to_str(int16_t n){
  char tmp[7];
  sprintf(tmp, "%6d",n); //min number of characters to be printed
  return tmp;
}

void setup() {
  Serial.begin(9600); //establish connection, 9600 bits per second
  Wire.begin();
  Wire.beginTransmission(GY_ADDR); //begins transmission to GY521
  Wire.write(0x6B);
  Wire.write(0); //wakes up the Gy521
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); //X value of acceloremeter is at register 0x3B so start reading here
  Wire.endTransmission(false); //keep the connection active
  Wire.requestFrom(GY_ADDR, 7*2, true); //each sensor value is stored in 2 registers

  accelerometer_x = Wire.read()<<8 | Wire.read(); //reading 0x3B(ACCEL_XOUT_H) and 0x3C(ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); //rest are next to the first, reading 0x3D and 0x3E
  accelerometer_z = Wire.read()<<8 | Wire.read(); //reading 0x3F and 0x40
  temperature = Wire.read()<<8 | Wire.read(); //reading 0x41 and 0x42
  gyroscope_x = Wire.read()<<8 | Wire.read(); //reading 0x43 and 0x44
  gyroscope_y = Wire.read()<<8 | Wire.read(); //reading 0x45 and 0x46
  gyroscope_z = Wire.read()<<8 | Wire.read(); //reading 0x47 and 0x48

  Serial.print("Acc X = ");
  Serial.print(convert_to_str(accelerometer_x));
  Serial.print("  Acc Y = ");
  Serial.print(convert_to_str(accelerometer_y));
  Serial.print("  Acc Z = ");
  Serial.print(convert_to_str(accelerometer_z));

  Serial.print("  Gyr X = ");
  Serial.print(convert_to_str(gyroscope_x));
  Serial.print("  Gyr Y = ");
  Serial.print(convert_to_str(gyroscope_y));
  Serial.print("  Gyr Z = ");
  Serial.print(convert_to_str(gyroscope_z));
  Serial.println();

  delay(1000);
}
