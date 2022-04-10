/*
ADS1256
DN  - pin 23
SCLK - pin 18 (SCK)
DOUT - pin 19 (MISO)
DRDY - pin 17
RESET - pin 16
CS - pin 5

BUTTON-pin G2       

WATER SENS - pin G34,G35
GENERAL RELAY - PIN G0,G14
DS18B20 -  pin 15

I2C
SDA -  pin 21
SDL -  pin  22
PCF857x pcf1(0x22, &Wire);
  PCF857x pcf2(0x24, &Wire);
LiquidCrystal_I2C lcd(0x27,20,4)





* PCF8574    ----- Esp32
 * A0         ----- GRD
 * A1         ----- GRD
 * A2         ----- GRD
 * VSS        ----- GRD
 * VDD        ----- 5V/3.3V
 * SDA        ----- 21
 * SCL        ----- 22
 *
 * P0     ----------------- LED0
 * P1     ----------------- LED1
 * P2     ----------------- LED2
 * P3     ----------------- LED3
 * P4     ----------------- LED4
 * P5     ----------------- LED5
 * P6     ----------------- LED6
 * P7     ----------------- LED7
*/

/*hw40
*LK (A pin)            any microcontroler intput pin with interrupt -> in this example pin 32
*DT (B pin)             any microcontroler intput pin with interrupt -> in this example pin 21
*SW (button pin)        any microcontroler intput pin with interrupt -> in this example pin 25
*GND - to microcontroler GND
*VCC                    microcontroler VCC (then set ROTARY_ENCODER_VCC_PIN -1) 
*/



 