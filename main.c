#include <stdio.h>
#include <stdlib.h>
#include "modules/processor.h" //para cargar datos desde el csv
#include "modules/sorter.h" //para aplicar quicksort

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <input.csv> <N_Cities> <output.txt>\n", argv[0]);
        return 1;
    } // Se verifica que el usuario haya pasado los 3 argumentos requeridos

    // Se llama a load_csv (de processor.c) para leer el input, validar los datos, almacenar los datos en "cities" y guardar la cantidad de ciudades en num_records
    int num_records;
    CityData *cities = load_csv(argv[1], &num_records);

    //Se llama a quicksort (de sorter.c) para ordenar las ciudades en base a nivel sismico y riesgo descendentes y orden alfabetico inverso
    quicksort(cities, 0, num_records - 1);

    int N = atoi(argv[2]); //Se convierte el segundo argumento (N) a entero
    if (N > num_records) N = num_records; //Si el usuario pide mas ciudades de las que hay, se limita a num_records

    FILE *out = fopen(argv[3], "w");
    if (!out) {
        perror("No se pudo abrir archivo de salida");
        return 1;
    } //Se abre el archivo de salida (output.txt) para escribir los resultados.



    fprintf(out, "city_name,seismic_level,risk_percent\n");
    for (int i = 0; i < N; i++) {
        if (cities[i].missing_risk)
            fprintf(out, "%s,%d,\n", cities[i].city_name, cities[i].seismic_level);
        else
            fprintf(out, "%s,%d,%.2f\n", cities[i].city_name, cities[i].seismic_level, cities[i].risk_percent);
    } //Se escribe el encabezado y luego se imprimen las N ciudades mas prioritarias.

    fclose(out);
    free(cities);
    return 0;
}
