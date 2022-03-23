#include <Servo.h>
#include <Ping.h>

Servo servo;
const int ppot = 0;
const int pservo = 8;
const int pulsoMin = 650;
const int pulsoMax = 2550;
int valor;
int angulo;

void setup() 
{
  Serial.begin(9600);
  servo.attach(pservo);
}

void loop() 
{
  //valor = analogRead(ppot);
  //angulo = map(distancia, 0, 50, 0, 180);
  servo.write(10);
  delay(100);
}
