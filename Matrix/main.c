#include<stdio.h>
#include<math.h>
#include"matrix_ops.c"

int main()
{
    int a = 1, b = 2;

    Matrix_16X1 m16_1;
    Matrix_3X3 m3_3;
    Matrix_2X2 m2_2;
    Matrix_3X1 m3_1;
    Matrix_2X1 m2_1;
    Matrix_1X1 m1_1;
    Matrix_4X4 m4_4;
    Matrix_4X1 m4_1;
    Matrix_10X1 m10_1;

    m16_1.elem_1_1 = a;
    m16_1.elem_2_1 = a;
    m16_1.elem_3_1 = a;
    m16_1.elem_4_1 = a;
    m16_1.elem_5_1 = a;
    m16_1.elem_6_1 = a;
    m16_1.elem_7_1 = a;
    m16_1.elem_8_1 = a;
    m16_1.elem_9_1 = a;
    m16_1.elem_10_1 = a;
    m16_1.elem_11_1 = a;
    m16_1.elem_12_1 = a;
    m16_1.elem_13_1 = a;
    m16_1.elem_14_1 = a;
    m16_1.elem_15_1 = a;
    m16_1.elem_16_1 = a;

    m3_3.elem_1_1 = a;
    m3_3.elem_1_2 = a;
    m3_3.elem_1_3 = a;
    m3_3.elem_2_1 = a;
    m3_3.elem_2_2 = a;
    m3_3.elem_2_3 = a;
    m3_3.elem_3_1 = a;
    m3_3.elem_3_2 = a;
    m3_3.elem_3_3 = a;


    m2_2.elem_1_1 = a;
    m2_2.elem_1_2 = a;
    m2_2.elem_2_1 = b;
    m2_2.elem_2_2 = b;

    m3_1.elem_1_1 = a;
    m3_1.elem_2_1 = b;
    m3_1.elem_3_1 = a;

    m2_1.elem_1_1 = a;
    m2_1.elem_2_1 = a;


    m1_1.elem_1_1 = b;


    m4_4.elem_1_1 = a;
    m4_4.elem_1_2 = a;
    m4_4.elem_1_3 = a;
    m4_4.elem_1_4 = a;
    m4_4.elem_2_1 = b;
    m4_4.elem_2_2 = b;
    m4_4.elem_2_3 = b;
    m4_4.elem_2_4 = b;
    m4_4.elem_3_1 = a;
    m4_4.elem_3_2 = a;
    m4_4.elem_3_3 = a;
    m4_4.elem_3_4 = a;
    m4_4.elem_4_1 = b;
    m4_4.elem_4_2 = b;
    m4_4.elem_4_3 = b;
    m4_4.elem_4_4 = b;

    m4_1.elem_1_1 = a;
    m4_1.elem_2_1 = b;
    m4_1.elem_3_1 = a;
    m4_1.elem_4_1 = b;


    m10_1.elem_1_1 = a;
    m10_1.elem_2_1 = a;
    m10_1.elem_3_1 = a;
    m10_1.elem_4_1 = a;
    m10_1.elem_5_1 = a;
    m10_1.elem_6_1 = a;
    m10_1.elem_7_1 = a;
    m10_1.elem_8_1 = a;
    m10_1.elem_9_1 = a;
    m10_1.elem_10_1 = a;

    double result, arg = 100;
    
    result = Trace_3x3(m3_3);
    //printf("%lf",result);


    Matrix_3X3 m3_3_result = MatrixMul_3x3_3x3(m3_3,m3_3);

    //PrintMat_3X3(m3_3_result);
    double val = 100;
    Matrix_10X1 m10_1_result =MatrixScalMul_10X1(m10_1,val);
    
    result = tangent(arg);
    //printf("%lf",result);
    result = arcTangent2(10,87);
    //printf("%lf",result);

    result = arcCosine(0.5);

    result = arcSine(0.3);

    result = divide(40,160);
    //printf("%lf",result);

    Matrix_3X1 m3_1_unit = GetUnitVector(m3_1);
    //PrintMat_3X1(m3_1_unit);

    result = norm2(m3_1);
    printf("%lf",result);


    

}