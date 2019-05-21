#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double Q = pow(10.0, -9.0);
const double k = 9 * pow(10.0, 9.0);

double Efield(double r, double a = 1){
    if(r < a){
        return (k*Q*r/pow(a,3.0));
    }else{
        return (k*Q/pow(r,2.0));
    }
}




int main()
{
    double r, a;

    cout << "Enter r: ";
    cin >> r;
    cout << "Enter a: ";
    cin >> a;
    cout << "Efield: " << Efield(r,a) << endl;
    return 0;
}
