#include <Arduino.h>
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! 
#endif

BluetoothSerial SerialBT;
Servo sortingServo;

const int SERVO_PIN = 18;      
const int POS_CENTER = 90;     
const int POS_BIO = 180;        
const int POS_NON_BIO = 0;   

void setup() {
  Serial.begin(115200);
  

  ESP32PWM::allocateTimer(0);
  sortingServo.setPeriodHertz(50); 
  sortingServo.attach(SERVO_PIN, 500, 2400);
  sortingServo.write(POS_CENTER);

  SerialBT.begin("ESP32_Waste_Sorter"); 
  Serial.println("==================================================");
  Serial.println("ESP32 Waste Sorter Ready!");
  Serial.println("Bluetooth Name: ESP32_Waste_Sorter");
  Serial.println("('0' or '1')...");
  Serial.println("==================================================");
}

void loop() {
  if (SerialBT.available()) {
    char incomingSignal = SerialBT.read();
    Serial.print("Received Signal over Bluetooth: ");
    Serial.println(incomingSignal);

    if (incomingSignal == '0') {
      Serial.println("Action: Sorting BIODEGRADABLE (Signal 0 Received)");
      sortingServo.write(POS_BIO);
      delay(5000);
      sortingServo.write(POS_CENTER);
    } 
    else if (incomingSignal == '1') {
      Serial.println("Action: Sorting NON-BIODEGRADABLE (Signal 1 Received)");
      sortingServo.write(POS_NON_BIO);
      delay(5000);
      sortingServo.write(POS_CENTER);
    }
  }

  delay(20);
}
