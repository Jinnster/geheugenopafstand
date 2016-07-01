#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
//#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch
char mychar;

int CS_PIN = 10;
File file;

//BUTTON
//#define buttonTOP A3
//#define buttonMID A4
//#define buttonBOT A5

const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 7;

//LED
const int ledBlue =  A0;      // the number of the LED pin
const int ledYellow =  A1;   
const int ledWhite =  A2;   

// Variables will change :
int ledState = LOW;   


int buttonState1 = 0; 
int buttonState2 = 0;
int buttonState3 = 0;


int var=0;
int var1=0;


void setup(){

pinMode(ledBlue, OUTPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledWhite, OUTPUT);

//  pinMode(buttonTOP, INPUT);
//  pinMode(buttonMID, INPUT);
//  pinMode(buttonBOT, INPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
    
  pinMode(CS_PIN, OUTPUT);
 SD.begin();
  

     tmrpcm.play("intro.wav"); 

  Serial.begin(9600);

  }

void loop(){  

    tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
    
  pinMode(CS_PIN, OUTPUT);
  
//  int buttonState1 = analogRead(buttonTOP);
//    int buttonState2 = analogRead(buttonMID);
//      int buttonState3 = analogRead(buttonBOT);
//
//        float voltage1 = buttonState1 ;
//          float voltage2 = buttonState3 ;
//            float voltage3 = buttonState3 ;

  buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
      buttonState3 = digitalRead(buttonPin3);

      if(buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == LOW){
        Serial.println("hi! button 1");
            analogWrite(ledBlue, 255);
        analogWrite(ledYellow, 0);
            analogWrite(ledWhite, 0);
    delay(250);

    SD.begin();
  

     tmrpcm.play("blauw.wav"); //the sound file "music" will play each time the arduino powers up, or is reset

      }


      
       else if (buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == LOW){
          Serial.println("hi! button 2");
          analogWrite(ledBlue, 0);
          analogWrite(ledYellow, 0);
          analogWrite(ledWhite, 0);
          
          
          SD.begin();

          tmrpcm.play("afspraak.wav"); //the sound file "music" will play each time the arduino powers up, or is reset

          
          
          delay(250);
    
       }
      else  if (buttonState1 == LOW && buttonState2 == LOW && buttonState3 == HIGH) {
        Serial.println("hi! button 3");
        analogWrite(ledBlue, 0);
        analogWrite(ledYellow, 0);

        delay(250);

        SD.begin();
  
     tmrpcm.play("rood.wav"); //the sound file "music" will play each time the arduino powers up, or is reset

analogWrite(ledWhite, 255);
            delay(1000);
                    analogWrite(ledWhite, 0);
            delay(1000);
                    analogWrite(ledWhite, 255);
                    delay(1000);
                    analogWrite(ledWhite, 0);
            delay(1000);
                    analogWrite(ledWhite, 255);
                                       delay(1000);
                    analogWrite(ledWhite, 0);
            delay(1000);
                    analogWrite(ledWhite, 255);
                                       delay(1000);
                    analogWrite(ledWhite, 0);
            delay(1000);
                    analogWrite(ledWhite, 255);
                                       delay(1000);
                    analogWrite(ledWhite, 0);
            delay(1000);
                    analogWrite(ledWhite, 255);
      }

  
}
//
//void initializeSD()
//
//{
//
//
//  if (SD.begin())
//  {
//    Serial.println("SD card is ready to use.");
//     tmrpcm.play("22hz.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
//     Serial.println("Afspelen....");
//  } else
//  {
//    Serial.println("SD card initialization failed");
//  }
//}


