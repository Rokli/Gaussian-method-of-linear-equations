#include <iostream>
#include "GaussMethod.h"
int main() {
    float matrixCreate[3][3]
        { {3,5,1},
          {1.799999,3,7},
          {8,1,1}
        };
    float matrixBarray[]{12,13.599998,18};
    int rows = 3;
    int cols = 3;
    float** matrixA;
    matrixA = static_cast<float **>(calloc(rows+1, sizeof(float *)));
    for(int i = 0; i < rows; i++){
        matrixA[i] = static_cast<float *>(calloc(cols+1, sizeof(float)));
    }
    for(int i = 0 ; i < rows; i++){
        for (int j = 0; j < rows; ++j) {
            matrixA[i][j] = matrixCreate[i][j];
        }
    }
    for(int i = 0;i < rows; i++){
        matrixA[i][rows] = matrixBarray[i];
    }
//    int rows = ...;
//    int cols = ...;
//    float **m;
//    m = calloc(rows, sizeof(float*));
//    for (int i=0; i<rows; i++) {
//        m[i] = calloc(cols, sizeof(float));
//    }
///* как-то заполняете значения */
////    float res = det(m, rows, cols);
//    for(int i = 0; i < rows;i++ ){
//        for (int j = 0; j < rows+1; ++j) {
//            cout << matrixA[i][j] << "  ";
//        }
//        cout << endl;
//    }
    GaussMethod::StartMethod(matrixA,matrixA,3);
    return 0;
}
