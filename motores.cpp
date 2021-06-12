#include "motores.h"

void mover_motor(PinesMotores pines, int speed){
  Serial.print("velocidad: ");
  Serial.println(speed);
  if (speed > MAX_PWM_SPEED){
    speed = MAX_PWM_SPEED;
  }else if (speed < (0 - MAX_PWM_SPEED)){
    speed = 0 - MAX_PWM_SPEED;
  }
  if (speed == 0) {
    ledcWrite(pines.canal_adelante, LOW);
    ledcWrite(pines.canal_atras, LOW);
  } else if (speed > 0) {
    ledcWrite(pines.canal_adelante, speed);
    ledcWrite(pines.canal_atras, LOW);
  } else {
    ledcWrite(pines.canal_adelante, LOW);
    ledcWrite(pines.canal_atras, 0 - speed);
  }
}

void motor_full_stop(PinesMotores izq, PinesMotores dch){
  mover_motor(izq, 0);
  mover_motor(dch, 0);
}