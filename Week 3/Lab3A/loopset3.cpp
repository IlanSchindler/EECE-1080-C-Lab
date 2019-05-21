#include <iostream>

using namespace std;

int main()
{
    double i;

    cout << "For an input value of ";
    cin >> i;
    cout << endl;

    for(i; i > 0; i = i - .5){
        cout << i << ",";
    }

    cout << i << endl;


    return 0;
}
