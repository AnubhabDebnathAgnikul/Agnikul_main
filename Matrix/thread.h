/**
 ******************************************************************************
 * @file			thread.h
 * @project         Sharedlibs
 * @brief			Please write a one-line description about this file's SW
 * @author			Shawn N.
 * @version			v2.0
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
*/

#ifndef THREAD_INCLUDE_THREAD_H_
#define THREAD_INCLUDE_THREAD_H_

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <pthread.h>
#include <stdatomic.h>
#include "timers.h"
#include <unistd.h>
#include <signal.h>
#include "fault_handling.h"

/*******************************************************************************
 * Pre-processor Definitions
 ******************************************************************************/

//! Thread name max size for multi-threaded applications
#define THREAD_NAME_SIZE	20

/*******************************************************************************
 * Structures and Enumerations
 ******************************************************************************/

/**
 *  \brief Struct to store all information pertaining to multi-threads
 *
 *  */
typedef struct{
	pthread_t pthread_ID;	/*!< Posix thread ID for generated thread */

	//Optional Parameters
	pid_t kthread_ID;	/*!< Kernel thread ID for generated thread */
	char name[THREAD_NAME_SIZE];	/**<Assign this thread a name if scheduled by timer*/

	//If used along with a timer
	timer_t timer_ID;	/*!< Timer ID used to schedule thread */
	struct timespec trig_time; /*!< Interval time for timer trigger */
}thread_info;

/**
 * @brief Function Description: Initialises a posix thread.
 * @param thread_info* - thread struct with information for thread to be initialised
 * @param void*(*)(void*)	- Function to be called as separate thread
 * @param void* - void pointer to parameters to be fed to the thread
 * @return FUNC_STATUS - Success / Failure
 */
FUNC_STATUS create_thread(thread_info*, void* (*)(void*), void*);

/**
 * @brief Function Description: Blocks all signal except the required one in a calling
 * @details thread
 * @param sigset* - sigset struct defining signals to be blocked/unblocked
 * @param int - signal to unblock
 * @return FUNC_STATUS - Success/Failure
 */
FUNC_STATUS set_procmask(sigset_t*, int);

/**
 * @brief Function Description: Loads the kernel thread ID and inits a timer
 * @details	to send the specified signal to the calling thread
 * @param thread_info* - thread struct with information for thread to be initialised
 * @param void*(*)(void*)	- Function to be called as separate thread
 * @return FUNC_STATUS - Success/Failure
 */
FUNC_STATUS init_thread_timer(thread_info*,  int);

#endif /* THREAD_INCLUDE_THREAD_H_ */
