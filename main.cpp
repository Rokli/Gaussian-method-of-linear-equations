#include <iostream>
#include "GaussMethod.h"
int main() {
    float matrixCreate[3][3]
        { {3,5,1},
          {1.799999,3,7,},
          {8,1,1}
        };
//    float matrixB[3][1]
//        {
//            {12},
//            {13.599998},
//            {18},
//        };
    int rows = 3;
    int cols = 3;
    float** matrixA;
    matrixA = static_cast<float **>(calloc(rows, sizeof(float *)));
    for(int i = 0; i < rows; i++){
        matrixA[i] = static_cast<float *>(calloc(cols, sizeof(float)));
    }
    for(int i = 0 ; i < rows; i++){
        for (int j = 0; j < rows; ++j) {
            matrixA[i][j] = matrixCreate[i][j];
        }
    }
//    int rows = ...;
//    int cols = ...;
//    float **m;
//    m = calloc(rows, sizeof(float*));
//    for (int i=0; i<rows; i++) {
//        m[i] = calloc(cols, sizeof(float));
//    }
///* как-то заполняете значения */
//    float res = det(m, rows, cols);
    GaussMethod::StartMethod(matrixA,matrixA,3);
    return 0;
}
