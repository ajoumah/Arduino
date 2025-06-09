int piezoPin = 8;
int ldrPin = A0;
int threshold = 300;

void setup() {}

void beep(int duration) {
  tone(piezoPin, 1000);
  delay(duration);
  noTone(piezoPin);
  delay(100);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  if (ldrValue < threshold) {
    // Play SOS: ... --- ...
    for (int i = 0; i < 3; i++) beep(100); // S: ...
    delay(200);
    for (int i = 0; i < 3; i++) beep(300); // O: ---
    delay(200);
    for (int i = 0; i < 3; i++) beep(100); // S: ...
    delay(1000);
  }
}
