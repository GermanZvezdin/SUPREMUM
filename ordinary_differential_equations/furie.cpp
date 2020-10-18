//
// Created by German Zvezdin on 17/10/2020.
//

#include <cmath>
#include <errno.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
int main(int argc, char *argv[]) {
    double Gamma, Omega, t, x, v, t_min, t_max, riemann_re = 0.0, riemann_im = 0.0, h;
    if (argc < 3) {
        perror("command line arguments error: missing ɣ, Ω, A\n");
        exit(1);
    }
    errno = 0;
    Gamma = strtod(argv[2], nullptr);
    Omega = strtod(argv[1], nullptr);
    h = std::min(2.0 * M_PI / 100, 2.0 * M_PI / (Omega * 100));
    t_min = 30 / Gamma;
    t_max = t_min + 100.0 * M_PI / Omega;
    while (scanf("%lf %lf %lf", &t, &x, &v) > 0) {
        if(t < t_min){
            continue;
        }
        riemann_re += (cos(Omega * (t + h / 2)) * x) / h;
        riemann_im += (sin(Omega * (t + h / 2)) * x) / h;
    }
    printf("%lf \n", sqrt(pow(2 * riemann_re, 2) + pow(2 * riemann_im , 2)));
    return 0;
}