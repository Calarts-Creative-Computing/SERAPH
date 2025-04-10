//SERAPH POTENIOMETER DEMO

#include <usb_midi.h>

//TOF
#include <Wire.h>

int testval = 0;

//change this pin assignment based on your specific circuit
int pot_pin = A9;

//instantiate previous values
int pot_val_prev = 0;

//instantiate filtered values
int pot_val_lp = 0;


//setup Function
void setup() {
  Serial.begin(9600);
  usbMIDI.begin();
}

void loop() {

//map and read potentiometer values
  int pot_val = map(analogRead(pot_pin), 1023, 0, 0, 127);

//low pass filter data:
  pot_val_lp = (pot_val_prev + pot_val) / 2;


//print values
  Serial.print(" pot value:");
  Serial.print(pot_val);
  Serial.println();

//send Midi CC

//send potentiometer data
  if (abs(pot_val_prev - pot_val) > 1){
    usbMIDI.sendControlChange(19,pot_val_lp,1);
  }

  while (usbMIDI.read()) {

  }

  // store previous values:
  pot_val_prev = pot_val;

//delay loop
  delay(1);
}
