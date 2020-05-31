/*      Termostato Servomotor     */
/*         Made by Karasu         */
/* https://github.com/XaviFortes/ */

float temp;
int tempPin = A1;
int tempMin = 25;
int tempMax = 70;
int fan = 11;
int fanSpeed = 0;
int buttonPin = 2;
int lledPin = 3;
int hledPin = 4;
int buttonState = 0;


void setup() {

pinMode(fan, OUTPUT);
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
  
fanSpeed = 0;
digitalWrite(fan, LOW);

}

if((temp >= tempMin) && (temp <= tempMax)) {

fanSpeed = map(temp, tempMin, tempMax, 32, 255); 

analogWrite(fan, fanSpeed);
Serial.print(fanSpeed);

}
if(fanSpeed <= 127.5) {

  digitalWrite (lledPin, HIGH);
  Serial.print("Por debajo de la mitad");


} else {
  digitalWrite (lledPin, LOW);
  Serial.print("Apagado Low Led Pin");
}

if(fanSpeed >= 127.5) {

  digitalWrite (hledPin, HIGH);
  Serial.print("Por encima de la mitad");


} else {
  digitalWrite (hledPin, LOW);
  Serial.print("Apagado High Led Pin");
}
}
}
