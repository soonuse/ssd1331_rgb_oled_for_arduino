/*****************************************************************************
*
* File                : ssd1331.c
* Hardware Environment: Arduino UNO
* Build Environment   : Arduino
* Version             : V1.0.7
* Author              : Yehui
*
*              (c) Copyright 2005-2017, WaveShare
*                   http://www.waveshare.com
*                   http://www.waveshare.net   
*                      All Rights Reserved
*              
******************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include "ssd1331.h"

#define WIDTH      96
#define HEIGHT     64
#define PAGES       8

#define OLED_RST    9 
#define OLED_DC     8
#define OLED_CS    10
#define SPI_MOSI   11    /* connect to the DIN pin of OLED */
#define SPI_SCK    13     /* connect to the CLK pin of OLED */

uint8_t oled_buf[WIDTH * HEIGHT / 8];

void setup() {
  Serial.begin(9600);
  Serial.print("OLED Example\n");
  
  SSD1331_begin();
  SSD1331_clear();
  /* display an image of bitmap matrix */
  SSD1331_mono_bitmap(0, 0, waveshare_logo, 96, 64, BLUE);
  delay(2000);
  SSD1331_clear();

  /* display images of bitmap matrix */
  SSD1331_mono_bitmap(0, 2, Signal816, 16, 8, GOLDEN); 
  SSD1331_mono_bitmap(19, 2, Msg816, 16, 8, GOLDEN); 
  SSD1331_mono_bitmap(38, 2, Bluetooth88, 8, 8, GOLDEN); 
  SSD1331_mono_bitmap(52, 2, GPRS88, 8, 8, GOLDEN); 
  SSD1331_mono_bitmap(66, 2, Alarm88, 8, 8, GOLDEN); 
  SSD1331_mono_bitmap(80, 2, Bat816, 16, 8, GOLDEN); 

  /* display strings */
  SSD1331_string(0, 52, "MUSIC", 12, 0, WHITE); 
  SSD1331_string(64, 52, "MENU", 12, 1, WHITE);

  /* display strings 32x16 */
  SSD1331_char3216(0,16, '1', BLUE);
  SSD1331_char3216(16,16, '2', BLUE);
  SSD1331_char3216(40,16, ':', RED);
  SSD1331_char3216(64,16, '3', GREEN);
  SSD1331_char3216(80,16, '4', GREEN);
}

void loop() {

}

