/*
 * hum.h
 *
 *  Created on: Jan 11, 2024
 *      Author: kacper
 */

#ifndef INC_HUM_H_
#define INC_HUM_H_

#define H_OUT_L 0x28
#define H_OUT_H 0x29
#define H0_rH_x2 0x30
#define H1_rH_x2 0x31
#define H0_T0_OUT_L 0x36
#define H0_T0_OUT_H 0x37
#define H1_T0_OUT_L 0x3A
#define H1_T0_OUT_H 0x3B

#define H0_T0_OUT (H0_T0_OUT_L | 0x80)
#define H1_T0_OUT (H1_T0_OUT_L | 0x80)
#define H_OUT (H_OUT_L | 0x80)

#endif /* INC_HUM_H_ */
