void setup() {
  pinMode (3, OUTPUT);

  pinMode (A0, INPUT);
}

void loop() {

  Serial.println  (A0);

  int potValue = analogRead (A0);

  digitalWrite (3, HIGH);

  delay (potValue);

  digitalWrite (3, LOW);

  delay (potValue);
}
