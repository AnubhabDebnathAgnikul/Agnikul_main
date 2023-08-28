#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 100
int getRandomNumber() {
    return rand() % 101;
}

int main() {
    // Initialize the random number generator with a seed
    srand(time(NULL));

    FILE *dataFile = fopen("data.txt", "w");
    if (dataFile == NULL) {
        perror("Failed to open data.txt");
        return 1;
    }

    // Initialize Gnuplot and create a pipe for real-time plotting
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL) {
        perror("Failed to initialize Gnuplot");
        return 1;
    }

    // Set up Gnuplot settings for real-time plotting
    fprintf(gnuplotPipe, "set title 'Real-time Random Data Plot'\n");
    fprintf(gnuplotPipe, "set xlabel 'Time'\n");
    fprintf(gnuplotPipe, "set ylabel 'Value'\n");
    fprintf(gnuplotPipe, "set yrange [0:100]\n");
    fprintf(gnuplotPipe, "plot 'data.txt' with lines\n");

    // Generate and save random numbers in an infinite loop
    while (1) {
        int randomNumber = getRandomNumber();
        fprintf(dataFile, "%d\n", randomNumber);
        fflush(dataFile);  // Flush the buffer to ensure data is written immediately

        // Update the plot in real-time
        fprintf(gnuplotPipe, "replot\n");
        fflush(gnuplotPipe);

        // Sleep for a short interval (e.g., 1 second)
        usleep(1000000);  // Sleep for 1 second
    }

    // Close the files and Gnuplot pipe (this will never be reached in an infinite loop)
    fclose(dataFile);
    pclose(gnuplotPipe);

    return 0;
}
