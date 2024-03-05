// Morse code
#define DOT true
#define LINE false

void toggle_all(const bool state) {
  digitalWrite(D6, state);
  digitalWrite(D5, state);
  digitalWrite(D3, state);
}

void morse(const bool unit) {
  toggle_all(HIGH);
  delay(unit == DOT ? 100 : 500);
  toggle_all(LOW);
  delay(100);
}

// Program
void setup() {
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  // M
  morse(LINE);
  morse(LINE);
  delay(1000);

  // I
  morse(DOT);
  morse(DOT);
  delay(1000);

  // C
  morse(LINE);
  morse(DOT);
  morse(LINE);
  morse(DOT);
  delay(1000);

  // K
  morse(LINE);
  morse(DOT);
  morse(LINE);
  delay(5000);
}
