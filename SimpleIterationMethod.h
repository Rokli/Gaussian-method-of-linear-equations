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
        float eps = 0.000001;
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
        }while(abs(prevx1 - x1) > eps && abs(prevx2 - x2) > eps && abs(prevx3 - x3) > eps);
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
    static void StartUniform(float** matrix, int rows){
        int counter = 0;
        float eps = 0.001;
        float answer[rows];
        float prevAnswer[rows];
        bool flag = true;
        for(int i = 0; i < rows;i++)
            prevAnswer[i] = matrix[i][rows]/matrix[i][i];
        do{
            for(int i = 0; i < rows;i++) {
                answer[i] =  matrix[i][rows]/matrix[i][i];
                for(int j = 0; j < rows; j++){
                    if(i == j)
                        continue;
                    else
                        answer[i] -= matrix[i][j] / matrix[i][i] * prevAnswer[j];
                }
            }
            for(int i = 0; i < rows; i++){
                if(prevAnswer[i] - answer[i] > eps)
                    flag = false;
            }
            for(int i = 0; i < rows+1;i++)
                prevAnswer[i] = answer[i];
            counter++;
        }while(flag);
        for(float i: answer){
            cout << i << endl;
        }
        cout << counter << endl;
    }
};


#endif //GAUSSIANMETHODSOLVE_SIMPLEITERATIONMETHOD_H
