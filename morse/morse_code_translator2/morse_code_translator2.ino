/*
 * Morse Code Translator
 * Takes serial input & translates it
 * into Morse Code which is then sent
 * to a buzzer & LED
 * 
 * 
 * by learnelectronics
 * 15 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * 
 * NOTE: INPUT MUST BE IN CAPS
 */

//-------------------------------------------------------------------------------------------------
//                                           LIBRARIES
//-------------------------------------------------------------------------------------------------

//NO LIBRARIES NECESSARY

//-------------------------------------------------------------------------------------------------
//                                            DEFINES
//-------------------------------------------------------------------------------------------------

//NO DEFINES NECESSARY

//-------------------------------------------------------------------------------------------------
//                                           VARIABLES
//-------------------------------------------------------------------------------------------------

String mCode = "";                                //string to store serial inut
byte mCodeLength = 0;                             //byte to store length of mCode
byte space = 150;                                 //delay for spacing
char i;                                           //char for parsing of mCode



//-------------------------------------------------------------------------------------------------
//                                             SETUP
//-------------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);                             //start serial comms for debuging
  pinMode(6,OUTPUT);                              //pin 6 (buzzer) set for OUTPUT
  pinMode(12,OUTPUT);                             //pin 12 (LED) set for OUTPUT
}

//-------------------------------------------------------------------------------------------------
//                                          FUNCTIONS
//-------------------------------------------------------------------------------------------------

void dot(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(30);                                     //on for 100ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(100);                                     //wait for 100ms
  Serial.print(".");
}

void dash(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(100);                                     //on for 300ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(100);                                     //wait for 100ms
   Serial.print("-");
}
void putspace()
{
  delay(space);  

}





void translate(){                                 //translate characters to Morse Code
  switch(i){
    case 'a':   
    case 'A':                                     //if it is A
      dot();                                      //do a dot
      delay(space);                               //wait
      dash();                                     //do a dash
      delay(space);                               //wait
    break; 
    case 'b':
    case 'B':
      dash();
      dot();
      delay(space);
      dot();
      delay(space);
      dot();
      delay(space);
     break;
    
     case 'c':
     case 'C':
       dash();
      delay(space);
       dot();
      delay(space);
       dash();
      delay(space);
      dot();
      delay(space);
     break;
     
     case 'd':
     case 'D':
       dash();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
     break;
   
     case 'e':
     case 'E':
       dot();
       delay(space);
     break;
     
     case 'f':
     case 'F':
       dot();
       delay(space);
       dot();
       delay(space);
       dash();
       delay(space);
     break;
     
     case 'g':
     case 'G':
       dash();
       delay(space);
       dash();
       delay(space);
       dot();
       delay(space);
      break;
     
      case 'h':
      case 'H':
       dot();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      
      case 'i':
      case 'I':
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      
      case 'j':
      case 'J':
       dot();
       delay(space);
       dash();
       delay(space);
       dash();
       delay(space);
       dash();
       delay(space);
      break;
 
      case 'k':
      case 'K':
       dash();
       delay(space);
       dot();
       delay(space);
       dash();
       delay(space);
      break;
      case 'l':
      case 'L':
       dot();
       delay(space);
       dash();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      case 'm':
      case 'M':
       dash();
       delay(space);
       dash();
       delay(space);
       break;
      case 'n':
       case 'N':
        dash();
        delay(space);
        dot();
        delay(space);
       break;
      case 'o':
       case 'O':
        dash();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
      case 'p':
       case 'P':
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
       break;
      case 'q':
       case 'Q':
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
      case 'r':
       case 'R':
        dot();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
       break;
      case 's':
       case 'S':
        dot();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
       break;
      case 't':
       case 'T':
        dash();
        delay(space);
       break;
      case 'u':
       case 'U':
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
      case 'v':
       case 'V':
        dot();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
      case 'w':
       case 'W':
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
      case 'x':
       case 'X':
        dash();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
      case 'y':
       case 'Y':
        dash();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
      case 'z':
       case 'Z':
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
       break;
       default:
         putspace();
       break;
   
  }
   Serial.print(" ");
}

void doString(){                                  //parse the string
  mCodeLength = mCode.length();                   //get the length of the string
  for(int x = 0;x<=mCodeLength;x++){              //repeat until reach end of string
    i = mCode.charAt(x);                          //get character at pos x
    translate();                                  //translate character to Morse Code
  }
}
//-------------------------------------------------------------------------------------------------
//                                              LOOP
//-------------------------------------------------------------------------------------------------

void loop() {
 while (Serial.available()) {                     //when something comes through serial
    char inChar = (char)Serial.read();            //get the new byte
    mCode += inChar;                              // add it to mCode
    if (inChar == '\n') {                         //if receive as CR
      Serial.println(mCode);
      doString();                                 //process the string
  }
                                       
 }
   delay(1000);                                    //delay between strings
   mCode = "";                                     //reset string
}
