// This program allows the Spark to act as a relay
// between a terminal program on a PC and the
// Fingerprint sensor connected to RX/TX (Serial1)
// on the Spark

void setup() {
  // initialize both serial ports:
  Serial.begin(57600);
  Serial1.begin(57600);
}

void loop() {
  // read from Serial1 (Fingerprint reader), send to Serial (USB to PC)
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from Serial (USB to PC), send to Serial1 (Fingerprint reader)
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}