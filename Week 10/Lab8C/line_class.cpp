// Add your information here

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    // Add your functions here
    void setX(int in_x){
        x = in_x;
    }

    void setY(int in_y){
        y = in_y;
    }

    void setXY(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void zero(){
        x = 0;
        y = 0;
    }
private:
    int x,y;
};

class Line{

    friend ostream &operator << (ostream &output, const Line &L){
        output << "Point 1" << endl;
        output << L.p1 << endl;
        output << "Point 2" << endl;
        output << L.p2 << endl;
        return output;
    }

    friend istream &operator >> (istream &input, Line &L){
        input >> L.p1 >> L.p2;
        return input;
    }

public:
    Line(){
        p1.zero();
        p2.zero();
    }

    Line(int inX1, int inY1, int inX2, int inY2){
        p1.setXY(inX1, inY1);
        p2.setXY(inX2, inY2);
    }

    void setP1(int inX, int inY){
        p1.setXY(inX, inY);
    }

    void setP2(int inX, int inY){
        p2.setXY(inX, inY);
    }

    void setLine(int inX1, int inY1, int inX2, int inY2){
        p1.setXY(inX1, inY1);
        p2.setXY(inX2, inY2);
    }

    Point getP1(){
        return p1;
    }

    Point getP2(){
        return p2;
    }

    double getSlope(){
        if(isVertical()) return INFINITY;
        else if (isHorizontal()) return 0;
        else return (deltaY()) / static_cast<double>(deltaX());
    }

    double getLength(){
        return pow((pow(deltaX(), 2.0) + pow(deltaY(), 2.0)), 0.5);
    }

    double getYIntercept(){
        return p1.getY() - (getSlope() * p1.getX());
    }

    bool isVertical(){
        return p2.getX() == p1.getX();
    }

    bool isHorizontal(){
        return p2.getY() == p1.getY();
    }

    bool parallel(Line &L){
        return (getSlope() - L.getSlope()) < 0.0001;
    }

    void display(){

    }

private:
    Point p1, p2;

    int deltaX(){
        return p2.getX() - p1.getX();
    }

    int deltaY(){
        return p2.getY() - p1.getY();
    }
};

void displayLine(Line &l1){
    cout << l1;
    cout << "Slope: "      << l1.getSlope()      << endl;
    cout << "Length: "     << l1.getLength()     << endl;
    cout << "Y-int: "      << l1.getYIntercept() << endl;
    cout << "Vertical: "   << l1.isVertical()    << endl;
    cout << "Horizontal: " << l1.isHorizontal()  << endl;
    cout << endl;
}

int main(){
    Line l1;
    displayLine(l1);

    cin >> l1;
    displayLine(l1);

    l1.setLine(0,0,1,0);
    displayLine(l1);

    l1.setP1(1,1);
    l1.setP2(1,2);
    displayLine(l1);

    Line l2(3,4,5,6);
    displayLine(l2);

    l2.setLine(0,0,1,1);
    l1.setLine(0,1,1,2);
    cout << "Parallel: " << l1.parallel(l2) << endl << endl;

    l1.setLine(0,0,7,6);
    displayLine(l1);

    return 0;
}
