const int piezoBuzzerPin = 6;      // New pin for piezo
const int lightSensorPin = A1;     // LDR connected to analog pin A1
const int darkThreshold = 500;     // Below this is considered "dark"

int sensorValue = 0;               // Raw reading from LDR
int minLight = 1023;               // Initial high for calibration
int maxLight = 0;                  // Initial low for calibration

unsigned long lastBeepTime = 0;
unsigned long beepInterval = 500;  // Time between tones

void setup() {
  pinMode(piezoBuzzerPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Calibrating LDR...");
  // Calibrate LDR for 3 seconds to learn ambient range
  for (int i = 0; i < 300; i++) {
    sensorValue = analogRead(lightSensorPin);
    if (sensorValue < minLight) minLight = sensorValue;
    if (sensorValue > maxLight) maxLight = sensorValue;
    delay(10);
  }

  Serial.print("Calibration complete. Min: ");
  Serial.print(minLight);
  Serial.print(" | Max: ");
  Serial.println(maxLight);
}

void loop() {
  sensorValue = analogRead(lightSensorPin);
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);

  if (sensorValue < darkThreshold) {
    // It's dark, map the light level to a frequency range
    int toneFrequency = map(sensorValue, minLight, darkThreshold, 1000, 300);
    toneFrequency = constrain(toneFrequency, 300, 1000);

    tone(piezoBuzzerPin, toneFrequency);
    Serial.print("Playing tone at ");
    Serial.print(toneFrequency);
    Serial.println(" Hz");

    delay(200);
    noTone(piezoBuzzerPin);
    delay(200);
  } else {
    // It's bright enough, no tone
    noTone(piezoBuzzerPin);
  }

  delay(100); // Adjust loop speed
}
