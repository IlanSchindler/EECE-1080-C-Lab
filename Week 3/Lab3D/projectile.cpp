#include <iostream>

using namespace std;

int main()
{
    const double g = 4.9;
    double x = 0;
    double v;
    int t = 0;
    int tMax = 0;
    double xMax = 0;

    cout << "Enter initial V0: ";
    cin >> v;
    cout << "\nInitial Velocity of Object: " << v << "-m/s\nTime\tHeight" << endl;

    do{
        cout << t << "\t" << x << endl;

        t++;
        x = v * t - g * t * t;

        if(x > xMax){
            xMax = x;
            tMax = t;
        }
        if(t>10000){
            break;
        }
    }while(x > 0);

    if(t == 1){
        cout << "\n" << endl;
        cout << "Total Time: " << t-1 << "-seconds" << endl;
        cout << "Maximum Height: " << xMax << " @ " << tMax << "-seconds" << endl;
    }
    cout << t << "\t0\n" << endl;
    cout << "Total Time: " << t << "-seconds" << endl;
    cout << "Maximum Height: " << xMax << " @ " << tMax << "-seconds" << endl;


    return 0;
}
