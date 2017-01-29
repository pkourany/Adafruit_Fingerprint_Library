// This program allows the Particle device to act as a relay
// between a terminal program on a PC and the
// Fingerprint sensor connected to RX/TX (Serial1)
// on the Particle

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  Serial1.begin(57600);

}

void loop() // run over and over
{
  while (Serial1.available())
    Serial.write(Serial1.read());

  while (Serial.available())
    Serial1.write(Serial.read());
}
