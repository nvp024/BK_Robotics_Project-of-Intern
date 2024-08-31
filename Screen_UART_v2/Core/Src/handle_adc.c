#include "handle_adc.h"

uint8_t Pressure[8] = {0x5a, 0xa5, 0x05, 0x82, PRESSURE_ADDR, 0x00, 0x00, 0x00};

void handle_adc(void)
{
    HAL_ADC_Start(&hadc1);
    adcValue = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);
    Pressure[6] = (adcValue >> 8) & 0xFF;
    Pressure[7] = adcValue & 0xFF;
    HAL_UART_Transmit(&huart1, Pressure, 8, HAL_MAX_DELAY);
}