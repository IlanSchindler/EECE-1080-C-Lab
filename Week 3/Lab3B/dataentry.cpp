#include <iostream>

using namespace std;

int main()
{
    double sum = 0;
    double userNum = 0;

    do{
        sum += userNum;
        cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
        cin >> userNum;
    }while(userNum > 0);

    cout <<"Sum of Entered Numbers: " << sum << endl;
    return 0;
}
