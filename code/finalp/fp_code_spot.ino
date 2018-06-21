char ID = '0';
int opbyte = 0; //byte de operacion. 'G' start, 'E' Secuencia, 'O' Solido
int idbyte = 1; //byte de identificacion.
int colorbyte = 2; //byte de color.
char buttoncolor;

int buttonpin = 12;
int state;

String readstr; //string variable to store incoming string
char instring[7]; //char array to store incoming string

int redPin= 10;
int greenPin = 5;
int bluePin = 6;

void setup() {
  Serial.begin (9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
}

void loop() {
  state = digitalRead(buttonpin);
  if (Serial.available()>0){

    readstr = Serial.readString();
    readstr.toCharArray(instring,7);

    if (instring[opbyte] == 'G'){
		startlight();
 	}//end if

    else if (instring[opbyte] == 'F'){
      if (instring[idbyte] == ID){
      offlight();
      }//end if
 	}//end else if

    else if (instring[opbyte] == 'E'){
      if (instring[idbyte] == ID){
        seclight(colorbyte);
            }//end if
      }//end else if

    else if (instring[opbyte] == 'O'){
      if (instring[idbyte] == ID){
        buttonlight(colorbyte);
            }//end if
      }//end else if

    else {
    	reset();
    }//end else

    }//end if available

  if (state == 0){ //Condicional de presionar el boton
  	Serial.print(String(String(ID)+String(buttoncolor)));
    delay(100);
  }//end if

}//end loop

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void startlight (){
  	setColor(255,255,255);
    delay(200);
    setColor(0,0,0);
    delay(200);
    setColor(255,255,255);
    delay(200);
    setColor(0,0,0);
    delay(200);
}

void offlight (){
    setColor(0,0,0);
    delay(100);
}

void seclight (int spotn){
  switch (instring[spotn]){
    case '1':
    setColor(255,0,0);
    delay(100);
    setColor(0,0,0);
    break;
    case '2':
    setColor(0,255,0);
    delay(100);
    setColor(0,0,0);
    break;
    case '3':
    setColor(0,0,255);
    delay(100);
    setColor(0,0,0);
    break;}
}

void buttonlight (int spotn){
  switch (instring[spotn]){
    case '1':
    setColor(255,0,0);
    delay(100);
    buttoncolor = '1';
    break;
    case '2':
    setColor(0,255,0);
    delay(100);
    buttoncolor = '2';
    break;
    case '3':
    setColor(0,0,255);
    delay(100);
    buttoncolor = '3';
    break;}
}

void reset() {
	instring[0] = '9';
    instring[1] = '9';
    instring[2] = '9';
}
