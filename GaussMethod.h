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
    static void StartMethod(float **matrixA, float **matrixB, int rows) {
        float **matrixCloneA = matrixA;
        for(int i = 0; i < rows-1;i++){ // строка первая
            for(int j = 0; j < rows; j++){ // проверка на нулевой элемент
                if(matrixA[j][i] != 0){
                    break;
                }
            }
            for (int j = i+1; j < rows; ++j) {// следующую строку превращаем
                float cup = matrixA[j][i];
                for(int k = i;k < rows-1; k++){
//                    float numberTwo = -matrixA[j][k];
                    float numberTwo = -cup;
                    float numberOne = matrixA[0][i];
                    float tmp = numberOne * (numberTwo/numberOne);
                    matrixA[j][k] += tmp;
                }
            }
        }

        for(int i = 0; i < rows;i++ ){
            for (int j = 0; j < rows; ++j) {
                cout << matrixA[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
#endif SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
