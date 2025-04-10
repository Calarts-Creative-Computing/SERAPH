//SERAPH POTENIOMETER DEMO

#include <usb_midi.h>

//TOF
#include <Wire.h>

int testval = 0;

//change this pin assignment based on your specific circuit
int fsr_pin = A9;

//instantiate previous values
int fsr_val_prev = 0;

//instantiate filtered values
int fsr_val_lp = 0;


//setup function
void setup() {
  Serial.begin(9600);
  usbMIDI.begin();
}

void loop() {

//map and read potentiometer values
  int fsr_val = map(analogRead(fsr_pin), 1023, 0, 0, 127);

//low pass filter data:
  fsr_val_lp = (fsr_val_prev + fsr_val) / 2;


//print value

  Serial.print(" pot value:");
  Serial.print(fsr_val_lp);
  Serial.println();

//send Midi CC

//send fsr data
if (abs(fsr_val_prev - fsr_val) > 1){
  usbMIDI.sendControlChange(19,fsr_val_lp,1);
}


  while (usbMIDI.read()) {


  }

  // store previous values:
  fsr_val_prev = fsr_val;

  delay(1);
}
