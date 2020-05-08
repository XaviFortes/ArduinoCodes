/*     Codigo por Xavi Fortes     */
/*           aka Karasu           */
/* https://github.com/XaviFortes/ */

const int pinSensor = 2;
const int pinMotor =  13;
int valorSensor = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);
  pinMode(pinMotor, OUTPUT);
}
void loop() {
  valorSensor = digitalRead(pinSensor);
  if (valorSensor == HIGH) {
    digitalWrite(pinMotor, HIGH);
    delay(4000);
  } else {
    digitalWrite(pinMotor, LOW);
  }
}
