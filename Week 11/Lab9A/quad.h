#ifndef quad_H
#define quad_H
#include "point.h"
#include <iostream>


class quad{
public:
    quad();
    quad(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3, double inX4, double inY4);
    quad(point &in1, point &in2, point &in3, point &in4);

    void setP1(double inX, double inY);
    void setP1(point &p);
    void setP2(double inX, double inY);
    void setP2(point &p);
    void setP3(double inX, double inY);
    void setP3(point &p);
    void setP4(double inX, double inY);
    void setP4(point &p);

    point getP1();
    point getP2();
    point getP3();
    point getP4();

    bool isQuad();
    double perimeter();
    double area();

    friend istream &operator >> (istream &in, quad &q){
        double tempX, tempY;
        in >> tempX >> tempY;
        q.p1.setXY(tempX, tempY);
        in >> tempX >> tempY;
        q.p2.setXY(tempX, tempY);
        in >> tempX >> tempY;
        q.p3.setXY(tempX, tempY);
        in >> tempX >> tempY;
        q.p4.setXY(tempX, tempY);
        return in;
    }

    friend ostream &operator << (ostream &output, quad &q){
        quad temp = q;
        output << "Point 1" << endl;
        output << temp.p1;
        output << "Point 2" << endl;
        output << temp.p2;
        output << "Point 3" << endl;
        output << temp.p3;
        output << "Point 4" << endl;
        output << temp.p4;

        output << "Is a Quadrilateral: " << temp.isQuad() << endl;
        if(temp.isQuad()){
            output << "Perimeter: " << temp.perimeter() << endl;
            output << "Area: " << temp.area() << endl;
        }
        return output;
    }

    void operator = (quad &q){
        p1 = q.p1;
        p2 = q.p2;
        p3 = q.p3;
        p4 = q.p4;
    }

    bool operator==(quad &q){
        point qp1 = q.getP1(), qp2 = q.getP2(), qp3 = q.getP3(), qp4 = q.getP4();
        bool p1match = p1 == qp1 || p1 == qp2 || p1 == qp3 || p1 == qp4;
        bool p2match = p2 == qp1 || p2 == qp2 || p2 == qp3 || p2 == qp4;
        bool p3match = p3 == qp1 || p3 == qp2 || p3 == qp3 || p3 == qp4;
        bool p4match = p4 == qp1 || p4 == qp2 || p4 == qp3 || p4 == qp4;
        return p1match && p2match && p3match && p4match;
    }

private:
    point p1, p2, p3, p4;

    void verify();

};

#endif // quad_H
