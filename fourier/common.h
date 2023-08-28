/**
 ******************************************************************************
 * @file           : common.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Header file containing all the commonly used values,
 *                   structures, enumerations and function definitions
 *                   across all Ethernet based programs.
 * @author         : Shawn N. Dheeraj R
 * @version        : v1.4
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

#ifndef COMMON_H_
#define COMMON_H_

/*******************************************************************************
 * Header inclusions
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <arpa/inet.h>
#include <semaphore.h>
#include "packetization_format.h"
#include "fault_handling.h"
#include "thread.h"
#include "ipc.h"

#ifdef FC_COMP		/**<Defined in Makefile as COMP variable*/
#include "fc.h"
#elif EC_COMP
#include "ec.h"
#endif

typedef enum process_enums process_t;

/** Common header for the Packetization format */
#include "packetization_format.h"

/** GNU source definition */
#define _POSIX_C_SOURCE 200809L

/** Limit code to NXP LS1028A*/
#define NXP_LS1028 	1
/** Limit code to Raspberry Pi 4B*/
//#define RASPBERRYPI_4B	1

///** To be used for all unused function parameters and variables */
//#define UNUSED __attribute__((unused))

#define MISSION_SEQ_FILENAME	"Mission_Seq_v1.5.csv"	

/**<.csv file containing
mission sequence to be loaded into FC.
Currently set for v1.5. Hard coding here will prevent on obsolete .csv from
being run */

#define GUIDANCE_FILENAME		"Guidance_file.csv"	

/**<.csv file containing
trajectory data to be loaded into FC*/

/**<.csv file containing gain parameters to be loaded for autopilot*/
#define GAINS_FILENAME			"Gains_v1.0.csv"		

#define GIMBAL_TRAJ_FILE        "Gimbal_traj_exe.csv"


#define EC_RX_PORT (3002)

#define FC_RX_PORT (3002)

/**< Bit fields. used in sequencer.c file */
#define P_F_LS_MFV (1<<3)


/*******************************************************************************
 * Structures and enumerations
 ******************************************************************************/
typedef struct
{
    uint8_t hold_status;
    uint64_t launch_epoch_time;
    int64_t current_cdt;
}cdt_shm_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

/**
 * @brief   initialises a shared memory object to be used to store an array of
 * @details	of all process pids
 * @param   pid_shm* - Pointer to shared memory object
 * @param	process_t - Process number whos PID is to be store in the SMO
 * @return  FUNC_STATUS - SUCCESS/FAILURE
 *
 * */
FUNC_STATUS init_pid_shm(process_t process_num);

/**
 * @brief   Used to access shared memory object that stores the process pid's
 * @details	and return the pid of the given process number
 * @param   pid_shm* - Pointer to shared memory object
 * @param 	process_t - Process number who PID is to be returned
 * @return  pid_t - PID of process to be returned. FAILURE on failure
 *
 * */
pid_t retrieve_pid(process_t);

/**
 * @brief   Function sends the specific fault ID along with the signal mentioned
 * @details	to the process mentioned
 * @param   pid_t - PID of process to send the signal to
 * @param	int - signal number to send
 * @param	fault_id - integer fault ID to send
 * @return  FUNC_STATUS - Success/Failure
 *
 * */
FUNC_STATUS raise_fault(faultID_t);

/**
 * @brief Intialize shared memory to share CDT.
 * 
 * @return FUNC_STATUS 
 */
FUNC_STATUS init_cdt_shm(void);

/**
 * @brief Get the cdt object
 * 
 * @return uint64_t 
 */
int64_t get_cdt(void);

extern pid_shm* pid_shm_ptr;

extern _Atomic cdt_shm_t* pCDT_status;

#endif /* COMMON_H_ */
