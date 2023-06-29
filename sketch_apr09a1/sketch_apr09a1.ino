int ledpin = 10;
int inpin=4;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(inpin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inpin);
  if ( val == HIGH )
  {
    digitalWrite(ledpin, HIGH);
    
  }
  else {
    digitalWrite(ledpin, LOW);
  }

}
