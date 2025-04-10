//SERAPH MULTIPLE BUTTON DEMO

#include <usb_midi.h>

int testval = 0;

//change these assignments based on your specific circuit
int button1_pin = 0;
int button2_pin = 1;
int button3_pin = 2;
int button4_pin = 3;
int button5_pin = 4;
int button6_pin = 5;
int led_pin = 3;

//instantiate previous values
int button1_val_prev = 0;
int button2_val_prev = 0;
int button3_val_prev = 0;
int button4_val_prev = 0;
int button5_val_prev = 0;
int button6_val_prev = 0;
int button7_val_prev = 0;


//setup Function
void setup() {
  Serial.begin(9600);
  usbMIDI.begin();
}

void loop() {

//map and read button values
  int button1_val = map(digitalRead(button1_pin), 0, 1, 0, 127);
  int button2_val = map(digitalRead(button2_pin), 0, 1, 0, 127);
  int button3_val = map(digitalRead(button3_pin), 0, 1, 0, 127);
  int button4_val = map(digitalRead(button4_pin), 0, 1, 0, 127);
  int button5_val = map(digitalRead(button5_pin), 0, 1, 0, 127);
  int button6_val = map(digitalRead(button6_pin), 0, 1, 0, 127);


//print values

  Serial.print(" button 1 value:");
  Serial.print(button1_val);
  Serial.print(" button 2 value:");
  Serial.print(button2_val);
  Serial.print(" button 3 value:");
  Serial.print(button3_val);
  Serial.print(" button 4 value:");
  Serial.print(button4_val);
  Serial.print(" button 5 value:");
  Serial.print(button5_val);
  Serial.print(" button 6 value:");
  Serial.print(button6_val);
  Serial.println();


//send button data

//send Midi CC
if (button1_val_prev != button1_val){
  usbMIDI.sendControlChange(20,button1_val,1);
  usbMIDI.sendNoteOn(60,127,1);
}
else {
  usbMIDI.sendNoteOff(60,127,1);
}
if (button2_val_prev != button2_val){
  usbMIDI.sendControlChange(21,button2_val,1);
  usbMIDI.sendNoteOn(64,127,1);
}
else {
  usbMIDI.sendNoteOff(64,127,1);
}
if (button3_val_prev != button3_val){
  usbMIDI.sendControlChange(22,button3_val,1);
  usbMIDI.sendNoteOn(67,127,1);
}
else {
  usbMIDI.sendNoteOff(67,127,1);
}
if (button4_val_prev != button4_val){
  usbMIDI.sendControlChange(23,button4_val,1);
  usbMIDI.sendNoteOn(71,127,1);
}
else {
  usbMIDI.sendNoteOff(71,127,1);
}
if (button5_val_prev != button5_val){
  usbMIDI.sendControlChange(24,button5_val,1);
  usbMIDI.sendNoteOn(72,127,1);
}
else {
  usbMIDI.sendNoteOff(72,127,1);
}
if (button6_val_prev != button6_val){
  usbMIDI.sendControlChange(25,button6_val,1);
  usbMIDI.sendNoteOn(76,127,1);
}
else {
  usbMIDI.sendNoteOff(76,127,1);
}


while (usbMIDI.read()) {
  }

  //set previous values
  button1_val_prev = button1_val;
  button2_val_prev = button2_val;
  button3_val_prev = button3_val;
  button4_val_prev = button4_val;
  button5_val_prev = button5_val;
  button6_val_prev = button6_val;

  delay(1);
}
