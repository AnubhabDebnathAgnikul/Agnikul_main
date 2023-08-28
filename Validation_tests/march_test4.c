#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// #include <sys/types.h>
// #include <sys/wait.h>

#define PAGE_SIZE 4096
#define MEMORY_SIZE 100000000
void*address_list;

unsigned long long physical_address(void* virtualAddress)
{
     // Open the /proc/self/pagemap file to access page mapping information
    int pagemap_fd = open("/proc/self/pagemap", O_RDONLY);
    if (pagemap_fd < 0) 
    {
        printf("Failed to open pagemap file.\n");
        return 1;
    }

    // Calculate the virtual address page number
    unsigned long long virtualPageNumber = (unsigned long long)virtualAddress / PAGE_SIZE;

    // Seek to the corresponding entry in the pagemap file
    off_t offset = virtualPageNumber * sizeof(unsigned long long);
    if (lseek(pagemap_fd, offset, SEEK_SET) == -1) 
    {
        printf("Failed to seek to the pagemap entry.\n");
        return 1;
    }

    // Read the entry from the pagemap file
    unsigned long long pagemapEntry;
    if (read(pagemap_fd, &pagemapEntry, sizeof(unsigned long long)) == -1) {
        printf("Failed to read the pagemap entry.\n");
        return 1;
    }
    // printf("page entry: %0llx\n",pagemapEntry);
    // Extract the physical page frame number from the pagemap entry
    unsigned long long physicalPageNumber = pagemapEntry & 0x7FFFFFFFFFFFFF;

    // Calculate the physical address
    unsigned long long physicalAddress = (physicalPageNumber * PAGE_SIZE) +
                                         ((unsigned long long)virtualAddress % PAGE_SIZE);

    // printf("Virtual Address: %p\n", virtualAddress);10000_2KHz PT
    // printf("Physical Address: %llx\n", physicalAddress);
    //return physicalAddress;

    // Cleanup
    close(pagemap_fd);

}

int march(unsigned char*p)
{
    int x =1,flag=0;
    unsigned char a[8];
    // physical_address(p);
    for(int t=0;t<8;t++)
    {
       a[t] = x<<t;
    }
    for(int k=0;k<8;k++)
    {
       *p = x<<k;
        // printf("value=%02x\n",*p);
        if(*p!=a[k])
            flag=1;    
    }
    return flag;
}


int task(int cpu, int mem_div)
{
    
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu,&set);
    sched_setaffinity(getpid(),sizeof(cpu_set_t),&set);

    void* virtualAddress = malloc(MEMORY_SIZE/mem_div);
    unsigned char* temp_adress = virtualAddress;
    if (virtualAddress == NULL) 
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // physical_address(virtualAddress);
    // sphysical_address(temp_adress);

    for(int i=0;i<MEMORY_SIZE/mem_div;i++)
    {
        // printf("count: %d\n",i);
        int check = march(temp_adress);
        temp_adress++;
        if(check==1)
        {
            printf("fault detected at %p\n",temp_adress);
        }   
    }
    free(virtualAddress);
}

int main()
{
    time_t start,end;
    int pid_main;
    time(&start);
    pid_main = fork();

    if(pid_main==0)
    {
        //child
        int pid_sub = fork();
        if(pid_sub==0)
        {
            //child
            task(3,4);
        }
        else
        {
            //parent
            int pid_sub_2 = fork();
            if(pid_sub_2==0)
            {
                //child
                int pid_sub_3 = fork();
                if(pid_sub_3==0)
                {
                    //child
                    task(2,4);
                }
                else
                {
                    task(1,4);
                }

            }
            else
            {
                task(0,4);
            }
            
        }
    }
    else
    {
        //parent
        wait();
        time(&end);
        sleep(1);
        printf("time taken: %ld\n",end-start);
    }
}


// physical address for failure only
// no zombies
// LUT
