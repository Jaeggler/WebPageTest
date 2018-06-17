int buttonpin = 12; //pin number for button input
int state;  //storage for pin current status

void setup()
{
  Serial.begin(9600);
	pinMode(buttonpin, INPUT_PULLUP);  //activate, pin internal PULLUP resistor
}

void loop()
{
  state = digitalRead(buttonpin);

  if (state == 0){
  Serial.write('1');
  delay (2000);
  Serial.write('2');
  delay (2000);
  }
}
