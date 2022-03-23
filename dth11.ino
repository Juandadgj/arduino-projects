#include <DHT.h>

byte pinS = 12;
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() 
{
  float t = dht.readTemperature();
  int val = dht.read(t);
  Serial.print("Temperatura: ");
  Serial.println(t);
  if (t >= 30 && t <=35) 
  {
    digitalWrite(6, HIGH);
  }
  else
  digitalWrite(6, LOW);
  if (t >= 36 && t <= 40)
  {
    digitalWrite(5, HIGH);
  }
  else
  digitalWrite(5, LOW);
  if (t >= 40 && t <= 45)
  {
  digitalWrite(3, HIGH);
  }
  else
  digitalWrite(3, LOW);
  delay(1000);
}
