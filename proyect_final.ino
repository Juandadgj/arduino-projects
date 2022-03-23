#include <Ping.h>
#include <DHT.h>

const int sonicTrig = 2;
const int sonicEcho = 7;
const int buzzer = 4;
const int ledRojo = 3;
const int ledAmarillo = 5;
const int ledVerde = 6;
int distancia;
int pausa;
byte pinS = 12;
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  pinMode(sonicTrig, OUTPUT);
  pinMode(sonicEcho, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() 
{
  long duracion, distancia;
  digitalWrite(sonicTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonicTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonicTrig, LOW);
  duracion = pulseIn(sonicEcho, HIGH);
  distancia = (duracion/2)/29.1;
  pausa = distancia * 10;
  
  if (distancia <= 30 && distancia >= 1)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(pausa);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(buzzer, LOW);
    delay(pausa);
  }

  float t = dht.readTemperature();
  int val = dht.read(t);
  if (t >= 26 && t <=30) 
  {
    digitalWrite(ledVerde, HIGH);
  }
  else
  digitalWrite(ledVerde, LOW);
  if (t >= 30 && t <= 38)
  {
    digitalWrite(ledRojo, HIGH);
  }
  else
  digitalWrite(ledRojo, LOW);
  
}
