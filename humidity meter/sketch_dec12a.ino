#include <dht11.h>
#define DHT11PIN 6

dht11 DHT11;
const int buttonPin = 12;
int buttonState = 0; 

void setup() {
      //Serial.begin(9600);
      pinMode(11, OUTPUT); //red
      pinMode(9, OUTPUT); // green
      pinMode(10, OUTPUT);//yelow
      pinMode(buttonPin, INPUT);
}

void loop() {
  //Serial.println();
  int chk = DHT11.read(DHT11PIN);
  /*Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);*/
  //delay(1000);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if((float)DHT11.humidity > 85){
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(11, LOW);
     }
     if((float)DHT11.humidity > 50 && (float)DHT11.humidity < 85){
      digitalWrite(10, HIGH);
      delay(1000);
      digitalWrite(10, LOW);
     }
     if((float)DHT11.humidity > 5 && (float)DHT11.humidity < 50){
      digitalWrite(9, HIGH);
      delay(1000);
      digitalWrite(9, LOW);
     }
  } else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
