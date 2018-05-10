#ifndef MOTOR_THREADS_H
#define MOTOR_THREADS_H


#include "mbed.h"
#include "my_motor.h"

void motor0_body(void);
void motor1_body(void);
void motor2_body(void);
void motor3_body(void);
void motor4_body(void);
void motor5_body(void);
void motor6_body(void);
void motor7_body(void);

void GoToNull(void);
void Trajectory1(void);
void Trajectory(int8_t pos0, int8_t pos1, int8_t pos2, int8_t pos3, int8_t pos4, int8_t pos5, int8_t pos6);
void Trajectory2(void);
void Trajectory3();
void Trajectory4();

#endif


