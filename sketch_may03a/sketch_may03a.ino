int ledPin  = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  byte sample = (byte) sensorValue/1024*127;
  Serial.println(sensorValue);
  analogWrite(ledPin, sensorValue/4);
  delay(100);
}
