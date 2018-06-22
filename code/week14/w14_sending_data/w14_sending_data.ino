int data1 = 0;
int data2 = 2;

void setup(){
Serial.begin(9600);
}

void loop(){
Serial.print(data1);
  delay(2000);
Serial.print(data2);
  delay(2000);
}
