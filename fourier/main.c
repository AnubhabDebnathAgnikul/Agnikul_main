#include <stdio.h>
#include <math.h>
#include<complex.h>
#include"fourier_transforms.c"
#define PI 3.14
int main()
{
    FILE *fp = NULL;
    FILE *fr = NULL;
    fp = fopen("plt.txt","w");
    double f1 = 200;
    double fs = 1000;

    double complex vector[5000],DFT[5000],FFT[5000];
    for(int t=0;t<5000;t++)
    {
        vector[t] = 100*cos(2*PI*f1/fs*t)/*+I*sin(2*PI*f2*t);*/;
        fprintf(fp,"%d\t%lf+i*%lf\n", t,creal(vector[t]),cimag(vector[t]));
    }

    DirectFourierTransform(DFT,vector,5000);
    for(int i=0; i<5000;i++)
    {
        //printf("%lf\n",DFT[i]); 
    }
    FastFourierTransform(FFT,vector,5000);

    fr = fopen("fft_plt.txt","w");
    for(int i=5000; i>2500;i--)
    {
        double freq = ((5000-i)*fs)/5000;
        printf("%lf\n",freq);
        fprintf(fr,"%lf\t%lf+i*%lf\n",freq, creal(DFT[i]),cimag(DFT[i]));
    }
    //printf("%ld\n",sizeof(FFT));
    
}