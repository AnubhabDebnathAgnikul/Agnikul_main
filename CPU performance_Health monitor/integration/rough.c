#include<stdio.h>

int main()

{
    char core_id[4] = {'0','1','2','3'}; 
    char line[256];
    line[3]='2'
    for(int i=0; i<4;i++)
    {
        if(core_id[i] == line[3])
        {
            printf("yes\n");
        }
    }
}