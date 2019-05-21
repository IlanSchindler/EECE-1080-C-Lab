#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "quad.h"
#include "circle.h"

using namespace std;

vector<double> breakupstring(string str){
   vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

void createCircle(vector<double> nums, ofstream &out){
    circle c(nums.at(0), nums.at(1), nums.at(2), nums.at(3));
    out << c;
}

void createTriangle(vector<double> nums, ofstream &out){
    triangle t(nums.at(0), nums.at(1), nums.at(2), nums.at(3), nums.at(4), nums.at(5));
    out << t;
}

void createQuad(vector<double> nums, ofstream &out){
    quad q(nums.at(0), nums.at(1), nums.at(2), nums.at(3), nums.at(4), nums.at(5), nums.at(6), nums.at(7));
    out << q;
}

int main()
{
    ifstream infile("shapes.txt");
    ofstream outfile("shapes-info.txt");
    string temp;

    vector<double> numbers;

    if(!infile.is_open()){
        cout<<"ERROR! input" << endl;
        return 1;
    }
    if(!outfile.is_open()){
        cout << "ERROR! output" << endl;
        return 1;
    }

    int points;
    while(!infile.eof()){
        outfile << "--------------------" << endl;
        getline(infile, temp);
        numbers = breakupstring(temp);
        if(numbers.size() % 2 == 1){
            outfile << "ERROR: Entry invalid, too few numbers entered.\nCoordinates cannot be formed." << endl;
        }else{
            points = numbers.size() / 2;
            switch(points){
            case 0:
            case 1: outfile << "ERROR: Too few points entered." << endl; break;
            case 2: createCircle(numbers, outfile); break;
            case 3: createTriangle(numbers, outfile); break;
            case 4: createQuad(numbers, outfile); break;
            default: outfile << "ERROR: Too many points entered." << endl; break;
            }
        }
    }
    outfile << "--------------------";

    infile.close();
    outfile.close();
    return 0;
}
