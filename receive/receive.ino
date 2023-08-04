#include <SoftwareSerial.h>

#define RX D5
#define TX D6
#define LED D1

SoftwareSerial Serial2 (RX, TX);

void setup() {
  // put your setup code here, to run once:
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial2.begin(19200);
  Serial.println("Hello, I'm receiver!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial2.available() > 0) {
    int data = Serial2.parseInt();
    if (Serial2.read() == '\n') {
      Serial.print("Received : ");
      Serial.println(data);
      if (data > 200) digitalWrite(LED, LOW);
      else digitalWrite(LED, HIGH);
    }
  }
}
