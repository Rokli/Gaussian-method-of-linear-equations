#ifndef SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#define SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#include <iostream>
using  namespace  std;

class GaussMethod {
private:

//        float matrixA[3][3]
//        { {3,5,1},
//          {1.799999,3,7,},
//          {8,1,1}
////        };
//        float matrixB[3][1]
//        {
//            {12},
//            {13.599998},
//            {18},
//        };
public:
    static void StartMethod(float** matrixA,float** matrixB,int rows,int cols){
        float** matrixCloneA = matrixA;
        for(int i = 0; i < rows; i++){
            matrixCloneA[i] = new float[cols];
        }
        for(int k = 0; k < rows; k++){
            for (int i = 0; k < rows + 1; k++){
                matrixCloneA[k][i] = matrixB[k][i] / matrixA[k][k];
            }
            for(int i = 0; k < rows+1; k++)
            {
                double K = matrixCloneA[i][ k] / matrixCloneA[k][k];
                for (int j = 0; j < rows + 1; j++)
                    matrixCloneA[i][ j] = matrixCloneA[i][j] - matrixCloneA[k][j] * K;
            }
            for (int i = 0; i < rows; i++) //Обновление, внесение изменений в начальную матрицу
                for (int j = 0; j < rows + 1; j++)
                    matrixA[i][ j] = matrixCloneA[i][ j];
        }
    }
};


#endif //SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
