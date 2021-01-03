#include "gpio.h"
#include "main.h"

void GPIO_SetLed(_Bool enabled)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
