//#include <iostream>

//using namespace std;

//// Please place your "determine quadrant" function and body
//// See google docs for details

//int whichQuadrant(double x, double y){
//    int xVal, yVal, quad;

//         if (x > 0) {xVal = 1;}
//    else if (x < 0) {xVal = 3;}
//    else            {xVal = 2;}

//         if (y > 0) {yVal = 0;}
//    else if (y < 0) {yVal = 6;}
//    else            {yVal = 3;}

//    quad = xVal + yVal;
//    switch(quad){
//        case 1: return 1;
//        case 3: return 2;
//        case 9: return 3;
//        case 7: return 4;
//        case 2:
//        case 8: return 'Y';
//        case 4:
//        case 6: return 'X';
//        case 5: return 'C';
//        default:
//            cout<<"\n\n\nAn error has been enountered. Terminating"<<endl;
//            exit(0);
//          }
//}

//string message(int q) {
//    string msg;
//    if(q == 'C') msg = "On Center";
//    if(q == 'X') msg = "On XAxis";
//    if(q == 'Y') msg = "On YAxis";
//    if(q ==  1)  msg = "Q1";
//    if(q ==  2)  msg = "Q2";
//    if(q ==  3)  msg = "Q3";
//    if(q ==  4)  msg = "Q4";
//    return msg;
//}

//int main() { // No need to change main()
//    double  x = 0;
//    double y = 0;

//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be On Center" << endl;

//    x = 0;
//    y = 4.8;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be YAxis" << endl;

//    y = 0;
//    x = 4.8;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be XAxis" << endl;

//    x = 4.8;
//    y = 4.8;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be On Q1" << endl;

//    x = -7;
//    y = -4.8;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be On Q3" << endl;

//    x = 7;
//    y = -3;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be On Q4" << endl;

//    x = -9;
//    y = 8;
//    cout << "For XY Pair: " << x << "," << y << " function returns: "
//         <<  message(whichQuadrant(x,y))
//         << " should be On Q2" << endl;

//    return 0;
//}
