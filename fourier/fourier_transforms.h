/**
 ******************************************************************************
 * @file           : fourier_transforms.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Fourier Transform - Direct FT and Fast FT implementation
 * @author         : Siddartha Tadepalli, Sreedhar Mahadevan
 * @version        : v1.0
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
*/
#ifndef INC_FOURIER_TRANSFORMS_H_
#define INC_FOURIER_TRANSFORMS_H_

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <math.h>
#include <complex.h>
#include "fault_handling.h"

/*******************************************************************************
 * Preprocessor definitions
 ******************************************************************************/
#ifndef PI
# define PI	3.14159265358979323846264338327950288
#endif

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief   Direct Fourier Transform implementation
 * @details The order of the transform O(n)= n^2
 *          The method is by matrix multiplication.
 *          If x(n) is the discretized time domain input, X(k) is the discretized
 *          frequency domain output of length N:
 *
 *          {X(k)}=[exp^(-i*2*pi*k*n/N)]*{x(n)}
 *
 * @param   double complex V  - Pointer of a complex datatype for the calculated DFT values
 * @param   double complex v  - Pointer of a complex datatype for the inputs to DFT
 * @param   int len           - Number of inputs
 * @return  FUNC_STATUS 	  - Success / Failure
 *
 * */
FUNC_STATUS DirectFourierTransform(double complex* V, double complex *v, int len);


/**
 * @brief   Fast Fourier Transform implementation
 * @details The order of the transform is O(n)=n*log2(n)
 *          It is implemented in a recursive fashion to create a butterfly structure and decrease
 *          the number of computations.
 *          Constraint: Only applicable for signals of length 2n.
 *          The function is recursively called for odd and even numbers separately
 *          (each call reduces the array size by 2) until the length is one (base case),
 *          where the value is returned as output
 *
 * @param   double complex V  - Pointer of a complex datatype for the calculated FFT values
 * @param   double complex v  - Pointer of a complex datatype for the inputs to FFT
 * @param   int len           - Number of inputs
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS FastFourierTransform(double complex* V, double complex *v, int len);



#endif /* INC_FOURIER_TRANSFORMS_H_ */
