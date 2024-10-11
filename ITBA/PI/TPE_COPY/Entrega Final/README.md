# TPE_04

Este proyecto analiza datos de multas de tránsito para ciudades como Chicago y Nueva York. Lee información de multas desde archivos CSV, procesa los datos y genera resultados de consultas.

## Estructura del Proyecto

- `back.c` / `back.h`: Lógica de backend para procesamiento de datos y ejecución de consultas.
- `front.c` / `front.h`: Funciones de frontend para E/S de archivos y manejo de errores.
- `ticketsADT.c` / `ticketsADT.h`: Implementación del Tipo de Dato Abstracto para datos de multas.
- `mainCHI.c`: Programa principal para el análisis de datos de Chicago.
- `mainNYC.c`: Programa principal para el análisis de datos de Nueva York.
- `makefile`: Instrucciones de compilación para el proyecto.

## Características

- Lee datos de infracciones y multas desde archivos CSV
- Procesa y almacena datos en estructuras de datos eficientes
- Ejecuta consultas sobre los datos procesados:
  - Consulta 1: Infracciones ordenadas por cantidad de multas
  - Consulta 2: Infracción más popular por agencia emisora
  - Consulta 3: Matrícula con más multas por infracción
- Escribe los resultados de las consultas en archivos CSV

## Compilación

Este proyecto incluye un makefile para facilitar la compilación. Se pueden usar los siguientes comandos:

Para compilar las versiones de Chicago y NYC:

*****************************
$make all
*****************************

Para compilar solo la versión de Chicago:

*****************************
$make parkingTicketsCHI
*****************************

Para compilar solo la versión de NYC:

*****************************
$make parkingTicketsNYC
*****************************

Para compilar con flags de depuración:

*****************************
$make debug
*****************************

Para limpiar los archivos compilados:

*****************************
$make clean
*****************************

El makefile usa gcc con los siguientes flags:
- "-pedantic"
- "-std=c99"
- "-Wall"
- "-fsanitize=address"

Para depuración, agrega los flags "-g" y "-DDEBUG=1".

## Uso

Después de la compilación, ejecute el programa con dos argumentos de línea de comandos:

1. Ruta al archivo CSV de multas
2. Ruta al archivo CSV de infracciones

Ejemplo:

*****************************
$./parkingTicketsCHI chicago_tickets.csv chicago_infractions.csv
$./parkingTicketsNYC nyc_tickets.csv nyc_infractions.csv
*****************************

## Salida

El programa genera tres archivos CSV con los resultados de las consultas:

- "query1.csv": Infracciones ordenadas por cantidad de multas
- "query2.csv": Infracción más popular por agencia emisora
- "query3.csv": Matrícula con más multas por infracción

## Manejo de Errores

El programa maneja varias condiciones de error, incluyendo:

- Errores al abrir archivos
- Errores de asignación de memoria
- Formato de datos inválido

Los mensajes de error se muestran en la consola.

## Contribuyentes

Jonás Glaubart, jglaubart@itba.edu.ar
Franco Manuel Pampuri, fpampuri@itba.edu.ar
Eugenio Migliaro, emigliaro@itba.edu.ar