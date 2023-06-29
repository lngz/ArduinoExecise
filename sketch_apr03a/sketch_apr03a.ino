int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // val = Serial.read();
  // if(val == 'F')
  // {
    digitalWrite(13, LOW);
    delay(500);
   
    Serial.println("Hello the world");
    
  // }
}
