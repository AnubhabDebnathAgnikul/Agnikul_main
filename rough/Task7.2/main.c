#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VALUES 100

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char *token;
    int values[MAX_VALUES];
    int offset = 100;

    // Open the input CSV file for reading
    inputFile = fopen("data.csv", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Create the output CSV file for writing
    outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        perror("Error creating output file");
        exit(EXIT_FAILURE);
    }

    // Read each line from the input file
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        int count = 0;

        // Tokenize  line using comma as the delimiter
        token = strtok(line, ",");
        while (token != NULL && count < MAX_VALUES) {
            // Convert token to an integer and add offset
            int value = atoi(token);
            values[count] = value + offset;
            count++;

          
            token = strtok(NULL, ",");
        }

        // Write to the output file
        for (int i = 0; i < count; i++) {
            fprintf(outputFile, "%d", values[i]);
            if (i < count - 1) {
                fprintf(outputFile, ",");
            }
        }
        fprintf(outputFile, "\n");
    }


    fclose(inputFile);
    fclose(outputFile);

    printf("Output file created successfully.\n");

    return 0;
}
