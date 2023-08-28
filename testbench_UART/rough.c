/**
 ******************************************************************************
 * @file           : uart.c test code 
 * @project        : Agnikul Generic Software Library
 * @brief          : UART configuration and functionalities for send and receive.
 * @author         : anubhab debnath
 * @version        : v2.0
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include"description.h"
//#include"fault_handling.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"file_compare.c"
#include "test_code.c" 

#define MAX 20
char prototype[] = "TA 5000";

char my_id[] = "";


/*checksum function*/
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
    /*file pointer declaration*/
    FILE *fw,*fr,*fr2,*file_ip,*file_op;

    /*openning transmitter data & receiver data file in append mode so that 
    if the file does not exist it will create a new one*/
    file_ip= fopen("transmitter_data_2.txt","a+");
    file_op = fopen("Receiver_data_2.txt","a+"); 
    //fclose(fw);
    

    

    /*openning the transmitter data file in read mode*/
    fr = fopen("transmitter_data_2.txt","r");
    

    
    /*openning the serial port*/
    int port = OpenSerialPort(UART_PORT1_NXP,B115200);
    printf("serial port opened: %d\n",port);

    /*declaring & initializing temp variables*/
    int x=0,prev,c;
    int counter = 5000;
    char s[2];
    
    /*check if the transmitter file is empty*/
    fseek (fr, 0, SEEK_END);
    int size = ftell(fr);
    if(size==0)
    {
        printf("empty");
    }
    /*close the transmitter file read mode*/
    fclose(fr);

    /*openning the transmitter data file in read mode & take the last count value*/
    fr2 = fopen("transmitter_data_2.txt","r");
    while(x!=prev && size!=0)
    {
        prev=x;
        fscanf(fr2,"%s %d %d",s,&x,&c);
            
        printf("%s %d %d\n",s,prev,x); 
        counter = prev+1;      
        //sleep(1);   
    }
    

    printf("%d\n",counter);

    /* make 10 iterations to send & receive data
    append sent & received data in apt. format to the corresponding files*/
    for(int i=0;i<10;i++)
    {
        char my_string[sizeof(prototype)] = "TA ";
        sprintf(my_id,"%d",counter++);
        strcat(my_string,my_id);
        int check = checksum(my_string);
        fprintf(file_ip,"%s %d\n",my_string,check);


        if(SendDataOverUART(port,my_string,MAX)<0)
             printf("send data failure:\n");

        char rcv_msg_cmplt[MAX];


        if(ReceiveDataOverUART(port,rcv_msg_cmplt,MAX)<0)    
            printf("failure:\n");
        else
        {
                
            fprintf(file_op,"%s %d\n", rcv_msg_cmplt,checksum(rcv_msg_cmplt));
            //printf("%d\n", check==checksum(rcv_msg_cmplt));
        }  

        /*clear the serial port buffer*/
        tcflush(port,TCIOFLUSH);
    }
    
    /*close the files*/
    fclose(file_ip);
    fclose(file_op);
    fclose(fr2);

    // FILE *fp1 = fopen("transmitter_data_2.txt", "r");
 	// FILE *fp2 = fopen("Receiver_data_2.txt", "r");

    // compareFiles(fp1,fp2);

    // fclose(fp1);
    // fclose(fp2);
}