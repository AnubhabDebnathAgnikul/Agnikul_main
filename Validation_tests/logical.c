#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define bits 8

// int shift(unsigned char n,int s)
// {   
//     unsigned char n_left = (n<<s) | (n>>(bits-s));
//     printf("%d %d",n,n_left); 
// }
int logical()
{
    time_t t;
    unsigned char my_char =  240;
    unsigned char f = 255;
    unsigned char my_char_not = ~my_char;
    srand(time(&t));
    unsigned char n = rand();

    //and & not
    unsigned char lsb = my_char_not & n;
    unsigned char msb = my_char & n;

    //xor & or
    unsigned char msb_l = n^lsb;
    unsigned char lsb_l = n^msb;    
    // printf("%d %d", n,lsb_l|msb_l);

    //shift
    unsigned char n_shift = (n<<4)| (n>>(bits-4)) ;
    // printf("%d %d %d %d", lsb,msb,lsb_l,msb_l);
    // printf("%d %d %d",n,(msb>>4)|(lsb<<4),n_shift);
}


int main()
{
    logical();
}