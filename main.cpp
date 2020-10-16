#include "z-curve-arrays.hpp"
#include <iostream>

int main() {
    int N = 100, M = 100;
    double h = 1.0/N;
    double tau = 1.0/M;
    ArrD<double, 2> u, v;
    u.init(ind(N,M));
    v.init(ind(N,M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            u[ind(i, j)] = 0.0;
        }
    }
    u[ind(50,50)] = 1.0;
    double c =  0.5 * (tau) / (h * h);
    for(int t = 0; t < 100; t++){
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                v[ind(i, j)] = (c * (u[ind(i + 1, j)] + u[ind(i, j + 1)]+
                               u[ind(i - 1, j)] + u[ind(i, j - 1)] -
                               4 * u[ind(i, j)]) + u[ind(i, j)]);
            }
        }
        u = v;
    }
    FILE *f;
    f = fopen("ans.txt", "w");
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            fprintf(f,"%.1lf %.1lf %lf\n", (i - 1) * h, (j - 1) * tau, u[ind(i, j)]);
        }
    }
    return 0;
}

