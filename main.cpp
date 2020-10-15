#include <vector>
#include <iostream>
template <int D> class Ind {
    int p[D];

    void set_x() {}

    template<typename T2, typename ... Args>
    void set_x(const T2 &x, const Args &... xxx) {
        p[D - 1 - sizeof...(Args)] = x;
        set_x(xxx...);
    }

public:
    template<typename ... Args>
    explicit Ind(const Args &... xxx) {
        //static_assert(sizeof...(Args) == D, "illegal parametrs count!");
        set_x(xxx...);
    }

    int &operator[](int i) { return p[i]; }

    const int &operator[](int i) const { return p[i]; }

    int operator*(const Ind &b) const {
        int res = 0;
        for (int i = 0; i < D; i++) res += p[i] * b[i];
        return res;
    }

    int prod() const {
        int res = p[0];
        for (int i = 1; i < D; i++) res *= p[i];
        return res;
    }
};

template<typename ... Args> inline Ind<sizeof...(Args)> ind(Args ... args) {
    return Ind<sizeof...(Args)>(args...);
}

template <typename T, int D> class ArrD {
    std::vector<T> data;
    Ind<D> N, mul;
public:
    const Ind<D> &size() const {
        return N;
    }

    void init(const Ind<D> &N_) {
        N = N_;
        mul[0] = 1;
        for (int i = 1; i < D; i++){
            mul[i] = mul[i - 1] * N[i - 1];
        }
        data.resize(N.prod());
    }

    T &operator[](const Ind<D> &pos) {
        return data[pos * mul];
    }

    const T &operator[](const Ind<D> &pos) const {
        return data[pos * mul];
    }
};
int main(){
    ArrD<double, 2> x;
    Ind<2> a(10, 10);
    x.init(a);
    for(auto i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            x[Ind<2>(i, j)] = j / 2.0;
        }
    }
    for(auto i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            std::cout << x[Ind<2>(i, j)] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}