/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
byte space = 150;     
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
}


void dot(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(50);                                     //on for 100ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(200);                                     //wait for 100ms
}

void dash(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(250);                                     //on for 300ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(200);                                     //wait for 100ms
}


// the loop function runs over and over again forever
void loop() {
    dot();                                      //do a dot
      delay(space);                               //wait
      dash();                                     //do a dash
      delay(space);                               //wait
}
