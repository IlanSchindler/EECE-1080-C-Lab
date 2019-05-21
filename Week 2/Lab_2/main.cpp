#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double A, B, C, D;
    cout << "Enter Four numbers: ";
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    double F1 = (A+B+C)/(2*A*C);
    double F2 = pow(A,2)/B+(C/D)*(A+B);
    double F3 = pow(A,2+B+C)+A-C+4;

    cout << "Formula 1: " << F1 << endl;
    cout << "Formula 2: " << F2 << endl;
    cout << "Formula 3: " << F3 << endl;

    return 0;
}
