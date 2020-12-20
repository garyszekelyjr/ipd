#include <stdio.h>
#include <DHT.h>

#define echo_pin 13
#define trig_pin 12
#define dht_sensor A0

#define red_light 6
#define green_light 5
#define blue_light 4

long duration;
double distance;
dht DHT;

void setup() {
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(dht_sensor, OUTPUT);
  pinMode(red_light, OUTPUT);
  pinMode(green_light, OUTPUT);
  pinMode(blue_light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(red_light, 0);
  analogWrite(green_light, 0);
  analogWrite(blue_light, 0);

  Serial.println("Enter your employee ID #: ");
  while (Serial.available()) { }
  
  while (true) {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    duration = pulseIn(echo_pin, HIGH);
    distance = (duration * 0.034) / 2;
    if (distance > 5) {
      Serial.println("Please step forward");
    } else if (distance < 2.62) {
      Serial.println("Please step back");
    } else {
      Serial.println("Closing door");
      delay(3000);
      Serial.println("Scanning");
      analogWrite(red_light, 0);
      analogWrite(green_light, 0);
      analogWrite(blue_light, 255);
      break;
    }
    delay(3000);
  }
  delay(3000);
  DHT.read11(dht_sensor);
  double humidity = DHT.humidity;
  Serial.print("\nContamination Level: ");
  Serial.print(humidity);
  Serial.println("%");
  if (humidity < 75) {
    Serial.println("Contamination Levels are LOW");
    analogWrite(red_light, 0);
    analogWrite(green_light, 255);
    analogWrite(blue_light, 0);
  } else {
    Serial.println("Contamination Levels are HIGH");
    Serial.println("Change of PPE recommended");
    analogWrite(red_light, 255);
    analogWrite(green_light, 0);
    analogWrite(blue_light, 0);
  }
  delay(3000);
  Serial.println();
}
