#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "line.h"


class triangle
{
public:
    triangle();
    triangle(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3);
    triangle(point &inP1, point &inP2, point &inP3);
    void setP1(double inX, double inY);
    void setP1(point &p);
    void setP2(double inX, double inY);
    void setP2(point &p);
    void setP3(double inX, double inY);
    void setP3(point &p);
    void setTrialge(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3);
    void setTriangle(point &inP1, point &inP2, point &inP3);
    point getP1();
    point getP2();
    point getP3();

    bool isTriangle();
    double area();
    double perimeter();
    bool isEquilateral();

    friend istream & operator>>(istream &input, triangle &t){
        double tempX, tempY;
        input >> tempX >> tempY;
        t.p1.setXY(tempX, tempY);
        input >> tempX >> tempY;
        t.p2.setXY(tempX, tempY);
        input >> tempX >> tempY;
        t.p3.setXY(tempX, tempY);
        return input;
    }

    friend ostream & operator<<(ostream &output, triangle &t){
        triangle temp = t;
        output << "Point 1" << endl;
        output << temp.p1;
        output << "Point 2" << endl;
        output << temp.p2;
        output << "Point 3" << endl;
        output << temp.p3;

        output << "Is a Triangle: " << temp.isTriangle() << endl;
        if(temp.isTriangle()){
            output << "Area: " << temp.area() << endl;
            output << "Perimeter: " << temp.perimeter() << endl;
            output << "Equilateral: " << temp.isEquilateral() << endl;
        }
        return output;
    }

    void operator=(triangle &t){
        p1 = t.p1;
        p2 = t.p2;
        p3 = t.p3;
    }

    bool operator==(triangle &t){
        if(!isTriangle() || !t.isTriangle()) return false;
        bool p1Match = p1 == t.p1 || p1 == t.p2 || p1 == t.p3;
        if(!p1Match) return false;
        bool p2Match = p2 == t.p1 || p2 == t.p2 || p2 == t.p3;
        if(!p2Match) return false;
        bool p3Match = p3 == t.p1 || p3 == t.p2 || p3 == t.p3;
        if(!p3Match) return false;
        return true;
    }

private:
    point p1, p2, p3;

};

#endif // TRIANGLE_H
