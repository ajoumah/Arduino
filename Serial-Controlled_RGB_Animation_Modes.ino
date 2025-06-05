char serialBuffer[32];
int redValue, greenValue, blueValue;
int pinRed = 11;
int pinGreen = 10;
int pinBlue = 9;

String currentMode = "off";
unsigned long lastUpdate = 0;
int animationStep = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  Serial.println("Enter a command (e.g., mode rainbow, mode police, set 255,100,50)");
}

void loop() {
  readSerialCommands();
  handleCurrentMode();
}

void readSerialCommands() {
  if (Serial.available()) {
    delay(50);
    int len = Serial.readBytesUntil('\n', serialBuffer, sizeof(serialBuffer) - 1);
    serialBuffer[len] = '\0';

    String input = String(serialBuffer);
    input.trim();

    if (input.startsWith("mode ")) {
      currentMode = input.substring(5);
      Serial.print("Mode set to: ");
      Serial.println(currentMode);
    } else if (input.startsWith("set ")) {
      int r, g, b;
      sscanf(input.c_str(), "set %d,%d,%d", &r, &g, &b);
      redValue = constrain(r, 0, 255);
      greenValue = constrain(g, 0, 255);
      blueValue = constrain(b, 0, 255);
      analogWrite(pinRed, redValue);
      analogWrite(pinGreen, greenValue);
      analogWrite(pinBlue, blueValue);
      currentMode = "static";
      Serial.println("Color set manually.");
    }
  }
}

void handleCurrentMode() {
  unsigned long now = millis();
  if (now - lastUpdate < 100) return;
  lastUpdate = now;

  if (currentMode == "rainbow") {
    redValue = (sin(animationStep * 0.1) * 127) + 128;
    greenValue = (sin(animationStep * 0.1 + 2) * 127) + 128;
    blueValue = (sin(animationStep * 0.1 + 4) * 127) + 128;
    applyRGB();
    animationStep++;
  }

  else if (currentMode == "police") {
    if ((animationStep / 5) % 2 == 0) {
      analogWrite(pinRed, 255);
      analogWrite(pinBlue, 0);
    } else {
      analogWrite(pinRed, 0);
      analogWrite(pinBlue, 255);
    }
    analogWrite(pinGreen, 0);
    animationStep++;
  }

  else if (currentMode == "calm") {
    int breathe = (sin(animationStep * 0.05) * 127) + 128;
    analogWrite(pinRed, 0);
    analogWrite(pinGreen, breathe / 2);
    analogWrite(pinBlue, breathe);
    animationStep++;
  }

  else if (currentMode == "static") {
    // static color already applied
  }

  else {
    analogWrite(pinRed, 0);
    analogWrite(pinGreen, 0);
    analogWrite(pinBlue, 0);
  }
}

void applyRGB() {
  analogWrite(pinRed, redValue);
  analogWrite(pinGreen, greenValue);
  analogWrite(pinBlue, blueValue);
}
