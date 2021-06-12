#include "main.h"

ESP32Encoder myEncoderLeft, myEncoderRight;
PinesMotores motor_izq;
PinesMotores motor_dch;

void setup() {
  Serial.begin(115200);
  /*
  Inicialización de sensores de distancia
  
  Wire.begin();
  setup_sensor(VLDIAGIZQ, TYPE_VL);
  setup_sensor(VLFRONIZQ, TYPE_VL);
  setup_sensor(VLDIAGDCHA, TYPE_VL);
  setup_sensor(VLFRONDCHA, TYPE_VL);
  */

  /*
  Inicialización de la pantalla

  setup_tft();
  */

  /*
  Inicialización de los encoders
  */

  setupEncoders();

  /*
  Inicialización de los motores
  */
  
  
  setupMotores();
 
}

void loop() {
  /*
  Pruebas de los sensores de distancia
  
  Serial.println(read_mm(VLDIAGIZQ));
  Serial.println(read_mm(VLFRONIZQ));
  Serial.println(read_mm(VLDIAGDCHA));
  Serial.println(read_mm(VLFRONDCHA));
  Serial.println();
  */

  /*
  Mostrar el voltaje en pantalla

  show_voltage();
  */

  /*
  Pruebas de encoders
 */

  Serial.print("Encoder izquierdo: ");
  Serial.println(String((int32_t)myEncoderLeft.getCount()));
  Serial.print("Encoder derecho:   ");
  Serial.println(String((int32_t)myEncoderRight.getCount()));
 
  /*
  Pruebas de motores

  */
/*   
  Serial.println("Motor derecho al 50%");
  mover_motor(motor_dch, 128);

  Serial.println("Motor izquierdo al 50%");
  mover_motor(motor_izq, 128);
  delay(2000);
  motor_full_stop(motor_izq, motor_dch);
 */
  delay(500);
}

void setupEncoders(){
  //ESP32Encoder::useInternalWeakPullResistors=DOWN;
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors=UP;
  myEncoderLeft.attachHalfQuad(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN);
  myEncoderRight.attachHalfQuad(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN);
  myEncoderLeft.clearCount();
  myEncoderRight.clearCount();
}

void setupMotores(){
  motor_dch.adelante = RIGHT_MOTOR_FWD_PIN;
  motor_dch.atras = RIGHT_MOTOR_REV_PIN;
  motor_dch.canal_adelante = RIGHT_MOTOR_FWD_CH;
  motor_dch.canal_atras = RIGHT_MOTOR_REV_CH;

  motor_izq.adelante = LEFT_MOTOR_FWD_PIN;
  motor_izq.atras = LEFT_MOTOR_REV_PIN;
  motor_izq.canal_adelante = LEFT_MOTOR_FWD_CH;
  motor_izq.canal_atras = LEFT_MOTOR_REV_CH;

  pinMode(motor_dch.adelante, OUTPUT);
  pinMode(motor_dch.atras, OUTPUT);
  pinMode(motor_izq.adelante, OUTPUT);
  pinMode(motor_izq.atras, OUTPUT);

  digitalWrite(motor_dch.adelante, 0);
  digitalWrite(motor_dch.atras, 0);
  digitalWrite(motor_izq.adelante, 0);
  digitalWrite(motor_izq.atras, 0);
  
  ledcSetup(motor_izq.canal_adelante, 500, 8);
  ledcAttachPin(motor_izq.adelante, motor_izq.canal_adelante);
  ledcSetup(motor_izq.canal_atras, 500, 8);
  ledcAttachPin(motor_izq.atras, motor_izq.canal_atras);
  ledcSetup(motor_dch.canal_adelante, 500, 8);
  ledcAttachPin(motor_dch.adelante, motor_dch.canal_adelante);
  ledcSetup(motor_dch.canal_atras, 500, 8);
  ledcAttachPin(motor_dch.atras, motor_dch.canal_atras);
}
