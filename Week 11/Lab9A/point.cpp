#include "point.h"
#include <iostream>

using namespace std;
point::point(){
    x = 0;
    y = 0;
}

point::point(double inX, double inY){
    x = inX;
    y = inY;
}

void point::setX(double inX){
    x = inX;
}

void point::setY(double inY){
    y = inY;
}

void point::setXY(double inX, double inY){
    x = inX;
    y = inY;
}

double point::getX(){
    return x;
}

double point::getY(){
    return y;
}


void point::swap(point &p){
    point temp = p;
    p.setX(x);
    p.setY(y);
    x = temp.getX();
    y = temp.getY();
}
