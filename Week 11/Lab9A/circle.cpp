#include "circle.h"
#include <cmath>;

circle::circle(){
    center.setXY(0, 0);
    radius = 0;
}

circle::circle(double inX1, double inY1, double inX2, double inY2){
    center.setXY(inX1, inY1);
    radius = line(center, inX2, inY2).getLength();
}

circle::circle(point &p1, point &p2){
    center = p1;
    radius = line(p1, p2).getLength();
}

circle::circle(point &p, double r){
    center = p;
    radius = r;
}

void circle::setCenter(double inX, double inY){
    center.setXY(inX, inY);
}
void circle::setCenter(point &p){
    center = p;
}
void circle::setRadius(double r){
    radius = r;
}
void circle::setRadius(double inX, double inY){
    radius = line(center, inX, inY).getLength();
}
void circle::setRadius(point &p){
    radius = line(center, p).getLength();
}

point circle::getCenter(){
    return center;
}
double circle::getRadius(){
    return radius;
}

bool circle::isCircle(){
    return radius > 0;
}
double circle::getDiameter(){
    return 2*radius;
}
double circle::area(){
    return M_PI * pow(radius, 2.0);
}
double circle::circumference(){
    return 2 * M_PI * radius;
}
