#include "validator.h"

int is_valid_seismic(int level) {
    return level >= 1 && level <= 5;
} //acepta valores entre 1 y 5, devuelve 1 si es valido, 0 si no.

int is_valid_risk(float risk) {
    return risk >= 0.0 && risk <= 100.0;
} //solo acepta valores en el rango de 0% a 100%


//Esta función se usa en processor.c para decidir si un registro leído desde el CSV debe ser guardado o descartado.
int is_valid_city(CityData *data) {
    if (!is_valid_seismic(data->seismic_level))
        return 0;

    if (!data->missing_risk && !is_valid_risk(data->risk_percent))
        return 0;

    return 1;
}
//chequea si el nivel sismico y el riesgo son validos