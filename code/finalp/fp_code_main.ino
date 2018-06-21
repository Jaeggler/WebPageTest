char colormix[3] = {'1','2','3'}; //1 to red, 2 to green, 3 to blue.
char secuence[6];
int seccount = 0;

int printdelay = 1750;

int buttonpin = 12;
int state;

String readstr; //string variable to store incoming string
char instring[1]; //char array to store incoming string

void setup()
{
  Serial.begin(9600);
	pinMode(buttonpin, INPUT_PULLUP);
}

void loop()
{
  state = digitalRead(buttonpin);

  if (state == 0){
    startsec();
    delay(1000);
    createsec();
    delay(100);
	printsec();
    delay(1000);
    shuffler(); //Shuflea los colores de colormix.
    delay(100);
	printshuffle();
    delay(1000);
  }//end if

  if (Serial.available()>0){
  	readstr = Serial.readString();
    readstr.toCharArray(instring,2);
    Serial.print(String(instring[0]));
    delay(100);
    Serial.print(String(instring[1]));
    delay(100);
    if (instring[1] == secuence[seccount]){
    	offsec(instring[0]);
      seccount = seccount + 1;
      Serial.print(String(instring[0]));
      if(seccount == 2){
      	seccount = 0;
      }//end if
    }//end if
  }//end if

}//end loop

void startsec(){
    Serial.print(String('G'));
    delay(100);
}

void offsec(char ledID){
    Serial.print(String(String('F')+String(ledID)));
    delay(100);
}

void createsec(){
	secuence[0]='2'; //deberia ser random pero solo para presentacion
   	secuence[1]='1'; //deberia ser random pero solo para presentacion
   	secuence[2]='3'; //deberia ser random pero solo para presentacion

}

void printsec(){
  Serial.print(String(String(String('E')+String('0')+String(secuence[0]))));
  delay(printdelay);
  Serial.print(String(String(String('E')+String('1')+String(secuence[1]))));
  delay(printdelay);
  Serial.print(String(String(String('E')+String('2')+String(secuence[2]))));
  delay(printdelay);
}

void shuffler(){ //Comando para mixear el array colormix
  for (int i = 0; i <= 2; i++){
    int pos1 = random(3);
    int pos2 = random(3);
    char newchar1 = colormix[pos1];
    char newchar2 = colormix[pos2];
    colormix[pos1] = newchar2;
    colormix[pos2] = newchar1;
  }
}

void printshuffle(){
  Serial.print(String(String('O')+String('0')+String(colormix[0])));
  delay(printdelay);
  Serial.print(String(String('O')+String('1')+String(colormix[1])));
  delay(printdelay);
  Serial.print(String(String('O')+String('2')+String(colormix[2])));
  delay(printdelay);
}
