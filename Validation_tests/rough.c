#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROCESS_NUM 5
int main()
{
    pid_t pid[PROCESS_NUM];
    int main_pid = getpid(),status;
    printf("parent process: %d\n",main_pid);
    for (int i=0; i<PROCESS_NUM;i++)
    {
        if((pid[i]= fork())== 0 )
        {
            //children
            exit(i);
        }
    }

    for (int i=0;i<PROCESS_NUM;i++)
    {
        pid_t cpid = waitpid(pid[i],&status,0);
        if(WIFEXITED(status))
        {
            printf("Child %d terminated with exit status %d\n", cpid,WEXITSTATUS(status));
        }
    }
    return 0;
}