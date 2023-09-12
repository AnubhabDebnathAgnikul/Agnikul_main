#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <string.h>

#define MAX_BUF_SIZE 128


// Function to read and parse /proc/cpuinfo to get CPU information
void getCPUInfo() 
{
    FILE *fp;
    char buffer[MAX_BUF_SIZE];
    
    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) 
    {
        perror("Error opening /proc/cpuinfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) 
    {
        if (strstr(buffer, "model name")) 
        {
            printf("CPU Model: %s", strchr(buffer, ':') + 2);
            break;
        }
    }

    fclose(fp);
}

// Function to read and parse /proc/meminfo to get memory information
void getMemoryInfo() 
{
    FILE *fp;
    char buffer[MAX_BUF_SIZE];
    
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) 
    {
        perror("Error opening /proc/meminfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) 
    {
        if (strstr(buffer, "MemTotal")) 
        {
            printf("Total Memory: %s", strchr(buffer, ':') + 2);
        } 
        else if (strstr(buffer, "MemFree")) 
        {
            printf("Free Memory: %s", strchr(buffer, ':') + 2);
        }
    }

    fclose(fp);
}

// Function to count the number of running processes
int countRunningProcesses() 
{
    FILE *fp;
    char buffer[MAX_BUF_SIZE];
    int count = 0;
    
    fp = popen("ps -e | wc -l", "r");
    if (fp == NULL) 
    {
        perror("Error executing ps command");
        return -1;
    }

    if (fgets(buffer, sizeof(buffer), fp)) 
    {
        count = atoi(buffer);
    }

    pclose(fp);
    
    return count;
}

// Function to count the number of threads in the current process
int countThreads() 
{
    int count = 0;
    char buffer[MAX_BUF_SIZE];
    FILE *fp;
    char line[256];

    // fp = fopen("/proc/self/status", "r");  // threads in current process
    fp = popen("ps -eo nlwp | tail -n +2 | awk '{ num_threads += $1 } END { print num_threads }'","r");
    if (fp == NULL) 
    {
        perror("Error executing ps command");
        return -1;
    }

    if (fgets(buffer, sizeof(buffer), fp)) 
    {
        count = atoi(buffer);
    }

    pclose(fp);
    return count;
}

 


void *cpu_monitor() 
{
    while(1)
    {
        printf("CPU Health Monitor\n");

        // Get CPU information
        getCPUInfo();

        // Get memory information
        getMemoryInfo();

        // Get the number of running processes
        int runningProcesses = countRunningProcesses();
        if (runningProcesses >= 0) 
        {
            printf("Running Processes: %d\n", runningProcesses);
        }

        // Get the number of threads in the current process
        int threads = countThreads();
        if (threads >= 0) 
        {
            printf("Threads running: %d\n", threads);
        }
        usleep(1000000);
    }

    return 0;
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, cpu_monitor, NULL);
    pthread_join(thread_id, NULL);
    exit(0);
}