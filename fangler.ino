#include <DHT.h>

const int relayPin = 2;
const int motorPin = 9;
const int dhtPin = 3;

DHT dht(dhtPin, DHT11);

float temperature;
float initialTemp;

//int highSpeed = 200; Was not able to find a visible difference in speeds due to the motor
//int lowSpeed = 10;

void setup() {

  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
 
  dht.begin();

  initialTemp = dht.readTemperature();

  Serial.print("Initial Temperature: ");
  Serial.print(initialTemp);
  Serial.println(" °C");

  temperature = dht.readTemperature();

  Serial.print("Initial Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");
}

void loop() {

  float temperature = dht.readTemperature();

  Serial.print("Current Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  analogWrite(motorPin, 225);

  if (temperature > initialTemp + 1) {
    digitalWrite(relayPin, HIGH); 
  } else { 
    digitalWrite(relayPin, LOW);
  }


  delay(2000);
}
