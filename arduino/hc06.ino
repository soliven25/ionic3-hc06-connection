/*
  HC-06 & Shock Sensor Sample
*/

#include <SoftwareSerial.h>

const int txPin = 2; 
const int rxPin = 3; 
const int Blue5V = 4;
const int LED = 5; 
String myString = "";

SoftwareSerial BTSerial(txPin, rxPin);

void setup() {
    pinMode(LED, OUTPUT); // LED
  
    pinMode(Blue5V, OUTPUT); // provide 5V for Bluetooth Moduel HC-06
    digitalWrite(Blue5V, HIGH); // initiate 5V
  
    Serial.begin(9600); // Serial Output
    BTSerial.begin(9600); // Bluetooth Serial
}


void loop() {

    while(BTSerial.available())
    {
        char myChar = (char)BTSerial.read();
        myString+=myChar;
        delay(5);
    }

    if(!myString.equal(""))
    {
        Serial.println("input : " + myString);

        if(myString == "ON")
        {
            digitalWrite(LED, HIGH);
        }else{
            digitalWrite(LED, LOW);
        }
        myString="";
    }
}