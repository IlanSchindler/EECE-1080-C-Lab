#include <iostream>

using namespace std;

int main()
{
    double x, y;
    int xVal, yVal, quad;

    cout << "Enter X Y Pair:" << endl;
    cin >> x;
    cin >> y;

         if (x > 0) {xVal = 1;}
    else if (x < 0) {xVal = 3;}
    else            {xVal = 2;}

         if (y > 0) {yVal = 0;}
    else if (y < 0) {yVal = 6;}
    else            {yVal = 3;}

    quad = xVal + yVal;
    switch(quad){
        case 1: cout << "Quadrant is Q1" << endl; break;
        case 3: cout << "Quadrant is Q2" << endl; break;
        case 9: cout << "Quadrant is Q3" << endl; break;
        case 7: cout << "Quadrant is Q4" << endl; break;
        case 2:
        case 8: cout << "On Y-Axis"      << endl; break;
        case 4:
        case 6: cout << "On X-Axis"      << endl; break;
        case 5: cout << "Center Point"   << endl; break;

    }

    return 0;
}
