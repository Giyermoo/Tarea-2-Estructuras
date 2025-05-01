Tarea 2 - Estructura de Datos y Algoritmos
Universidad Adolfo Ibáñez
Asignatura: TICS311
Nombre del estudiantes: Isadora Belair, Fernando Guaita y Guillermo Hidalgo
Grupo: 19

---

Descripción General:
-----------------------
Este programa implementa un sistema de priorización de ciudades en riesgo sísmico. A partir de un archivo CSV con datos de ciudades, nivel sísmico y porcentaje de riesgo, el sistema selecciona las N ciudades más prioritarias según los criterios definidos por la tarea y genera un archivo de salida con los resultados ordenados.

El programa utiliza estructuras dinámicas en C, validación de datos, y el algoritmo QuickSort personalizado con múltiples criterios de ordenamiento.

---

Estructura del Proyecto:
---------------------------
Tarea-2-Estructuras/
├── Makefile                      → Compilación automática
├── main.c                        → Función principal
├── input.csv                     → Datos de entrada (generado o proporcionado)
├── output.txt                    → Archivo de salida generado por el programa
├── cities.txt                    → Lista de ciudades para uso con generator.c
├── generador.c                   → Programa auxiliar para generar input.csv
├── modules/
│   ├── processor.c / processor.h → Lectura y validación de datos
│   ├── sorter.c / sorter.h       → Algoritmo de ordenamiento QuickSort
│   └── validator.c / validator.h → Validación de rangos y registros
└── README.txt                    → Este archivo (explicación)

---

Compilación y Ejecución:
---------------------------
1. Compilamos el programa con:
   make

2. Ejecutamos el programa con:
   ./tarea2 input.csv 15 output.txt

   Donde:
   - input.csv     → Archivo de entrada con datos sísmicos
   - 15            → Cantidad de ciudades a priorizar
   - output.txt    → Archivo donde se escriben los resultados

3. Limpiamos archivos objeto con:
   make clean

---

Criterios de Priorización Aplicados:
---------------------------------------
1. Nivel sísmico (`seismic_level`) descendente (mayor = más prioritario).
2. Porcentaje de riesgo (`risk_percent`) descendente.
3. Si falta el `risk_percent`:
   - Nivel 4–5 → se prioriza al inicio
   - Nivel 3   → prioridad media
   - Nivel 1–2 → se relega al final
4. Desempate por nombre de ciudad en orden alfabético inverso (Z–A).

---

Uso de generator.c:
---------------------------------
Generamos un archivo input.csv con datos aleatorios utilizando `generator.c`. Para ello:

1. Creamos un archivo `cities.txt` con al menos 20 nombres de ciudades.
2. Compilamos el generador:
   gcc generador.c -o generador
3. Ejecutamos el generador:
   ./generador

Así creamos un archivo input.csv con 1000 registros simulados.

---

Validaciones Implementadas:
------------------------------
- `seismic_level` debe estar entre 1 y 5.
- `risk_percent`, si está presente, debe estar entre 0.0 y 100.0.
- Las líneas con errores o campos faltantes esenciales son descartadas.
- Toda la memoria dinámica se libera correctamente con `free()`.