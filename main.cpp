#include "z-curve-arrays.hpp"
#include <iostream>
#include <time.h>
int main() {
    int N = 100;
    double a = 3.0;
    double h = 0.2;
    double tau = pow(h, 3) / a;
    ArrD<double, 2> u, v;
    u.init(ind(N,N));
    v.init(ind(N,N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            u[ind(i, j)] = 0.0;
        }
    }
    u[ind(N / 2,N / 2)] = 1.0;
    double t1 = clock();
    double c = a * (tau) / (h * h);
    for(int t = 0; t < 100; t++){
        for(int j = 1; j < N - 1; j++){
            for(int i = 1; i < N - 1; i++){
                v[ind(i, j)] = (c * (u[ind(i + 1, j)] + u[ind(i, j + 1)]+
                               u[ind(i - 1, j)] + u[ind(i, j - 1)] -
                               4 * u[ind(i, j)]) + u[ind(i, j)]);
            }
        }
        u = v;
    }
    // 0.391279 i -> j
    // 0.334201 j -> i
    std::cout <<"TIME: "<< (double)(clock() - t1)/CLOCKS_PER_SEC <<std::endl;
    FILE *x, *y, *z;
    x = fopen("x.txt", "w");
    y = fopen("y.txt", "w");
    z = fopen("z.txt", "w");
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            fprintf(x,"%.1lf ", (i - 1) * h);
            fprintf(y, "%.1lf ", (j - 1) * h);
            fprintf(z, "%lf ", u[ind(i, j)]);
        }
        fprintf(x, "\n");
        fprintf(y, "\n");
        fprintf(z, "\n");
    }
    fclose(x);
    fclose(y);
    fclose(z);
    system("/Users/germanzvezdin/Desktop/Git/SUPREMUM/SCRIPT");
    return 0;
}

