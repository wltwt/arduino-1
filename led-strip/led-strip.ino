#include "buttons.h"

const int btnPin = 4;
const int ledPin = 3;
const int trigPin = 8;
const int echoPin = 9;
const int lightSensorPin = A1;
int reading;
int btnState;
int lightValue;
int result;

int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;  
long duration, cm;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(btnPin, INPUT);
    pinMode(lightSensorPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(ledPin, ledState);
    Serial.begin(9600);
}

void loop(){
    static int prevTime = 0;
    reading = digitalRead(btnPin);
    lightValue = analogRead(lightSensorPin);
    // Serial.println("for git");

    // if (millis() - prevTime > 1000){
        // prevTime = millis();
        // if (reading == 1) {
            // Serial.println("knappetrykk");
            // 
        // }
        // if (digitalRead(ledPin)){
            // digitalWrite(ledPin, LOW);
        // } else {
            // digitalWrite(ledPin, HIGH);
        // }
    // }

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration / 2) /29.1;

    if (reading != lastButtonState) {
    // reset the debouncing timer
        lastDebounceTime = millis();
    }


    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                ledState = !ledState;
                result = addTwoInts(3, buttonState);
            }
            Serial.print("Distance: ");
            Serial.print(cm);
            Serial.print(" cm \n");
            //Serial.println(result);
        }
    }

    
    // set the LED:
    if (lightValue < 300){
        digitalWrite(ledPin, LOW);
    } else {
        digitalWrite(ledPin, ledState);
    }
    

    // save the reading. Next time through the loop, it'll be the lastButtonState:
    lastButtonState = reading;
}