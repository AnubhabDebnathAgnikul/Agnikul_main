#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void timer_handler(union sigval sv) {
    printf("Timer expired!\n");
}

int main() {
    timer_t timer_id;
    struct sigevent sev;
    struct itimerspec its;
    time_t start,end;
    
    // Create a timer
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = timer_handler;
    sev.sigev_value.sival_ptr = &timer_id;
    sev.sigev_notify_attributes = NULL;

    if (timer_create(CLOCK_REALTIME, &sev, &timer_id) == -1) 
    {
        perror("timer_create");
        return 1;
    }
    
    // Set the timer to expire after 5 seconds
    its.it_value.tv_sec = 6;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    if (timer_settime(timer_id, 0, &its, NULL) == -1) 
    {
        perror("timer_settime");
        return 1;
    }
    time(&start);
    // Print the current timer status
    struct itimerspec current_its;
    while(1)
    {
        if (timer_gettime(timer_id, &current_its) == -1) 
        {
            perror("timer_gettime");
            return 1;
        }
        
        printf("Current timer value: %ld seconds %ld nanoseconds\n",
            current_its.it_value.tv_sec, current_its.it_value.tv_nsec);

        if(current_its.it_value.tv_sec == 0 && current_its.it_value.tv_nsec == 0)
            break;
    }
    time(&end);
    printf("%ld\n",end-start);
    // Wait for the timer handler to complete 
    sleep(3);
    
    // Clean up the timer
    timer_delete(timer_id);
    
    return 0;
}
