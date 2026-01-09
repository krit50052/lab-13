#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double x[], int N, double y[]) {

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    y[0] = sum / N;
    
    double sumSquaredDiff = 0;
    for (int i = 0; i < N; i++) {
        sumSquaredDiff += pow(x[i] - y[0], 2);
    }
    y[1] = sqrt(sumSquaredDiff / N);
    
    double product = 1;
    for (int i = 0; i < N; i++) {
        product *= x[i];
    }
    y[2] = pow(product, 1.0 / N);
    
    double sumReciprocals = 0;
    for (int i = 0; i < N; i++) {
        sumReciprocals += 1.0 / x[i];
    }
    y[3] = N / sumReciprocals;
    
    y[4] = x[0];
    for (int i = 1; i < N; i++) {
        if (x[i] > y[4]) {
            y[4] = x[i];
        }
    }
    
    y[5] = x[0];
    for (int i = 1; i < N; i++) {
        if (x[i] < y[5]) {
            y[5] = x[i];
        }
    }
}