#ifndef SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#define SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
#include <iostream>
using  namespace  std;

class GaussMethod {
public:
    static void StartMethod(float **matrix,int rows) {
        //Прямой ход
        for(int i = 0; i < rows;i++){ // строка первая
            for(int j = 0; j < rows; j++){ // проверка на нулевой элемент
                if(matrix[j][i] != 0){
                    matrix = ChangingLines(matrix,rows,j);
                    break;
                }
            }
            for (int j = i+1; j < rows; ++j) {// следующую строку превращаем
                float tmp = -matrix[j][i]/matrix[i][i];
                for(int k = i;k < rows+1; k++){
                    matrix[j][k] += matrix[i][k] * tmp;
                }
            }
        }
        //Прямой ход
        //Обратный ход
        for (int k = rows- 1; k > -1; k--)
        {
            for (int i = rows; i > -1; i--)
                matrix[k][i] = matrix[k][i] / matrix[k][k];
            for (int i = k - 1; i > -1; i--)
            {
                float K = matrix[i][k] / matrix[k][k];
                for (int j = rows; j > -1; j--)
                    matrix[i][j] = matrix[i][j] - matrix[k][j] * K;
            }
        }
        //Обратный ход
        PrintMatrix(matrix,rows);
    }
    static void PrintMatrix(float** matrix,int rows){
        for(int i = 0; i < rows;i++ ){
            for (int j = 0; j < rows+1; ++j) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    static void ChoiceMainGauss(float** matrix, int rows){
        //Прямой ход

        for(int i = 0; i < rows;i++){ // строка первая
            float max = abs(matrix[i][i]);
            int col = 0;
            for(int j = 0; j < rows; j++){ // проверка на нулевой элемент
                if(abs(matrix[j][i]) > max){
                    max = abs(matrix[j][i]);
                    col = j;
                }
            }
            if(i+1 < rows)
                matrix = ChangingLines(matrix, rows, col, i);


            for (int j = i+1; j < rows; ++j) {// следующую строку превращаем
                float tmp = -matrix[j][i]/matrix[i][i];
                for(int k = i;k < rows+1; k++){
                    matrix[j][k] += matrix[i][k] * tmp;
                }
            }
        }
        //Прямой ход
        for (int k = rows- 1; k > -1; k--)
        {
            for (int i = rows; i > -1; i--)
                matrix[k][i] = matrix[k][i] / matrix[k][k];
            for (int i = k - 1; i > -1; i--)
            {
                float K = matrix[i][k] / matrix[k][k];
                for (int j = rows; j > -1; j--)
                    matrix[i][j] = matrix[i][j] - matrix[k][j] * K;
            }
        }
        PrintMatrix(matrix, rows);
    }
    static float** StraightStroke(float** matrix, int rows){

    }
    static float** ChangingLines(float** matrix, int rows,int col,int i){
            for(int j = i; j < rows+1; j++){
                float tmp = matrix[i][j];
                matrix[i][j] = matrix[col][j];
                matrix[col][j] = tmp;
            }
        return matrix;
    }
    static float** ChangingLines(float** matrix, int rows,int col){
            for(int j = 0; j < rows+1; j++){
                float tmp = matrix[0][j];
                matrix[0][j] = matrix[col][j];
                matrix[col][j] = tmp;
            }
        return matrix;
    }
};
#endif SOLVINGLINEARMETHODSGAUSSIAN_METHOD_GAUSSMETHOD_H
