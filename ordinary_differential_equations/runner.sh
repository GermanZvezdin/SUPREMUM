#!/bin/bash
    g++ -Wall -O3 -o odu main.cpp
    g++ -Wall -O3 -o furie furie.cpp
    for w in $(seq .1 .01 2)
    do
    echo -n "$w " >> res.txt
    ./odu 0.1 $w 1 | ./furie $w 0.1 >> res.txt
    done
    gnuplot -e 'plot "res.txt" w l, "real_ans.txt" w l; pause -1'
    rm odu
    rm furie
    rm res.txt
   # omega = 2.0 sqrt(real((-0.32 - 0.043*i)*exp(2 * x) * sin(0.99 * x)**2 + (0.05 + 0.66*i)*exp(0.1 * x)*sin(0.99*x)+(0.32-0.043*i)*exp(0.1*x)*cos(0.99*x)+(6.9 * 10**(-18)+5.5*10**(-17)*i)*exp(2 * x)*sin(1.98*x)+(-0.32+0.04*i)*exp(2*x)*cos(0.99*x)**2)**2 + imag((-0.32 - 0.043*i)*exp(2 * x) * sin(0.99 * x)**2 + (0.05 + 0.66*i)*exp(0.1 * x)*sin(0.99*x)+(0.32-0.043*i)*exp(0.1*x)*cos(0.99*x)+(6.9 * 10**(-18)+5.5*10**(-17)*i)*exp(2 * x)*sin(1.98*x)+(-0.32+0.04*i)*exp(2*x)*cos(0.99*x)**2)**2)