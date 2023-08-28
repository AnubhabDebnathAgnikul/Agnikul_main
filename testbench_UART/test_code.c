/**
 ******************************************************************************
 * @file           : uart.c
 * @project        : Agnikul Generic Software Library
 * @brief          : UART configuration and functionalities for send and receive.
 * @author         : Sreedhar Mahadevan, Shawn Nagar
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Linux headers
#include <fcntl.h>  // Contains file controls like O_RDWR
#include <errno.h>  // Error integer and strerror() function
#include <unistd.h> // write(), read(), close()

// Project headers
//#include "uart.h"
#include "description.h"
//#include "fault_handling.h"
//#define PRINT_ERR perror

typedef enum{
	FAILURE = -1,/**< FAILURE */
	SUCCESS = 1, /**< SUCCESS */
}FUNC_STATUS;
/**
 * Routine to open serial port, set the necessary configurations
 * and return the file id
 * @param    speed_t - uart_baud - Baud rate. Refer termios.h for valid values
 * @return    file-id of the Serial port opened
 * */
int OpenSerialPort(const char* path_name, speed_t uart_baud)
{
	/**<Open the serial port in read / write mode*/
	int serial_port = open(path_name, O_RDWR);
	if(serial_port < 0){
		//PRINT_ERR();
		perror("error: ");
		return FAILURE;
	}

	/**<Create new termios struct, we call it 'tty' for convention*/
	struct termios tty;

	/**<Read in existing settings, and handle any error*/
	if(tcgetattr(serial_port, &tty) != 0) {
		//PRINT_ERR();
		perror("error: ");
		return FAILURE;
	}

	tty.c_cflag &= (uint) ~PARENB; 	/**<Clear parity bit, disabling parity (most common)*/
	tty.c_cflag &= (uint) ~CSTOPB; 	/**<Clear stop field, only one stop bit used in communication (most common)*/
	tty.c_cflag &= (uint) ~CSIZE; 	/**<Clear all bits that set the data size*/
	tty.c_cflag |= (uint) CS8; 		/**<8 bits per byte (most common)*/
	tty.c_cflag &= (uint) ~CRTSCTS; /**<Disable RTS/CTS hardware flow control (most common)*/
	tty.c_cflag |= (uint) CREAD | CLOCAL; /**<Turn on READ & ignore ctrl lines (CLOCAL = 1)*/

	tty.c_lflag &= (uint) ~ICANON;	/**<Disable canonical mode*/
	tty.c_lflag &= (uint) ~ECHO; 	/**<Disable echo*/
	tty.c_lflag &= (uint) ~ECHOE; 	/**<Disable erasure*/
	tty.c_lflag &= (uint) ~ECHONL; 	/**<Disable new-line echo*/
	tty.c_lflag &= (uint) ~ISIG; 	/**<Disable interpretation of INTR, QUIT and SUSP*/
	tty.c_iflag &= (uint) ~(IXON | IXOFF | IXANY); /**<Turn off s/w flow ctrl*/
	tty.c_iflag &= (uint) ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); /**<Disable any special handling of received bytes*/

	tty.c_oflag &= (uint) ~OPOST; /**<Prevent special interpretation of output bytes (e.g. newline chars)*/
	tty.c_oflag &= (uint) ~ONLCR; /**<Prevent conversion of newline to carriage return/line feed*/
	// tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
	// tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

	tty.c_cc[VTIME] = 10;    /**<Wait for up to 1s (10 deciseconds), returning as soon as any data is received.*/
	tty.c_cc[VMIN]  = 100;    /**<Wait for the UART blocking read to check atleast 50 bytes (TODO: Check details)*/

	/**<Set in/out baud rate to be 'uart_baud' parameter*/
	if(cfsetispeed(&tty, uart_baud) < 0){
		//PRINT_ERR();
		perror("error: ");
		return FAILURE;
	}
	if(cfsetospeed(&tty, uart_baud) < 0){
		//PRINT_ERR();
		perror("error: ");
		return FAILURE;
	}

	/**<Save tty settings, also checking for error*/
	if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
		//printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
		//return 0;
		//PRINT_ERR();
		perror("error: ");
		return FAILURE;
	}

	return serial_port;
}


/**
 * Routine to close the specified serial port
 * @param    serial_port - Serial port ID
 * @return    FUNC_STATUS - Success/Failure
 * */
FUNC_STATUS CloseSerialPort(int serial_port)
{
	if(close(serial_port) < 0){
		//0PRINT_ERR();
		perror("closing port error: ");
		return FAILURE;
	}

	return SUCCESS;
}


/**
 * @brief	Transmit data through UART
 * @param	int - serial port to use
 * @param   uint8_t* - pointer to transmit-data buffer
 * @param   uint16_t - number of bytes to be transmitted
 * @return  ssize_t - Number of bytes written or failure
 * */
ssize_t SendDataOverUART(int serial_port, uint8_t* p_transmit_data, uint16_t tx_msg_size)
{
	/**<idiot proof this bu checking for NULL pointers*/
	if(p_transmit_data == NULL){
		perror("NULL pointer detected!\n");
		return FAILURE;
	}

	/**<tx_msg_size should be less than 1024 (Kernel default)*/
	if(tx_msg_size > 1024){
		perror("uart buffer cannot exceed 1024 bytes by default\n");
		return FAILURE;
	}

	/**<Write to serial port*/
	ssize_t status = write(serial_port, p_transmit_data, tx_msg_size);
	if(status < 0){
		perror("error is: ");
		return FAILURE;
	}

	return status;
}

ssize_t ReceiveValOverUART(int serial_port, uint8_t* p_data){

	/**<idiot proof this bu checking for NULL pointers*/
	if(p_data == NULL){
		perror("NULL pointer detected!\n");
		return FAILURE;
	}

	/**<Read 1 byte of data from port*/
	ssize_t status = read(serial_port, p_data, 1);
	if(status < 0){
		perror("Error in reception of data..");
		//PRINT_ERR();
		return FAILURE;
	}

	return status;
}

/**
 * @brief 	Receive data through UART.
 * @details
 * @param	int - serial port to use
 * @param   uint8_t* - pointer to buffer to store data in
 * @param   uint16_t - Max Number of bytes expected
 * @return	ssize_t - Number of bytes read / FAILURE
 * */
ssize_t ReceiveDataOverUART(int serial_port, uint8_t* p_data_uart_rx, uint16_t MAX_rx_msg_size)
{
	/**<idiot proof this bu checking for NULL pointers*/
	if(p_data_uart_rx == NULL){
		perror("NULL pointer detected!\n");
		return FAILURE;
	}

	/**<Read MAX_rx_msg_size bytes from serial port*/
	ssize_t status = read(serial_port, p_data_uart_rx, MAX_rx_msg_size);
	if(status < 0){
		perror("Error in reception of data..");
		//PRINT_ERR();
		return FAILURE;
	}

	return status;
}