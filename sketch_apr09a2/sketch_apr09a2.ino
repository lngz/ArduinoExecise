int ledpin = 10;
int inpin=4;
int val;
boolean ledState = false;
unsigned char count = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(inpin,INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
  unsigned char temp = count;
  for (int i =6 ; i<=13; i=i+1) 
  {

    ledState = temp % 2;
     
    temp /= 2;
    
    if ( ledState == 1 )
    {
      digitalWrite(i, HIGH);
    }
    else 
    {
      digitalWrite(i, LOW);
    }

  }
  delay(250);
   while( digitalRead(inpin) == HIGH ){};
  count += 1;
  
}
