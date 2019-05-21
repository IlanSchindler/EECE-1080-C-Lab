#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class point{
public:
    friend ostream & operator<<( ostream &output, const point &P ){
        output << "x: " << P.x << " y: " << P.y << endl;
        return output;
    }

    friend istream & operator>>( istream &input, point &P ){
        input >> P.x >> P.y;
        return input;
    }

    void operator=(point &inP){
        x = inP.getX();
        y = inP.getY();
    }

    bool operator==(point &inP){
        return x == inP.x && y == inP.y;
    }

    point();
    point(double inX, double inY);
    void setX(double inX);
    void setY(double inY);
    void setXY(double inX, double inY);
    double getX();
    double getY();

    void swap(point &p);

private:
    double x,y;
};

#endif // POINT_H
