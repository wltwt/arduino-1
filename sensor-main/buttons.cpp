#include "Arduino.h"
#include "buttons.h"
 
buttons::buttons(int pin){
    pinMode(pin, OUTPUT);
    _pin = pin;
 }
