//SERAPH ACCELEROMETER, BUTTON, and POTENIOMETER DEMO

#include <usb_midi.h>

//TOF
#include <Wire.h>

int testval = 0;

//assign pins (if using built in Seraph accelerometer, pins are always these values)
int accelX_pin = A15;
int accelY_pin = A16;
int accelZ_pin = A17;


//instantiate previous values
int accelX_val_prev = 0;
int accelY_val_prev = 0;
int accelZ_val_prev = 0;


//instantiate filtered values
int accelX_val_lp = 0;
int accelY_val_lp = 0;
int accelZ_val_lp = 0;


//setup Function
void setup() {
  Serial.begin(9600);
  usbMIDI.begin();
}

void loop() {


//map and read accelerometer values
  int accelX_val = map(analogRead(accelX_pin), 1023, 0, 0, 127);
  int accelY_val = map(analogRead(accelY_pin), 1023, 0, 0, 127);
  int accelZ_val = map(analogRead(accelZ_pin), 1023, 0, 0, 127);


//low pass filter data:
  accelX_val_lp = (accelX_val_prev + accelX_val) / 2;
  accelY_val_lp = (accelY_val_prev + accelY_val) / 2;
  accelZ_val_lp = (accelZ_val_prev + accelZ_val) / 2;


//print values

  Serial.print(" accelX:");
  Serial.print(accelX_val_lp);
  Serial.print(" accelY:");
  Serial.print(accelY_val_lp);
  Serial.print(" accelZ:");
  Serial.print(accelZ_val_lp);

  Serial.print(" button value:");
  Serial.print(button_val);

  Serial.print(" pot value:");
   Serial.print(pot_val);

  Serial.println();


  //send Midi CC

  //send accelerometer data
  if (accelX_val_lp > 10 || abs(accelX_val - accelX_val_prev) > 1) { 
    usbMIDI.sendControlChange(16, accelX_val, 1);
    accelX_val_prev = accelX_val;
  }

  if (accelY_val_lp > 10 || abs(accelY_val - accelY_val_prev) > 1) {
    usbMIDI.sendControlChange(17, accelY_val, 1);
    accelY_val_prev = accelY_val;
  }

  if (accelZ_val_lp > 10 || abs(accelZ_val - accelZ_val_prev) > 1) {
    usbMIDI.sendControlChange(18, accelZ_val, 1);
    accelZ_val_prev = accelZ_val;
  }





  while (usbMIDI.read()) {


  }

  // store previous values:
  accelX_val_prev = accelX_val;
  accelY_val_prev = accelY_val;
  accelZ_val_prev = accelZ_val;

  pot_val_prev = pot_val;

  button_val_prev = button_val;


  delay(1);
}
