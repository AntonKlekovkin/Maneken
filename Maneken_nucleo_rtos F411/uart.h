#ifndef UART_H
#define UART_H

#include "mbed.h"
#include "motors_threads.h"
#include "my_motor.h"


void UartRX(void);
void ParseBuffer(void);
void ParseCommand(My_motor *uartMotor, uint8_t number);

void ParseBufferKinnect(void);
void KinnectUartInterrupt(void);
void InitUartKinnect(void);
void SoundThreadBody(void);
void PhotoStart(void);

#endif

