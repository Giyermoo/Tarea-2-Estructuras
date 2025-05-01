#include "sorter.h"
#include <string.h>

// Función para comparar dos CityData según los criterios
int compare(CityData *a, CityData *b) {
    // 1. Comparar por nivel sísmico
    if (a->seismic_level != b->seismic_level)
        return b->seismic_level - a->seismic_level;

    // 2. Comparar por riesgo considerando valores faltantes
    if (a->missing_risk && !b->missing_risk) return 1;
    if (!a->missing_risk && b->missing_risk) return -1;
    // 3. Si ambos tienen risk_percent, comparar por riesgo
    if (!a->missing_risk && !b->missing_risk) {
        if (a->risk_percent != b->risk_percent)
            return (b->risk_percent > a->risk_percent) ? 1 : -1;
    }

    // 4. Orden alfabético inverso para desempatar
    return strcmp(b->city_name, a->city_name);
}

// Función para hacer swap entre dos estructuras
void swap(CityData *a, CityData *b) {
    CityData temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort, toma un pivote (array[high]) y reorganiza el subarreglo
int partition(CityData *array, int low, int high) {
    CityData pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(&array[j], &pivot) < 0) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
} //Elementos "menores" que el pivote a la izquierda, "Mayores" a la derecha (porque priorizamos)

//Ordena el arreglo CityData usando QuickSort puro y recursivo
void quicksort(CityData *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}
//main.c llama esto y las ciudades quedan ordenadas por prioridad.