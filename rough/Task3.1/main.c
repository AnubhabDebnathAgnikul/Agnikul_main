#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* function(void* arg)
{
    char* pointer = (char*)arg; 
    //char value = *pointer;
    //printf("the number is: %c\n", *pointer);
    char filename[100];
    int i=0;
    while(*pointer!=0)
    {
        //printf("the number is: %c\n", *pointer);
        filename[i] = *pointer;
        pointer++;
        i++;
    }
    strcat(filename,".txt");
    FILE *fp;
    fp = fopen(filename,"w");
    fprintf(fp,"%s","I'm a super sayian!!!");
    fclose(fp);

    printf("%s created\n",filename);
    return 0;

}

int main()
{
    pthread_t thread_1, thread_2;

    char n[] = "thread1";
    char m[] = "thread2";

    pthread_create(&thread_1,NULL,function,(void*)&n);     
    pthread_create(&thread_2,NULL,function,(void*)&m);

    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
}