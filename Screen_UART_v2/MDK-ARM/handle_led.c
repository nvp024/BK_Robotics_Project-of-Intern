#include "handle_led.h"

void relay_control(void) 
{
    if (rxBuffer[0] == 0x5A) {
        switch (rxBuffer[4]) {
            case 0x65:  // for light
                HAL_GPIO_WritePin(GPIOA, LIGHT_PIN, rxBuffer[8] == 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
                break;
                
            case 0x66:  // for fan
                HAL_GPIO_WritePin(GPIOA, FAN_PIN, rxBuffer[8] == 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
                break;
                
            case 0x67:  // for AC
                HAL_GPIO_WritePin(GPIOA, AC_PIN, rxBuffer[8] == 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
                break;
                
            case 0x68:  // for TV
                HAL_GPIO_WritePin(GPIOA, TV_PIN, rxBuffer[8] == 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
                break;
                
            default:
                break;
        }
        HAL_UART_Receive_IT(&huart1, rxBuffer, RX_BUFFER_SIZE);  // Re-enable UART receive interrupt
    }
}