#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid = fork();
    
    if (pid == -1) {
        printf("Failed to create child process.\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        int frequency = 10; // Frequency in Hz
        int period = 1000000 / frequency; // Period in microseconds
        int iterations = frequency; // Print "hello" for 1 second
        
        int i;
        for (i = 0; i < iterations; i++) {
            printf("Hello\n");
            usleep(period);
        }
    }
    else {
        // Parent process
        sleep(1); // Wait for 1 second
        printf("Terminating child process.\n");
        kill(pid, SIGTERM); // Terminate the child process
        wait(NULL); // Wait for the child process to exit
    }
    
    return 0;
}
