#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 30
#define MAX_VALUES 100


int main()
{

    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int values[MAX_VALUES];
    int sum;

    file = fopen("data.csv","r");

    while(fgets(line,sizeof(line),file)!=NULL)
    {
        sum=0;
        int count = 0;

        token = strtok(line, ",");
        while(token!=NULL && count<MAX_VALUES)
        {
            int n = atoi(token);
            sum+=n;
            values[count]=n;

            printf("%d, ",n);

            count++;
            token = strtok(NULL,",");
        }
        
        printf("= %d\n",sum);
    }

}