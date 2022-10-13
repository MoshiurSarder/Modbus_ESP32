/* #include <ModbusMaster.h>

#define MAX485_DE 18
#define MAX485_RE_NEG 19

ModbusMaster node;

void preTransmission()
{
  digitalWrite(MAX485_DE, 1);
  digitalWrite(MAX485_RE_NEG, 1);
}

void postTransmission()
{
  digitalWrite(MAX485_DE, 0);
  digitalWrite(MAX485_RE_NEG, 0);
}

void setup() {
  pinMode(MAX485_DE, OUTPUT);
  pinMode(MAX485_RE_NEG, OUTPUT);

  digitalWrite(MAX485_DE, 0);
  digitalWrite(MAX485_RE_NEG, 0);

  Serial.begin(9600);
  node.begin(1, Serial);

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}

void loop() {

  uint8_t result;
 
  result = node.readInputRegisters(0x0000, 9);
  
  if (result == node.ku8MBSuccess)
  {
  Serial.println("________");
  Serial.print("Voltage: ");
  Serial.print(node.getResponseBuffer(0x0000) / 10.0);
  Serial.println(" V");
  Serial.print("Currrent: ");
  Serial.print(node.getResponseBuffer(0x0001) / 1000.0f);
  Serial.println(" A");
  Serial.print("Power: ");
  Serial.print(node.getResponseBuffer(0x0003) / 10.0f);
  Serial.println(" W");
  Serial.print("Energy: ");
  Serial.print(node.getResponseBuffer(0x0005) / 10.0f);
  Serial.println(" Wh");
  Serial.print("Frequency: ");
  Serial.print(node.getResponseBuffer(0x0007) / 10.0f);
  Serial.println(" Hz");
  }
  delay(3000);
} */

#include <ModbusMaster.h>

#define MAX485_DE 26
#define MAX485_RE_NEG 25

#define Pzemserial Serial2

#define RXD2 22
#define TXD2 4

ModbusMaster node;

void preTransmission()
{
  digitalWrite(MAX485_DE, 1);
  digitalWrite(MAX485_RE_NEG, 1);
}

void postTransmission()
{
  digitalWrite(MAX485_DE, 0);
  digitalWrite(MAX485_RE_NEG, 0);
}

void setup() {

  pinMode(MAX485_DE, OUTPUT);
  pinMode(MAX485_RE_NEG, OUTPUT);

  digitalWrite(MAX485_DE, 0);
  digitalWrite(MAX485_RE_NEG, 0);

  Serial.begin(9600);
  Pzemserial.begin(9600, SERIAL_8N1, RXD2, TXD2);
  node.begin(1, Pzemserial);

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}

void loop() {

  uint8_t result;
 
  result = node.readInputRegisters(0x0000, 9);
  
  if (result == node.ku8MBSuccess)
  {
  Serial.println("________");
  Serial.print("Voltage: ");
  Serial.print(node.getResponseBuffer(0x0000) / 10.0);
  Serial.println(" V");
  Serial.print("Currrent: ");
  Serial.print(node.getResponseBuffer(0x0001) / 1000.0f);
  Serial.println(" A");
  Serial.print("Power: ");
  Serial.print(node.getResponseBuffer(0x0003) / 10.0f);
  Serial.println(" W");
  Serial.print("Energy: ");
  Serial.print(node.getResponseBuffer(0x0005) / 10.0f);
  Serial.println(" Wh");
  Serial.print("Frequency: ");
  Serial.print(node.getResponseBuffer(0x0007) / 10.0f);
  Serial.println(" Hz");
  }
  delay(3000);
}