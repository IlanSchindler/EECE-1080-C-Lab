#include "line.h"
#include "point.h"
#include <cmath>

line::line(){
    p1.setXY(0, 0);
    p2.setXY(0, 0);
}

line::line(double inX1, double inY1, double inX2, double inY2){
    p1.setXY(inX1, inY1);
    p2.setXY(inX2, inY2);
}

line::line(point &inP1, point &inP2){
    p1 = inP1;
    p2 = inP2;
}

line::line(point &inP, double inX, double inY){
    p1 = inP;
    p2.setXY(inX, inY);
}

void line::setP1(double inX, double inY){
    p1.setXY(inX, inY);
}

void line::setP2(double inX, double inY){
    p2.setXY(inX, inY);
}

void line::setLine(double inX1, double inY1, double inX2, double inY2){
    p1.setXY(inX1, inY1);
    p2.setXY(inX2, inY2);
}

point line::getP1(){
    return p1;
}

point line::getP2(){
    return p2;
}

double line::getSlope(){
    if(isVertical()) return INFINITY;
    else if (isHorizontal()) return 0;
    else return (deltaY()) / static_cast<double>(deltaX());
}

double line::getLength(){
    return pow((pow(deltaX(), 2.0) + pow(deltaY(), 2.0)), 0.5);
}

double line::getYdoubleercept(){
    return p1.getY() - (getSlope() * p1.getX());
}

bool line::isVertical(){
    return p2.getX() == p1.getX();
}

bool line::isHorizontal(){
    return p2.getY() == p1.getY();
}

bool line::parallel(line &L){
    return (getSlope() - L.getSlope()) < 0.0001;
}

double line::deltaX(){
    return p2.getX() - p1.getX();
}

double line::deltaY(){
    return p2.getY() - p1.getY();
}
