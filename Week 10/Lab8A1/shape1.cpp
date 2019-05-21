#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Sphere{
public:
    Sphere(){
        r = 0;
    }

    Sphere(double in_r){
        setR(in_r);
    }

    double getR(){
        return r;
    }

    void setR(double in_r){
        r = in_r;
    }

    void display(){
        cout << "Sphere Parameters:" << fixed << setprecision(2) << endl;
        cout << "Radius: " << r << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
    }

private:
    double r;

    double getVolume(){
        return (4/3.0) * M_PI * pow(r, 3.0);
    }

    double getSurfaceArea(){
        return 4 * M_PI * pow(r, 2.0);
    }
};

int main()
{
    Sphere s1;
    s1.display();

    Sphere s2(2);
    s2.display();
    s2.setR(3);
    s2.display();

    return 0;
}
