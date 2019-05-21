#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double TOL = .001;

double f(double x){
    return (pow(x, 4.0) /**/ + 2 * pow(x, 3.0) /**/ - 31 * pow(x, 2.0) /**/ - 32 * x /**/ + 60);
}

double fprime(double x){
    return (4 * pow(x, 3.0) /**/ + 6 * pow(x, 2.0) /**/ - 62 * x /**/ - 32);
}

double newtonRoot(double x){
    double x0 = x;
    double x1 = x;
    double delt = 0;
    int i = 0;
    do{
        x0 = x1;
        delt = f(x0)/fprime(x0);
        x1 = x0 - delt;
        i++;
        if(i>10000){
            cout << "\n\n\nINFINITE LOOP" << endl;
            return -100000;
        }
    }while(!(fabs(x1-x0)<TOL));
    return x1;
}

int main()
{
    cout.precision(0);
    cout.setf(ios::fixed);

    double guess;
    char cont = 'y';

    do{
        cout << "Enter guess: ";
        cin >> guess;
        cout << "Root: " << newtonRoot(guess)<< endl;
        cout << "Enter Another Guess: y/n? ";
        cin >> cont;
        cont = tolower(cont);
    }while(cont == 'y');


    return 0;
}
