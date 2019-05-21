#ifndef LINE_H
#define LINE_H
#include "point.h"

class line{
public:
    line();
    line(double inX1, double inY1, double inX2, double inY2);
    line(point &inP1, point &inP2);
    line(point &inP, double inX, double inY);
    void setP1(double inX, double inY);
    void setP2(double inX, double inY);
    void setLine(double inX1, double inY1, double inX2, double inY2);
    point getP1();
    point getP2();
    double getSlope();
    double getLength();
    double getYdoubleercept();
    bool isVertical();
    bool isHorizontal();
    bool parallel(line &L);

    friend ostream &operator << (ostream &output, const line &L){
        output << "point 1" << endl;
        output << L.p1 << endl;
        output << "point 2" << endl;
        output << L.p2 << endl;
        return output;
    }

    friend istream &operator >> (istream &input, line &L){
        input >> L.p1 >> L.p2;
        return input;
    }

private:
    point p1, p2;
    double deltaX();
    double deltaY();
};

#endif // LINE_H
