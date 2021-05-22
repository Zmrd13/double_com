#include <iostream>

#include <cmath>
using namespace std;
typedef double(*f_point)(double);
double Func(double x) {
    return (x-(1/x));
}

double Simp(f_point f, double a, double b, int n) {
    double h = (b-a)/n;
    double TEMP1 = 0, TEMP2 = 0;
    for(int i = 1; i < n; i += 2) {

        TEMP2 += f(a + (i+1)*h);
        TEMP1 += f(a + i*h);
    }
    return h/3*(f(a) + 4*TEMP1 + 2*TEMP2);
}
int main() {
    double long a=2, b=4;
    double long eps=0.0000001;
    double long Simp_temp, s;
    int n = 10;
//    cout << "a = ";
//    cin >> a;
//    cout << "\nb = ";
//    cin >> b;
    Simp_temp = Simp(Func, a, b, n);
    do {
        s = Simp_temp;
        n = 2 * n;
        Simp_temp = Simp(Func, a, b, n);
        cout << "\nInt = " << Simp_temp<< endl;
    }
    while (fabs(Simp_temp - s) > eps);
    cout << "\nInt = " << Simp_temp<< endl;
}