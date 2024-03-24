#include <iostream>
#include "GaussMethod.h"
#include "SimpleIterationMethod.h"
#include "MatrixAB.h"
#include "PassingMethod.h"

int main() {
    MatrixAB matrix = MatrixAB();
    //cout<< "Метод прогонки" << endl;
    //PassingMethod::Start(matrix.GetMatrixC(),matrix.rowsC);

    cout<< "Метод простых итераций" << endl;
//    if(SimpleIterationMethod::Check(matrix.GetMatrixB(),matrix.rows))
        SimpleIterationMethod::StartUniform(matrix.GetMatrixB(),matrix.rows);

//    cout<< "Метод Гаусса без выбора главного элемента" << endl;
//    GaussMethod::StartMethod(matrix.GetMatrixA(),matrix.rows);

//    cout<< "Метод Гаусса с выбором главного элементом(по столбцу)" << endl;
//    GaussMethod::ChoiceMainGauss(matrix.GetMatrixA(),matrix.rows);

    return 0;
}
