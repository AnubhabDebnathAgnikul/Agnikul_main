#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 1000
int main()
{
    printf("enter something: ");
    char my_string[MAX];
    while(1)
    {
        if (fgets(my_string,MAX,stdin) != 0)
        {
            if(!strcmp(my_string,"stop"))
            {
                break;
            }
            printf("\nyou entered: %s\n", my_string);
        }
        else
            printf("error!");
        memset(my_string,0,MAX);
    }
   
}