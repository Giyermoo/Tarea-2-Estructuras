#ifndef SORTER_H
#define SORTER_H

#include "processor.h" //para que sorter.h pueda usar la estructura CityData, definida en processor.h

//firma de la función de ordenamiento principal, implementada en sorter.c
void quicksort(CityData *array, int low, int high);
//recibe un arreglo de ciudades y dos indices para aplicar el algoritmo de forma recursiva
#endif
