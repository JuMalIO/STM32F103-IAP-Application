#include "app.h"
#include "main.h"
#include "gpio.h"
#include "msd.h"

#define FLASH_FILE "update.bin"

static _Bool LedBlink;

void APP_Init(void)
{
	MSD_Init();
}

void APP_Run(void)
{
	if (MSD_IsExistingFile(FLASH_FILE))
	{
		MSD_DeleteFile(FLASH_FILE);
		
		for (uint16_t i = 0; i < 100; i++)
		{
			GPIO_SetLed(i % 2);
			HAL_Delay(50);
		}
	}
	
	LedBlink = !LedBlink;
	GPIO_SetLed(LedBlink);
	HAL_Delay(500);
}
