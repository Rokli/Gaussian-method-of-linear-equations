//
// Created by hikiray on 05.03.24.
//

#ifndef GAUSSIANMETHODSOLVE_SIMPLEITERATIONMETHOD_H
#define GAUSSIANMETHODSOLVE_SIMPLEITERATIONMETHOD_H

#include <iostream>
#include <cstdlib>
using namespace std;

class SimpleIterationMethod {
public:
    static void Start(float** matrix, int rows){
        int counter = 0;
        float eps = 0.001;
        float x1 = matrix[0][rows]/matrix[0][0];
        float prevx1 = 0;
        float x2 = matrix[1][rows]/matrix[1][1];
        float prevx2 = 0;
        float x3 = matrix[2][rows]/matrix[2][2];
        float prevx3 = 0;
        do{
            prevx1 = x1;
            prevx2 = x2;
            prevx3 = x3;
            x1 = OneFunc(prevx2,prevx3);
            x2 = TwoFunc(prevx1,prevx3);
            x3 = ThreeFunc(prevx1,prevx2);
            counter++;
        }while(abs(x1 - prevx1) > eps && abs(x2 - prevx2) > eps && abs(x3 - prevx3) > eps);
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
        cout << "x3: " << x3 << endl;
        cout << "counter: " << counter << endl;
    }
    static float OneFunc(float x2, float x3){
        return (15-2 * x2 - x3)/10;
    }
    static float TwoFunc(float x1,float x3){
        return (53-5 * x1 - 6* x3)/30;
    }
    static float ThreeFunc(float x1, float x2){
        return (61 + 3 * x1 - 4 * x2)/20;
    }
};


#endif //GAUSSIANMETHODSOLVE_SIMPLEITERATIONMETHOD_H
