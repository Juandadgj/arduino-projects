#include <Ping.h>
#include <LiquidCrystal_I2C.h>

const int sonicTrig = 2;
const int sonicEcho = 7;
const int buzzer = 4;
const int led = 3;
int distancia;
int pausa;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  pinMode(sonicTrig, OUTPUT);
  pinMode(sonicEcho, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
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
  distancia = round((duracion/2)/29.1);
  /*pausa = distancia * 10;
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
  }*/
  lcd.display();
  lcd.setCursor(0, 1);
  lcd.print(distancia);
}
