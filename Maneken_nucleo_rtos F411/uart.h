#include "mbed.h"
#include "my_pid.h"
#include "my_motor.h"
#include "my_potentiometer.h"

void UartRX(void);
void ParseBuffer(void);
void ParseCommand(My_motor *uartMotor, My_potentiometer *uartPot, uint8_t number);

