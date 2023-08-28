#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of the shared memory

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key for the shared memory segment
    key = ftok(".", 'R');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        while (1) {
            printf("Child Process: %s\n", shm);
            sleep(1);
        }
    } else {
        // Parent process
        while (1) {
            printf("Enter data: ");
            fgets(shm, SHM_SIZE, stdin);
        }
    }

    // Detach the shared memory segment
    shmdt(shm);

    // Deallocate the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

