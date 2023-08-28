#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int MAX = 10;
int data = 0;
int flag = 0;
pthread_t parent_thread,child_thread;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *child_function(void *arg)
{
    while(data < MAX) 
    {
        pthread_mutex_lock(&mutex);
        while(flag != 1) 
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d \n", data);
        flag=0;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    printf("terminating child process\n");
    pthread_exit(0);
}
void *parent_function(void *arg)
{
    while(data < MAX) 
    {
        pthread_mutex_lock(&mutex);
        while(flag != 0) 
        {
            pthread_cond_wait(&cond, &mutex);
        }
        //printf("%d ", data++);
        data++;
        flag=1;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}
int main(){
   pthread_t thread1;
   pthread_t thread2;
   pthread_mutex_init(&mutex, 0);
   pthread_cond_init(&cond, 0);
   pthread_create(&parent_thread, 0, &parent_function, NULL);
   pthread_create(&child_thread, 0, &child_function, NULL);
   pthread_join(parent_thread, 0);
   pthread_join(child_thread, 0);
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);
   return 0;
}