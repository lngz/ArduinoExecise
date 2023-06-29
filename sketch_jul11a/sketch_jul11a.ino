int ledPin  = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = checkloop();
  
  Serial.println(sensorValue);
  
}
int checkloop() {
  
  int Time1 = millis();
  int Time2 = 0;
  int i = 0;
  
  int imax = analogRead(A0);;
  int imin = analogRead(A0);;
  while( i< 15){
    int sensorValue = analogRead(A0);
    if (sensorValue > imax)
      imax = sensorValue;
    if (sensorValue < imin)
      imin = sensorValue;
    Time2 = millis();
    i = Time2 - Time1;
  }
  int sound = imax - imin ;
//  Serial.println(sound);
 
  return sound;
  
  
}
