#!/bin/bash

# -----------------------------------------------------------------
#                 PRUEBAS PRÁCTICA DE RECURSIVIDAD
#   Es necesario tener este archivo .sh (shell) en una misma 
#   carpeta junto con ambos programas ya compilados. Nos genera
#   dos archivos .txt con los resultado de las pruebas.
#       PRUEBAS:
#           - Ejecutar ambos archivos por separado aumentando
#           los valores del tamaño del problema, en nuestro caso
#           el producto de "filas" * "columnas", es decir el área.
# -----------------------------------------------------------------

ulimit -s unlimited

STARTTIMESCRIPT=$(date +%s) #time in seconds

mypath=$(pwd) # creo una variable mypath que contiene my root path desde el cual estoy ejecutando el script
echo "Estoy en el directorio $mypath" #así se ponen commandos con variables
echo "---------------------" # para imprimir por pantalla

STARTTIMELOOP=$(date +%s%3N) #time in milliseconds

file="output_recursive.txt"
touch $file

# Write column names
echo "repeticiones filas area tiempo iteraciones" > $file

initial=20
final=1000
step=50
contador=0

while [ $initial -le $final ]
    do 
        while [ $contador -le 5 ]
        do
            echo -n $contador\ >> $file
            $mypath/Maze_Recursivo $initial $initial 1\ >> $file
            contador=$(($contador+1))
        done
        initial=$(( $initial + $step ))
        contador=$(($contador-5))
    done

ENDTIMELOOP=$(date +%s%3N) #time in milliseconds
echo "The for loop takes $(($ENDTIMELOOP - $STARTTIMELOOP)) milliseconds to complete..."


ENDTIMESCRIPT=$(date +%s) #time in seconds

echo "---------------------"
echo "This script takes $(($ENDTIMESCRIPT - $STARTTIMESCRIPT)) seconds to complete..."
exit
exit