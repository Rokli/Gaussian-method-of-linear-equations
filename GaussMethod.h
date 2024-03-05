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
        for(int i = 0; i < rows;i++ ){
            for (int j = 0; j < rows+1; ++j) {
                cout << matrixA[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0; i < rows;i++){ // строка первая
            for(int j = 0; j < rows; j++){ // проверка на нулевой элемент
                if(matrixA[j][i] != 0){
                    break;
                }
            }
            float divider = matrixA[i][i];
            for(int j = 0; j < rows+1; j++){
                float tmp = matrixA[i][j];
                matrixA[i][j] = matrixA[i][j]/ divider;
            }
            for (int j = i+1; j < rows; ++j) {// следующую строку превращаем
                float tmp = -matrixA[j][i]/matrixA[i][i];
                for(int k = i;k < rows+1; k++){
                    matrixA[j][k] += matrixA[i][k] * tmp;
                }
            }
        }
        for(int i = 0; i < rows;i++ ){
            for (int j = 0; j < rows+1; ++j) {
                cout << matrixA[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
#endif SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
