#include "quad.h"
#include "triangle.h"
#include <cmath>
#include <iostream>

quad::quad(){
    p1.setXY(0,0);
    p2.setXY(0,0);
    p3.setXY(0,0);
    p4.setXY(0,0);
}

quad::quad(double inX1, double inY1, double inX2, double inY2, double inX3, double inY3, double inX4, double inY4){
    p1.setXY(inX1, inY1);
    p2.setXY(inX2, inY2);
    p3.setXY(inX3, inY3);
    p4.setXY(inX4, inY4);
    verify();
}

quad::quad(point &in1, point &in2, point &in3, point &in4){
    p1 = in1;
    p2 = in2;
    p3 = in3;
    p4 = in4;
    verify();
}

void quad::setP1(double inX, double inY){
    p1.setXY(inX, inY);
    verify();
}
void quad::setP1(point &p){
    p1 = p;
    verify();
}
point quad::getP1(){
    return p1;
}

void quad::setP2(double inX, double inY){
    p2.setXY(inX, inY);
    verify();
}
void quad::setP2(point &p){
    p2 = p;
    verify();
}
point quad::getP2(){
    return p2;
}

void quad::setP3(double inX, double inY){
    p3.setXY(inX, inY);
    verify();
}
void quad::setP3(point &p){
    p3 = p;
    verify();
}
point quad::getP3(){
    return p3;
}

void quad::setP4(double inX, double inY){
    p4.setXY(inX, inY);
    verify();
}
void quad::setP4(point &p){
    p4 = p;
    verify();
}
point quad::getP4(){
    return p4;
}

bool quad::isQuad(){
    bool tri123 = triangle(p1,p2,p3).isTriangle();
    bool tri124 = triangle(p1,p2,p4).isTriangle();
    bool tri134 = triangle(p1,p3,p4).isTriangle();
    bool tri234 = triangle(p2,p3,p4).isTriangle();
    return tri123 && tri124 && tri134 && tri234;
}

double quad::perimeter(){
    line l12(p1, p2), l23(p2, p3), l34(p3, p4), l14(p1, p4);
    return l12.getLength() + l23.getLength() + l34.getLength() + l14.getLength();
}

double quad::area(){
    triangle t123(p1,p2,p3);
    triangle t134(p1,p3,p4);
    return t123.area() + t134.area();
}

/*
 * this method is used to verify that the points entered for the quadrilateral are corectly ordered
 * clockwise from p1 to p4, as such
 * p2          p3
 *
 *       c
 *
 * p1          p4
 * this is done by finding a "center" point whos x and y coordinates are the average of the coordinates of the entered 4 points.
 * this point will always be within the quadrilateral.
 * Then, the area of the quadrilateral can be computed as the sum of the 4 triangles created by any 2 neighboring points
 *      and the center point.
 * if the points are correcly numbered clockwise, then the area should also be equal to the area of triangle 123 and triangle 134, as line 13
 *      is the diagonal of the quadrilateral.
 * if the two areas computed this way are not equal, then the points are not ordered correctly, and points 3 and 4 are swapped.
 * p2   p4   p2   p3
 *         ->
 * p1   p3   p1   p4
 * The areas are then compared again, and if they are again unequal, then points 2 and 3 are swapped
 * p3   p4   p3   p2    p2   p3
 *         ->        ->
 * p1   p2   p1   p4    p1   p4
 * After 2 swaps, if the areas are still unequal, then the quadrilateral is in a unique case where the 4th point is within the triangle formed
 *      by the other three
 * p2             p4
 *
 *        p3
 *
 *
 *       p1
 * in this case, to ensure the correct order, p1 must be the interior point, so a third swap between p1 and p3 is done.
 * at this point the quadrilateral is guarenteed to be correctcly ordered.
 *
 * for a visual representation, see here
 * https://www.desmos.com/calculator/2ttavl85lw
 *
 * the red line is a line between (0,0) and (a5,aq)
 *      where a5 is the area calculated with respect to the inner point, and
 *      where aq is the area calculated without respect to the inner point.
 * the purple line is the line y = x.
 * the points on the quadrilateral are moveable.
 * notice that the line y=x and (a5,aq) only align when the points are in the clockwise or counter-clocwise order 1,2,3,4,
 *      or in the unique case where point 1 is on the interior of triangle 234.
 * This visualization proves that the concept used here is correct.
 *
 */
void quad::verify(){
    double x = p1.getX() + p2.getX() + p3.getX() + p4.getX();
    x /= 4.0;
    double y = p1.getY() + p2.getY() + p3.getY() + p4.getY();
    y /= 4.0;
    point p5(x,y);
    triangle t125(p1,p2,p5);
    triangle t235(p2,p3,p5);
    triangle t345(p3,p4,p5);
    triangle t145(p1,p4,p5);
    triangle t123(p1,p2,p3);
    triangle t134(p1,p3,p4);
    double a5, aq;
    a5 = t125.area() + t235.area() + t345.area() + t145.area();
    aq = t123.area() + t134.area();
    if(!(abs(a5-aq) < 0.0001)){
        p3.swap(p4);
        t125.setTriangle(p1,p2,p5);
        t235.setTriangle(p2,p3,p5);
        t345.setTriangle(p3,p4,p5);
        t145.setTriangle(p1,p4,p5);
        t123.setTriangle(p1,p2,p3);
        t134.setTriangle(p1,p3,p4);
        a5 = t125.area() + t235.area() + t345.area() + t145.area();
        aq = t123.area() + t134.area();
        if(!(abs(a5-aq) < 0.0001)){
            p2.swap(p3);
            t125.setTriangle(p1,p2,p5);
            t235.setTriangle(p2,p3,p5);
            t345.setTriangle(p3,p4,p5);
            t145.setTriangle(p1,p4,p5);
            t123.setTriangle(p1,p2,p3);
            t134.setTriangle(p1,p3,p4);
            a5 = t125.area() + t235.area() + t345.area() + t145.area();
            aq = t123.area() + t134.area();
            if(!(abs(a5-aq) < 0.0001)){
                p1.swap(p3);
            }
        }
    }
}
