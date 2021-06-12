#ifndef motores_h

#define motores_h

#include <Arduino.h>
#include "setup.h"

typedef struct PinesMotores{
  uint8_t adelante, atras;
  uint8_t canal_adelante, canal_atras;
}PinesMotores;

void mover_motor(PinesMotores pines, int speed);
void motor_full_stop(PinesMotores izq, PinesMotores dch);

#endif