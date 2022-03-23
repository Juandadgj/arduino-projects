#include <Ping.h>

const int sonicTrig = 2;
const int sonicEcho = 7;
const int buzzer = 4;
const int ledRojo = 3;
const int ledAmarillo = 5;
const int ledVerde = 6;
int distancia;
int pausa;

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
  
  if (distancia <= 100 && distancia >= 30)
  {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(pausa);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, LOW);
    delay(pausa);
  }
  
  else if (distancia <= 29 && distancia >= 10)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(pausa);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(buzzer, LOW);
    delay(pausa);
  }
  
  else if (distancia <= 9 && distancia >= 0)
  {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(pausa);
    digitalWrite(ledRojo, LOW);
    digitalWrite(buzzer, LOW);
    delay(pausa);
  }
  
  if (distancia >= 200 && distancia <=0)
  {
    Serial.println("Fuera de rango.");
  }
  
  else
  {
  Serial.print(distancia);
  Serial.println("cm");
  }
  delay(100);
}
