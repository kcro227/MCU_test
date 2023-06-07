#ifndef _H_APP
#define _H_APP

#include "main.h"

#define LED_PORT                   GPIOA
#define LED_PIN_WorkIndicator      GPIO_PIN_1

#define LED_WorkIndicator_ON()     LED_PORT->BRR = LED_PIN_WorkIndicator
#define LED_WorkIndicator_OFF()    LED_PORT->BSRR = LED_PIN_WorkIndicator
#define LED_WorkIndicator_Toggle() LED_PORT->ODR ^= LED_PIN_WorkIndicator

#endif // !_H_APP