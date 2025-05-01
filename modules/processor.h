#ifndef PROCESSOR_H
#define PROCESSOR_H

typedef struct { //declara la estructura de CityData
    char city_name[50];
    int seismic_level;
    float risk_percent;
    int missing_risk; // 1 si falta el valor, 0 si está presente
} CityData;
//Se usa en todo el programa para almacenar, ordenar y validar ciudades

CityData* load_csv(const char *filename, int *size);
//puntero a un arreglo dinámico de CityData con todos los datos válidos
#endif
//evita que el archivo se incluya dos veces por error, lo que generaría errores de compilación.