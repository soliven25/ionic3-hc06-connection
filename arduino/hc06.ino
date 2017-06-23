/*
  HC-06 & Shock Sensor Sample
*/

#include <SoftwareSerial.h>

const int txPin = 2; 
const int rxPin = 3; 
const int Blue5V = 4;
const int ShockPin = 10; 

int shockCounter = 0;
int shockVal = HIGH;

SoftwareSerial BTSerial(txPin, rxPin);

void setup() {
    pinMode(ShockPin, INPUT_PULLUP); // Shock is an input pin
  
    pinMode(Blue5V, OUTPUT); // provide 5V for Bluetooth Moduel HC-06
    digitalWrite(Blue5V, HIGH); // initiate 5V
  
    Serial.begin(9600); // Serial Output
    BTSerial.begin(9600); // Bluetooth Serial
}

void deliverShockToRemote(){
    BTSerial.write("Shock");
}

void loop() {

    shockVal = digitalRead(ShockPin); //read the value from shock sensor

    if(shockVal == LOW){
        Serial.print("Shock = "); // Output to serial
        Serial.println(shockVal);

        deliverShockToRemote();
    
        delay(1000);
        shockCounter++;
    }
}