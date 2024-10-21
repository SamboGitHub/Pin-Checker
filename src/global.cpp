#include <WInterrupts.h>
#include <wiring_digital.h>
#include <libprintf.h>
#include <wiring_constants.h>
#include <Arduino.h>
#include "global.h"
#include "rotary_encoder.h"

unsigned int BCDtoDEC(unsigned char const* nybbles, int length)
{
    unsigned int result(0);
    while (length--) {
        result = result * 100 + (*nybbles >> 4) * 10 + (*nybbles & 15);
        ++nybbles;
    }
    return result;
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




//untested - parked
// unsigned int bcd_decimal(unsigned char const* hex[1])
// {
//     unsigned int dec;
//     dec = 0;

//     if((((int)hex[0] & 0xF0) >> 4) < 10 &&  // More significant nybble is valid
//     ((int)hex[0] & 0x0F) < 10)
//     {
//         dec = (((int)hex[0] & 0xF0) >> 4) * 10 + ((int)hex[0] & 0x0F);
//     };         // Less significant nybble is valid
    
//     return dec;
// }  