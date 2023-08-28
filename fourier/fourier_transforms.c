/**
 ******************************************************************************
 * @file           : fourier_transforms.c
 * @project        : Agnikul Generic Software Library
 * @brief          : Fast Fourier Transform - also includes
 *                   Direct Fourier Transform
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

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fourier_transforms.h"


/*******************************************************************************
 * Function definitions
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
FUNC_STATUS DirectFourierTransform(double complex *V, double complex *v, int len)
{
	/**<Check for NULL pointers*/
	if((V == NULL) | (v == NULL)){
		//PRINT_ERR("NULL pointer detected!\n");
		perror("NULL pointer detected!\n");
        return FAILURE;
	}

	/**<Check for 0 len*/
	if(len <= 0){
		//PRINT_ERR("0 error!\n");
        perror("0 error!\n");
		return FAILURE;
	}

    for (int i=0; i<len; i++)
    {
        for (int j=0; j<len; j++)
        {
            /* {X(k)}=[exp^(-i*2*pi*k*n/N)]*{x(n)} */
            *(V+i)+=cexp(-I*2*PI*i*j/len)*(*(v+j));
        }
    }
    return SUCCESS;
}

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
 * @return  FUNC_STATUS 	  - Success / Failure
 *
 * */
FUNC_STATUS FastFourierTransform(double complex* V, double complex *v, int length)
{
	/**<Check for NULL pointers*/
	if((V == NULL) | (v == NULL)){
		//PRINT_ERR("NULL pointer detected!\n");
        perror("NULL pointer detected!\n");
		return FAILURE;
	}

	/**<Check for 0 len*/
	if(length <= 0){
		//PRINT_ERR("0 error!\n");
        perror("0 error!\n");
		return FAILURE;

	}else if (length==1)
    {
        *V=*v;
    }
    else
    {
        double complex G[length/2], H[length/2];
        double complex v_odd[length/2], v_even[length/2];
        for (int fft_index=0;fft_index<length;fft_index++)
        {
            if (1 == (fft_index + 1) % 2)
            {
                v_odd[fft_index/2]=*(v+fft_index);
            }
            else
            {
                v_even[fft_index/2]=*(v+fft_index);
            }
        }

        /* Recursive calls of FastFourierTransform() function */
        FastFourierTransform(&G[0],&v_odd[0],length/2);
        FastFourierTransform(&H[0],&v_even[0],length/2);

        for (int fft_index=0;fft_index<length/2;fft_index++)
        {
            *(V+fft_index)=(*(G+fft_index))+(*(H+fft_index))*cexp(-I*2*PI*fft_index/length);
            *(V+fft_index+length/2)=(*(G+fft_index))+(*(H+fft_index))*cexp(-PI*I-I*2*PI*fft_index/length);
        }
    }

	return SUCCESS;
}

