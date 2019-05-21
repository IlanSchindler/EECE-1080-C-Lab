#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

double getMean(int numVals, int maxVal){
    return static_cast<double>(numVals) / static_cast<double>(maxVal + 1);
}

int getMin(vector<int> &valVec){
    int min = valVec.at(0);
    for(unsigned i = 1; i < valVec.size(); i++){
        if(valVec.at(i) < min) min = valVec.at(i);
    }
    return min;
}

int getMax(vector<int> &valVec){
    int max = valVec.at(0);
    for(unsigned i = 0; i < valVec.size(); i++){
        if(valVec.at(i) > max) max = valVec.at(i);
    }
    return max;
}

int randVal(int maxVal){
    return rand() % maxVal;
}

vector<int> createVector(int numVals, int maxVal){
    maxVal += 1;
    vector<int> vals(maxVal, 0);
    for(unsigned i = 0; i < numVals; i++){
        vals.at(randVal(maxVal)) += 1;
    }
    return vals;
}

void createChart(vector<int> &valVec, int maxValSize){
    const int BAR_SCALE = maxValSize / 50;
    cout << "Value\tFrequency  Bar" << fixed << endl;
    for(unsigned i = 0; i < valVec.size(); i++){
        cout << setw(6) << i << "\t" << setw(9) << valVec.at(i) << "  ";
        int numStars = valVec.at(i) / BAR_SCALE;
        for(unsigned j = 0; j < numStars; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << "Scale: " << BAR_SCALE << " per *\n" << endl;
}

int main(){
    srand(time(NULL));

    int maxVal, numVals, sum, min, max;
    double mean;
    vector<int> vals;

    while(true){
        cout << "Enter End Range:" << endl;
        cin >> maxVal;
        if(maxVal > 100){
            cout << "Error: Please enter a value <= 100" << endl;
        } else {break;}
    }

    while(true){
        cout<<"Enter number of Samples:" << endl;
        cin >> numVals;
        if(numVals < 10000){
            cout << "Error: Please allow at least 10 000 samples" << endl;

        } else {break;}
    }

    vals = createVector(numVals, maxVal);
    mean = getMean(numVals, maxVal);
    sum = numVals;
    min = getMin(vals);
    max = getMax(vals);

    createChart(vals, max);
    cout << "Range: 0 to " << maxVal << endl;
    cout << "Sample Count: " << numVals << endl;
    cout << "Min Frequency: " << min << endl;
    cout << "Max Frequency: " << max << endl;
    cout << "Sum of Frequencies: " << sum << endl;
    cout << "Mean Frequency: " << setprecision(3) << mean << endl;
    cout << endl;

    return 0;
}
