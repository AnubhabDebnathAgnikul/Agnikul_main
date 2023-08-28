/**
 ******************************************************************************
 * @file           : matrix_ops.c
 * @project        : Agnikul Generic Software Library
 * @brief          : Library of functionalities providing matrix operations for 
 *                   different dimensions
 * @author         : Prateek Gupta, Sreedhar Mahadevan
 * @version		   : v5.6
 * @company        : Agnikul Cosmos Private Limited
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
*/

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <math.h>
#include "matrix_ops.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * Function definitions
 ******************************************************************************/
/**
 * @brief          : calculates tan(argument) with fault handling
 * @param argument : input to tangent in radians
*/
double tangent(double argument)
{
    if ( ((int)(argument/(M_PI / 2.0)) % 2) != 0)
    {
        printf("\nArgument to tangent is odd multiple of PI/2!!!!\n");
        printf("Accuracy of tangent is decreased to float!!\n");
        argument -= 1E-7;
        return (double)tanf((float)argument);
    } 
    return tan(argument);
}
/**
 * @brief     : calculates atan2 with fault handling
 * @param num : y for atan2
 * @param den : x for atan2
*/
double arcTangent2(double num, double den)
{
    if (fabs(den) < 1E-15)
    {
        printf("denominator for atan2 is less than 1E-15!!!!\n");
        den = 1E-15;
        return (double)atan2f((float)num, (float)den);
    }
    return atan2(num, den);
}
/**
 * @brief calculates acos with fault handling
 * @param argument : x for acos(x) in radians
*/
double arcCosine(double argument)
{
    if (argument > 1.0)
    {
        printf("Argument of acos() is greater than 1!!!!\n");
        double error = (argument - 1.0);
        if (error < 1E-7f)
        {
            argument = 1.0;
            printf("Error handled accuracy reduced to float\n");
            return (float)acosf((float)argument);
        }
        else {
            printf("Argument error cannot be handled!!\n");
            exit(1);
        }
    }
    else if (argument < -1.0)
    {
        printf("Argument of acos() is less than -1!!!!\n");
        double error = (argument + 1.0);
        if (error > -1E-7f)
        {
            argument = -1.0;
            printf("Error handled accuracy reduced to float\n");
            return (float)acosf((float)argument);
        }
        else {
            printf("Argument error cannot be handled!!\n");
            exit(1);
        }
    }
    else{
        return acos(argument);
    }
}

/**
 * @brief calculates asin with fault handling
 * @param argument : x for asin(x) in radians
*/
double arcSine(double argument)
{
    if (argument > 1.0)
    {
        printf("Argument of asin() is greater than 1!!!!\n");
        double error = (argument - 1.0);
        if (error < 1E-7f)
        {
            argument = 1.0;
            printf("Error handled accuracy reduced to float\n");
            return (float)asinf((float)argument);
        }
        else {
            printf("Argument error cannot be handled!!\n");
            exit(1);
        }
    }
    else if (argument < -1.0)
    {
        printf("Argument of asin() is less than -1!!!!\n");
        double error = (argument + 1.0);
        if (error > -1E-7f)
        {
            argument = -1.0;
            printf("Error handled accuracy reduced to float\n");
            return (float)asinf((float)argument);
        }
        else {
            printf("Argument error cannot be handled!!\n");
            exit(1);
        }
    }
    else{
        return asin(argument);
    }
}
/// @brief      global function for divide 
/// @param num  numerator in division operation
/// @param den  denominator in division operation
/// @return     num/den if den > 1E-15 else returns 0
double divide(double num, double den)
{
    // printf("inside divide function: dem=%lf\n", den);
    if (fabs(den) < 1E-15)
    {
        perror("Divide By Zero!!!\n");
        return 0;
    }
    else
    {
        return (num/den);
    }
}
/// @brief converts a vector to unit vector
/// @param V input vector 3X1
/// @return unit vector of V
Matrix_3X1 GetUnitVector(Matrix_3X1 V)
{
    return MatrixScalMul_3x1(V, divide(1.0,norm2(V)));
}

/**
 * @brief prints nx1 array
 * @details
 *
 * @param double array[] - array to be printed
 * @return void
 *
 * */
void PrintDoubleArray(double array[], int length)
{
    printf("\n");
    for (int i=0; i<length; i++)
    {
        printf("%.15f\n", array[i]);
    }
}
/**
 * @brief prints 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_2X2(Matrix_2X2 M)
{
    printf("\n[[%.15f, %.15f]\n[%.15f, %.15f]]\n", M.elem_1_1, M.elem_1_2, M.elem_2_1, M.elem_2_2);
}
/**
 * @brief prints 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_3X1(Matrix_3X1 M)
{
    printf("\n[%.15f, %.15f, %.15f]\n", M.elem_1_1, M.elem_2_1, M.elem_3_1);
}

/**
 * @brief prints 4x1 matrix
 * @details
 *
 * @param Matrix_3X1 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_4X1(Matrix_4X1 M)
{
    printf("\n[%.15f, %.15f, %.15f, %.15f]\n", M.elem_1_1, M.elem_2_1, M.elem_3_1, M.elem_4_1);
}

/**
 * @brief prints 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 M - matrix to be printed
 * @return void
 *
 * */
void PrintMat_3X3(Matrix_3X3 M)
{
    printf("\n[%f, %f, %f\n%f, %f, %f\n%f, %f, %f]\n", M.elem_1_1, M.elem_1_2, M.elem_1_3, M.elem_2_1, M.elem_2_2, M.elem_2_3, M.elem_3_1, M.elem_3_2, M.elem_3_3);
}


/**
 * @brief Calculates trace of 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 V - Vector
 * @return double  - trace of the matrix
 *
 * */

double Trace_3x3(Matrix_3X3 M)
{
    double trace;
    trace = M.elem_1_1 + M.elem_2_2 + M.elem_3_3;

    return trace;

}

/**
 * @brief Perform Matrix addition between a 16x1 matrix and a 16x1 matrix
 * @details
 *
 * @param Matrix_16X1 A - first matrix
 * @param Matrix_16X1 B - second matrix
 * @return Matrix_16X1  - Added matrix
 *
 * */
Matrix_16X1 MatrixAdd_16x1_16x1 (Matrix_16X1 A, Matrix_16X1 B)
{
    Matrix_16X1 C;
    C.elem_1_1  = A.elem_1_1  + B.elem_1_1;
    C.elem_2_1  = A.elem_2_1  + B.elem_2_1;
    C.elem_3_1  = A.elem_3_1  + B.elem_3_1;
    C.elem_4_1  = A.elem_4_1  + B.elem_4_1;
    C.elem_5_1  = A.elem_5_1  + B.elem_5_1;
    C.elem_6_1  = A.elem_6_1  + B.elem_6_1;
    C.elem_7_1  = A.elem_7_1  + B.elem_7_1;
    C.elem_8_1  = A.elem_8_1  + B.elem_8_1;
    C.elem_9_1  = A.elem_9_1  + B.elem_9_1;
    C.elem_10_1 = A.elem_10_1 + B.elem_10_1;
    C.elem_11_1 = A.elem_11_1 + B.elem_11_1;
    C.elem_12_1 = A.elem_12_1 + B.elem_12_1;
    C.elem_13_1 = A.elem_13_1 + B.elem_13_1;
    C.elem_14_1 = A.elem_14_1 + B.elem_14_1;
    C.elem_15_1 = A.elem_15_1 + B.elem_15_1;
    C.elem_16_1 = A.elem_16_1 + B.elem_16_1;

    return C;
}

/**
 * @brief Perform Scalar multiplication of a 16x1 Matrix
 * @details
 *
 * @param Matrix_16X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_16X1  - Multiplied matrix
 *
 * */
Matrix_16X1 MatrixScalMul_16x1 (Matrix_16X1 A, double val)
{
    Matrix_16X1 C;
    C.elem_1_1 = (A.elem_1_1 * val);
    C.elem_2_1 = (A.elem_2_1 * val);
    C.elem_3_1 = (A.elem_3_1 * val);
    C.elem_4_1 = (A.elem_4_1 * val);
    C.elem_5_1 = (A.elem_5_1 * val);
    C.elem_6_1 = (A.elem_6_1 * val);

    C.elem_7_1  = (A.elem_7_1  * val);
    C.elem_8_1  = (A.elem_8_1  * val);
    C.elem_9_1  = (A.elem_9_1  * val);
    C.elem_10_1 = (A.elem_10_1 * val);
    C.elem_11_1 = (A.elem_11_1 * val);
    C.elem_12_1 = (A.elem_12_1 * val);

    C.elem_13_1 = (A.elem_13_1 * val);
    C.elem_14_1 = (A.elem_14_1 * val);
    C.elem_15_1 = (A.elem_15_1 * val);
    C.elem_16_1 = (A.elem_16_1 * val);
    
    return C;
}
/**
 * @brief Calculates 2 norm of a vector
 * @details
 *
 * @param Matrix_3X1 V - Vector
 * @param int8_t L - length of Vector
 * @return double  - norm of the input vector
 *
 * */
double norm2(Matrix_3X1 V)
{
    double nm = sqrt( pow(V.elem_1_1,2) + pow(V.elem_2_1,2) + pow(V.elem_3_1,2) );
    return nm;
}


/**
 * @brief Perform Matrix multiplication on two 3x3 matrices
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Multiplied matrix
 *
 * */
Matrix_3X3 MatrixMul_3x3_3x3 (Matrix_3X3 A, Matrix_3X3 B)
{
    Matrix_3X3 C;

    C.elem_1_1    =    (A.elem_1_1 * B.elem_1_1) + (A.elem_1_2 * B.elem_2_1) + (A.elem_1_3 * B.elem_3_1);
    C.elem_1_2    =    (A.elem_1_1 * B.elem_1_2) + (A.elem_1_2 * B.elem_2_2) + (A.elem_1_3 * B.elem_3_2);
    C.elem_1_3    =    (A.elem_1_1 * B.elem_1_3) + (A.elem_1_2 * B.elem_2_3) + (A.elem_1_3 * B.elem_3_3);

    C.elem_2_1    =    (A.elem_2_1 * B.elem_1_1) + (A.elem_2_2 * B.elem_2_1) + (A.elem_2_3 * B.elem_3_1);
    C.elem_2_2    =    (A.elem_2_1 * B.elem_1_2) + (A.elem_2_2 * B.elem_2_2) + (A.elem_2_3 * B.elem_3_2);
    C.elem_2_3    =    (A.elem_2_1 * B.elem_1_3) + (A.elem_2_2 * B.elem_2_3) + (A.elem_2_3 * B.elem_3_3);

    C.elem_3_1    =    (A.elem_3_1 * B.elem_1_1) + (A.elem_3_2 * B.elem_2_1) + (A.elem_3_3 * B.elem_3_1);
    C.elem_3_2    =    (A.elem_3_1 * B.elem_1_2) + (A.elem_3_2 * B.elem_2_2) + (A.elem_3_3 * B.elem_3_2);
    C.elem_3_3    =    (A.elem_3_1 * B.elem_1_3) + (A.elem_3_2 * B.elem_2_3) + (A.elem_3_3 * B.elem_3_3);

    return C;
}

Matrix_2X2 MatrixMul_2x2_2x2 (Matrix_2X2 A, Matrix_2X2 B)
{
    Matrix_2X2 C;

    C.elem_1_1    =    (A.elem_1_1 * B.elem_1_1) + (A.elem_1_2 * B.elem_2_1);
    C.elem_1_2    =    (A.elem_1_1 * B.elem_1_2) + (A.elem_1_2 * B.elem_2_2);

    C.elem_2_1    =    (A.elem_2_1 * B.elem_1_1) + (A.elem_2_2 * B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_1 * B.elem_1_2) + (A.elem_2_2 * B.elem_2_2);

    return C;
}

/**
 * @brief Perform Scalar multiplication of a 3x3 Matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_3X3  - Multiplied matrix
 *
 * */
Matrix_3X3 MatrixScalMul_3x3 (Matrix_3X3 A, double val)
{
    Matrix_3X3 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_1_2    =    (A.elem_1_2 * val);
    C.elem_1_3    =    (A.elem_1_3 * val);

    C.elem_2_1    =    (A.elem_2_1 * val);
    C.elem_2_2    =    (A.elem_2_2 * val);
    C.elem_2_3    =    (A.elem_2_3 * val);

    C.elem_3_1    =    (A.elem_3_1 * val);
    C.elem_3_2    =    (A.elem_3_2 * val);
    C.elem_3_3    =    (A.elem_3_3 * val);

    return C;
}


/**
 * @brief Perform Scalar multiplication of a 4x4 Matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_4X4  - Multiplied matrix
 *
 * */
Matrix_4X4 MatrixScalMul_4x4 (Matrix_4X4 A, double val)
{
    Matrix_4X4 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_1_2    =    (A.elem_1_2 * val);
    C.elem_1_3    =    (A.elem_1_3 * val);
    C.elem_1_4    =    (A.elem_1_4 * val);

    C.elem_2_1    =    (A.elem_2_1 * val);
    C.elem_2_2    =    (A.elem_2_2 * val);
    C.elem_2_3    =    (A.elem_2_3 * val);
    C.elem_2_4    =    (A.elem_2_4 * val);

    C.elem_3_1    =    (A.elem_3_1 * val);
    C.elem_3_2    =    (A.elem_3_2 * val);
    C.elem_3_3    =    (A.elem_3_3 * val);
    C.elem_3_4    =    (A.elem_3_4 * val);

    C.elem_4_1    =    (A.elem_4_1 * val);
    C.elem_4_2    =    (A.elem_4_2 * val);
    C.elem_4_3    =    (A.elem_4_3 * val);
    C.elem_4_4    =    (A.elem_4_4 * val);


    return C;
}

/**
 * @brief Perform Scalar multiplication of a 2x2 Matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_2X2  - Multiplied matrix
 *
 * */
Matrix_2X2 MatrixScalMul_2x2 (Matrix_2X2 A, double val)
{
    Matrix_2X2 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_1_2    =    (A.elem_1_2 * val);

    C.elem_2_1    =    (A.elem_2_1 * val);
    C.elem_2_2    =    (A.elem_2_2 * val);

    return C;
}

/**
 * @brief Perform Scalar multiplication of a 3x1 Matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_3X1  - Multiplied matrix
 *
 * */
Matrix_3X1 MatrixScalMul_3x1 (Matrix_3X1 A, double val)
{
    Matrix_3X1 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_2_1    =    (A.elem_2_1 * val);
    C.elem_3_1    =    (A.elem_3_1 * val);

    return C;
}

/**
 * @brief Perform Scalar multiplication of a 2x1 Matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_2X1  - Multiplied matrix
 *
 * */
Matrix_2X1 MatrixScalMul_2x1 (Matrix_2X1 A, double val)
{
    Matrix_2X1 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_2_1    =    (A.elem_2_1 * val);

    return C;
}


/**
 * @brief Perform Scalar multiplication of a 4x1 Matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_2X1  - Multiplied matrix
 *
 * */
Matrix_4X1 MatrixScalMul_4x1 (Matrix_4X1 A, double val)
{
    Matrix_4X1 C;

    C.elem_1_1    =    (A.elem_1_1 * val);
    C.elem_2_1    =    (A.elem_2_1 * val);
    C.elem_3_1    =    (A.elem_3_1 * val);
    C.elem_4_1    =    (A.elem_4_1 * val);

    return C;
}

/**
 * @brief Perform Scalar multiplication of a 10x1 Matrix
 * @details
 * @param Matrix_10X1 A - first matrix
 * @param double val  - scalar value
 * @return Matrix_10X1  - Multiplied matrix
 *
 * */
Matrix_10X1 MatrixScalMul_10X1 (Matrix_10X1 A, double val)
{
    Matrix_10X1 C;

    C.elem_1_1  = (A.elem_1_1 * val);
    C.elem_2_1  = (A.elem_2_1 * val);
    C.elem_3_1  = (A.elem_3_1 * val);
    C.elem_4_1  = (A.elem_4_1 * val);
    C.elem_5_1  = (A.elem_5_1 * val);
    C.elem_6_1  = (A.elem_6_1 * val);
    C.elem_7_1  = (A.elem_7_1 * val);
    C.elem_8_1  = (A.elem_8_1 * val);
    C.elem_9_1  = (A.elem_9_1 * val);
    C.elem_10_1 = (A.elem_10_1 * val);

    return C;
}

/**
 * @brief Perform Matrix multiplication between a 3x3 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Multiplied matrix
 *
 * */
Matrix_3X1 MatrixMul_3x3_3x1 (Matrix_3X3 A, Matrix_3X1 B)
{
    Matrix_3X1 C;

    C.elem_1_1    =    (A.elem_1_1 * B.elem_1_1) + (A.elem_1_2 * B.elem_2_1) + (A.elem_1_3 * B.elem_3_1);
    C.elem_2_1    =    (A.elem_2_1 * B.elem_1_1) + (A.elem_2_2 * B.elem_2_1) + (A.elem_2_3 * B.elem_3_1);
    C.elem_3_1    =    (A.elem_3_1 * B.elem_1_1) + (A.elem_3_2 * B.elem_2_1) + (A.elem_3_3 * B.elem_3_1);

    return C;
}


/**
 * @brief Perform Matrix multiplication between a 2x2 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Multiplied matrix
 *
 * */
Matrix_2X1 MatrixMul_2x2_2x1 (Matrix_2X2 A, Matrix_2X1 B)
{
    Matrix_2X1 C;

    C.elem_1_1    =    (A.elem_1_1 * B.elem_1_1) + (A.elem_1_2 * B.elem_2_1);
    C.elem_2_1    =    (A.elem_2_1 * B.elem_1_1) + (A.elem_2_2 * B.elem_2_1);
    return C;
}


/**
 * @brief Perform Matrix multiplication between a 4x4 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Multiplied matrix
 *
 * */
Matrix_4X1 MatrixMul_4x4_4x1 (Matrix_4X4 A, Matrix_4X1 B)
{
    Matrix_4X1 C;

    C.elem_1_1    =    (A.elem_1_1 * B.elem_1_1) + (A.elem_1_2 * B.elem_2_1) + (A.elem_1_3 * B.elem_3_1) + (A.elem_1_4 * B.elem_4_1);
    C.elem_2_1    =    (A.elem_2_1 * B.elem_1_1) + (A.elem_2_2 * B.elem_2_1) + (A.elem_2_3 * B.elem_3_1) + (A.elem_2_4 * B.elem_4_1);
    C.elem_3_1    =    (A.elem_3_1 * B.elem_1_1) + (A.elem_3_2 * B.elem_2_1) + (A.elem_3_3 * B.elem_3_1) + (A.elem_3_4 * B.elem_4_1);
    C.elem_4_1    =    (A.elem_4_1 * B.elem_1_1) + (A.elem_4_2 * B.elem_2_1) + (A.elem_4_3 * B.elem_3_1) + (A.elem_4_4 * B.elem_4_1);

    return C;
}



/**
 * @brief Perform Matrix addition between a 3x3 matrix and a 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Added matrix
 *
 * */
Matrix_3X3 MatrixAdd_3x3_3x3 (Matrix_3X3 A, Matrix_3X3 B)
{
    Matrix_3X3 C;

    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_1_2    =    (A.elem_1_2 + B.elem_1_2);
    C.elem_1_3    =    (A.elem_1_3 + B.elem_1_3);

    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_2 + B.elem_2_2);
    C.elem_2_3    =    (A.elem_2_3 + B.elem_2_3);

    C.elem_3_1    =    (A.elem_3_1 + B.elem_3_1);
    C.elem_3_2    =    (A.elem_3_2 + B.elem_3_2);
    C.elem_3_3    =    (A.elem_3_3 + B.elem_3_3);

    return C;
}

/**
 * @brief Perform Matrix addition between a 4x4 matrix and a 4x4 matrix
 * @details
 *
 * @param Matrix_4X4 A - first matrix
 * @param Matrix_4X4 B - second matrix
 * @return Matrix_4X4  - Added matrix
 *
 * */
Matrix_4X4 MatrixAdd_4x4_4x4 (Matrix_4X4 A, Matrix_4X4 B)
{
    Matrix_4X4 C;

    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_1_2    =    (A.elem_1_2 + B.elem_1_2);
    C.elem_1_3    =    (A.elem_1_3 + B.elem_1_3);
    C.elem_1_4    =    (A.elem_1_4 + B.elem_1_4);

    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_2 + B.elem_2_2);
    C.elem_2_3    =    (A.elem_2_3 + B.elem_2_3);
    C.elem_2_4    =    (A.elem_2_4 + B.elem_2_4);

    C.elem_3_1    =    (A.elem_3_1 + B.elem_3_1);
    C.elem_3_2    =    (A.elem_3_2 + B.elem_3_2);
    C.elem_3_3    =    (A.elem_3_3 + B.elem_3_3);
    C.elem_3_4    =    (A.elem_3_4 + B.elem_3_4);

    C.elem_4_1    =    (A.elem_4_1 + B.elem_4_1);
    C.elem_4_2    =    (A.elem_4_2 + B.elem_4_2);
    C.elem_4_3    =    (A.elem_4_3 + B.elem_4_3);
    C.elem_4_4    =    (A.elem_4_4 + B.elem_4_4);

    return C;
}

/**
 * @brief Perform Matrix addition between a 2x2 matrix and a 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X2 B - second matrix
 * @return Matrix_2X2  - Added matrix
 *
 * */
Matrix_2X2 MatrixAdd_2x2_2x2 (Matrix_2X2 A, Matrix_2X2 B)
{
    Matrix_2X2 C;

    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_1_2    =    (A.elem_1_2 + B.elem_1_2);

    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_2 + B.elem_2_2);

    return C;
}


/**
 * @brief Perform Matrix subtraction between a 3x3 matrix and a 3x3 matrix
 * @details
 *
 * @param Matrix_3X3 A - first matrix
 * @param Matrix_3X3 B - second matrix
 * @return Matrix_3X3  - Subtracted matrix
 *
 * */
Matrix_3X3 MatrixSub_3x3_3x3 (Matrix_3X3 A, Matrix_3X3 B)
{
    Matrix_3X3 C;

    C.elem_1_1    =    (A.elem_1_1 - B.elem_1_1);
    C.elem_1_2    =    (A.elem_1_2 - B.elem_1_2);
    C.elem_1_3    =    (A.elem_1_3 - B.elem_1_3);

    C.elem_2_1    =    (A.elem_2_1 - B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_2 - B.elem_2_2);
    C.elem_2_3    =    (A.elem_2_3 - B.elem_2_3);

    C.elem_3_1    =    (A.elem_3_1 - B.elem_3_1);
    C.elem_3_2    =    (A.elem_3_2 - B.elem_3_2);
    C.elem_3_3    =    (A.elem_3_3 - B.elem_3_3);

    return C;
}



/**
 * @brief Perform Matrix subtraction between a 2x2 matrix and a 2x2 matrix
 * @details
 *
 * @param Matrix_2X2 A - first matrix
 * @param Matrix_2X2 B - second matrix
 * @return Matrix_2X2  - Subtracted matrix
 *
 * */
Matrix_2X2 MatrixSub_2x2_2x2 (Matrix_2X2 A, Matrix_2X2 B)
{
    Matrix_2X2 C;

    C.elem_1_1    =    (A.elem_1_1 - B.elem_1_1);
    C.elem_1_2    =    (A.elem_1_2 - B.elem_1_2);

    C.elem_2_1    =    (A.elem_2_1 - B.elem_2_1);
    C.elem_2_2    =    (A.elem_2_2 - B.elem_2_2);

    return C;
}

/**
 * @brief Perform Matrix addition between a 3x1 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Added matrix
 *
 * */
Matrix_3X1 MatrixAdd_3x1_3x1 (Matrix_3X1 A, Matrix_3X1 B)
{
    Matrix_3X1 C;

    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);
    C.elem_3_1    =    (A.elem_3_1 + B.elem_3_1);

    return C;
}


/**
 * @brief Perform Matrix addition between a 4x1 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Added matrix
 *
 * */
Matrix_4X1 MatrixAdd_4x1_4x1 (Matrix_4X1 A, Matrix_4X1 B)
{
    Matrix_4X1 C;
    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);
    C.elem_3_1    =    (A.elem_3_1 + B.elem_3_1);
    C.elem_4_1    =    (A.elem_4_1 + B.elem_4_1);
    return C;
}
/**
 * @brief Perform Matrix addition between a 10x1 matrix and a 10x1 matrix
 * @details
 * @param Matrix_10X1 A - first matrix
 * @param Matrix_10X1 B - second matrix
 * @return Matrix_10X1  - Added matrix
 *
 * */
Matrix_10X1 MatrixAdd_10X1_10X1 (Matrix_10X1 A, Matrix_10X1 B)
{
    Matrix_10X1 C;
    C.elem_1_1   =  (A.elem_1_1  + B.elem_1_1);
    C.elem_2_1   =  (A.elem_2_1  + B.elem_2_1);
    C.elem_3_1   =  (A.elem_3_1  + B.elem_3_1);
    C.elem_4_1   =  (A.elem_4_1  + B.elem_4_1);
    C.elem_5_1   =  (A.elem_5_1  + B.elem_5_1);
    C.elem_6_1   =  (A.elem_6_1  + B.elem_6_1);
    C.elem_7_1   =  (A.elem_7_1  + B.elem_7_1);
    C.elem_8_1   =  (A.elem_8_1  + B.elem_8_1);
    C.elem_9_1   =  (A.elem_9_1  + B.elem_9_1);
    C.elem_10_1  =  (A.elem_10_1 + B.elem_10_1);
    return C;
}
/**
 * @brief Perform Matrix addition between a 2x1 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Added matrix
 *
 * */
Matrix_2X1 MatrixAdd_2x1_2x1 (Matrix_2X1 A, Matrix_2X1 B)
{
    Matrix_2X1 C;

    C.elem_1_1    =    (A.elem_1_1 + B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 + B.elem_2_1);

    return C;
}

/**
 * @brief Perform Matrix subtraction between a 3x1 matrix and a 3x1 matrix
 * @details
 *
 * @param Matrix_3X1 A - first matrix
 * @param Matrix_3X1 B - second matrix
 * @return Matrix_3X1  - Subtracted matrix
 *
 * */
Matrix_3X1 MatrixSub_3x1_3x1 (Matrix_3X1 A, Matrix_3X1 B)
{
    Matrix_3X1 C;

    C.elem_1_1    =    (A.elem_1_1 - B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 - B.elem_2_1);
    C.elem_3_1    =    (A.elem_3_1 - B.elem_3_1);

    return C;
}

/**
 * @brief Perform Matrix subtraction between a 4x1 matrix and a 4x1 matrix
 * @details
 *
 * @param Matrix_4X1 A - first matrix
 * @param Matrix_4X1 B - second matrix
 * @return Matrix_4X1  - Subtracted matrix
 *
 * */
Matrix_4X1 MatrixSub_4x1_4x1 (Matrix_4X1 A, Matrix_4X1 B)
{
    Matrix_4X1 C;

    C.elem_1_1    =    (A.elem_1_1 - B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 - B.elem_2_1);
    C.elem_3_1    =    (A.elem_3_1 - B.elem_3_1);
    C.elem_4_1    =    (A.elem_4_1 - B.elem_4_1);

    return C;
}

/**
 * @brief Perform Matrix subtraction between a 2x1 matrix and a 2x1 matrix
 * @details
 *
 * @param Matrix_2X1 A - first matrix
 * @param Matrix_2X1 B - second matrix
 * @return Matrix_2X1  - Subtracted matrix
 *
 * */
Matrix_2X1 MatrixSub_2x1_2x1 (Matrix_2X1 A, Matrix_2X1 B)
{
    Matrix_2X1 C;

    C.elem_1_1    =    (A.elem_1_1 - B.elem_1_1);
    C.elem_2_1    =    (A.elem_2_1 - B.elem_2_1);

    return C;
}

/**
 * @brief Returns a 3x3 identity matrix
 * @details 1's on the main diagonal and 0's elsewhere
 *
 * @param None
 * @return Matrix_3X3  - 3x3 Identity matrix
 *
 * */
Matrix_3X3 Eye3X3 (void)
{
    Matrix_3X3 identity_matrix;

    identity_matrix.elem_1_1 = 1;
    identity_matrix.elem_1_2 = 0;
    identity_matrix.elem_1_3 = 0;

    identity_matrix.elem_2_1 = 0;
    identity_matrix.elem_2_2 = 1;
    identity_matrix.elem_2_3 = 0;

    identity_matrix.elem_3_1 = 0;
    identity_matrix.elem_3_2 = 0;
    identity_matrix.elem_3_3 = 1;

    return identity_matrix;
}


/**
 * @brief Returns a 2x2 identity matrix
 * @details 1's on the main diagonal and 0's elsewhere
 *
 * @param None
 * @return Matrix_2X2  - 2x2 Identity matrix
 *
 * */
Matrix_2X2 Eye2X2 (void)
{
    Matrix_2X2 identity_matrix;

    identity_matrix.elem_1_1 = 1;
    identity_matrix.elem_1_2 = 0;

    identity_matrix.elem_2_1 = 0;
    identity_matrix.elem_2_2 = 1;


    return identity_matrix;
}

/**
 * @brief Return the transpose of a Matrix_3X3 element
 * @details
 *
 * @param  Matrix_3X3  - 3x3 Input matrix to be transposed
 * @return Matrix_3X3  - 3x3 Transposed matrix
 *
 * */
Matrix_3X3 MatrixTranspose_3x3 (Matrix_3X3 A)
{
    Matrix_3X3 A_Transpose;

    A_Transpose.elem_1_1    =    A.elem_1_1;
    A_Transpose.elem_1_2    =    A.elem_2_1;
    A_Transpose.elem_1_3    =    A.elem_3_1;

    A_Transpose.elem_2_1    =    A.elem_1_2;
    A_Transpose.elem_2_2    =    A.elem_2_2;
    A_Transpose.elem_2_3    =    A.elem_3_2;

    A_Transpose.elem_3_1    =    A.elem_1_3;
    A_Transpose.elem_3_2    =    A.elem_2_3;
    A_Transpose.elem_3_3    =    A.elem_3_3;

    return A_Transpose;
}


/**
 * @brief Return the transpose of a Matrix_4X4 element
 * @details
 *
 * @param  Matrix_4X4  - 4x4 Input matrix to be transposed
 * @return Matrix_4X4  - 4x4 Transposed matrix
 *
 * */
Matrix_4X4 MatrixTranspose_4x4 (Matrix_4X4 A)
{
    Matrix_4X4 A_Transpose;

    A_Transpose.elem_1_1    =    A.elem_1_1;
    A_Transpose.elem_1_2    =    A.elem_2_1;
    A_Transpose.elem_1_3    =    A.elem_3_1;
    A_Transpose.elem_1_4    =    A.elem_4_1;

    A_Transpose.elem_2_1    =    A.elem_1_2;
    A_Transpose.elem_2_2    =    A.elem_2_2;
    A_Transpose.elem_2_3    =    A.elem_3_2;
    A_Transpose.elem_2_4    =    A.elem_4_2;

    A_Transpose.elem_3_1    =    A.elem_1_3;
    A_Transpose.elem_3_2    =    A.elem_2_3;
    A_Transpose.elem_3_3    =    A.elem_3_3;
    A_Transpose.elem_3_4    =    A.elem_4_3;
    
    A_Transpose.elem_4_1    =    A.elem_1_4;
    A_Transpose.elem_4_2    =    A.elem_2_4;
    A_Transpose.elem_4_3    =    A.elem_3_4;
    A_Transpose.elem_4_4    =    A.elem_4_4;

    return A_Transpose;
}


/**
 * @brief Return the transpose of a Matrix_2X2 element
 * @details
 *
 * @param  Matrix_2X2  - 2x2 Input matrix to be transposed
 * @return Matrix_2X2  - 2x2 Transposed matrix
 *
 * */
Matrix_2X2 MatrixTranspose_2x2 (Matrix_2X2 A)
{
    Matrix_2X2 A_Transpose;

    A_Transpose.elem_1_1    =    A.elem_1_1;
    A_Transpose.elem_1_2    =    A.elem_2_1;

    A_Transpose.elem_2_1    =    A.elem_1_2;
    A_Transpose.elem_2_2    =    A.elem_2_2;

    return A_Transpose;
}


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
double VectorDotProd_3x1_3x1(Matrix_3X1 A, Matrix_3X1 B)
{
    double dot_product;

    dot_product = (A.elem_1_1 * B.elem_1_1) + (A.elem_2_1 * B.elem_2_1) + (A.elem_3_1 * B.elem_3_1);

    return dot_product;
}



/**
 * @brief Returns the dot product of two 2x1 vectors
 * @details
 *
 * @param  Matrix_2X1 A - 2x1 first matrix
 * @param  Matrix_2X1 B - 2x1 second matrix
 * @return double     - Dot product
 *
 * */
double VectorDotProd_2x1_2x1(Matrix_2X1 A, Matrix_2X1 B)
{
    double dot_product;

    dot_product = (A.elem_1_1 * B.elem_1_1) + (A.elem_2_1 * B.elem_2_1);

    return dot_product;
}

/**
 * @brief Returns the cross product of two 3x1 vectors
 * @details
 *
 * @param  Matrix_3X1 A - 3x1 first matrix
 * @param  Matrix_3X1 B - 3x1 second matrix
 * @return Matrix_3X1   - Cross product
 *
 * */
Matrix_3X1 VectorCrossProd_3x1_3x1(Matrix_3X1 A, Matrix_3X1 B)
{
    Matrix_3X1 cross_product;

    cross_product.elem_1_1 = (A.elem_2_1 * B.elem_3_1 - A.elem_3_1 * B.elem_2_1);
    cross_product.elem_2_1 = (A.elem_3_1 * B.elem_1_1 - A.elem_1_1 * B.elem_3_1);
    cross_product.elem_3_1 = (A.elem_1_1 * B.elem_2_1 - A.elem_2_1 * B.elem_1_1);

    return cross_product;
}

/**
 * @brief Returns the cross product of two 2x1 vectors
 * @details
 *
 * @param  Matrix_2X1 A - 2x1 first matrix
 * @param  Matrix_2X1 B - 2x1 second matrix
 * @return Matrix_2X1   - Cross product
 *
 * */
Matrix_1X1 VectorCrossProd_2x1_2x1(Matrix_2X1 A, Matrix_2X1 B)
{
    Matrix_1X1 cross_product;

    cross_product.elem_1_1 = (A.elem_1_1 * B.elem_2_1 - A.elem_2_1 * B.elem_1_1);

    return cross_product;
}

/// @brief calculates determinant of 2x2 matrix
/// @param M Matrix of which determinant to be calculated
/// @return determinant 
double MatrixDeterminant_2X2(Matrix_2X2 M)
{
    double detM = M.elem_1_1 * M.elem_2_2 - M.elem_1_2 * M.elem_2_1;
    return detM;
}

/// @brief      Calculates Determinant of a Matrix over first column
/// @param M    pointer to array storing the 2D matrix
/// @param size dimension of the matrix
/// @return     determinant of the matrix
double MatrixDeterminantOverColumn(Matrix_3X3 M)
{
    //as this is over column determinant, we will go through first column and second index of matrix is fixed to 0
    Matrix_2X2 m11, m21, m31;
    m11.elem_1_1 = M.elem_2_2;
    m11.elem_1_2 = M.elem_2_3;
    m11.elem_2_1 = M.elem_3_2;
    m11.elem_2_2 = M.elem_3_3;

    m21.elem_1_1 = M.elem_1_2;
    m21.elem_1_2 = M.elem_1_3;
    m21.elem_2_1 = M.elem_3_2;
    m21.elem_2_2 = M.elem_3_3;

    m31.elem_1_1 = M.elem_1_2;
    m31.elem_1_2 = M.elem_1_3;
    m31.elem_2_1 = M.elem_2_2;
    m31.elem_2_2 = M.elem_2_3;

    double minor11, minor21, minor31;
    minor11 = MatrixDeterminant_2X2(m11);
    minor21 = MatrixDeterminant_2X2(m21);
    minor31 = MatrixDeterminant_2X2(m31);

    double cofactor11, cofactor21, cofactor31;
    cofactor11 = minor11;
    cofactor21 = -minor21;
    cofactor31 = minor31;

    double detM = M.elem_1_1 * cofactor11 + M.elem_2_1 * cofactor21 + M.elem_3_1 * cofactor31;
    
    return detM;
}
/// @brief           performs scalar multiplication on a row
/// @param M         input Matrix
/// @param scalar    scalar to be multiplied 
/// @param rowNumber number of the row (first row = 1)
void Matrix3X3_RowOperation_ScalMul(Matrix_3X3 * M, double scalar, int rowNumber)
{
    switch (rowNumber)
    {
    case 1:
        /* code */
        M->elem_1_1 *= scalar;
        M->elem_1_2 *= scalar;
        M->elem_1_3 *= scalar;
        break;
    case 2:
        M->elem_2_1 *= scalar;
        M->elem_2_2 *= scalar;
        M->elem_2_3 *= scalar;
        break;
    case 3:
        M->elem_3_1 *= scalar;
        M->elem_3_2 *= scalar;
        M->elem_3_3 *= scalar;
    default:
        break;
    }
}
/// @brief           performs scalar division on a row: Ri/a
/// @param M         input Matrix
/// @param scalar    scalar to be divided by 
/// @param rowNumber number of the row (first row = 1)
void Matrix3X3_RowOperation_ScalDiv(Matrix_3X3 * M,double scalar, int rowNumber)
{
    switch (rowNumber)
    {
    case 1:
        M->elem_1_1 = divide(M->elem_1_1, scalar);       
        M->elem_1_2 = divide(M->elem_1_2, scalar);
        M->elem_1_3 = divide(M->elem_1_3, scalar);
        break;
    case 2:
        M->elem_2_1 = divide(M->elem_2_1, scalar);
        M->elem_2_2 = divide(M->elem_2_2, scalar);
        M->elem_2_3 = divide(M->elem_2_3, scalar);
        break;
    case 3:
        M->elem_3_1 = divide(M->elem_3_1, scalar);
        M->elem_3_2 = divide(M->elem_3_2, scalar);
        M->elem_3_3 = divide(M->elem_3_3, scalar);
    default:
        break;
    }
}

/// @brief calculates inverse of 3x3 Matrix
/// @param M Matrix of size 3x3
/// @return Matrix after inversion
Matrix_3X3 MatrixInverse_3X3(Matrix_3X3 M)
{
     if (MatrixDeterminantOverColumn(M) <= 1E-7)
     {
        return Eye3X3();
     }
    Matrix_3X3 I = Eye3X3();
    //using row operations to build inverse
    //making column 1 as 1,0,0

    if ( fabs(M.elem_1_1 - 1.0) > 1E-15)
    {
        Matrix3X3_RowOperation_ScalDiv(&I, M.elem_1_1, 1);
        Matrix3X3_RowOperation_ScalDiv(&M, M.elem_1_1, 1);
    }

    if ( fabs(M.elem_2_1) > 1E-15)
    {
        I.elem_2_1 -= I.elem_1_1 * M.elem_2_1;
        I.elem_2_2 -= I.elem_1_2 * M.elem_2_1;
        I.elem_2_3 -= I.elem_1_3 * M.elem_2_1;

        M.elem_2_2 -= M.elem_1_2 * M.elem_2_1;
        M.elem_2_3 -= M.elem_1_3 * M.elem_2_1;
        M.elem_2_1 -= M.elem_1_1 * M.elem_2_1;
    }

    if ( fabs(M.elem_3_1) > 1E-15)
    {
        I.elem_3_1 -= I.elem_1_1 * M.elem_3_1;
        I.elem_3_2 -= I.elem_1_2 * M.elem_3_1;
        I.elem_3_3 -= I.elem_1_3 * M.elem_3_1;

        M.elem_3_2 -= M.elem_1_2 * M.elem_3_1;
        M.elem_3_3 -= M.elem_1_3 * M.elem_3_1;
        M.elem_3_1 -= M.elem_1_1 * M.elem_3_1;

    }

    //making column 2 as 0,1,0
    if (fabs(M.elem_2_2 - 1.0) > 1E-15)
    {
        Matrix3X3_RowOperation_ScalDiv (&I, M.elem_2_2, 2);
        Matrix3X3_RowOperation_ScalDiv (&M, M.elem_2_2, 2);
    }

    if( fabs(M.elem_1_2) > 1E-15)
    {
        I.elem_1_1 -= I.elem_2_1 * M.elem_1_2;
        I.elem_1_2 -= I.elem_2_2 * M.elem_1_2;
        I.elem_1_3 -= I.elem_2_3 * M.elem_1_2;

        M.elem_1_1 -= M.elem_2_1 * M.elem_1_2;
        M.elem_1_3 -= M.elem_2_3 * M.elem_1_2;
        M.elem_1_2 -= M.elem_2_2 * M.elem_1_2;

    }

    if (fabs(M.elem_3_2) > 1E-15)
    {
        
        I.elem_3_1 -= I.elem_2_1 * M.elem_3_2;
        I.elem_3_2 -= I.elem_2_2 * M.elem_3_2;
        I.elem_3_3 -= I.elem_2_3 * M.elem_3_2;

        M.elem_3_1 -= M.elem_2_1 * M.elem_3_2;
        M.elem_3_3 -= M.elem_2_3 * M.elem_3_2;
        M.elem_3_2 -= M.elem_2_2 * M.elem_3_2;
        

    }

    //making column3 as 0,0,1
    if (fabs(M.elem_3_3 - 1.0) > 1E-15)
    {
        Matrix3X3_RowOperation_ScalDiv(&I, M.elem_3_3, 3);
        Matrix3X3_RowOperation_ScalDiv(&M, M.elem_3_3, 3);

    }

    if (fabs(M.elem_1_3) > 1E-15)
    {
        I.elem_1_1 -= I.elem_3_1 * M.elem_1_3;
        I.elem_1_2 -= I.elem_3_2 * M.elem_1_3;
        I.elem_1_3 -= I.elem_3_3 * M.elem_1_3;

        M.elem_1_1 -= M.elem_3_1 * M.elem_1_3;
        M.elem_1_2 -= M.elem_3_2 * M.elem_1_3;
        M.elem_1_3 -= M.elem_3_3 * M.elem_1_3;
    }

    if (fabs(M.elem_2_3) > 1E-15)
    {
        I.elem_2_1 -= I.elem_3_1 * M.elem_2_3;
        I.elem_2_2 -= I.elem_3_2 * M.elem_2_3;
        I.elem_2_3 -= I.elem_3_3 * M.elem_2_3;

        M.elem_2_1 -= M.elem_3_1 * M.elem_2_3;
        M.elem_2_2 -= M.elem_3_2 * M.elem_2_3;
        M.elem_2_3 -= M.elem_3_3 * M.elem_2_3;
    }


    return I;
}

/// @brief                  performs row operation Ri => a*Ri + b*Rj
/// @details                Ri is the ith row of Matrix M. 
/// @param M                Input matrix on which row operation to be done
/// @param rowTobeUpdate    index of the row to be updated in matrix array = Ri
/// @param scalar1          scalar to be multiplied by row being updated = a
/// @param rowFromUpdate    index of the row which to update the row from = Rj
/// @param scalar2          scalar to be multitpled to Rj = b
void Matrix_RowOperation(double * M,int numberOfRows, int numberOfColumns, int rowTobeUpdate, double scalar1, int rowFromUpdate, double scalar2)
{
    if (rowTobeUpdate >= numberOfRows || rowFromUpdate >= numberOfRows)
    {
        printf("Invalid input Row number!\n");
        exit(1);
    }
    
    for (int col=0; col<numberOfColumns; col++)
    {
        M[rowTobeUpdate*numberOfColumns + col] = scalar1 * (M[rowTobeUpdate*numberOfColumns + col]) + scalar2 * (M[rowFromUpdate*numberOfColumns + col]);
    }
}
/// @brief            performs scalar multiplication to a row in Matrix array  
/// @param M          input Matrix struct
/// @param rowNumber  index of the row to be update
/// @param scalar     scalar to be multiplied to the row
void Matrix_RowScalMultiplication(double * M,int numberOfRows, int numberOfColumns, int rowIndex, double scalar)
{   
    if (rowIndex >= numberOfRows)
    {
        printf("Invalid Input row number! Row number greater than matrix dimension!!\n");
        exit(1);
    }
    for (int col=0; col<numberOfColumns; col++)
    {
        M[rowIndex*numberOfColumns + col] *= scalar;
    }
}
/// @brief   calculates determinant of a matrix
/// @param M Matrix struct which specifies the matrix
/// @return  det of M
double Matrix_GeneralDeterminant(double * M, int numberOfRows, int numberOfColumns)
{
    double det = 0;
    if (numberOfColumns != numberOfRows)
    {
        printf("Matrix is Not Square!! Square can not be found!!\n");
    }
    else if ((numberOfColumns == numberOfRows) && (numberOfRows == 2))
    {
        det = M[0*2 + 0] * M[1*2 + 1] - M[0*2 + 1] * M[1*2 + 0];
        return det;
    }
    else
    {
        double minorArray[numberOfRows];
        double cofactorArray[numberOfRows];
        for(int row=0; row<numberOfRows; row++)
        {
            
            int MinorMatrix_numberOfColumns = numberOfColumns - 1;
            int MinorMatrix_numberOfRows    = numberOfRows - 1;
            double *MinorMatrix = calloc(MinorMatrix_numberOfRows * MinorMatrix_numberOfColumns, sizeof(double));

            int minorMatrixStoreRow = 0;
            int minorMatrixStoreCol = 0;
            for (int rw=0; rw<numberOfRows; rw++)
            {
                for(int cl=0; cl<numberOfColumns; cl++)
                {
                    if (rw != row && cl!=0)
                    {
                        MinorMatrix[minorMatrixStoreRow*MinorMatrix_numberOfColumns + minorMatrixStoreCol] = M[rw*numberOfColumns + cl];
                        if (minorMatrixStoreCol == (numberOfColumns - 2))
                        {
                            minorMatrixStoreCol = 0;
                            minorMatrixStoreRow++;
                        }
                        else
                        {
                            minorMatrixStoreCol++;
                        }   
                    }
                }
            }
            minorArray[row]    = Matrix_GeneralDeterminant(MinorMatrix, MinorMatrix_numberOfRows, MinorMatrix_numberOfColumns);
            cofactorArray[row] = minorArray[row] * pow(-1, (row+1+1));
            det               += cofactorArray[row] * M[row*numberOfColumns + 0];
            free(MinorMatrix);
        }
    }
    return det;
}

void printMatrixArray(double * M, int row, int cols)
{
    printf("\n");
    for (int rw = 0; rw<row; rw++)
    {
        for (int cl = 0; cl<cols; cl++)
        {
            printf("%f, ", M[rw*cols + cl]);
        }
        printf("\n");
    }
    printf("\n");
}
/// @brief              converts the input matrix into its row echelon form
/// @param M 
/// @param numberOfRows 
/// @param numberOfCols 
void Matrix_RowEchelonForm(double * M, int numberOfRows, int numberOfCols)
{
    for (int cl=0; cl<numberOfCols; cl++)
    {
        if (fabs(M[cl*numberOfCols + cl]) < 1E-15)
        {
            for (int i=cl+1; i<numberOfRows; i++)
            {
                if (i==cl)
                {
                    continue;
                }
                else
                {
                    if (fabs(M[i*numberOfCols + cl]) > 1E-15)
                    {
                        Matrix_RowSwitchRowOperation(M, numberOfRows, numberOfCols, cl, i);
                    }
                }
            }
        }
        for (int rw=cl+1; rw<numberOfRows; rw++)
        {
            Matrix_RowOperation(M, numberOfRows, numberOfCols, rw, 1, cl, -(divide(M[rw*numberOfCols + cl],M[cl*numberOfCols + cl])));
        }
    }
}

/// @brief           swtiches row1 with row 2 in input matrix M
/// @param M         input matrix
/// @param row1Index index of first row 
/// @param row2Index index of second row 
void Matrix_RowSwitchRowOperation(double * M, int numberOfRows, int numberOfCols, int row1Index, int row2Index)
{
    if (row1Index >= numberOfRows || row2Index >= numberOfRows)
    {
        printf("invalid Row index!!\n");
        exit(1);
    }
    for (int col=0; col<numberOfCols; col++)
    {
        double temp = M[row1Index*numberOfCols + col];
        M[row1Index*numberOfCols + col] = M[row2Index*numberOfCols + col];
        M[row2Index*numberOfCols + col] = temp;
    }
}

/// @brief               calculates determinant using row echelon form
/// @param M             pointer to input matrix
/// @param numberOfRows  total number of rows in matrix
/// @param numberOfCols  total number of columns in matrix
/// @return 
double Matrix_DetRowEchelon(double *M, int numberOfRows, int numberOfCols)
{
    Matrix_RowEchelonForm(M, numberOfRows, numberOfCols);
    double det=1;
    for (int rw=0; rw<numberOfRows; rw++)
    {
        det *= M[rw*numberOfCols + rw];
    }
    return det;
}

/// @brief              calculates matrix inverse using general row operations
/// @param M            input matrix 
/// @param Minv         pointer to an Identity matrix for performing row operations on
/// @param numberOfRows total number of rows in M
/// @param numberOfCols total number of cols in M
/// @return 
/// @brief              calculates matrix inverse using general row operations
/// @param M            input matrix 
/// @param Minv         pointer to an Identity matrix for performing row operations on
/// @param numberOfRows total number of rows in M
/// @param numberOfCols total number of cols in M
/// @return 
void Matrix_GeneralInverse(double * M, int numberOfRows, int numberOfCols, double * Minv)
{
    double det = Matrix_DetRowEchelon(M, numberOfRows, numberOfCols);
    if (fabs(det) <= 1E-15)
    {
        printf("Matrix is Singular!!\n");
        exit(1);
    }
     for (int cl=0; cl<numberOfCols; cl++)
    {
        if (fabs(M[cl*numberOfCols + cl]) < 1E-15)
        {
            for (int i=cl+1; i<numberOfRows; i++)
            {
                if (i==cl)
                {
                    continue;
                }
                else
                {
                    if (fabs(M[i*numberOfCols + cl]) > 1E-15)
                    {
                        Matrix_RowSwitchRowOperation(Minv, numberOfRows, numberOfCols, cl, i);
                        Matrix_RowSwitchRowOperation(M, numberOfRows, numberOfCols, cl, i);
                    }
                }
            }
        }
        if (fabs(M[cl*numberOfCols + cl] - 1) > 1E-15)
        {
            Matrix_RowScalMultiplication(Minv, numberOfRows, numberOfCols, cl, divide(1.0, M[cl*numberOfCols + cl]));
            Matrix_RowScalMultiplication(M, numberOfRows, numberOfCols, cl, divide(1.0, M[cl*numberOfCols + cl]));
        }
        for (int rw=0; rw<numberOfRows; rw++)
        {
            if (rw == cl)
            {
                continue;
            }
            else{
                Matrix_RowOperation(Minv, numberOfRows, numberOfCols, rw, 1, cl, -(M[rw*numberOfCols + cl]));
                Matrix_RowOperation(M, numberOfRows, numberOfCols, rw, 1, cl, -(M[rw*numberOfCols + cl]));
            }
        }
    }
}

/// @brief          performs matrix multiplication [M1]ij * [M2]jk = [M]ik
/// @param M1       first matrix     
/// @param M2       second matrix
/// @param M1_rows  number of rows in first matrix
/// @param M1_cols  number of columns in first matrix = numnber of rows in second matrix
/// @param M2_cols  number of columns in second matrix
/// @param M        Matrix pointer to store the result (pass zero matrix of results size)
void MatrixMul_General(double *M1, double *M2, int M1_rows, int M1_cols, int M2_cols, double * M)
{
    for (int i=0; i<M1_rows; i++)
    {
        for (int k=0; k<M2_cols; k++)
        {
            for (int j=0; j<M1_cols; j++)
            {   
                M[i*M2_cols + k] += M1[i*M1_cols + j] * M2[j*M2_cols + k];
            }
        }
    }
}

/// @brief         converts input matrix into its transpose
/// @param M       input matrix
/// @param numRows number of rows in input matrix
/// @param numCols number of cols in input matrix
void MatrixTranspose_General(double *M, int numRows, int numCols)
{
    double temp=0;
    for (int i=0; i<numRows; i++)
    {
        for (int j=i; j<numCols; j++)
        {
            if (i!=j)
            {
                temp = M[i*numCols + j];
                M[i*numCols + j] = M[j*numCols + i];
                M[j*numCols + i] = temp;
            }
        }
    }
}
