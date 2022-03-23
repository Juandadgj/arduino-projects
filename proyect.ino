#include <DHT.h>
#include <Ping.h>

byte pinS = 12;
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int sonicTrig = 2;
const int sonicEcho = 7;
const int buzzer = 4;
const int led = 3;
int distancia;
int pausa;

void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(sonicTrig, OUTPUT);
  pinMode(sonicEcho, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{
  float t = dht.readTemperature();
  int val = dht.read(t);
  if (t >= 28 && t <=29) 
  {
    digitalWrite(6, HIGH);
  }
  else
  digitalWrite(6, LOW);
  if (t >= 30 && t <= 31)
  {
    digitalWrite(5, HIGH);
  }
  else
  digitalWrite(5, LOW);
  if (t >= 32 && t <= 33)
  {
  delay(1000);
  long duracion, distancia;
  digitalWrite(sonicTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonicTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonicTrig, LOW);
  duracion = pulseIn(sonicEcho, HIGH);
  distancia = (duracion/2)/29.1;
  pausa = distancia * 10;
  }
  if (distancia < 30)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(pausa);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(pausa);
  }
  else
  {
  digitalWrite(led, HIGH);
  noTone(led);
  }
  delay(100);
}
