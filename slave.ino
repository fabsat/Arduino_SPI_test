/*=============================================
 * For Arduino UNO SPI Slave
 * Receive 1 byte data and 
 * display it to Serial Monitor via uart
 *
 * Hirofumi Hamada
 * ver.1.00
 *============================================*/

#include <SPI.h>

/*-----------------------------------
 * SPI_Slave_Receive
 *---------------------------------*/
 char spi_slave_receive(void)
 {
   /* Wait for reception complete */
   while(!(SPSR & (1 << SPIF)))
     ;
    
   /* Return Data Register */
   return SPDR;
 }
 
 
/***********************************
 * setup function
 **********************************/
void setup()
{
  Serial.begin(9600);
  
  /* Initialize SPI */
  pinMode(SS, INPUT);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);  
  pinMode(MISO, OUTPUT);
  
  /* enable SPI */
  SPCR = (1 << SPE);  // no Interrrupt, MSB first, Slave select 
}
 
/***********************************
 * main loop function
 **********************************/
void loop()
{
  Serial.println("start SPI receive");
  char data = spi_slave_receive();
  Serial.print("data = 0x");
  Serial.println(data, HEX);
}
