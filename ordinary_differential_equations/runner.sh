#!/bin/bash
    g++ -Wall -O3 -o odu main.cpp
    g++ -Wall -O3 -o furie furie.cpp
    for w in $(seq .1 .01 10)
    do
    echo -n "$w " >> res.txt
    ./odu 0.1 $w 1 | ./furie $w 0.1 >> res.txt
    done
    gnuplot -e 'plot "res.txt" w l; pause -1'
    rm odu
    rm furie
    rm res.txt
