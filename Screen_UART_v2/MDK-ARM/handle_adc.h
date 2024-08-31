#ifndef HANDLE_ADC_H
#define HANDLE_ADC_H

#include "stm32f1xx_hal.h"  // Replace with the correct HAL header for your MCU


extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;
extern uint32_t adcValue;
extern uint8_t Pressure[8];

void handle_adc(void);

#endif /* HANDLE_ADC_H */
