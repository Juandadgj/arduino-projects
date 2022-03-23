#include <DHT.h>
#include <LiquidCrystal_I2C.h>

byte pinS = 12;
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(5,1);
  lcd.print("C");
}

void loop() 
{
  float t = dht.readTemperature();
  int val = dht.read(t);
  Serial.print("Temperatura: ");
  Serial.println(t);
  if (t >= 0 && t <=20) 
  {
    digitalWrite(6, HIGH);
  }
  else
  digitalWrite(6, LOW);
  if (t >= 21 && t <= 40)
  {
    digitalWrite(5, HIGH);
  }
  else
  digitalWrite(5, LOW);
  if (t >= 41 && t <= 60)
  {
  digitalWrite(3, HIGH);
  }
  else
  digitalWrite(3, LOW);
  delay(1000);
  lcd.display();
  lcd.setCursor(0, 1);
  lcd.print(t);
}
