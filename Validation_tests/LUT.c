#include<stdlib.h>
#include<stdio.h>

int main()
{
    int x =1,flag=0;
    unsigned char a[8];
    // physical_address(p);
    for(int t=0;t<8;t++)
    {
       a[t] = x<<t;
       printf("%d\n",a[t]);
    }
    
}