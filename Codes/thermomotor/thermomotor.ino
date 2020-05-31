/*       Termostato Motor DC      */
/*         Made by Karasu         */
/* https://github.com/XaviFortes/ */

float temp;
int tempPin = A1;
int tempMin = 0;
int tempMax = 50;
int engine = 11;
int engineSpeed = 0;
int buttonPin = 2;
int lledPin = 3;
int hledPin = 4;
int buttonState = 0;


void setup() {

pinMode(engine, OUTPUT);
pinMode(tempPin, INPUT);
pinMode(lledPin, OUTPUT);
pinMode(hledPin, OUTPUT);
pinMode(buttonPin, INPUT);

Serial.begin(9600);

}

void loop() {
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
  
temp = analogRead(tempPin);
temp = (temp *5.0*100.0)/1024.0;
Serial.print(temp);

delay(500);
if(temp < tempMin) {
  
engineSpeed = 0;
digitalWrite(engine, LOW);

}

if((temp >= tempMin) && (temp <= tempMax)) {

engineSpeed = (temp /50)*255;

analogWrite(engine, engineSpeed);
Serial.print(engineSpeed);

}
if(engineSpeed <= 127.5) {

  digitalWrite (lledPin, HIGH);
  Serial.print("Por debajo de la mitad");


} else {
  digitalWrite (lledPin, LOW);
  Serial.print("Apagado Low Led Pin");
}

if(engineSpeed >= 127.5) {

  digitalWrite (hledPin, HIGH);
  Serial.print("Por encima de la mitad");


} else {
  digitalWrite (hledPin, LOW);
  Serial.print("Apagado High Led Pin");
}
}
}
