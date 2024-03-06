//
// Created by hikiray on 06.03.24.
//

#ifndef GAUSSIANMETHODSOLVE_PASSINGMETHOD_H
#define GAUSSIANMETHODSOLVE_PASSINGMETHOD_H
//{8,-2,0,0,0} {-7}
//{-1,5,3,0,0}  {6}
//{0,7,-5,-9,0} {9}
//{0,0,4,7,9} {-8}
//{0,0,0,-5,8} {5}

#include "GaussMethod.h"

class PassingMethod {
public:
    static void Start(float** matrix, int rows){
        for(int i = 1; i < rows; i++){
            matrix[i][i] -= matrix[i][i-1] * (matrix[i-1][i] / matrix[i-1][i-1]);
            matrix[i][rows] -= matrix[i-1][rows] *(matrix[i][i-1]/matrix[i-1][i-1]);
            matrix[i][i-1] = 0;
        }
        GaussMethod::ReverseStroke(matrix,rows);
    }
};


#endif //GAUSSIANMETHODSOLVE_PASSINGMETHOD_H
