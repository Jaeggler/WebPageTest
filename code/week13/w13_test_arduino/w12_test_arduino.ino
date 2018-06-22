char data;
int led1 = 10;
int led2 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
 
if (Serial.available() > 0){
  data = Serial.read();
}

if (data == 49){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  }

 if (data == 50){
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  }
}
