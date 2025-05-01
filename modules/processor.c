#include "processor.h"
#include "validator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

//abrir input.csv, convierte datos a numericos, los valida y los almacena en CityData (arreglo)
CityData* load_csv(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo CSV");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];

    // Leer y descartar encabezado
    if (!fgets(line, MAX_LINE, file)) {
        fclose(file);
        fprintf(stderr, "Error al leer encabezado\n");
        exit(EXIT_FAILURE);
    }

    //Se reserva memoria para un arreglo de 100 registros. Si necesita más, se ampliará con realloc
    int capacity = 100;
    CityData *data = malloc(capacity * sizeof(CityData));
    if (!data) {
        perror("Error de memoria");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fgets(line, MAX_LINE, file)) { //Se lee una línea del archivo por cada iteración.
        if (*size >= capacity) {
            capacity *= 2;
            data = realloc(data, capacity * sizeof(CityData));
            if (!data) {
                perror("Error al hacer realloc");
                exit(EXIT_FAILURE);
            }
        }
//Dividir la línea en 3 partes usando strtok y comas como separador.
        char *city = strtok(line, ",");
        char *seismic_str = strtok(NULL, ",");
        char *risk_str = strtok(NULL, ",");

        if (!city || !seismic_str) continue; //Si la ciudad o el nivel sísmico están vacíos, el registro se omite.

        CityData temp;

        // Copia segura del nombre, se usa un struct temp para cargar datos de forma segura
        strncpy(temp.city_name, city, sizeof(temp.city_name) - 1);
        temp.city_name[sizeof(temp.city_name) - 1] = '\0';

        // Parseo numérico
        temp.seismic_level = atoi(seismic_str);

        // Revisar si hay dato faltante en risk_percent
        if (!risk_str || strcmp(risk_str, "\n") == 0 || strlen(risk_str) == 0) {
            temp.risk_percent = 0.0;
            temp.missing_risk = 1;
        } else {
            temp.risk_percent = atof(risk_str);
            temp.missing_risk = 0;
        }

        // Validación antes de guardar
        if (!is_valid_city(&temp)) continue;

        data[*size] = temp;
        (*size)++;
    }

    fclose(file);
    return data;
}
