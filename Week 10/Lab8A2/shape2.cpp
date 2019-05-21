#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Cube{
public:
    Cube(){
        s = 0;
    }

    Cube(double in_s){
        setS(in_s);
    }

    double getS(){
        return s;
    }

    void setS(double in_s){
        s = in_s;
    }

    void display(){
        cout << "Sphere Parameters:" << fixed << setprecision(2) << endl;
        cout << "Radius: " << s << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
    }

private:
    double s;

    double getVolume(){
        return pow(s, 3.0);
    }

    double getSurfaceArea(){
        return 6 * pow(s, 2.0);
    }
};

int main()
{
    Cube c1;
    c1.display();

    Cube c2(2);
    c2.display();
    c2.setS(3);
    c2.display();

    return 0;
}
