#include <iostream>
#include "GaussMethod.h"
#include "SimpleIterationMethod.h"
#include "MatrixAB.h"
#include "PassingMethod.h"

int main() {
    MatrixAB matrix = MatrixAB();
    //PassingMethod::Start(matrix.GetMatrixC(),matrix.rowsC);
    //SimpleIterationMethod::StartUniform(matrix.GetMatrixB(),matrix.rows);
    //GaussMethod::StartMethod(matrix.GetMatrixA(),3);
    //GaussMethod::ChoiceMainGauss(matrix.GetMatrixA(),3);
    return 0;
}
