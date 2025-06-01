#include <OneWire.h>
#include <DallasTemperature.h>

// Constants
#define TEMP_BUS_PIN 3            // Data line connected to digital pin 3
#define READ_INTERVAL 1000        // Read interval in milliseconds
#define DEVICE_COUNT_EXPECTED 2   // Expected number of sensors

// OneWire and DallasTemperature setup
OneWire oneWireBus(TEMP_BUS_PIN);
DallasTemperature tempSensors(&oneWireBus);

// Device addresses
DeviceAddress sensorA, sensorB;

// Last temperatures for change detection
float lastTempSensorA = -127.0;
float lastTempSensorB = -127.0;

// Units toggle
bool displayInFahrenheit = false;

// Function Prototypes
void displaySensorAddress(DeviceAddress addr);
void displayTemperature(DeviceAddress addr, const char* name);
void readAndPrintTemperatures();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Initializing temperature monitoring system..."));

  tempSensors.begin();

  int foundDevices = tempSensors.getDeviceCount();
  Serial.print(F("Devices found: "));
  Serial.println(foundDevices);

  if (foundDevices < DEVICE_COUNT_EXPECTED) {
    Serial.println(F("WARNING: Less than expected number of devices found!"));
  }

  // Try to get addresses
  if (!tempSensors.getAddress(sensorA, 0)) {
    Serial.println(F("ERROR: Could not retrieve address for sensor 0"));
  } else {
    Serial.print(F("Sensor A Address: "));
    displaySensorAddress(sensorA);
    Serial.println();
  }

  if (!tempSensors.getAddress(sensorB, 1)) {
    Serial.println(F("ERROR: Could not retrieve address for sensor 1"));
  } else {
    Serial.print(F("Sensor B Address: "));
    displaySensorAddress(sensorB);
    Serial.println();
  }

  tempSensors.setResolution(sensorA, 12);
  tempSensors.setResolution(sensorB, 12);
  Serial.println(F("Setup complete.\n"));
}

void loop() {
  readAndPrintTemperatures();
  delay(READ_INTERVAL);
}

void readAndPrintTemperatures() {
  Serial.println(F("Requesting temperatures..."));
  tempSensors.requestTemperatures();

  float tempA = tempSensors.getTempC(sensorA);
  float tempB = tempSensors.getTempC(sensorB);

  // Check and print only if changed
  if (tempA != lastTempSensorA) {
    displayTemperature(sensorA, "Sensor A");
    lastTempSensorA = tempA;
  }

  if (tempB != lastTempSensorB) {
    displayTemperature(sensorB, "Sensor B");
    lastTempSensorB = tempB;
  }

  Serial.println();
}

void displaySensorAddress(DeviceAddress addr) {
  for (uint8_t i = 0; i < 8; i++) {
    if (addr[i] < 16) Serial.print("0");
    Serial.print(addr[i], HEX);
    if (i < 7) Serial.print(":");
  }
}

void displayTemperature(DeviceAddress addr, const char* name) {
  float celsius = tempSensors.getTempC(addr);
  float fahrenheit = DallasTemperature::toFahrenheit(celsius);

  Serial.print(name);
  Serial.print(" - ");

  if (celsius == DEVICE_DISCONNECTED_C) {
    Serial.println(F("Temperature sensor not connected."));
    return;
  }

  Serial.print("Temperature: ");
  if (displayInFahrenheit) {
    Serial.print(fahrenheit, 2);
    Serial.println(" °F");
  } else {
    Serial.print(celsius, 2);
    Serial.println(" °C");
  }
}
