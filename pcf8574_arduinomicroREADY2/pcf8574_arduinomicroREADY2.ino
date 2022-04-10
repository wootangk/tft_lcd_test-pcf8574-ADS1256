/*  Example sketch for the pcf1 for the purposes of showing how to use the interrupt-pin.

    Attach the positive lead of an LED to PIN7 on the pcf1 and the negative lead to GND,
    a wire from Arduino-pin 13 to pin 3 on the PCF8474, a wire from the int-pin on the pcf1
    to Arduino-pin 7 and wires for SDA and SCL to Arduino-pins 2 and 3, respectively.

    If all goes well you should see the small blue LED on the ESP-module lighting up and the
    LED connected to the PCF going off, and vice versa. */

#include <pcf8574_esp.h>

/*  We need to set up the I2C-bus for the library to use */
#include <Wire.h>

// Initialize a PCF8574 at I2C-address 0x20
PCF857x pcf1(0x22, &Wire);
PCF857x pcf2(0x24, &Wire);
//If you had a PCF8575 instead you'd use the below format
//PCF857x pcf8575(0x20, &Wire, true);

volatile bool PCFInterruptFlag = false;

void PCFInterrupt() {
  PCFInterruptFlag = true;
}

void setup() {
  Serial.begin(115200);


  Wire.begin();
  //Specsheets say PCF8574 is officially rated only for 100KHz I2C-bus
  //PCF8575 is rated for 400KHz
  Wire.setClock(100000L);
  pcf1.begin();
 pcf1.resetInterruptPin();
 pcf1.write(0, 1);
  pcf1.write(1, 0);
  pcf1.write(2, 1);
  pcf1.write(3, 0);
  pcf1.write(4, 0);
  pcf1.write(5, 1);
  pcf1.write(6, 0);
  pcf1.write(7, 1);
pcf2.begin();
 pcf2.resetInterruptPin();
 pcf2.write(0, 1);
  pcf2.write(1, 0);
  pcf2.write(2, 1);
  pcf2.write(3, 0);
  pcf2.write(4, 0);
  pcf2.write(5, 1);
  pcf2.write(6, 0);
  pcf2.write(7, 1);

}

void loop() {
Serial.println(pcf1.read(0));
Serial.println(pcf1.read(1));
Serial.println(pcf1.read(2));
Serial.println(pcf1.read(3));
Serial.println(pcf1.read(4));
Serial.println(pcf1.read(5));
Serial.println(pcf1.read(6));
Serial.println(pcf1.read(7));
 delay(1000);
  pcf1.write(0, 1);
 delay(1000);
  pcf1.write(0, 0);
   delay(1000);
  pcf1.write(0, 1);
 delay(1000);
  pcf1.write(0, 0);
  Serial.println(pcf2.read(0));
Serial.println(pcf2.read(1));
Serial.println(pcf2.read(2));
Serial.println(pcf2.read(3));
Serial.println(pcf2.read(4));
Serial.println(pcf2.read(5));
Serial.println(pcf2.read(6));
Serial.println(pcf2.read(7));
 delay(1000);
  pcf2.write(2, 1);
 delay(1000);
  pcf2.write(2, 0);
   delay(1000);
  pcf2.write(2, 1);
 delay(1000);
  pcf2.write(2, 0);
}
