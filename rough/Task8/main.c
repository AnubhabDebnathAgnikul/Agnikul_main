#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process with PID: %d\n", getpid());
        printf("Child process is sleeping...\n");
        sleep(5);
        printf("Child process woke up!\n");
    } else {
        // Parent process
        printf("Parent process with PID: %d\n", getpid());
        printf("Parent process is sleeping...\n");
        sleep(2);
        printf("Parent process woke up and is killing the child process...\n");
        kill(child_pid, SIGKILL);

        int status;
        pid_t return_pid = waitpid(child_pid, &status, 0);

        if (return_pid == -1) 
        {
            printf("error\n");
        } 
        else if (return_pid == 0) 
        {
            printf("child is still running\n");
        } 
        else if (return_pid == child_pid) 
        {
            printf("child is finished\n");
        }


    }

    return 0;
}
