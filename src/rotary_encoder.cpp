
#include "rotary_encoder.h"
#include <WInterrupts.h>
#include <wiring_digital.h>
#include <libprintf.h>
#include <wiring_constants.h>
#include <Arduino.h>
#include "global.h"

// RotaryEncoder::RotaryEncoder(&input)
RotaryEncoder::RotaryEncoder(void)
{
}
// void RotaryEncoder::initialize(void)
//  {
//   attachInterrupt(digitalPinToInterrupt(interruptA), RotateStateChanged, FALLING);
//   // attachInterrupt(interruptB, buttonState, FALLING);

//   pinMode(CLK, INPUT);
//   digitalWrite(CLK, HIGH);  // Pull High Restance 
//   pinMode(DAT, INPUT);
//   digitalWrite(DAT, HIGH);  // Pull High Restance
//   pinMode(BUTTON, INPUT);
//   digitalWrite(BUTTON, HIGH);  // Pull High Restance
//   printf("RotaryEncoder.Initialize\n");
//  }


void RotaryEncoder::run(void)
{
  if  (!(digitalRead(BUTTON)))
    {
    //  rotary_encoder_pos = 0; 
     printf("%lu Button\n", millis());
     printf("%i \n", rotary_encoder_pos);
    //  digitalWrite(LED1, LOW);
    //  digitalWrite(LED2, LOW);
    //  delay (2000);
    }
    //  printf("Count= %d\n",rotary_encoder_pos); 
    //  printf("%lu Not Button\n", millis());
    //  printf("%i \n", rotary_encoder_pos);

}

// void RotateStateChanged() //When CLK  FALLING READ DAT
// {
// int DAT = 4;     // PIN4
// printf("in RotateStateChanged\n");
//  if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
//    {
//     rotary_encoder_pos++;
//     printf("RotateStateChanged Up %d \n", rotary_encoder_pos);
//     // digitalWrite(LED1, HIGH);
//     // digitalWrite(LED2, LOW);
//     // delay(20);
//    }
//  else                   // When DAT = LOW IS BackRote
//    {
//     rotary_encoder_pos--;
//     printf("RotateStateChanged Down %d \n", rotary_encoder_pos);
//     // digitalWrite(LED2, HIGH);
//     // digitalWrite(LED1, LOW);
//     // delay(20);
//    }
// }



//-------------------------------------------
// void RotateStateChanged() //When CLK  FALLING READ DAT
// {


// int DAT = 3;     // PIN3


//  if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
//    {
//     rotary_encoder_pos++;
//     // digitalWrite(LED1, HIGH);
//     // digitalWrite(LED2, LOW);
//     // delay(20);
//    }
//  else                   // When DAT = LOW IS BackRote
//    {
//     rotary_encoder_pos--;
//     // digitalWrite(LED2, HIGH);
//     // digitalWrite(LED1, LOW);
//     // delay(20);
//    }
// }


//original code from KS0013
// const int interruptA = 0;       
// const int interruptB = 1;       
// int CLK = 2;     // PIN2
// int DAT = 3;     // PIN3
// int BUTTON = 4;  // PIN4
// int LED1 = 5;    // PIN5
// int LED2 = 6;    // PIN6
// int COUNT = 0;

// void setup() 
//  {
//   attachInterrupt(interruptA, RoteStateChanged, FALLING);
//  // attachInterrupt(interruptB, buttonState, FALLING);
//   pinMode(CLK, INPUT); 
//   digitalWrite(2, HIGH);  // Pull High Restance  
//   pinMode(DAT, INPUT); 
//   digitalWrite(3, HIGH);  // Pull High Restance 
 
// pinMode(BUTTON, INPUT); 
//   digitalWrite(4, HIGH);  // Pull High Restance
//   pinMode(LED1, OUTPUT); 
//   pinMode(LED2, OUTPUT); 
//    Serial.begin(9600);
//  }


// void loop() 
// {
//   if  (!(digitalRead(BUTTON))) 
//     {
//      COUNT = 0;  
//      Serial.println("STOP COUNT = 0");
//      digitalWrite(LED1, LOW);
//      digitalWrite(LED2, LOW);
//      delay (2000);
//     }
//      Serial.println(COUNT);  
// }

// //-------------------------------------------
// void RoteStateChanged() //When CLK  FALLING READ DAT
// {
//  if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
//    {
//     COUNT++;
//     digitalWrite(LED1, HIGH);
//     digitalWrite(LED2, LOW);
//     delay(20);
//    }
//  else                   // When DAT = LOW IS BackRote
//    {
//     COUNT--;
//     digitalWrite(LED2, HIGH);
//     digitalWrite(LED1, LOW);
//     delay(20);
//    }
// }