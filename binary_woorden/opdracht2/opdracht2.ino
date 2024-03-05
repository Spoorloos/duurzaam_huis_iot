void setup() {
  // Open serial monitor
  Serial.begin(115200);
}

void loop() {
  /*
  char h = 0b1101000;
  char a = 0b1100001;
  char l = 0b1101100;
  char o = 0b1101111;

  Serial.println(h);
  ...
  */

  // Print "hallo"
  char hallo[] = { 0b1101000, 0b1100001, 0b1101100, 0b1101100, 0b1101111 };

  Serial.println(hallo);
}
