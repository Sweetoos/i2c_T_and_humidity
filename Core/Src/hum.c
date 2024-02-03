#include "hum.h"
#include <stdio.h>
#include <stdint.h>
#include "i2c.h"

//int16_t h_t_out = 0;
//uint16_t h0_rh = 0;
//uint16_t h1_rh = 0;
//int16_t h0_t0_out = 0;
//int16_t h1_t0_out = 0;
//float humidity = 0;
//
//humidity = (((float)(h1_rh - h0_rh) * (float)(h1_t0_out - h0_t0_out)) / (float)(h_t_out - h0_t0_out)) + (float)h0_rh;

uint8_t Settings = MASK_L | MASK_H;
uint8_t hData1[2];
uint8_t hData20,hData21,hData22;
uint8_t hData3[2];
uint8_t hData4[2];
int16_t HOUT = 0;
int16_t T0degC = 0;
int16_t T1degC= 0;
int16_t T1T0msb = 0;
int16_t H0O = 0;
int16_t H1O = 0;
int16_t H1_rH = 0;
int16_t H0_rH = 0;
int16_t H0_T0_OU = 0;
int16_t H1_T0_OU = 0;
float temperatura = 0;
float wilgotnosc = 0;
uint8_t who_am;

void search_humidity(void)


