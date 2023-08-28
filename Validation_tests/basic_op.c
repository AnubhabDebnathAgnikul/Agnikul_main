#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<math.h>

long int random()
{
    time_t t;
    time(&t);
    srand(t);

    int n = (rand()%360)+1;
    return n;
}

int swap()
{
    int a = random();
    int b = random();

    int real_a = a;
    int real_b = b;

    a = a+b;
    b = a-b;
    a = a-b;

    if(b==real_a && a==real_b)
    return 1;
    else
    return 0; 
}

int trig()
{
    int theta = random(); 
    // float a = sin(theta);
    // float b = cos(theta);
    // float c = tan(theta);
    // printf("%f,%f,%f\n", a,b,c);
    double a = sin(theta);
    double b = cos(theta);
    double c = tan(theta);

    double result = a*a+ b*b;
    // printf("%f\n",result);

    if((a/b)==c)
        return 1;
    else
        return 0;
}

int logical()
{
    time_t t;
    int bits = 8;
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

    if((lsb==lsb_l)&&(msb==msb_l)&&(n==(lsb_l|msb_l))&&((msb>>4)|(lsb<<4) == n_shift))
        return 1;
    else
        return 0;
}


int main()
{
    if(swap()==1 && trig()==1 && logical()==1) 
    printf("success\n");
    else
    printf("failed\n");


}