int ledpin = 10;
int inpin=4;
int val;
boolean ledState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(inpin,INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while( digitalRead(inpin) == HIGH )();
  if ( ledState == HIGH )
  {
    digitalWrite(ledpin, HIGH);
    ledState = !ledState;
    
  }
  else 
  {
    digitalWrite(ledpin, LOW);
    ledState = !ledState;
  }

}
