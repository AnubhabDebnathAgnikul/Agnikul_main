#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* printHello(void* arg) 
{
    int i=0;
    while (1) 
    {
        printf("Hello, World! %d\n",i);
        i++;
        usleep(1000000 / 10); // Sleep for 100 milliseconds (10 Hz)
    }
    
}

int main() {
    pthread_t thread;
    int err;

    
    err = pthread_create(&thread, NULL, printHello, NULL);
    if (err != 0) 
    {
        printf("Error creating thread: %d\n", err);
        return 1;
    }

    // Wait for 2 seconds
    sleep(2);

    // Cancel the child thread and wait for it to terminate
    pthread_cancel(thread);
    pthread_join(thread, NULL);

    printf("Thread terminated.\n");
    return 0;
}
