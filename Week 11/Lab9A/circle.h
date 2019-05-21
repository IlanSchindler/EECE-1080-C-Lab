#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
#include "line.h"

class circle{
public:
    circle();
    circle(double inX1, double inY1, double inX2, double inY2);
    circle(point &p1, point &p2);
    circle(point &p, double r);

    void setCenter(double inX, double inY);
    void setCenter(point &p);
    void setRadius(double r);
    void setRadius(double inX, double inY);
    void setRadius(point &p);

    point getCenter();
    double getRadius();

    bool isCircle();
    double getDiameter();
    double area();
    double circumference();

    friend istream &operator >> (istream &in, circle &c){
        double tempX, tempY;
        in >> tempX >> tempY;
        c.center.setXY(tempX,tempY);
        in >> tempX >> tempY;
        c.radius = line(c.center, tempX, tempY).getLength();
        return in;
    }

    friend ostream &operator << (ostream &out, circle &c){
        out << "Center:" << endl;
        out << c.center;        
        out << "Radius: " << c.radius << endl;

        out << "Is a Circle: " << c.isCircle() << endl;
        if(c.isCircle()){
            out << "Diameter: " << c.getDiameter() << endl;
            out << "Area: " << c.area() << endl;
            out << "Circumference: " << c.circumference() << endl;
        }
    }

    void operator = (circle &c){
        center = c.center;
        radius = c.radius;
    }

    bool operator == (circle &c){
        return center == c.center && radius - c.radius < 0.0001;
    }

private:
    point center;
    double radius;

};

#endif // CIRCLE_H
