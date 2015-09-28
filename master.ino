#include <SPI.h>

/* define SS Pin */
#define SS_pin (10)

/* global variable */ 
char val = 0xF;
 
 
/***********************************
 * setup function
 **********************************/
void setup()
{
  /* SS_pin mode set */
  pinMode(SS_pin, OUTPUT);

  /* SPI Master Initialize */ 
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}


/***********************************
 * main loop function
 **********************************/ 
void loop()
{
  digitalWrite(SS_pin, LOW);
  
  SPI.transfer(val);
  digitalWrite(SS_pin, HIGH);  
 
  delay(1000);
}
