#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double FT, tTot, tH, tM;
    cout << "Enter Hours: ";
    cin >> tH;
    cout << "Enter Minutes: ";
    cin >> tM;

    tTot = tH + (tM / 60.0);
    FT = (4 * pow(tTot, 2)) / (tTot + 2) - 20;

    cout << "Approximate Temperature: " << FT << endl;

    return 0;
}
