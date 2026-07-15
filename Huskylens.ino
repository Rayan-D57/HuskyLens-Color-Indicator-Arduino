#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;

const int ledblue = 7;
const int ledred = 8;
const int ledgreen = 9;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  pinMode(ledblue, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);

  while (!huskylens.begin(Wire)) {
    Serial.println("HuskyLens not found!");
    delay(1000);
  }
}

void loop() {
  if (huskylens.request()) {
    if (huskylens.isLearned()) {
 
      if (huskylens.available()) {
        HUSKYLENSResult result = huskylens.read(); 
        
        digitalWrite(ledblue, LOW);
        digitalWrite(ledred, LOW);
        digitalWrite(ledgreen, LOW);


        if (result.ID == 1) {
          digitalWrite(ledblue, HIGH);
        } else if (result.ID == 3) {
          digitalWrite(ledred, HIGH);
        } else if (result.ID == 2) {
          digitalWrite(ledgreen, HIGH);
        }
      }
    }
  }
}
