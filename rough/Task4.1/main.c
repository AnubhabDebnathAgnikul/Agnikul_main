#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[]) {
	int fd[2];
	int data = 0;

	pipe(fd);
    printf("%d, %d\n", fd[0], fd[1]);

    pid_t pid = fork();

    for(int i=0;i<=20;i++)
    {
        data++;
        if(i==10)
        {
            data=-1;
        }
        if (pid != 0) 
        {
            
            close(fd[0]);
            write(fd[1], &data, sizeof(data));
            close(fd[1]);
        } 
        else 
        {
            
            close(fd[1]);
            read(fd[0], &data, sizeof(data));
            close(fd[0]);

            if(data==-1)
            {
                kill(pid, SIGTERM);                
            }
            else
            {
                printf("%d\n", data);
            }
        }
        
    }	
	
}
	
