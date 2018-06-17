const int ID = 2; //set ID to this board
int redPin= 7;  //pin number for red leg of RGB
int greenPin = 5; //pin number for green leg of RGB
int bluePin = 6; //pin number for blue leg of RGB
int inbit;

void setup() {
  Serial.begin (9600); //open serial comm
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  if (Serial.available()>0){
    inbit = Serial.read();
    inbit = inbit-48;
    Serial.print(inbit);
  }
  if (inbit == ID){ 
    setColor(255, 0, 0); // Red Color
    delay(500);
    setColor(0, 255, 0); // Green Color
    delay(500);
    setColor(170, 0, 255); // Purple Color
    delay(500);
    setColor(0, 0, 0); // off
    delay(500);
    inbit = 0;
  }
}

void setColor(int redValue, int greenValue, int blueValue) {  //function for set color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
