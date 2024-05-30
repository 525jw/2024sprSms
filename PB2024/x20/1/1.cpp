#include <iostream>
#include <string>
using namespace std;

typedef long long long_t;

class Complex {
public:
    long_t real;
    long_t imag;
    void mult(Complex *x);
    string toString();
};
void Complex::mult(Complex *x){
        long_t temr=this->real*x->real - this->imag*x->imag;
        long_t temi=this->imag*x->real + this->real*x->imag;
        this->real=temr;
        this->imag=temi;
}
string Complex::toString() {
    string s = "(";
    s += to_string(this->real);
    s += ") + (";
    s += to_string(this->imag);
    s += ")i";
    return s;
}

int main() {
    Complex a, b;
    cin >> a.real >> a.imag;
    cin >> b.real >> b.imag;
    a.mult(&b);
    cout << a.toString() << endl;
}