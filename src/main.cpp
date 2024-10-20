#include <Arduino.h>
#include <sam.h>
#include <libprintf.h>
#include <SPI.h>
#include <HardwareSerial.h>
#include <wiring_constants.h>
#include <WInterrupts.h>
#include <wiring_digital.h>

enum states
{
//s_Initialize,
s_Change,
s_NoChange,
s_Read
};

states state;

const int num_pins = 13;
int pin_value[num_pins];
int read_pin;
int current_pin_value;
int i=0;


void setup()
{
   // state = s_Initialize;
state = s_Read;
   delay(10000);
   printf("waking up\n");

for (i=0 ; (i<num_pins+1) ; i++ )
  {
  pinMode(i, INPUT);
  printf("  %d  ",i % 10); // write last digita 
  pin_value[i]=0;
  // digitalWrite(i, HIGH);  // Pull High Restance 
  }
   printf("\n");

}

void loop()
{
  switch (state)
  {
  case s_Read:
   
    state = s_NoChange;
    read_pin= 0;
    current_pin_value=0;

    for(i=0;(i<num_pins+1);i++)
    {
      read_pin = digitalRead(i);
      current_pin_value = pin_value[i];
      // printf("i=%d:Read=%d: Pin=%d  \n",i,read_pin,current_pin_value);


      if (read_pin == current_pin_value)
      {
        state = s_NoChange;  
      }
      else
      {
        state=s_Change;
      }
    printf("  %d  ",read_pin);
    pin_value[i] = read_pin;
    }
        
    break;  
  case s_Change:
    printf("\n");
    
    state = s_Read;
    break;
  case s_NoChange:
    printf("\n");
    
    state = s_Read;
    break;
    }
}

