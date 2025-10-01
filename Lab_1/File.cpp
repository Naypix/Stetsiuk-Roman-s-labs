#include <cmath>
#include <iostream>
using namespace std;

double calculateB(double x, double y, double z);
double calculateA(double x, double y, double z, double b);

int main() {
    double x = 0.48, y = 0.47, z = -1.32;

    double b = calculateB(x, y, z); 
    double a = calculateA(x, y, z, b);
    double eps = 1e-9;

    cout << "\na = " << a;
    cout << " b = " << b << endl;

    for (double x = -1; x < 1; x += 0.2) {
        if (fabs(x) < eps) {
            x = 0;
        }
        double B = calculateB(x, y, z);
        double A = calculateA(x, y, z, B);
        cout << "\nx = " << x << " [] b = " << B << " [] a = " << A;
        cout << endl;
    } 
    return 0;
}

double calculateB(double x, double y, double z) {
        double b = 1 - x + pow(y, 2) / 6.0 + pow(z, 3) / 120.0
            + (sin(pow(x - z, 2)) / fabs(pow(y, 1.23)) + z);
        return b;
    
}

double calculateA(double x, double y, double z, double b) {
    double a = (2 * cos(pow(fabs(pow(x, 2) - b / 6.0), 1.0 / 3.0)))
        / (1 + x * b + pow(sin(pow(y, 3)), 2))
        + log(pow(fabs((x + 1) / z), 1.2));
    
    return (a);
}