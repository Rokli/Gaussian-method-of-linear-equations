#ifndef SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#define SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#include <iostream>
using  namespace  std;

class GaussMethod {
public:
    static void StartMethod(float **matrixA,int rows) {
        cout << endl;
        for(int i = 0; i < rows;i++){ // строка первая
            for(int j = 0; j < rows; j++){ // проверка на нулевой элемент
                if(matrixA[j][i] != 0){
                    break;
                }
            }
            float divider = matrixA[i][i];
            for(int j = 0; j < rows+1; j++){
                matrixA[i][j] = matrixA[i][j]/ divider;
            }
            for (int j = i+1; j < rows; ++j) {// следующую строку превращаем
                float tmp = -matrixA[j][i]/matrixA[i][i];
                for(int k = i;k < rows+1; k++){
                    matrixA[j][k] += matrixA[i][k] * tmp;
                }
            }
        }
        //Прямой ход
        for (int k = rows- 1; k > -1; k--)
        {
            for (int i = rows; i > -1; i--)
                matrixA[k][i] = matrixA[k][i] / matrixA[k][k];
            for (int i = k - 1; i > -1; i--)
            {
                float K = matrixA[i][k] / matrixA[k][k];
                for (int j = rows; j > -1; j--)
                    matrixA[i][j] = matrixA[i][j] - matrixA[k][j] * K;
            }
        }
        //Обратный ход
        PrintMatrix(matrixA,rows);
    }
    static void PrintMatrix(float** matrix,int rows){
        for(int i = 0; i < rows;i++ ){
            for (int j = 0; j < rows+1; ++j) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
#endif SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
