#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

void countdown_timer(int seconds) 
{
    while (seconds > 0) 
    {
        printf("Child: %d seconds remaining...\n", seconds);
        sleep(1);
        seconds--;
    }
    printf("Child: Timer done!\n");
}

int main() 
{
    int countdown = 10; // Countdown timer in seconds
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    

    if (child_pid == 0) 
    {
        // Child process
        countdown_timer(countdown);
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        // Parent process
        struct timeval parent_start, parent_end;
        gettimeofday(&parent_start, NULL);

        int status;
        waitpid(child_pid, &status, 0);

        gettimeofday(&parent_end, NULL);
        
        double parent_time_taken = (parent_end.tv_sec - parent_start.tv_sec) +
                                   (parent_end.tv_usec - parent_start.tv_usec) / 1e6;

        printf("Parent: Child timer verification - Parent time taken: %.6f seconds\n", parent_time_taken);
    }

    return 0;
}
