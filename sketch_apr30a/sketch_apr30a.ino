int ledPin  = 9;

int F = 2;
int Fs = 500;
int n = 500;
float t;
int si;
byte sample[500];
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  for (int n = 0; n<500; n++)
  {
    t = (float) n/Fs;
    sample[n] = (byte) (64.0* sin(2*3.14 * t) +64);
  }
  si = 1000000 /(F*n);
}


void loop() {
  // put your main code here, to run repeatedly:

  for( int fadeValue = 0; fadeValue <500; fadeValue ++) {
    analogWrite(ledPin, sample[fadeValue]);
//    Serial.println(sample[fadeValue]);
//    Serial.println(fadeValue);
    delay(10);
  }
   

}
