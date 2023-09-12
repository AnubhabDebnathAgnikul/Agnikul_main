#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_CORES 4 // Change this to match the number of CPU cores on the target system

// Function to calculate CPU usage for a specific core
void* calculate_cpu_usage(void* arg) {
    int core_id = *((int*)arg);
    FILE* file = NULL;
    char filename[128];
    unsigned long long total_time[2], idle_time[2];

    snprintf(filename, sizeof(filename), "/proc/stat");

    while (1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            perror("fopen");
            exit(1);
        }

        char line[256];
        char* cpu_line = NULL;
        while (fgets(line, sizeof(line), file)) {
            if (line[0] == 'c' && line[1] == 'p' && line[2] == 'u' && line[3] == core_id + '0') {
                cpu_line = line;
                break;
            }
        }
        fclose(file);

        if (cpu_line) {
            unsigned long long user, nice, system, idle;
            sscanf(cpu_line, "cpu%d %llu %llu %llu %llu", &core_id, &user, &nice, &system, &idle);

            total_time[1] = user + nice + system + idle;
            idle_time[1] = idle;

            if (total_time[0] > 0) {
                unsigned long long total_delta = total_time[1] - total_time[0];
                unsigned long long idle_delta = idle_time[1] - idle_time[0];
                double usage = 100.0 * (1.0 - ((double)idle_delta / (double)total_delta));

                printf("Core %d CPU Usage: %.2f%%\n", core_id, usage);
            }

            total_time[0] = total_time[1];
            idle_time[0] = idle_time[1];
        }

        sleep(1); // Sleep for 1 second before checking again
    }
}

int main() {
    pthread_t threads[NUM_CORES];
    int core_ids[NUM_CORES];

    for (int i = 0; i < NUM_CORES; i++) {
        core_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_cpu_usage, &core_ids[i]);
    }

    for (int i = 0; i < NUM_CORES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
