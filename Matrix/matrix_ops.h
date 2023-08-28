/**
 ******************************************************************************
 * @file           : matrix_ops.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Header of functionalities providing matrix operations for 
 *                   different dimensions
 * @author         : Prateek Gupta, Sreedhar Mahadevan
 * @version		   : v5.2
 * @company        : Agnikul Cosmos Private Limited
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */
#define M_PI 3.14159265358979323846
#ifndef INC_MATRIX_OPS_H_
#define INC_MATRIX_OPS_H_
#include <math.h>
/*******************************************************************************
 * Structures and Enumerations
 ******************************************************************************/
/**
 * @brief 16 x 1 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_16X1
{
    double elem_1_1;
    double elem_2_1;
    double elem_3_1;
    double elem_4_1;
    double elem_5_1;
    double elem_6_1;
    double elem_7_1;
    double elem_8_1;
    double elem_9_1;
    double elem_10_1;
    double elem_11_1;
    double elem_12_1;
    double elem_13_1;
    double elem_14_1;
    double elem_15_1;
    double elem_16_1;
} Matrix_16X1;


/**
 * @brief 3 x 3 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_3X3
{
    double elem_1_1;
    double elem_1_2;
    double elem_1_3;
    double elem_2_1;
    double elem_2_2;
    double elem_2_3;
    double elem_3_1;
    double elem_3_2;
    double elem_3_3;
} Matrix_3X3;


/**
 * @brief 2 x 2 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_2X2
{
    double elem_1_1;
    double elem_1_2;
    double elem_2_1;
    double elem_2_2;
} Matrix_2X2;



/**
 * @brief 3 x 1 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_3X1
{
    double elem_1_1;
    double elem_2_1;
    double elem_3_1;
} Matrix_3X1;

/**
 * @brief 2 x 1 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_2X1
{
    double elem_1_1;
    double elem_2_1;
} Matrix_2X1;

/**
 * @brief 1 x 1 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_1X1
{
    double elem_1_1;
} Matrix_1X1;

/**
 * @brief 4 x 4 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_4X4
{
    double elem_1_1;
    double elem_1_2;
    double elem_1_3;
    double elem_1_4;
    double elem_2_1;
    double elem_2_2;
    double elem_2_3;
    double elem_2_4;
    double elem_3_1;
    double elem_3_2;
    double elem_3_3;
    double elem_3_4;
    double elem_4_1;
    double elem_4_2;
    double elem_4_3;
    double elem_4_4;
} Matrix_4X4;

/**
 * @brief 4 x 1 Matrix in double
 * @details
 *
 * */
typedef struct MATRIX_4X1
{
    double elem_1_1;
    double elem_2_1;
    double elem_3_1;
    double elem_4_1;
} Matrix_4X1;

/**
 * @brief 6 x 1 Matrix in double
 * @details
 *
 * */
typedef struct Matrix_10X1
{
    double elem_1_1;
    double elem_2_1;
    double elem_3_1;
    double elem_4_1;
    double elem_5_1;
    double elem_6_1;
    double elem_7_1;
    double elem_8_1;
    double elem_9_1;
    double elem_10_1;
} Matrix_10X1;


/*******************************************************************************
 * Preprocessor definitions
 ******************************************************************************/

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

/**
 * @defgroup group1 Matrix Operations
 * @brief Matrix Operations group
 * @details Group pertaining to all mathematical operations using Matrices of
 * different dimensions.
 * @{
 */

/**
 * @brief calculates tangent of a value
*/
double tangent(double argument);

/**
 * @brief     : calculates atan2
 * @param num : numerator for atan2
 * @param den : denominator for atan2
*/
double arcTangent2(double num, double den);

/**
 * @brief calculates acos with fault handling
 * @param argument : x for acos(x) in radians
*/
double arcCosine(double argument);

/**
 * @brief calculates asin with fault handling
 * @param argument : x for asin(x) in radians
*/
double arcSine(double argument);

/// @brief      global function for divide
/// @param num  numerator in division operation
/// @param den  denominator in division operation
/// @return     num/den if den > 1E-15 else returns 0
double divide(double num, double den);

/// @brief converts a vector to unit vector
/// @param V input vector 3X1
/// @return unit vector of V
Matrix_3X1 GetUnitVector(Matrix_3X1 V);

/**
 * @brief prints nx1 array
 * @details
 *
 * @param double array[] - array to be printed
 * @return void
 *
 * */
void PrintDoubleArray(double array[], int length);


void printMatrixArray(double * M, int row, int cols);

/**
 * @brief prints 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_2X2(Matrix_2X2 M);

/**
 * @brief prints 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_3X1(Matrix_3X1 M);

/**
 * @brief prints 4x1 matrix
 * @details
 *
 * @param Matrix_3X1 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_4X1(Matrix_4X1 M);

/**
 * @brief prints 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_3X3(Matrix_3X3 M);

/**
 * @brief Calculates trace of 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 V - Vector
 * @return double  - trace of the matrix
 *
 * */

double Trace_3x3(Matrix_3X3 M);


/**
 * @brief Calculates 2 norm of a vector
 * @details
 *
 * @param Matrix_3X1 V - Vector
 * @param int8_t L - length of Vector
 * @return double  - norm of the input vector
 *
 * */
double norm2(Matrix_3X1 V);



/**
 * @brief Perform Matrix multiplication on two 3x3 matrices
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Multiplied matrix
 *
 * */
Matrix_3X3 MatrixMul_3x3_3x3(Matrix_3X3 A, Matrix_3X3 B);

/**
 * @brief Perform Matrix multiplication on two 2x2 matrices
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X2 B - second matrix
 * @return Matrix_2X2  - Multiplied matrix
 *
 * */
Matrix_2X2 MatrixMul_2x2_2x2(Matrix_2X2 A, Matrix_2X2 B);

/**
 * @brief Perform Scalar multiplication of a 3x3 Matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_3X3  - Multiplied matrix
 *
 * */
Matrix_3X3 MatrixScalMul_3x3 (Matrix_3X3 A, double val);

/**
 * @brief Perform Scalar multiplication of a 4x4 Matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_4X4  - Multiplied matrix
 *
 * */
Matrix_4X4 MatrixScalMul_4x4 (Matrix_4X4 A, double val);

/**
 * @brief Perform Scalar multiplication of a 2x2 Matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_2X2  - Multiplied matrix
 *
 * */
Matrix_2X2 MatrixScalMul_2x2 (Matrix_2X2 A, double val);

/**
 * @brief Perform Scalar multiplication of a 3x1 Matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_3X1  - Multiplied matrix
 *
 * */
Matrix_3X1 MatrixScalMul_3x1 (Matrix_3X1 A, double val);

/**
 * @brief Perform Scalar multiplication of a 16x1 Matrix
 * @details
 *
 * @param Matrix_16X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_16X1  - Multiplied matrix
 *
 * */
Matrix_16X1 MatrixScalMul_16x1 (Matrix_16X1 A, double val);

/**
 * @brief Perform Scalar multiplication of a 2x1 Matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_2X1  - Multiplied matrix
 *
 * */
Matrix_2X1 MatrixScalMul_2x1 (Matrix_2X1 A, double val);

/**
 * @brief Perform Scalar multiplication of a 4x1 Matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_4X1  - Multiplied matrix
 *
 * */
Matrix_4X1 MatrixScalMul_4x1 (Matrix_4X1 A, double val);
/**
 * @brief Perform Scalar multiplication of a 6x1 Matrix
 * @details
 * @param Matrix_10X1 A - first matrix
 * @param double val   - scalar value
 * @return Matrix_10X1  - Multiplied matrix
 *
 * */
Matrix_10X1 MatrixScalMul_10X1 (Matrix_10X1 A, double val);

/**
 * @brief Perform Matrix multiplication between a 3x3 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Multiplied matrix
 *
 * */
Matrix_3X1 MatrixMul_3x3_3x1 (Matrix_3X3 A, Matrix_3X1 B);

/**
 * @brief Perform Matrix multiplication between a 2x2 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Multiplied matrix
 *
 * */
Matrix_2X1 MatrixMul_2x2_2x1 (Matrix_2X2 A, Matrix_2X1 B);

/**
 * @brief Perform Matrix multiplication between a 4x4 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Multiplied matrix
 *
 * */
Matrix_4X1 MatrixMul_4x4_4x1 (Matrix_4X4 A, Matrix_4X1 B);

/**
 * @brief Perform Matrix addition between a 3x3 matrix and a 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Added matrix
 *
 * */
Matrix_3X3 MatrixAdd_3x3_3x3 (Matrix_3X3 A, Matrix_3X3 B);

/**
 * @brief Perform Matrix addition between a 4x4 matrix and a 4x4 matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param Matrix_4X4 B - second matrix
 * @return Matrix_4X4  - Added matrix
 *
 * */
Matrix_4X4 MatrixAdd_4x4_4x4 (Matrix_4X4 A, Matrix_4X4 B);

/**
 * @brief Perform Matrix addition between a 2x2 matrix and a 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X2 B - second matrix
 * @return Matrix_2X2  - Added matrix
 *
 * */
Matrix_2X2 MatrixAdd_2x2_2x2 (Matrix_2X2 A, Matrix_2X2 B);

/**
 * @brief Perform Matrix subtraction between a 3x3 matrix and a 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Subtracted matrix
 *
 * */
Matrix_3X3 MatrixSub_3x3_3x3 (Matrix_3X3 A, Matrix_3X3 B);

/**
 * @brief Perform Matrix subtraction between a 2x2 matrix and a 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X2 B - second matrix
 * @return Matrix_2X2  - Subtracted matrix
 *
 * */
Matrix_2X2 MatrixSub_2x2_2x2 (Matrix_2X2 A, Matrix_2X2 B);

/**
 * @brief Perform Matrix addition between a 3x1 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Added matrix
 *
 * */
Matrix_3X1 MatrixAdd_3x1_3x1 (Matrix_3X1 A, Matrix_3X1 B);

/**
 * @brief Perform Matrix addition between a 4x1 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Added matrix
 *
 * */
Matrix_4X1 MatrixAdd_4x1_4x1 (Matrix_4X1 A, Matrix_4X1 B);
/**
 * @brief Perform Matrix addition between a 6x1 matrix and a 6x1 matrix
 * @details
 *
 * @param Matrix_10X1 A - first matrix
 * @param Matrix_10X1 B - second matrix
 * @return Matrix_10X1  - Added matrix
 *
 * */
Matrix_10X1 MatrixAdd_10X1_10X1 (Matrix_10X1 A, Matrix_10X1 B);

/**
 * @brief Perform Matrix addition between a 16x1 matrix and a 16x1 matrix
 * @details
 *
 * @param Matrix_16X1 A - first matrix
 * @param Matrix_16X1 B - second matrix
 * @return Matrix_16X1  - Added matrix
 *
 * */
Matrix_16X1 MatrixAdd_16x1_16x1 (Matrix_16X1 A, Matrix_16X1 B);

/**
 * @brief Perform Matrix addition between a 2x1 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Added matrix
 *
 * */
Matrix_2X1 MatrixAdd_2x1_2x1 (Matrix_2X1 A, Matrix_2X1 B);

/**
 * @brief Perform Matrix subtraction between a 3x1 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Subtracted matrix
 *
 * */
Matrix_3X1 MatrixSub_3x1_3x1 (Matrix_3X1 A, Matrix_3X1 B);

/**
 * @brief Perform Matrix subtraction between a 4x1 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Subtracted matrix
 *
 * */
Matrix_4X1 MatrixSub_4x1_4x1 (Matrix_4X1 A, Matrix_4X1 B);

/**
 * @brief Perform Matrix subtraction between a 2x1 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Subtracted matrix
 *
 * */
Matrix_2X1 MatrixSub_2x1_2x1 (Matrix_2X1 A, Matrix_2X1 B);

/**
 * @brief Returns a 3x3 identity matrix
 * @details 1's on the main diagonal and 0's elsewhere
 *
 * @param None
 * @return Matrix_3X3  - 3x3 Identity matrix
 *
 * */
Matrix_3X3 Eye3X3 (void);

/**
 * @brief Returns a 2x2 identity matrix
 * @details 1's on the main diagonal and 0's elsewhere
 *
 * @param None
 * @return Matrix_2X2  - 2x2 Identity matrix
 *
 * */
Matrix_2X2 Eye2X2 (void);

/**
 * @brief Return the transpose of a Matrix_3X3 element
 * @details
 *
 * @param  Matrix_3X3  - 3x3 Input matrix to be transposed
 * @return Matrix_3X3  - 3x3 Transposed matrix
 *
 * */
Matrix_3X3 MatrixTranspose_3x3 (Matrix_3X3 A);

/**
 * @brief Return the transpose of a Matrix_4X4 element
 * @details
 *
 * @param  Matrix_4X4  - 4x4 Input matrix to be transposed
 * @return Matrix_4X4  - 4x4 Transposed matrix
 *
 * */
Matrix_4X4 MatrixTranspose_4x4 (Matrix_4X4 A);

/**
 * @brief Return the transpose of a Matrix_2X2 element
 * @details
 *
 * @param  Matrix_2X2  - 2x2 Input matrix to be transposed
 * @return Matrix_2X2  - 2x2 Transposed matrix
 *
 * */
Matrix_2X2 MatrixTranspose_2x2 (Matrix_2X2 A);

/* Vector Operations */
/**
 * @brief Returns the dot product of two 3x1 vectors
 * @details
 *
 * @param  Matrix_3X1 A - 3x1 first matrix
 * @param  Matrix_3X1 B - 3x1 second matrix
 * @return double     - Dot product
 *
 * */
double VectorDotProd_3x1_3x1(Matrix_3X1 A, Matrix_3X1 B);

/**
 * @brief Returns the dot product of two 2x1 vectors
 * @details
 *
 * @param  Matrix_2X1 A - 2x1 first matrix
 * @param  Matrix_2X1 B - 2x1 second matrix
 * @return double     - Dot product
 *
 * */
double VectorDotProd_2x1_2x1(Matrix_2X1 A, Matrix_2X1 B);

/**
 * @brief Returns the cross product of two 3x1 vectors
 * @details
 *
 * @param  Matrix_3X1 A - 3x1 first matrix
 * @param  Matrix_3X1 B - 3x1 second matrix
 * @return Matrix_3X1   - Cross product
 *
 * */
Matrix_3X1 VectorCrossProd_3x1_3x1(Matrix_3X1 A, Matrix_3X1 B);

/**
 * @brief Returns the cross product of two 2x1 vectors
 * @details
 *
 * @param  Matrix_2X1 A - 2x1 first matrix
 * @param  Matrix_2X1 B - 2x1 second matrix
 * @return Matrix_2X1   - Cross product
 *
 * */
Matrix_1X1 VectorCrossProd_2x1_2x1(Matrix_2X1 A, Matrix_2X1 B);

/// @brief calculates inverse of 3x3 Matrix
/// @param M Matrix of size 3x3
/// @return Matrix after inversion
Matrix_3X3 MatrixInverse_3X3(Matrix_3X3 M);

/// @brief      Calculates Determinant of a Matrix over first column
/// @param M    pointer to array storing the 2D matrix
/// @param size dimension of the matrix
/// @return     determinant of the matrix
double MatrixDeterminantOverColumn(Matrix_3X3 M);

/// @brief calculates determinant of 2x2 matrix
/// @param M Matrix of which determinant to be calculated
/// @return determinant 
double MatrixDeterminant_2X2(Matrix_2X2 M);

/// @brief           performs scalar multiplication on a row, Rj*a
/// @param M         input Matrix
/// @param scalar    scalar to be multiplied 
/// @param rowNumber number of the row (first row = 1)
void Matrix3X3_RowOperation_ScalMul(Matrix_3X3 * M,double scalar, int rowNumber);

/// @brief           performs scalar division on a row, Rj/a
/// @param M         input Matrix
/// @param scalar    scalar to be divided by 
/// @param rowNumber number of the row (first row = 1)
void Matrix3X3_RowOperation_ScalDiv(Matrix_3X3 * M,double scalar, int rowNumber);

/// @brief                  performs row operation Ri => a*Ri + b*Rj
/// @details                Ri is the ith row of Matrix M. 
/// @param M                Input matrix on which row operation to be done
/// @param rowTobeUpdate    index of the row to be updated in matrix array = Ri
/// @param scalar1          scalar to be multiplied by row being updated = a
/// @param rowFromUpdate    index of the row which to update the row from = Rj
/// @param scalar2          scalar to be multitpled to Rj = b
void Matrix_RowOperation(double * M,int numberOfRows, int numberOfColumns,  int rowTobeUpdate, double scalar1, int rowFromUpdate, double scalar2);

/// @brief            performs scalar multiplication to a row in Matrix array  
/// @param M          input Matrix struct
/// @param rowNumber  index of the row to be update
/// @param scalar     scalar to be multiplied to the row
void Matrix_RowScalMultiplication(double * M,int numberOfRows, int numberOfColumns, int rowIndex, double scalar);

/// @brief   calculates determinant of a matrix
/// @param M Matrix struct which specifies the matrix
/// @return  det of M
double Matrix_GeneralDeterminant(double * M,int numberOfRows, int numberOfColumns);

/// @brief              converts the input matrix into its row echelon form
/// @param M 
/// @param numberOfRows 
/// @param numberOfCols 
void Matrix_RowEchelonForm(double * M, int numberOfRows, int numberOfCols);
/// @brief           swtiches row1 with row 2 in input matrix M
/// @param M         input matrix
/// @param row1Index index of first row 
/// @param row2Index index of second row 
void Matrix_RowSwitchRowOperation(double * M, int numberOfRows, int numberOfCols, int row1Index, int row2Index);

/// @brief               calculates determinant using row echelon form
/// @param M             pointer to input matrix
/// @param numberOfRows  total number of rows in matrix
/// @param numberOfCols  total number of columns in matrix
/// @return 
double Matrix_DetRowEchelon(double *M, int numberOfRows, int numberOfCols);
/// @brief              calculates matrix inverse using general row operations
/// @param M            input matrix 
/// @param numberOfRows total number of rows in M
/// @param numberOfCols total number of cols in M
/// @return 
void Matrix_GeneralInverse(double * M, int numberOfRows, int numberOfCols, double * Minv);
/// @brief          performs matrix multiplication [M1]ij * [M2]jk = [M]ik
/// @param M1       first matrix     
/// @param M2       second matrix
/// @param M1_rows  number of rows in first matrix
/// @param M1_cols  number of columns in first matrix = numnber of rows in second matrix
/// @param M2_cols  number of columns in second matrix
/// @param M        Matrix pointer to store the result (pass zero matrix of results size)
void MatrixMul_General(double *M1, double *M2, int M1_rows, int M1_cols, int M2_cols, double * M);
/// @brief         converts input matrix into its transpose
/// @param M       input matrix
/// @param numRows number of rows in input matrix
/// @param numCols number of cols in input matrix
void MatrixTranspose_General(double *M, int numRows, int numCols);


//Closes the @defgroup block
/**@}*/

#endif /* INC_MATRIX_OPS_H_ */
