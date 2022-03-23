
const int led1 = 3;
const int led2 = 5;
const int led3 = 6;
const int pot1 = 0;
const int pot2 = 1;
const int pot3 = 2;
int brillo1;
int brillo2;
int brillo3;

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() 
{
   brillo1 = analogRead(pot1) / 4;
   brillo2 = analogRead(pot2) / 4;
   brillo3 = analogRead(pot3) / 4;
   analogWrite(led1, brillo1);
   analogWrite(led2, brillo2);
   analogWrite(led3, brillo3);
}
