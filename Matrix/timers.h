/**
 ******************************************************************************
 * @file           : timers.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Header containing the functions related to timers and time
 *                   in general.
 * @author         : Shawn N, Dheeraj R
 * @version        : v1.4
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 * @par Issues:
 * 1.The timers fail to work if the expiration time is set to less than 10 us on Rpi.
 *
 * @par References:
 * 1. Shared objects with Signal Handlers: 
 * https://wiki.sei.cmu.edu/confluence/display/c/SIG31-C+Do+not+access+shared+objects+in+signal+handlers
 * 2. Atomic Operations: https://www.techopedia.com/definition/3466/atomic-operation
 * 3. Hands on system programming with linux by Kaiwan N Billimoria (Page 475)
 * 4. Multiple Timers, One signal Handler: https://stackoverflow.com/questions/37854681/how-to-handle-multiple-timer-signals
 * ****************************************************************************
 */

#ifndef TIME_H_
#define TIME_H_

#include <time.h>
#include <signal.h>
#include <errno.h>
#include <stdint.h>
#include "fault_handling.h"
#include <stdatomic.h>
#include <string.h>

/*******************************************************************************
 * Preprocessor definitions
 ******************************************************************************/

/*
 * Macro: timer_struct_sub
 * Perform (on struct timespec's): result=(a-b).
 * Mirrors the original 'timersub' function defined in the <sys/time.h> header.
 * Return: Pointer to struct timespec result
 */
#define _TIMER_STRUCT_SUB_(a, b, result)					    \
		do {									      				\
			(result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			\
			(result)->tv_nsec = (a)->tv_nsec - (b)->tv_nsec;		\
			if ((result)->tv_nsec < 0) {					      	\
				--(result)->tv_sec;						      		\
				(result)->tv_nsec += 1000000000;					    \
			}									      				\
		} while (0)

/**
 * @brief Enum containing modes for timer operation
 */
typedef enum{
	ONESHOT,
	REPEAT,
}TIMER_MODE;


/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
/**
 * @brief    Returns the number of microseconds since UNIX epoch (Jan 1, 1970).
 * @param    struct timespec* - time struct to store sec and nsec
 * @return   microseconds since epoch in unsigned long long / FAILURE on failure
 * */
uint64_t GetuSeconds(struct timespec*);    /* Get timestamp uSec or nSec or Sec*/

/**
 * @brief    Fills the timestamp header in accordance with
 * @details	 "Stripping Software Requirement Document_V1.0 - section 9.2"
 * @param    struct tm* - Pointer to linux struct containing current UTC time.
 * 			 Does not contain msec.
 * @param	 time_t* - Pointer to msec
 * @return   timestamp header or 0 on failure
 * */
uint32_t GetTimestamp(struct tm*, time_t*);

/**
 * @brief    Prints current time in UTC
 * @details
 * @param	 void
 * @return   SUCCESS/FAILURE
 * */
FUNC_STATUS print_time(void);

/**
 * @brief    Prints current time in UTC to file
 * @details
 * @param	 FILE - file descriptor of file to print to
 * @return   SUCCESS/FAILURE
 * */
FUNC_STATUS fprint_time(FILE*);

/**
 * @brief    Returns the number of microseconds since time stored in parameter 1
 * @details	 Fills the 2nd parameter with current monotonic time
 * @param    struct timespec - time to calculate elapsed time from
 * @param	 struct timespec* - Pointer to timespec struct to fill with current
 * 								time from monotonic clock.
 * 								Leave as NULL if not required.
 * @return   microseconds since time given in first parameter / FAILURE on failure
 * */
uint64_t Elapsedtime_us(struct timespec, struct timespec*);

/**
 * @brief    Gets the current date and time
 * @param    pointer to the date/time string
 * @return   FUNC_STATUS - Success/Failure
 * */
FUNC_STATUS Getlocaltime (char*);

/**
 * @brief Function Description: Returns the system time
 * @param struct tm* - Pointer to struct to store current system time
 * @return FUNC_STATUS - Success/Failure
 */
FUNC_STATUS return_sys_time(struct tm*);

/**
 * @brief    Initialises timer with a signal handler already assigned
 * @param    void (*)(int, siginfo_t*, void*) - Signal handler assigned to this timer
 * @param 	 uint8_t - Realtime Signal Number
 * @param    timer_t* - Returns the unique timer id
 * @return   FUNC_STATUS - Success/Failure
 */
FUNC_STATUS init_sighandlertimer(void (*)(int, siginfo_t*, void*), uint8_t, timer_t*);

/**
 * @brief    Initialises timer with a signal handler that is called
 * 			 as a separate thread
 * @param    void (*)(union sigval) - Signal handler assigned to this timer
 * @param    timer_t* - Returns the unique timer id
 * @return   FUNC_STATUS - Success/Failure
 */
FUNC_STATUS init_functhreadtimer(void (*)(union sigval), timer_t*);

/**
 * @brief    Initialises timer that triggers a signal number
 * 			 dedicated to the specific thread id
 * @param    pid_t - Thread ID to send the signal to
 * @param 	 int - Signal number to be triggered
 * @param    timer_t* - Returns the unique timer id
 * @return   FUNC_STATUS - SUCCESS/FAILURE
 */
FUNC_STATUS init_sigthreadtimer(pid_t, int, timer_t*);

/**
 * @brief    Initialises timer that triggers a signal number
 * 			 dedicated to the specific thread id
 * @param    struct sigevent - Struct that defined the signal to be triggered
 * @param    timer_t* - Returns the unique timer id
 * @return   FUNC_STATUS - Success/Failure
 */
FUNC_STATUS init_sigtimer(struct sigevent, timer_t*);

/**
 * @brief Starts the timer initialised previously
 * @param timer_t - unique timer id
 * @param TIMER_MODE - mode to setup timer as either one shot or repeating
 * @param struct timespec* - Pointer to struct containing time in sec and nano sec
 *
 * @return FUNC_STATUS - Success / Failure
 */
FUNC_STATUS start_timer(timer_t, TIMER_MODE, struct timespec*);

/**
 * @brief Stops the timer
 * @param timer_t - unique timer id
 * @return FUNC_STATUS - Success / Failure
 */
FUNC_STATUS stop_timer(timer_t);

/**
 * @brief Returns the timers time till expiration in sec and nsec
 * @param timer_t - timer id
 * @param struct timespec* - Pointer to struct returning time in sec and nsec
 * @return void
 */
FUNC_STATUS return_counter_time(timer_t, struct timespec*);

/**
 * @brief Function Description: Returns number of timer signals missed
 * before a signal is processed
 * @param timer_t - timer id
 * @param atomic_int_fast64_t* - number of timer overruns
 * @return FUNC_STATUS - Success / Failure
 */
FUNC_STATUS return_timer_overrun(timer_t, volatile atomic_int_fast64_t*);


#endif /* TIME_H_ */
