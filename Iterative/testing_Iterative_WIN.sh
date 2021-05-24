#!/bin/bash

#-----------------------------------------------------------------------
# -> Authors: Gonzalo Quiros, Celia Ramos and Josep Mª Barberá, 
#    students of the Technical University of Madrid.
#
# -> Description: Shell Script file for testing the programs on Windows.
#    It performs 5 loops per test in order to have more data and minimize 
#    later the error calculating the mean.
#-----------------------------------------------------------------------

/STACK:reserve[1000000,commit] # for using extra stack on running

STARTTIMESCRIPT=$(date +%s) #time in seconds

mypath=$(pwd)
echo "I'm on the next directory: $mypath" 
echo "---------------------" #

STARTTIMELOOP=$(date +%s%3N) #time in milliseconds

file="testing_Iterative_WIN.csv"
touch $file

# Write column names
echo "repetitions rows area time iterations" > $file

initial=20
final=10000
step=50
counter=1

while [ $initial -le $final ]
    do 
        while [ $counter -le 5 ]
        do
            echo -n $counter\ >> $file #coment line this for only one loop per test
            $mypath/Maze_Iterative.exe $initial $initial 1 >> $file
            counter=$(($counter+1))    #coment this line for only one loop per test
        done
        initial=$(( $initial + $step ))
        counter=$(($counter-5))        #coment this line for only one loop per test
    done

ENDTIMELOOP=$(date +%s%3N) #time in milliseconds
echo "The for loop takes $(($ENDTIMELOOP - $STARTTIMELOOP)) milliseconds to complete..."



ENDTIMESCRIPT=$(date +%s) #time in seconds

echo "---------------------"
echo "This script takes $(($ENDTIMESCRIPT - $STARTTIMESCRIPT)) seconds to complete..."
exit
