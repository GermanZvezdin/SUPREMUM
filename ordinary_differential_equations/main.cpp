#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
void real_solv(double gamma, double Omega = -1){
    FILE *real_sol;
    real_sol = fopen("real_ans.txt", "w");
    double sigma = 2.02*gamma/Omega;
    double ans;
    for(double omg = 0.1; omg < 2; omg += 0.001){
        ans = 1 / sqrt((1 - omg*omg)*(1 - omg*omg) + 4 * gamma * omg * omg * gamma);
        fprintf(real_sol, "%lf %lf\n", omg, ans);
    }
    fclose(real_sol);
    return;
}
int main(int argc, char* argv[]) {
    double Gamma, Omega, A, h, t_min, t_max, x = 0.0, v = 0.0;
    if (argc < 4) {
        perror("command line arguments error: missing ɣ, Ω, A \n");
        exit(1);
    }
    Gamma = strtod(argv[1], nullptr);
    Omega = strtod(argv[2], nullptr);
    A = strtod(argv[3], nullptr);


    h = std::min(2.0 * M_PI / 100, 2.0 * M_PI / (Omega * 100));
    t_min = 30 / Gamma;
    t_max = t_min + 30 * M_PI / Omega;

    double t = 0.0;
    while(t < t_max){
        x += v * h * 0.5;
        v += h * (-x - 2.0 * Gamma * v + A * cos(Omega * t));
        x += h * v * 0.5;
        printf("%lf %lf %lf\n", t,x,v);
        t+=h;
    }
    real_solv(Gamma);
    return 0;
}
