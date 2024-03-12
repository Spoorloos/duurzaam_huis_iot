#include <ArduinoJson.h>

JsonDocument doc;
bool flicker_state = false;

void setup() {
  // Setup pins
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);

  // Setup serial
  Serial.begin(115200);
}

void loop() {
  // Get LDR value
  uint16_t ldr_value = analogRead(A0);

  // Save to json
  doc["ldr_value"] = ldr_value;
  serializeJson(doc, Serial);

  if (ldr_value < 500 || flicker_state) {
    // Toggle lights
    flicker_state = !flicker_state;

    digitalWrite(D6, flicker_state);
    digitalWrite(D5, flicker_state);
    digitalWrite(D3, flicker_state);

    // Wait 50ms
    delay(50);
  } else {
    // Wait half a second
    delay(500);
  }
}
