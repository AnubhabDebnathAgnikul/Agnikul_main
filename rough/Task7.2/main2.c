#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 30
#define MAX_VALUES 100


int main()
{

    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int values[MAX_VALUES];
    int sum;

    input_file = fopen("data.csv","r");
    output_file = fopen("out.csv","w");

    while(fgets(line,sizeof(line),input_file)!=NULL)
    {
        sum=0;
        int count = 0;

        token = strtok(line, ",");
        while(token!=NULL && count<MAX_VALUES)
        {
            int n = atoi(token);
            sum+=n;
            values[count]=n;

            //printf("%d, ",n);
            
            count++;
            token = strtok(NULL,",");
        }
        for (int i = 0; i < count; i++) 
        {
            fprintf(output_file, "%d", values[i]);
            if (i < count - 1) 
            {
                fprintf(output_file, ",");
            }
        }

        fprintf(output_file, "\n");
    }

}