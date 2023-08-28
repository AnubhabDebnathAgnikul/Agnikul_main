#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <math.h>



#define PORT 1234
#define MESSAGE "Hello, client! it's server"
#define MAX 100
#define BUFFER_SIZE 1024

int main() 
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    struct timespec t_sent, t_received;


    FILE *dataFile = fopen("time_data.txt", "w");
    if (dataFile == NULL) 
    {
        perror("Failed to open time_data.txt");
        return 1;
    }

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL) {
        perror("Failed to initialize Gnuplot");
        return 1;
    }

    // Set up Gnuplot settings for real-time plotting
    fprintf(gnuplotPipe, "set title 'Real-time Delay Data Plot'\n");
    fprintf(gnuplotPipe, "set xlabel 'Epoch'\n");
    fprintf(gnuplotPipe, "set ylabel 'Delay in nanonsec'\n");
    fprintf(gnuplotPipe, "set yrange [0:400000]\n");
    fprintf(gnuplotPipe, "plot 'time_data.txt' with lines\n");

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) 
    {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept a new client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) 
    {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    char message[100];
    char buffer[BUFFER_SIZE] = {0};
    int i = 10,j;
    uint64_t time_sent,time_rec,delay,mean_delay=0;


    int count = 0;
    while(count<100000)
    {
        clock_gettime(CLOCK_MONOTONIC,&t_sent);

        time_sent = (t_sent.tv_sec)*pow(10,9)+t_sent.tv_nsec;
        write(new_socket,&i,sizeof(i));
        
        valread = read(new_socket, &j,sizeof(j));
        
        clock_gettime(CLOCK_MONOTONIC,&t_received);
        delay = ((t_received.tv_sec)*pow(10,9)+t_received.tv_nsec)-(t_sent.tv_sec*pow(10,9)+t_sent.tv_nsec);
    

        fprintf(dataFile, "%ld\n", delay);
        fflush(dataFile);  // Flush the buffer to ensure data is written immediately

        // Update the plot in real-time
        // fprintf(gnuplotPipe, "replot\n");
        // fflush(gnuplotPipe);

        // usleep(1000);
        count++;
    }

    close(new_socket);
    close(server_fd);

    // Close the files and Gnuplot pipe (this will never be reached in an infinite loop)
    fclose(dataFile);
    pclose(gnuplotPipe);

    return 0;
}
