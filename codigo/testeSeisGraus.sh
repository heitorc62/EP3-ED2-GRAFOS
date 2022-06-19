#!/bin/bash
valsN=("1000" "5000" "10000" "30000")
conexoes=("5" "30" "55")
cont=0
for val in ${valsN[@]}; do
    for conex in ${conexoes[@]}; do
        echo $val > entrada3.txt
        conex=$(echo "scale=5; ${conex}/${val}" | bc)
        echo $conex >> entrada3.txt
        { time ./teste < entrada3.txt > saidasSeisGraus/saida$(echo ${cont}).txt ; } 2>> saidasSeisGraus/saida$(echo ${cont}).txt
        cont=$((cont+1))
    done
done