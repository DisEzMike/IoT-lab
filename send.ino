#include <SoftwareSerial.h>

#define RX D5
#define TX D6
#define LDR A0

SoftwareSerial Serial2(RX, TX);

void setup() {
  // put your setup code here, to run once:
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
  Serial2.begin(19200);
  Serial.println("Hello, I'm sender!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(LDR);
  Serial.print("Sending : ");
  Serial.println(data);
  Serial2.print(data);
  Serial2.print('\n');
  delay(100);
}
