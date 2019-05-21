#include <iostream>

using namespace std;

int main()
{
    int w, h;

    cout << "Width?";
    cin >> w;
    cout <<"Height?";
    cin >> h;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i == 0 || i == h - 1 || j == 0 || j == w - 1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
