int ledpin = 2;
int buttonpin = 3;
boolean state = 0;

void setup()
{
  pinMode(ledpin, OUTPUT);
 }

void loop()
{
  state = digitalRead(buttonpin);
    
  if(state == 1){
    digitalWrite(ledpin, HIGH);
  }else {
    digitalWrite(ledpin, LOW);
  }
}
