#pragma once
#ifndef LINEFOLLOWERV1_H
#define LINEFOLLOWERV1_H
#endif
#define SENSOR_ERROR    1
#define SENSOR_GOOD     0
#define MOT_ENABLE_PIN                  5
#define MOT_LEFT_DIRECTION_PIN1         3
#define MOT_LEFT_DIRECTION_PIN2         4
#define MOT_RIGHT_DIRECTION_PIN1        6
#define MOT_RIGHT_DIRECTION_PIN2        7
#define SENSOR_1  A0
#define SENSOR_2  A1
#define SENSOR_3  A2
#define SENSOR_4  A3
#define SENSOR_5  A4
#define SENSOR_6  A5

int lineFollowerInitialize() {
  pinMode(MOT_LEFT_DIRECTION_PIN1, OUTPUT);             
  pinMode(MOT_LEFT_DIRECTION_PIN2, OUTPUT);
  pinMode(MOT_ENABLE_PIN, OUTPUT);
  pinMode(MOT_RIGHT_DIRECTION_PIN1, OUTPUT);
  pinMode(MOT_RIGHT_DIRECTION_PIN2, OUTPUT);
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(SENSOR_4, INPUT);
  pinMode(SENSOR_5, INPUT);
  pinMode(SENSOR_6, INPUT);
  if ((analogRead(SENSOR_1) > 100 && analogRead(SENSOR_1) < 1020) && \
      (analogRead(SENSOR_2) > 100 && analogRead(SENSOR_2) < 1020) && \
      (analogRead(SENSOR_3) > 100 && analogRead(SENSOR_3) < 1020) && \
      (analogRead(SENSOR_4) > 100 && analogRead(SENSOR_4) < 1020) && \
      (analogRead(SENSOR_5) > 100 && analogRead(SENSOR_5) < 1020) && \
      (analogRead(SENSOR_6) > 100 && analogRead(SENSOR_6) < 1020)) {
        return 0;
      }
  else {
    return 1;
  } 
}

void kananMaju() {
  digitalWrite(MOT_RIGHT_DIRECTION_PIN1, LOW);
  digitalWrite(MOT_RIGHT_DIRECTION_PIN2, HIGH);
}

void kiriMaju() {
  digitalWrite(MOT_LEFT_DIRECTION_PIN1, LOW);
  digitalWrite(MOT_LEFT_DIRECTION_PIN2, HIGH);
}

void kananMundur() {
  digitalWrite(MOT_RIGHT_DIRECTION_PIN1, HIGH);
  digitalWrite(MOT_RIGHT_DIRECTION_PIN2, LOW);
}

void kiriMundur() {
  digitalWrite(MOT_LEFT_DIRECTION_PIN1, HIGH);
  digitalWrite(MOT_LEFT_DIRECTION_PIN2, LOW);
}

void kananStop() {
  digitalWrite(MOT_RIGHT_DIRECTION_PIN1, LOW);
  digitalWrite(MOT_RIGHT_DIRECTION_PIN2, LOW);
}

void kiriStop() {
  digitalWrite(MOT_LEFT_DIRECTION_PIN1, LOW);
  digitalWrite(MOT_LEFT_DIRECTION_PIN2, LOW);
}

void motorEnable(int speed) {
  if (speed == 255) {
    digitalWrite(MOT_ENABLE_PIN, HIGH);  
  }
  else {
    analogWrite(MOT_ENABLE_PIN, speed);
  }
}

void motorDisable() {
  digitalWrite(MOT_ENABLE_PIN, LOW); 
}

int cekSensor1() {
  return analogRead(SENSOR_1);
}

int cekSensor2() {
  return analogRead(SENSOR_2);
}

int cekSensor3() {
  return analogRead(SENSOR_3);
}

int cekSensor4() {
  return analogRead(SENSOR_4);
}

int cekSensor5() {
  return analogRead(SENSOR_5);
}

int cekSensor6() {
  return analogRead(SENSOR_6);
}