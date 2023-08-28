/**
 ******************************************************************************
 * @file			ipc.h
 * @project         Sharedlibs
 * @brief			Please write a one-line description about this file's SW
 * @author			shawn
 * @version			v1.1
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

#ifndef IPC_INCLUDE_IPC_H_
#define IPC_INCLUDE_IPC_H_

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <pthread.h>
#include <sys/mman.h>
#include <stdint.h>
#include <signal.h>
#include <semaphore.h>
#include "fault_handling.h"
/*******************************************************************************
 * Structures and Enumerations
 ******************************************************************************/
/**<Define shm datatype for shared memory objects used to store pid's of all procs*/
typedef void* pid_shm;

/*******************************************************************************
 * Pre-processor Definitions
 ******************************************************************************/

//! Default permissions for new files/queues/semaphores
#define    	FILE_MODE    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/**< Permissions for posix shared memory buffers*/
#define		SHM_READ	 PROT_READ
#define		SHM_WRITE	 PROT_WRITE
#define 	SHM_RDWR	 PROT_READ | PROT_WRITE

/**< Permission for posix message queues*/
#define		MQ_READ		O_CREAT | O_RDONLY
#define		MQ_WRITE	O_CREAT	| O_WRONLY
#define		MQ_RDWR		o_CREAT	| O_RDWR

/**< Size of shared memory object in bytes*/
#define	SHARED_MEM_SIZE	4096

/**< Message queue attributes*/
#define MQ_MSG_SIZE	300
#define MQ_NUM_MSGS	20

/**< Message Queue Priorities*/
typedef enum{
	HIGH_PRIORITY = 0,
	MID_PRIORITY  = 1,
	LOW_PRIORITY  = 2,
}MQ_PRIOR;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief   Initialises the message queue. Return the mq_attr with
 * @details	message queue attributes. Remember to use mq_attr as global
 * @param   const char* - Message Queue Name
 * @param 	const int - Permission flags
 * @param	mq_attr* - Message Queue Attributes
 * @return  mqd_t - Message Queue Descriptor
 *
 * */
mqd_t mqueue_init(const char*, const int, struct mq_attr*);

/**
 * @brief	Send the IPC packet through message queue
 * @details
 * @param   const mqd_t - Message Queue Descriptor
 * @param	const char* - Pointer to buffer of data to send
 * @param	const size_t - Number of bytes of data to send
 * @param	MQ_PRIOR - Message Priority
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS mqueue_send(const mqd_t, const char*, const size_t, MQ_PRIOR);

/**
 * @brief   Receive IPC packet through message queue
 * @details
 * @param	const mqd_t - Message Queue Descriptor
 * @param	char* - pointer to buffer to store data
 * @param	const struct mq_attr - pointer to attributes struct
 * @return	int - num of bytes read
 *
 * */
int mqueue_receive(const mqd_t, char*, const struct mq_attr);

/**
 * @brief   Receive most recent IPC packet through message queue
 * @caution	For this function to work, the message queue has to be non-blocking
 * @param	const mqd_t - Message Queue Descriptor
 * @param	char* - pointer to buffer to store data
 * @param	const struct mq_attr - pointer to attributes struct
 * @return	int - num of bytes read
 *
 * */
int mqueue_receive_recent(const mqd_t, char*, const struct mq_attr);

/**
 * @brief   Closes the message queue
 * @details
 * @param   const mqd_t - Message Queue Descriptor
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS mqueue_close(const mqd_t);

/**
 * @brief   Removes the specific message queue
 * @details
 * @param   const char* - Message Queue Name
 * @return  FUNC_STATUS - Success/Failures
 *
 * */
FUNC_STATUS mqueue_unlink(const char*);

/**
 * @brief   Initialise a posix shared memory object
 * @details
 * @param	const char* - Name of shared memory object to create/open
 * @param	const sizeof - size of shared mem object in bytes
 * @return  void* - Pointer to shared memory
 *
 * */
 void* shared_mem_init(const char*, const size_t);

/**
 * @brief   write to a shared memory object
 * @details
 * @param   void* - pointer to shared memory object
 * @param	const void* - pointer to data to write
 * @param	size_t - size of data to send in bytes
 * @return  FUNC_STATUS - SUCCESS/FAILURE
 *
 * */
FUNC_STATUS shared_mem_write(void*, const void*, size_t);

/**
 * @brief   Read from shared memory object
 * @details
 * @param   void* - pointer to store read data
 * @param	void* - pointer to shared mem object
 * @param	size_t - size of data to read in bytes
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS shared_mem_read(void*, void*, size_t);

/**
 * @brief   Close file descriptor to shred memory buffer
 * @details
 * @param   const void* - pointer to memory mapping
 * @param	size_t - Size of shared memory object
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS shared_mem_close(const void*, size_t);

/**
 * @brief   unlink the shared memory name
 * @details
 * @param   const char* - shared memory object name
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS shared_mem_unlink(const char*);

/**
 * @brief   Send a signal to the process id
 * @details
 * @param   pid_t - process id to send the signal to
 * @param	int - signal number to be sent
 * @param	int - int value to be sent along with the signal
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS send_sig(pid_t, int, int);

#endif /* IPC_INCLUDE_IPC_H_ */
