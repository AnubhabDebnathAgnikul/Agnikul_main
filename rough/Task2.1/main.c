#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{   
    int process_id = fork();
    //printf("this fork\n");
    FILE *fp;
    //char file_name = str(process_id);
    //printf("%d\n",process_id);
    char file_name[10]; 
    sprintf(file_name,"%d",process_id); 
    //printf("file name %s\n",file_name);
    strcat(file_name,".txt");
    fp = fopen(file_name,"w");
    int num0 = rand()% 10+1;
    int num1 = rand()% 10+1;
    if(process_id==0)
        fprintf(fp,"%d\n",num0);
    else
        fprintf(fp,"%d\n",num1);
    

    fclose(fp);

}