//
// Created by hikiray on 06.03.24.
//

#ifndef GAUSSIANMETHODSOLVE_MATRIXAB_H
#define GAUSSIANMETHODSOLVE_MATRIXAB_H


#include <cstdlib>

class MatrixAB {
private:
    float matrixB[4][4]
            { {10,1,1,1},
              {2,14,3,-2},
              {1,2,15,1},
              {-1,3,2,20}
            };
    float matrixBsv[4]{13,17,19,24};
    float matrixA[3][3]
            { {3,5,1},
              {1.799999,3,7},
              {8,1,1}
            };
    float matrixAsv[3]{12,13.599998,18};
    float matrixC[5][5]
            { {8,-2,0,0,0},
              {-1,5,3,0,0},
              {0,7,-5,-9,0},
              {0,0,4,7,9},
              {0,0,0,-5,8}
            };
    float matrixCsv[5]{-7,6,9,-8,5};
public:
    int rows = 4;
    int rowsC  = 5;
    float** GetMatrixB(){
        float** matrix;
        matrix = static_cast<float **>(calloc(rows+1, sizeof(float *)));
        for(int i = 0; i < rows; i++){
            matrix[i] = static_cast<float *>(calloc(rows+1, sizeof(float)));
        }
        for(int i = 0 ; i < rows; i++){
            for (int j = 0; j < rows; ++j) {
                matrix[i][j] = matrixB[i][j];
            }
        }
        for(int i = 0;i < rows; i++){
            matrix[i][rows] = matrixBsv[i];
        }
        return matrix;
    }
    float** GetMatrixA(){
        float** matrix;
        matrix = static_cast<float **>(calloc(rows+1, sizeof(float *)));
        for(int i = 0; i < rows; i++){
            matrix[i] = static_cast<float *>(calloc(rows+1, sizeof(float)));
        }
        for(int i = 0 ; i < rows; i++){
            for (int j = 0; j < rows; ++j) {
                matrix[i][j] = matrixA[i][j];
            }
        }
        for(int i = 0;i < rows; i++){
            matrix[i][rows] = matrixAsv[i];
        }
        return matrix;
    }
    float** GetMatrixC(){
        float** matrix;
        matrix = static_cast<float **>(calloc(rowsC+1, sizeof(float *)));
        for(int i = 0; i < rowsC; i++){
            matrix[i] = static_cast<float *>(calloc(rowsC+1, sizeof(float)));
        }
        for(int i = 0 ; i < rowsC; i++){
            for (int j = 0; j < rowsC; ++j) {
                matrix[i][j] = matrixC[i][j];
            }
        }
        for(int i = 0;i < rowsC; i++){
            matrix[i][rowsC] = matrixCsv[i];
        }
        return matrix;
    }

};


#endif //GAUSSIANMETHODSOLVE_MATRIXAB_H
