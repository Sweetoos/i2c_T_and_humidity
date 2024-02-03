/*
 * libka.h
 *
 *  Created on: Jan 11, 2024
 *      Author: kacper
 */

#ifndef INC_LIBKA_H_
#define INC_LIBKA_H_

#define ADDRESS (0x5F << 1) // adres wilgotosci: 0011110x
#define WHO_AM_I 0x0F // adres do identyfikacji
#define CTRL_REG1 0x20 // rejestr ustawien 1
#define T_OUT_L 0x2A // niższy bajt danych temperatury
#define T_OUT_H 0x2B // wyzszy bajt danych temperatury

#define T0_degC_x8 0x32
#define T1_degC_x8 0x33
#define T1_T0msb   0x35
#define T0_OUT_L   0x3C
#define T0_OUT_H   0x3D
#define T1_OUT_L   0x3E
#define T1_OUT_H   0x3F

#define T_OUT (T_OUT_L | 0x80)
#define T0_O (T0_OUT_L | 0x80)
#define T1_O (T1_OUT_L | 0x80)

// Maski bitowe
#define MASK_L 0x01 // 0000 0001
#define MASK_H 0x80 //1000 0000

void _search(void);
void _read(void);

#endif /* INC_LIBKA_H_ */
