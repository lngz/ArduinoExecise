int ledpin = 10;
int inpin=4;
int val;
boolean ledState = false;
unsigned char = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(inpin,INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while( digitalRead(inpin) == HIGH ){};
  if ( ledState == HIGH )
  {
    digitalWrite(ledpin, HIGH);
    ledState = !ledState;
    delay(500);
    
  }
  else 
  {
    digitalWrite(ledpin, LOW);
    ledState = !ledState;
    delay(500);
  }

}
