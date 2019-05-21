#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    double w, x, tol;
    string inTol;

    cout << "Width: ";
    cin >> w;
    cout << "Tolerance: ";
    cin >> tol;
    cout << "Temperature      Width	  Within Tolerance" << endl;

    double min = w - tol;
    double max = w + tol;

    for(int t = 60; t < 86; t++){
        x = w + (t - 70) * (0.0001);
        if(x > min && x < max){
            inTol = "  	*";
        }else{
            inTol = "";
        }
        cout << "      " << t << "   " << fixed << setw(11) << setprecision(7) << x << inTol << endl;
    }

    return 0;
}

