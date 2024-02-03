#include "libka.h"
#include "i2c.h"
#include "main.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

uint8_t tData1[2]; // Zmienna do bezposredniego odczytu danych temperatury
uint8_t tData20,tData21,tData22;
uint8_t tData3[2];
uint8_t tData4[2];

int16_t TOUT = 0;
int16_t T0degC = 0;
int16_t T1degC= 0;
int16_t T1T0msb = 0;
int16_t T0O = 0;
int16_t T1O = 0;
float temperatura=0;
uint8_t who_am;
uint8_t Settings = MASK_L | MASK_H;

void _search(void)
{


	    // Wpisanie konfiguracji do rejestru
	    HAL_I2C_Mem_Write(&hi2c1, ADDRESS, CTRL_REG1, 1, &Settings, 1, 100);

	    printf("Wyszukiwanie ...\n");
	    HAL_I2C_Mem_Read(&hi2c1, ADDRESS, 0x0F, 1, &who_am, 1, 100);

	    if (who_am == 0xBC) {
	    	printf("Znaleziono czujnik HTS221\n");
	    }
	    else
	    {
	    	printf("Niepoprawna odpowiedz ukladu (0x%02X)\n", who_am);
	    }
}

void _read(void)
{
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T_OUT, 1, tData1, 2, 100);

		  	  HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T0_degC_x8, 1, &tData20, 1, 100);
		  	  HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T1_degC_x8, 1, &tData21, 1, 100);
		  	  HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T1_T0msb, 1, &tData22, 1, 100);
		  	  HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T0_O, 1, tData3, 2, 100);
		  	  HAL_I2C_Mem_Read(&hi2c1, ADDRESS, T1_O, 1, tData4, 2, 100);

		  	  // Konwersja odebranych bajtow danych na typ int16_t

		  	  TOUT = ((tData1[1] << 8) | tData1[0]);
		  	  T1T0msb = tData22;
		  	  T0degC = (tData20|((T1T0msb& 0x03)<< 8))/8.0;
		  	  T1degC = (tData21|((T1T0msb& 0x0C)<< 6))/8.0;
		  	  T0O = ((tData3[1] << 8) | tData3[0]);
		  	  T1O = ((tData4[1] << 8) | tData4[0]);


		  	  temperatura=((float)(T1degC -T0degC)*(float)(TOUT-T0O)/(float)(T1O-T0O)+(float)T0degC);

		  	  printf("Temp = %d\t\n", (int)temperatura);
}
