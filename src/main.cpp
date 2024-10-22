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
s_Change,
s_NoChange,
s_Read
};

states state;

const int num_pins = 25;
int pin_value[num_pins+1];
int read_pin;
int current_pin_value;
int read_loop=0;


void setup()
{
state = s_Read;
   delay(10000);
   printf("waking up\n");

  printf("%ld  ",millis());
  
  for (read_loop=0 ; (read_loop<num_pins+1) ; read_loop++ )
  {
  pinMode(read_loop, INPUT);

  // printf("%d  ",read_loop % 10); // write last digit 
  pin_value[read_loop]=0;
  // digitalWrite(read_loop, HIGH);  // Pull High Restance 
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

    for(read_loop=0;(read_loop<num_pins+1);read_loop++)
    {
      read_pin = digitalRead(read_loop);
      current_pin_value = pin_value[read_loop];
      // printf("read_loop=%d:Read=%d: CurrPin=%d  \n",read_loop,read_pin,current_pin_value);
      if (read_pin == current_pin_value and state != s_Change)
      {
        state = s_NoChange;  
      }
      else
      {
        state=s_Change;
      }
      pin_value[read_loop] = read_pin;
    }
    break;  
  
  case s_Change:
    printf("%ld  ",millis());

    for (read_loop=0 ; (read_loop<num_pins+1) ; read_loop++ )
      {
        printf("%d  ",read_loop % 10); // write last digit 
      }
      printf("\n");
      printf("%ld  ",millis());
      for(read_loop=0;(read_loop<num_pins+1);read_loop++)
      {
        printf("%d  ",pin_value[read_loop]);
      }
    printf("\n");
    
    state = s_Read;
    break;
  
  case s_NoChange:

    state = s_Read;
    break;
    }
}

