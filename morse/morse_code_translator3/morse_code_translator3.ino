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
  delay(30);                                     //wait for 100ms
  Serial.print(".");
}

void dash(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(90);                                     //on for 300ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(30);                                     //wait for 100ms
   Serial.print("-");
}
void putspace()
{
  delay(space);  

}

void send(String ch)
{
    int length = ch.length();
    for (int i = 0; i < length; i++)
    {
        if (ch.charAt(i) == '.')
        {
            dot();
        }
        else if (ch.charAt(i) == '-')
        {
            dash();
        }
    }
    delay(90); 
}




void translate(){                                 //translate characters to Morse Code
  switch(toLowerCase(i)){
    case 'a':    send(".-");    break; 
    case 'b':    send("-...");      break;
    case 'c':    send("-.-.");      break;
    case 'd':    send("-..");      break;
    case 'e':    send(".");      break;
    case 'f':    send("..-.");      break;
    case 'g':    send("--.");      break;
    case 'h':    send("....");      break;
    case 'i':    send("..");      break;
    case 'j':    send(".---");      break;
    case 'k':    send("-.-");      break;
    case 'l':    send(".-..");      break;
    case 'm':    send("--");      break;
    case 'n':    send("-.");      break;
    case 'o':    send("---");      break;
    case 'p':    send(".--.");      break;
    case 'q':    send("--.-");      break;
    case 'r':    send(".-.");      break;
    case 's':    send("...");      break;
    case 't':    send("-");      break;
    case 'u':    send("..-");      break;
    case 'v':    send("...-");      break;
    case 'w':    send(".--");      break;
    case 'x':    send("-..-");      break;
    case 'y':    send("-.--");      break;
    case 'z':    send("--..");      break;
    case '1':    send(".----");      break;
    case '2':    send("..---");      break;
    case '3':    send("...--");      break;
    case '4':    send("....-");      break;
    case '5':    send(".....");      break;
    case '6':    send("-....");      break;
    case '7':    send("--...");      break;
    case '8':    send("---..");      break;
    case '9':    send("----.");      break;
    case '0':    send("-----");      break;


 
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
