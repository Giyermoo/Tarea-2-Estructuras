#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "processor.h" // Necesario para que validator.h pueda reconocer la estructura CityData

int is_valid_seismic(int level); //Verifica que el nivel sísmico esté entre 1 y 5.
int is_valid_risk(float risk); //Verifica que el porcentaje de riesgo esté entre 0.0% y 100.0% (solo si no está faltante).
int is_valid_city(CityData *data); //Reúne las validaciones anteriores y se asegura de que un registro completo (CityData) sea válido.



#endif
