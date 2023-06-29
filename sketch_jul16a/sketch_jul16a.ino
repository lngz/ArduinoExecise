/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press
 */

// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 7; // the number of the pushbutton pin
const int SHORT_PRESS_TIME = 130; // 1000 milliseconds
const int LONG_PRESS_TIME  = 150; // 1000 milliseconds

// Variables will change:
int lastState = HIGH;  // the previous state from the input pin
int currentState = HIGH;     // the current reading from the input pin
int idleState = 1;
int speaker = LOW;
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;
unsigned long idleTime = 0;
int printed = 0;
String mCode="";

void setup() {
  Serial.begin(9600);
//  pinMode(BUTTON_PIN, INPUT_PULLUP);
//  pinMode(6,OUTPUT);
}

void loop() {
  // read the state of the switch/button:
//  currentState = digitalRead(BUTTON_PIN);
  currentState = checkvoice();
//  Serial.println(currentState);
  if(lastState == HIGH && currentState == LOW)        // button is pressed
  { 
    pressedTime = millis();
    printed = 0;
//    Serial.println(pressedTime);
    if (idleState == 1)
    {
      
      mCode = "";
      idleState = 0;
    }
  }
  else if(lastState == LOW && currentState == HIGH) { // button is released
    releasedTime = millis();
    printed = 0;
//    Serial.println(releasedTime);
    long pressDuration = releasedTime - pressedTime;
//    Serial.println(pressDuration);
    if( pressDuration < SHORT_PRESS_TIME )
    {  //Serial.print(".");
      mCode += ".";
    }else if( pressDuration > LONG_PRESS_TIME )
    {  //Serial.print("-");
      mCode += "-";
    } 
  }
  else if(lastState == HIGH && currentState == HIGH)
  {
    idleTime = millis();
    long idleDuration = idleTime - releasedTime ;
//    Serial.println( idleDuration);
    if( idleDuration > 2 * SHORT_PRESS_TIME ){
      idleState = 1;
      if (printed != 1){
//        Serial.println(mCode);
        String  c = translate(mCode);
        Serial.print(c);
        printed = 1;
      }
    }
    else {
      printed = 0;
      idleState = 0;
    }
    
  }
//  if (currentState == LOW)
//    speaker = HIGH;
//  else 
//    speaker = LOW;
//  digitalWrite(6,speaker);
  // save the the last state
  lastState = currentState;
  delay(10);
}


int checkvoice() {
  
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
 
  if (sound >4)
    return LOW ;
  else
    return HIGH;
  
  
}

String translate( String mCode ){                                 //translate characters to Morse Code
  
    if(mCode == ".-")     return "a";  
    if(mCode == "-...")   return "b";     
    if(mCode == "-.-.")   return "c";     
    if(mCode == "-..")    return "d";    
    if(mCode == ".")      return "e";  
    if(mCode == "..-.")   return "f";     
    if(mCode == "--.")    return "g";    
    if(mCode == "....")   return "h";     
    if(mCode == "..")     return "i";   
    if(mCode == ".---")   return "j";     
    if(mCode == "-.-")    return "k";    
    if(mCode == ".-..")   return "l";     
    if(mCode == "--")     return "m";   
    if(mCode == "-.")     return "n";   
    if(mCode == "---")    return "o";    
    if(mCode == ".--.")   return "p";     
    if(mCode == "--.-")   return "q";     
    if(mCode == ".-.")    return "r";    
    if(mCode == "...")    return "s";    
    if(mCode == "-")      return "t";  
    if(mCode == "..-")    return "u";    
    if(mCode == "...-")   return "v";     
    if(mCode == ".--")    return "w";    
    if(mCode == "-..-")   return "x";     
    if(mCode == "-.--")   return "y";     
    if(mCode == "--..")   return "z";     
    if(mCode == ".----")  return "1";      
    if(mCode == "..---")  return "2";      
    if(mCode == "...--")  return "3";      
    if(mCode == "....-")  return "4";      
    if(mCode == ".....")  return "5";      
    if(mCode == "-....")  return "6";      
    if(mCode == "--...")  return "7";      
    if(mCode == "---..")  return "8";      
    if(mCode == "----.")  return "9";      
    if(mCode == "-----")  return "0";      
    return "unknow";
   
   
  
 
}
