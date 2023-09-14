const int btnPin = 4;
const int ledPin = 3;
int reading;
int btnState;

int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;  

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(btnPin, INPUT);
    Serial.begin(9600);
    digitalWrite(ledPin, ledState);
}

void loop(){
    static int prevTime = 0;
    reading = digitalRead(btnPin);

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

    if (reading != lastButtonState) {
    // reset the debouncing timer
        lastDebounceTime = millis();
    }


    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                ledState = !ledState;
            }
        }
    }

    // set the LED:
    digitalWrite(ledPin, ledState);

    // save the reading. Next time through the loop, it'll be the lastButtonState:
    lastButtonState = reading;
}