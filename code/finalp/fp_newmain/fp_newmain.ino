unsigned char ID0 = 0;
unsigned char ID1 = 1;
unsigned char ID2 = 2;
unsigned char redPin= 10;
unsigned char greenPin = 5;
unsigned char bluePin = 6;
unsigned char buttonpin = 12;
boolean state;
boolean start;
unsigned char rannum1;
unsigned char rannum2;
unsigned char rannum3;

void setup() {
  Serial.begin (9600);
}

void loop() {
  state = digitalRead(buttonpin);
  if (digitalRead(buttonpin) == 1){
    start = 1;
    char rannum1 = random(3);
    char rannum2 = random(3);
    char rannum3 = random(3);
    }
  if (start == 1){
    Serial.print(ID0);
    delay(100);
    Serial.print(rannum1);
    delay(100);
    Serial.print(ID1);
    delay(100);
    Serial.print(rannum2);
    delay(100);
    Serial.print(ID2);
    delay(100);
    Serial.print(rannum3);
    delay(100);
   start == 0;
    }
}
