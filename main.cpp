#include <iostream>
#include "GaussMethod.h"
#include "SimpleIterationMethod.h"

int main() {
    float matrixCreate[3][3]
        { {10,2,1},
          {5,30,6},
          {-3,4,20}
        };
    float matrixBarray[]{15,53,61};
    int rows = 3;
    float** matrixA;
    matrixA = static_cast<float **>(calloc(rows+1, sizeof(float *)));
    for(int i = 0; i < rows; i++){
        matrixA[i] = static_cast<float *>(calloc(rows+1, sizeof(float)));
    }
    for(int i = 0 ; i < rows; i++){
        for (int j = 0; j < rows; ++j) {
            matrixA[i][j] = matrixCreate[i][j];
        }
    }
    for(int i = 0;i < rows; i++){
        matrixA[i][rows] = matrixBarray[i];
    }

    SimpleIterationMethod::Start(matrixA,rows);
    //GaussMethod::StartMethod(matrixA,3);
    //GaussMethod::ChoiceMainGauss(matrixA,3);
    return 0;
}
