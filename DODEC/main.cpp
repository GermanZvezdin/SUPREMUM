#include <iostream>
#include <math.h>
#include <fstream>

struct V {
    double x,y,z;
    V(): x(0),y(0),z(0) {}
    V(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    V operator - () const { return V(-x,-y,-z);}
    V operator + (const V& b) const { return V(x+b.x, y+b.y, z+b.z);}
    V operator - (const V& b) const { return V(x-b.x, y-b.y, z-b.z);}
    V operator * (double S) const { return V (x*S, y*S, z*S);}
    void operator += (const V&b) { x+= b.x; y+= b.y ; z+= b.z;}
    V operator %( const V &b) const { return V(y*b.z-z*b.y, -x*b.z+z*b.x, x*b.y-y*b.x);}
    double operator * (const V& b) const { return (x*b.x + y*b.y + z*b.z);}
    double abs () const { return sqrt(x*x+y*y+z*z) ;}
    V rotate ( const V& b) const { V a=V(x,y,z); return a*cos(b.abs()) - (a%b)*(sin(b.abs())/(b.abs())) + b*(a*b)*((1-cos(b.abs()))/(b*b));}
};

V operator *( double d, const V &v ) { return v*d; }
std::ostream& operator <<(std::ostream& S, const V& a) { S<<a.x <<' ' << a.y << ' ' << a.z; return S;}
template <int D>
struct G {
    V data[D];

    void set_V() {};

    template<typename T2, typename ... Args>
    void set_V(const T2 &x, const Args &... xxx) {
        data[D - 1 - sizeof...(Args)] = x;
        set_V(xxx...);
    }

public:
    template<typename ... Args>
    explicit G(const Args &... xxx) {
        set_V(xxx...);
    }

    V &operator[](int i) /*const*/ { return data[i]; }

    const V &operator[](int i) const { return data[i]; }

    G operator-() const {
        G<D> ans;
        ans = *this;
        for (int i = 0; i < D; i++) {
            ans[i] = -ans[i];
        }
        return ans;
    }

    friend std::ostream& operator << (std::ostream& S, const G& g){
        for (int i = 0; i < D + 1; i++)
            S << g[i % D] << '\n';
        return S << "\n\n";
    }

    G rotate(const V &b) const {
        V newg[D];
        G<D> ans;
        for (int i = 0; i < D; ++i) {
            newg[i] = data[i].rotate(b);
            ans[i] = newg[i];
        }
        return ans;
    }

    G rotate(int i) const {};

};

int main(){

    G<5> g0;
    g0[0] = V(0,
              1/(cos(3*M_PI/10)*sqrt(1+pow(sin(3*M_PI/10),2)/pow(sin(M_PI/10),2) )),
              sqrt(1-pow(1/(cos(3*M_PI/10)*sqrt(1+pow(sin(3*M_PI/10),2)/pow(sin(M_PI/10),2))),2)));

    for(int i=1; i<5; i++){
        g0[i] = g0[i-1].rotate(V(0, 0, 2*M_PI/5));
    }
    
    std::ofstream fout("ans.txt");

    fout<<g0<<-g0;

    for(int i=0; i<5; i++){
        G g = g0.rotate(g0[i]*(2*M_PI/3));
        fout<<g<<-g;
    }
    fout.close();
    return 0;
}