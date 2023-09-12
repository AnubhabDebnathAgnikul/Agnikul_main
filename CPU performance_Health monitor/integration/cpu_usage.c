#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_CORES 4 // Change this to match the number of CPU cores on the target system

void cpu_core_usage()
{
    FILE* stat_file = fopen("/proc/stat","r");
    if(stat_file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char line[256];
    char* cpu_line = NULL;
    int core_id;
    unsigned long long total_time[2], idle_time[2];
    for(int i=0 ; i<=1; i++)
    {
        fgets(line, sizeof(line), stat_file);
        // printf("id = %c\n", core_id[i]);
        if(line[0] == 'c' && line[1] == 'p' && line[2] == 'u' && line[3]!=32)
        {
            cpu_line = line;
            printf("%s",cpu_line);

            if (cpu_line) 
            {
                unsigned long long user, nice, system, idle;
                sscanf(cpu_line, "cpu%d %llu %llu %llu %llu", &core_id, &user, &nice, &system, &idle);
                printf("user=%llu \nnice=%llu \nsystem=%llu \nidle=%llu\n",user,nice,system,idle);
            }
        }
    }
}

int main()
{
    cpu_core_usage();
}