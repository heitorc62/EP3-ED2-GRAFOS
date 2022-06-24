#!/bin/bash
make EP3
if [ ! -d "saidasCompGigante" ] 
then
    mkdir saidasCompGigante
fi
valsN=("100" "500" "1000" "5000" "10000")
epsilon="0.12"
cont=0
for val in ${valsN[@]}; do
    #echo $val
    inf=$(echo "scale=8; ((1 - ${epsilon})/(${val}))/10" | bc)
    sup=$(echo "scale=8; ((1 + ${epsilon})/(${val}))*10" | bc)
    for i in `seq 0 3`; do
        p=$(echo "scale=9; ${inf} + (((${sup} - ${inf})/3) * ${i})" | bc)
        echo inf = $(echo "scale=8; ((1 - ${epsilon})/(${val}))" | bc) > saidasCompGigante/saida$(echo ${cont}).txt
        echo sup = $(echo "scale=8; ((1 + ${epsilon})/(${val}))" | bc) >> saidasCompGigante/saida$(echo ${cont}).txt
        echo $val > entrada3.txt
        echo $p >> entrada3.txt
        echo n = $val >> saidasCompGigante/saida$(echo ${cont}).txt
        echo p = $p >> saidasCompGigante/saida$(echo ${cont}).txt
        ./EP3 < entrada3.txt >> saidasCompGigante/saida$(echo ${cont}).txt
        cont=$((cont+1))
    done
done
