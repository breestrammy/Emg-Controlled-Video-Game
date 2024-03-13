#include "Keyboard.h"


int i = 0;
unsigned t = 0;   // the time variable 
unsigned v = 0;   // the voltage value
unsigned s=0;  // start time
  
const int analogInPin = A11;
const int emgPin = A11;
const int threshold = 513;
int emgValue = 0;
int prevEmgValue = 0;
bool muscleContraction = false;



void setup() {
  Serial.begin(9600);
  // Serial.println('Test');
  pinMode(analogInPin, INPUT);
  Keyboard.begin();
  Keyboard.end();
 }
  
void loop() {
  emgValue = analogRead(emgPin);
  
  // Check if muscle contraction is detected
  if (emgValue > threshold) {
    muscleContraction = true;
     Serial.println(emgValue);
     Serial.println('a');
     Keyboard.print(' ');

  } else {
    muscleContraction = false;
    Keyboard.releaseAll();
  }

  // Update previous EMG sensor reading
  prevEmgValue = muscleContraction;


  // Add a delay to avoid continuous readings
  delay(10);
}