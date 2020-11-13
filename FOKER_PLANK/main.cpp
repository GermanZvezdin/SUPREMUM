#include <iostream>
#include "/Users/germanzvezdin/Desktop/Git/SUPREMUM/Heat Conduction Equation/z-curve-arrays.hpp"
#include <cmath>
#include <ctime>
#include <cstdlib>
double dU(double x) {
    return -x + x * x * x;
}
double drand(){
    return static_cast<double>(rand() % RAND_MAX + 1) / static_cast<double>(RAND_MAX);
}
double dksi(){
    double betta_1 = drand();
    double betta_2 = drand();
    //printf("%lf %lf \n", betta_1, betta_2);
    return sqrt(-2 * log(betta_1)) * cos(M_PI * betta_2);
}
int main() {
    srand(time(NULL));
    int N = 10000;
    ArrD<double, 1> X, V, dV;
    double tau = 0.05;
    double gamma = 0.1;
    double tem = 0.1;
    X.init(ind(N));
    V.init(ind(N));
    dV.init(ind(N));
    X[0] = V[0] = 0;
    for(int t = 0; t < 100; t++){
        for(int i = 1; i < N - 1; i++){
            X[i] = 0.5 * tau * V[i - 1] + X[i - 1];
            dV[i] = V[i - 1] - tau * dU(X[i]);
            X[i] = 0.5 * tau * dV[i - 1] + X[i];
            V[i] = dV[i] - tau * gamma * dV[i] + sqrt(2 * gamma * tau * tem)* dksi();
           // printf("%lf \n", X[i]);
        }
        V = dV;
    }
    FILE *f;
    f = fopen("res.txt", "w");
    for(int i = 0 ; i < N; i++) {
        fprintf(f, "%lf %lf\n", X[i], V[i]);
    }
    fclose(f);

    return 0;
}
