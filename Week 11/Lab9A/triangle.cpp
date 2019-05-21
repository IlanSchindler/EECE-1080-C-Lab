#include "triangle.h"
#include <cmath>

triangle::triangle(){
    p1.setXY(0,0);
    p2.setXY(0,0);
    p3.setXY(0,0);
}

triangle::triangle(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3){
    p1.setXY(inX1, inY1);
    p2.setXY(inX2, inY2);
    p3.setXY(inX3, inY3);
}
triangle::triangle(point &inP1, point &inP2, point &inP3){
    p1 = inP1;
    p2 = inP2;
    p3 = inP3;
}

void triangle::setP1(double inX, double inY){
    p1.setXY(inX, inY);
}

void triangle::setP2(double inX, double inY){
    p2.setXY(inX, inY);
}

void triangle::setP3(double inX, double inY){
    p3.setXY(inX, inY);
}

void triangle::setP1(point &p){
    p1 = p;
}

void triangle::setP2(point &p){
    p2 = p;
}

void triangle::setP3(point &p){
    p3 = p;
}

void triangle::setTrialge(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3){
    setP1(inX1, inY1);
    setP2(inX2, inY2);
    setP3(inX3, inY3);
}

void triangle::setTriangle(point &inP1, point &inP2, point &inP3){
    p1 = inP1;
    p2 = inP2;
    p3 = inP3;
}

point triangle::getP1(){
    return p1;
}

point triangle::getP2(){
    return p2;
}

point triangle::getP3(){
    return p3;
}

bool triangle::isTriangle(){
    return !((p1.getX() * (p2.getY() - p3.getY()))
             + (p2.getX() * (p3.getY() - p1.getY()))
             + (p3.getX() * (p1.getY() - p2.getY())) == 0);
}

double triangle::area(){
    double p = perimeter() / 2.0;
    double a = line(p1, p2).getLength();
    double b = line(p2, p3).getLength();
    double c = line(p3, p1).getLength();
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double triangle::perimeter(){
    return line(p1, p2).getLength() + line(p2, p3).getLength() + line(p3, p1).getLength();
}

bool triangle::isEquilateral(){
    return line(p1, p2).getLength() - line(p2, p3).getLength() < 0.0001 && line(p1, p2).getLength() - line(p1, p3).getLength() < 0.0001;
}
