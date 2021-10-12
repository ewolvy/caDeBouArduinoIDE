#ifndef tipos_h
#define tipos_h

typedef struct Casilla{
  uint8_t x;
  uint8_t y;
  uint8_t o;
}Casilla;

typedef struct Posicion{
  uint16_t x;
  uint16_t y;
  int16_t a;
}Posicion;

typedef struct Estado{
  Casilla casilla;
  Posicion posicion;
  uint8_t vel_lineal;
  int8_t vel_angular;
}Estado;

#endif
