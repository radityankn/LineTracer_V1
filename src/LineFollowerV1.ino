#include "LineFollower_V1.h"

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.print(cekSensor1());
  Serial.print(", ");
  Serial.print(cekSensor2());
  Serial.print(", ");
  Serial.print(cekSensor3());
  Serial.print(", ");
  Serial.print(cekSensor4());
  Serial.print(", ");
  Serial.print(cekSensor5());
  Serial.print(", ");
  Serial.println(cekSensor6());
  if (lineFollowerInitialize() == 0) {
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
  }
  else {
    while (1) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);      
    }
  }
}

void loop() {
  motorEnable(255);
  if(cekSensor3() < 830 && cekSensor4() > 830) {
    kiriMaju();
    kananStop();
    kananMundur();
    delay(1);
    kananStop();
    while(cekSensor4() > 830){
      kiriMaju();
      kananStop();
    }
  }
  else if (cekSensor3() > 830 && cekSensor4() < 830) {
    kananMaju();
    kiriStop();
    kiriMundur();
    delay(1);
    kiriStop();
    while(cekSensor3() > 830){
      kananMaju();
      kiriStop();
    }
  }
  else if (cekSensor1() < 870) {
    while(cekSensor4() < 830){
      kiriMaju();
      kananStop();
    }
    while(cekSensor4() > 830){
      kiriMaju();
      kananStop();
    }
    kiriStop();
    delay(1);
  }
  else {
    kananMaju();
    kiriMaju();
  }
  delay(1);
}