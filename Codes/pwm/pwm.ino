void setup() 
{
  int digPin = 6; 
  pinMode(digPin, OUTPUT);
}

void loop() {
   digitalWrite(digPin, HIGH);
   delay(250);
   digitalWrite(digPin, LOW); 
   delay(750);
}
