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

    // Open the CSV file in reading mode
    file = fopen("data.csv", "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        
        sum = 0;
        int count = 0;

        // Tokenize the line using comma as the delimiter
        token = strtok(line, ",");
        while (token != NULL && count < MAX_VALUES) 
        {
            // Convert the token to an integer 
            int n = atoi(token);
            sum += n;
            values[count] = n;
            count++;

            // Move to the next token
            token = strtok(NULL, ",");
        }


        printf("Sum of row elements: %d\n", sum);

        printf("Values in the row: ");
        for (int i = 0; i < count; i++) 
        {
            printf("%d ", values[i]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
