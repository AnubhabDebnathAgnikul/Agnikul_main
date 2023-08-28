#include"description.h"
//#include"fault_handling.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#include "test_code.c" 

#define MAX 20

char prototype[] = "TA 5000";

char my_id[] = "";

int checksum(char* ptr)
{
    int sum = 0;
    while(*ptr!=NULL)
    {
        sum += *ptr;
        //printf("%c",*ptr);
        *ptr++;
    }
    return sum;
}



int main()
{
    time_t now;
    int counter = 5000;
    int x,prev;
    char s[2];
    
    //strcat(my_string,id);

    FILE *file_ip,*file_op,*fr,*fr2;
    file_ip = fopen("transmitted_data.txt","a");
    file_op = fopen("Receiver_data.txt","a"); 
    
    fr = fopen("transmitted_data.txt","r");

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    
    
    
    int port = OpenSerialPort(UART_PORT1_NXP,B115200);
    printf("serial port opened: %d\n",port);
    sleep(1);


    fseek (fr, 0, SEEK_END);
    int size = ftell(fr);
    if(size==0)
    {
        printf("empty");
    }

    fclose(fr);
    fr2 = fopen("transmitted_data.txt","r");
    while(x!=NULL && x!=prev && size!=0)
    {
        prev=x;
        fscanf(fr2,"%s %d",s,&x);
            
        printf("%s %d %d\n",s,prev,x); 
        counter = prev+1;         
    }
    fclose(fr2);

    fprintf(file_ip,"\n%d:%d:%d\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    fprintf(file_op,"\n%d:%d:%d\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    for(int i =0;i<10;i++)
    {
        char my_string[sizeof(prototype)] = "TA ";
        sprintf(my_id,"%d",counter++);
        strcat(my_string,my_id);
        //printf("%s\n",my_string);
        int check = checksum(my_string);
        fprintf(file_ip,"%s %d\n",my_string,check);
        if(SendDataOverUART(port,my_string,MAX)<0)
             printf("send data failure:\n");

        char rcv_msg_cmplt[MAX]="";


        if(ReceiveDataOverUART(port,rcv_msg_cmplt,MAX)<0)    
            printf("failure:\n");
        else
        {
                
            fprintf(file_op,"%s %d\n", rcv_msg_cmplt,checksum(rcv_msg_cmplt));
            printf("%d\n", check==checksum(rcv_msg_cmplt));
        }
        

        
        tcflush(port,TCIOFLUSH);
        //sleep(1);

    }
    fclose(file_ip);
    fclose(file_op);
    

}

// int main()
// {
//     int port = OpenSerialPort(UART_PORT1_NXP,B115200);
//     printf("serial port opened: %d\n",port);
//     sleep(1);
//     // defining the message
//     uint8_t msg[] = "10101111";   
//     // uint8_t msg_bin[100]; 
//     // //printf("%d\n",(uint16_t)sizeof(msg));
    
//     // for(int i=0;i<8*strlen(msg);i++)
//     // {
//     //     msg_bin[i] = (0 != (msg[i/8] & 1 << (~i&7)));
//     // }
    
    
//     if(SendDataOverUART(port,msg,MAX)<0)
//     printf("send data failure:\n");    
//     else
//     printf("yeah!!\n");
//     sleep(1);
//     uint8_t rcv_msg[]="";
//     uint8_t rcv_msg_cmplt[100]="";
//     // if(ReceiveValOverUART(port,rcv_msg)<0)    
//     //     printf("failure:\n");
//     // else
//     //     printf("full data: %s\n", rcv_msg);

//     //sleep(2);

//     if(ReceiveDataOverUART(port,rcv_msg_cmplt,MAX)<0)    
//         printf("failure:\n");
//     else
//         printf("data: %s\n", rcv_msg_cmplt);
//     tcflush(port,TCIOFLUSH);
//     // printf("%d\n",ReceiveValOverUART(port,rcv_msg_cmplt));
//     // printf("data: %s\n", rcv_msg_cmplt);
//     printf("serial port closed success: %d\n",CloseSerialPort(port));
// }