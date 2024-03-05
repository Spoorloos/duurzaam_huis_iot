void setup() {
  // Begin serial monitor
  Serial.begin(115200);
    
  // Setup pins
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  // Get random integers
  uint16_t a = random(999),
           b = random(999),
           c = random(999),
           d = random(999);

  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);

  if (d > a && d > b && d > c) {
    for (uint8_t i = 0; i < 100; i++) {
      // Toggle the lights
      bool state = (i & 1) ? HIGH : LOW;
      
      digitalWrite(D6, state);
      digitalWrite(D5, state);
      digitalWrite(D3, state);

      // Sleep for 1/10th of a second, which makes up for the 10 seconds
      delay(100);
    }
  } else {
    // Toggle the lights
    digitalWrite(D6, (a > b || a < c) ? HIGH : LOW);
    digitalWrite(D5, (c > a && a < b) ? HIGH : LOW);
    digitalWrite(D3, (b > c && b > a && c < a) ? HIGH : LOW);

    // Sleep for 10 seconds
    delay(10000);
  }
  
}
