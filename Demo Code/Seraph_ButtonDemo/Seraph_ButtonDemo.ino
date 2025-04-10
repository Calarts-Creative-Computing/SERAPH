//SERAPH BUTTON DEMO

#include <usb_midi.h>

int testval = 0;

//change these assignments based on your specific circuit
int button_pin = 0;
int led_pin = 3;

//instantiate previous values
int button_val_prev = 0;


//setup Function
void setup() {
  Serial.begin(9600);
  usbMIDI.begin();
}

void loop() {

//map and read button values
  int button_val = map(digitalRead(button_pin), 0, 1, 0, 127);
  int button_state = digitalRead(button_pin);


//print values

  Serial.print(" button value:");
  Serial.print(button_val);
  Serial.println();


//send button data

//send Midi CC 
if (button_val_prev != button_val){
  usbMIDI.sendControlChange(20,button_val,1); //Modify the first atribute of this function to send your data on the correct Midi CC lane for your project
  button_val_prev = button_val; 
}

//send Note On and LED 
 if (buttonState == HIGH) {
   usbMIDI.sendNoteOn(60,127,1);
   digitalWrite(led_pin, HIGH); //turn LED on
 } else {
   usbMIDI.sendNoteOff(60,127,1);
   digitalWrite(led_pin, LOW); //turn LED off
 };

  while (usbMIDI.read()) {

  }

  button_val_prev = button_val;

  delay(1);
}
