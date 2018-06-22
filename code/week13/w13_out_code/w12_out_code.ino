int inPin1 = 2;
int inPin2 = 1;
int redPin= 0;
int greenPin = 4;
int bluePin = 3;
int state = 0;

void setup() {
  pinMode (inPin1, INPUT_PULLUP);
  digitalWrite (inPin1, LOW);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  state = digitalRead(inPin1);
  
  if (state == HIGH){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  }
  else {
    digitalWrite (redPin, LOW);
    digitalWrite (greenPin, LOW);
    digitalWrite (bluePin, LOW);
    }
}
