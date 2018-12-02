unsigned char ID = 0;

unsigned char redPin= 10;
unsigned char greenPin = 5;
unsigned char bluePin = 6;
char buttonpin = 12;

unsigned char indata;
boolean getcolor;
boolean state;

void setup() {
  Serial.begin (9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    indata = Serial.read();
     if (indata == ID){
    getcolor = 1;
   } 
  }
  if (Serial.available()>0 && getcolor == 1){
    
    }
}
