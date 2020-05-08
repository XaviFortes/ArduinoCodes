/*     Codigo por Xavi Fortes     */
/*           aka Karasu           */
/* https://github.com/XaviFortes/ */

const int pinboton = 2;
const int pinled =  13;
int valorPulsador = 0;
void setup() {
  pinMode(pinboton, OUTPUT);
  pinMode(pinboton, INPUT);
}
void loop() {
  valorPulsador = digitalRead(pinboton);
  if (valorPulsador == HIGH) {
    digitalWrite(pinboton, HIGH);
    delay(5000);
  } else {
    digitalWrite(pinled, LOW);
  }
}
