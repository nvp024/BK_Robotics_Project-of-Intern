#ifndef HANDLE_LED_H
#define HANDLE_LED_H

#include "stm32f1xx_hal.h"  // Replace with the correct HAL header for your MCU

extern UART_HandleTypeDef huart1;

#define RX_BUFFER_SIZE 9
#define LIGHT_PIN GPIO_PIN_3
#define FAN_PIN GPIO_PIN_4
#define AC_PIN GPIO_PIN_5
#define TV_PIN GPIO_PIN_6

extern uint8_t rxBuffer[RX_BUFFER_SIZE];

void relay_control(void);

#endif /* HANDLE_LED_H */