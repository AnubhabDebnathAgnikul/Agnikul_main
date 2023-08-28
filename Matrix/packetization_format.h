/**
 ******************************************************************************
 * @file           : packetization_format.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Avionics Packetization format
 * @author         : Agnikul Avionics Team
 * @version        : v1.5
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

#ifndef PACKETIZATION_FORMAT_H_
#define PACKETIZATION_FORMAT_H_

#include "stdint.h"

/*******************************************************************************
 * Preprocessor definitions
 ******************************************************************************/

/**
 * IPaddressdefines IP Addresses of all subsystems
 * Contains the IP Adress definitions used by subsystems.
 * All addresses are in the 1.1.1.1/24 network.
 *
 * \todo Group these on doxygen */
#define FC_IPADDR           "127.0.0.1"
#define TELEMETRY_IPADDR    "1.1.1.10"
#define LC_IPADDR	    	"1.1.1.3"
#define EC_IPADDR 			"1.1.1.2"
#define ECU1_S1_IPADDR      "1.1.1.4"
#define ECU2_S1_IPADDR      "1.1.1.5"
#define ECU3_S1_IPADDR      "1.1.1.6"
#define ECU4_S1_IPADDR      "1.1.1.7"
#define ECU5_S1_IPADDR      "1.1.1.8"
#define ECU6_S1_IPADDR      "1.1.1.9"
#define ECU7_S1_IPADDR      "1.1.1.10"
#define ECU1_S2_IPADDR      "1.1.1.11"
#define PC_IPADDR           "1.1.1.20"
#define GC_IPADDR			"1.1.1.21"
#define MCRC_IPADDR			"1.1.1.22"
#define LOOPBACK_IPADDR     "127.0.0.1"

//! Total number of client connections expected to FCU/Telemetry/GC server
#define SERVER_MAX_CONNECTIONS	2

//! Default Tx and Rx ports for all communications.
#define DEFAULT_RXPORT 	3002
#define DEFAULT_TXPORT 	"9001"

/** Number of intra-vehicle packets considered for transmission over Telemetry */
#define MAX_NUM_DATA_PACKS 30

/*******************************************************************************
 * Structures and enumerations
 ******************************************************************************/

/**
 *  \brief 		All parameters ID's
 *	\details	Designed based on SO_Parameter_V1.7
 *
 *  */


/**
 *  \brief 		All parameters ID's
 *	\details	Designed based on SO_Parameter_V1.7
 *
 *  */
typedef enum
{
	P_C_PT_LOX_inj = 100,
	P_F_PT_ATF_inj = 101,
	P_E_PT_CC_1 = 102,
	P_M_PT_inj = 103,
	P_G_PT_inj = 104,
	P_I_PT_1 = 105,
	P_I_PT_2 = 106,
	P_R_PT_RCS_2 = 107,
	P_VALS_IGS = 2,
	P_F_PT_ATF_Press_Tank = 108,
	P_F_PT_ATF_Tank = 109,
	P_F_PT_ATF_Press = 110,
	P_C_PT_LOX_Press_Tank = 111,
	P_C_PT_LOX_Tank = 112,
	P_C_PT_LOX_Press = 113,
	P_R_PT_RCS_1 = 114,
	P_C_LS_LOX_Tank = 115,
	P_FTS_n_TTDS_M = 116,
	P_FTSD_R = 117,
	P_TTPS_2 = 3,
	P_ITSM_A1 = 4,
	P_ITSM_A2 = 5,
	P_ITSM_A3 = 6,
	P_ITSM_A4 = 7,
	P_ITSM_A5 = 8,
	P_ITSM_A6 = 9,
	P_ITSM_A7 = 10,
	P_SARBM_A1 = 11,
	P_ITSR_A1 = 12,
	P_ITSR_A2 = 13,
	P_ITSR_A3 = 14,
	P_ITSR_A4 = 15,
	P_ITSR_A5 = 16,
	P_ITSR_A6 = 17,
	P_ITSR_A7 = 18,
	P_SARBR_A1 = 19,
	P_ITSM_A8 = 20,
	P_ITSR_A8 = 21,
	P_AB_VS = 22,
	P_AB_CS = 23,
	P_AB_TS = 24,
	P_EP_DAQ_Reserved_1 = 25,
	P_C_RTD_inj = 118,
	P_F_RTD_inj = 119,
	P_F_RTD_ATF_Press_Tank = 120,
	P_R_RTD_RCS = 121,
	P_C_RTD_LOX_Press_Tank = 122,
	P_FS_TM_1 = 123,
	P_FS_Acc_1 = 124,
	P_CMD_EMGA_PL_E1 = 125,
	P_CMD_EMGA_YL_E1 = 126,
	P_EMGA_P_E1 = 127,
	P_EMGA_Y_E1 = 128,
	P_EMGAV_P_E1 = 26,
	P_EMGAA_P_E1 = 27,
	P_EMGAT_P_E1 = 28,
	P_EMGAV_Y_E1 = 29,
	P_EMGAA_Y_E1 = 30,
	P_EMGAT_Y_E1 = 31,
	P_EMGA_STATUS = 150,
	P_EC_TS = 32,
	P_EC_CS = 33,
	P_EC_VS = 34,
	P_EC_SEQ = 35,
	P_CMD_EC = 36,
	P_EC_Reserved_1 = 37,
	P_EC_Reserved_2 = 151,
	P_EC_Reserved_3 = 152,
	P_EC_FAULT_STATUS = 38,
	P_EC_STATUS = 153,
	P_IMUR_X_M = 155,
	P_IMUR_Y_M = 156,
	P_IMUR_Z_M = 157,
	P_IMUA_X_M = 158,
	P_IMUA_Y_M = 159,
	P_IMUA_Z_M = 160,
	P_IMU_STATUS_M = 161,
	P_IMU_Reserved_1 = 162,
	P_IMU_Reserved_2 = 163,
	P_IMU_Reserved_3 = 164,
	P_IMU_Reserved_4 = 165,
	P_GNC_POS_X_FC = 167,
	P_GNC_POS_Y_FC = 168,
	P_GNC_POS_Z_FC = 169,
	P_GNC_VEL_X_FC = 170,
	P_GNC_VEL_Y_FC = 171,
	P_GNC_VEL_Z_FC = 172,
	P_GNC_PR_FC = 173,
	P_GNC_YR_FC = 174,
	P_GNC_RR_FC = 175,
	P_GNC_PA_FC = 176,
	P_GNC_YA_FC = 177,
	P_GNC_RA_FC = 178,
	P_CMD_EMGA_PA_E1 = 129,
	P_CMD_EMGA_YA_E1 = 130,
	P_CMD_RCS = 39,
	P_CDT_Time = 179,
	/**< These were 180 and 181*/
	P_CMD_PA = 180,
	P_CMD_YA = 181,
	P_CMD_RA = 182,
	P_Delta_PA = 183,
	P_Delta_YA = 184,
	P_Delta_RA = 185,
	P_FC_TS = 40,
	P_FC_CS = 41,
	P_FC_VS = 42,
	P_IMUT_M = 43,
	P_IMUV_M = 44,
	P_GNSS_PPS = 45,
	P_GNSS_GGA_LAT = 186,
	P_GNSS_GGA_LONG = 187,
	P_GNSS_GGA_QI_n_HDOP = 131,
	P_GNSS_GGA_ALT = 188,
	P_GNSS_GGA_GEOSEP = 132,
	P_GNSS_VTG_SP_n_MI = 189,
	P_GNSS_GLL_LAT = 190,
	P_GNSS_GLL_LONG = 191,
	P_GNSS_GLL_UTC = 192,
	P_GNSS_GLL_STAT_n_MI = 46,
	P_GNSS_GSA_MODE = 47,
	P_GNSS_GSA_PRN_1 = 193,
	P_GNSS_GSA_PRN_2 = 194,
	P_GNSS_GSA_DOPVAL = 195,
	P_GNSS_ECEF_UTC = 196,
	P_GNSS_ECEF_FHPOS_X = 197,
	P_GNSS_ECEF_LHPOS_X = 198,
	P_GNSS_ECEF_FHPOS_Y = 199,
	P_GNSS_ECEF_LHPOS_Y = 200,
	P_GNSS_ECEF_FHPOS_Z = 201,
	P_GNSS_ECEF_LHPOS_Z = 202,
	P_GNSS_ECEF_VEL_X = 203,
	P_GNSS_ECEF_VEL_Y = 204,
	P_GNSS_ECEF_VEL_Z = 205,
	P_G1_P = 206,
	P_G2_P = 207,
	P_FLT_COEF_1_P = 208,
	P_FLT_COEF_2_P = 209,
	P_FLT_COEF_3_P = 210,
	P_FLT_COEF_4_P = 211,
	P_G1_Y = 212,
	P_G2_Y = 213,
	P_FLT_COEF_1_Y = 214,
	P_FLT_COEF_2_Y = 215,
	P_FLT_COEF_3_Y = 216,
	P_FLT_COEF_4_Y = 217,
	P_FC_FAULT_STATUS = 48,
	P_FC_STATUS = 218,
	P_FC_SEQ = 49,
	P_CMD_FC = 50,
	P_FC_Reserved_1 = 219,
	P_FC_Reserved_2 = 220,
	P_FC_Reserved_3 = 221,
	P_FC_Reserved_4 = 222,
	P_IMUR_X_PLD = 223,
	P_IMUR_Y_PLD = 224,
	P_IMUR_Z_PLD = 225,
	P_IMUA_X_PLD = 226,
	P_IMUA_Y_PLD = 227,
	P_IMUA_Z_PLD = 228,
	P_IMU_STATUS_PLD = 229,
	P_GNC_POS_X_PLD = 230,
	P_GNC_POS_Y_PLD = 231,
	P_GNC_POS_Z_PLD = 232,
	P_GNC_VEL_X_PLD = 233,
	P_GNC_VEL_Y_PLD = 234,
	P_GNC_VEL_Z_PLD = 235,
	P_GNC_PR_PLD = 236,
	P_GNC_YR_PLD = 237,
	P_GNC_RR_PLD = 238,
	P_GNC_PA_PLD = 239,
	P_GNC_YA_PLD = 240,
	P_GNC_RA_PLD = 241,
	P_TS_PLD = 51,
	P_CS_PLD = 52,
	P_VS_PLD = 53,
	P_IMUT_PLD = 54,
	P_IMUV_PLD = 55,

	/**< 8Bit parameters */
	S_IPC = 99,
    S_MFV1 = 98,
    ATF_PT = 97,
		/**< Sequence Feedback. */
	P_SEQ_EC_FB = 96,
	P_SEQ_CRIO_FB = 95, /**< Command feedback comes from CRIO. */
	P_CMD_CRIO = 94, /**< Commands that comes from CRIO. */

	/**< 16 Bit parameters */

	/**< 32 Bit parameters. */

	/**< CRIO Health status*/
	P_CRIO_HEALTH_STATUS = 149
}parameter_id;

typedef enum
{
	SEQ_STARTUP = 1,
	SEQ_HIL_CTRL,
	SEQ_HIL_NAV,
	SEQ_TELEM_ON,
	SEQ_TELEM_OFF,
	SEQ_ECU_ON,
	SEQ_ECU_OFF,
	SEQ_GIM_ON,
	SEQ_GIM_OFF,
	SEQ_GNSS_ON,
	SEQ_GNSS_OFF,
	SEQ_IMU_ON,
	SEQ_IMU_OFF
}sequence_id_t;

typedef enum
{
	EC_CMD_STARTS = 1,
	EC_CMD_TELEM_CONN,
	EC_CMD_TELEM_DISCONN,
	EC_CMD_CRIO_CONN,
	EC_CMD_CRIO_DISCONN,
	EC_CMD_ATS_CONN,
	EC_CMD_ATS_DISCONN,

	EC_CMD_GIMBAL_DISABLE,
	EC_CMD_GIMBAL_ENABLE,
	EC_CMD_GIMBAL_ACT_INIT,

	EC_CMD_LOAD_CALIB,
	EC_CMD_ECU_PWROFF,
	EC_CMD_VALVE_CMD_STARTS = 18,
	/**< Put all the valve commands here. */

	C_EV_LOX_PRESS_ON,
	C_EV_LOX_VENT_ON,
	R_EV_RCS_1_ON,
	R_EV_RCS_2_ON,
	R_EV_RCS_3_ON,
	R_EV_RCS_4_ON,
	C_EV_LOX_FILL_ON,
	C_EV_CHILL_DRAIN_ON,
	F_EV_ATF_FILL_ON,
	C_EPV_MOV_ON,
	F_EPV_MFV_ON,
	F_EV_ATF_VENT_ON,
	F_EV_ATF_PRESS_ON,
	C_EV_LOX_PRS_fill_ON,
	F_EV_ATF_PRS_fill_ON,
	R_EV_RCS_PRS_fill_ON,
	VALVE_NOT_CONNECTED_ON,
	QD_H_DB50M_1a_ON,
	QD_H_DB50M_1b_ON,
	QD_H_DB50M_1c_ON,
	
	C_EV_LOX_PRESS_OFF,
	C_EV_LOX_VENT_OFF,
	R_EV_RCS_1_OFF,
	R_EV_RCS_2_OFF,
	R_EV_RCS_3_OFF,
	R_EV_RCS_4_OFF,
	C_EV_LOX_FILL_OFF,
	C_EV_CHILL_DRAIN_OFF,
	F_EV_ATF_FILL_OFF,
	C_EPV_MOV_OFF,
	F_EPV_MFV_OFF,
	F_EV_ATF_VENT_OFF,
	F_EV_ATF_PRESS_OFF,
	C_EV_LOX_PRS_fill_OFF,
	F_EV_ATF_PRS_fill_OFF,
	R_EV_RCS_PRS_fill_OFF,
	VALVE_NOT_CONNECTED_OFF,
	QD_H_DB50M_1a_OFF,
	QD_H_DB50M_1b_OFF,
	QD_H_DB50M_1c_OFF,
	
	EC_CMD_VALVE_CMD_ENDS =  59,

	/**< NOTE: Sensor commands are not handled by this list */
	EC_CMD_SENSOR_CMD_STARTS = 60,

	/**< Put all the sensor commands here. */
	EC_CMD_PHASE_CMD_STARTS = 100,
	EC_CMD_PHASE_1,
	EC_CMD_PHASE_2,
	EC_CMD_PHASE_3,
	EC_CMD_PHASE_4,
	EC_CMD_PHASE_5,
	EC_CMD_PHASE_6,
	EC_CMD_PHASE_7,
	EC_CMD_PHASE_8,
	EC_CMD_PHASE_9,
	EC_CMD_PHASE_10,

	/**< FC Commands start from here. */
	FC_CMD_STARTS = 150,
	FC_CMD_TELEM_CONN,
	FC_CMD_TELEM_DISCONN,
	FC_CMD_CRIO_CONN,
	FC_CMD_CRIO_DISCONN,
	FC_CMD_ATS_CONN,
	FC_CMD_ATS_DISCONN,
	FC_CMD_EC_CONN,
	FC_CMD_EC_DISCONN,
	
	/**<
	 * Internal commands.
	 * */
	/**< Commands to start or stop Guidance */
	FC_CMD_GUID_STOP,
	FC_CMD_GUID_START,

	/**< Command to start NAV from selfalignment */
	FC_CMD_NAV_SLFAL,

	/**< Commands to Start or stop Control */
	FC_CMD_CTRL_STOP,
	FC_CMD_CTRL_START,

	/**< Commands to start or stop Gimbal Trajectory */
	FC_CMD_GIMB_EXE,
	FC_CMD_GIMB_STP,

	/**< Commands to start or stop IMU */
	FC_CMD_IMU_START,
	FC_CMD_IMU_STOP,

	/**< Load Gimbal Trajectory File. */
	FC_CMD_GUID_LOAD_TRAJ,

	/**< Commands to start or stop GNSS */
	FC_CMD_GNSS_START,
	FC_CMD_GNSS_STOP,

	/**< Command to send the gimbal actuator to mean. */
	FC_CMD_GIMB_MEAN,

	/**< Command to start control from strapdown. */
	FC_CMD_NAV_STRAPDOWN,

	/**< Command to start 6 DOF. */
	FC_CMD_START_6DOF,
	FC_CMD_STOP_6DOF,

	/**< FC Relay command starts. */
	FC_CMD_RELAY_STARTS = 180,
	FC_CMD_GPIO_1_OUT_OFF,
	FC_CMD_GPIO_2_OUT_OFF,
    FC_CMD_FC_VP_EN_OFF,  /**< Valve package. */
    FC_CMD_ECU_EN_OFF,    /**< Engine Computer. */
    FC_CMD_PP_EN_OFF,     /**< Payload Unit */
    FC_CMD_IMU_EN_OFF,    /**< IMU Unit */
    FC_CMD_TT_EN_OFF,     /**< Tracking Transponder*/
    FC_CMD_GA_EN_OFF,     /**< Gimbal Actuator*/
    FC_CMD_CAM_EN_OFF,    /**< Camera */
    FC_CMD_TMT_EN_OFF,    /**< Telemetry Transmitting Unit */
    FC_CMD_TMP_EN_OFF,    /**< Telemetry Processing Unit */
    FC_CMD_GNSS_EN_OFF,   /**< GNSS */
	FC_CMD_GPIO_1_OUT_ON,
	FC_CMD_GPIO_2_OUT_ON,
    FC_CMD_FC_VP_EN_ON,
    FC_CMD_ECU_EN_ON,
    FC_CMD_PP_EN_ON,
    FC_CMD_IMU_EN_ON,
    FC_CMD_TT_EN_ON,
    FC_CMD_GA_EN_ON,
    FC_CMD_CAM_EN_ON,
    FC_CMD_TMT_EN_ON,
    FC_CMD_TMP_EN_ON,
    FC_CMD_GNSS_EN_ON,

	/**< FC Input commands*/
	FC_CMD_INPUT_STARTS = 210,
    FC_CMD_GPIO_3_IN_1,
    FC_CMD_LMP_2,
    FC_CMD_LMP_1,

	

	/**< CRIO Commands start from here. */
	CRIO_CMD_STARTS = 220,
	N_EPV_MP1_OFF,
	N_EPV_GP1_OFF,
	SPARK_PLUG_ON
}command_id;

/**< Sequence IDs*/
typedef enum
{
    SEQ_IGNITION = 1,
	SEQ_ALS,
}sequence_ids_t;

/**< Fault IDs.*/
typedef enum
{
    F_S_IPC,
    F_S_MFV1,
    F_ATF_PT,
    P_F1,
    P_F2,
    P_F3,

	F_EC_GC_TIMEOUT,
	F_EC_GC_INIT_FAIL,
	F_EC_GC_GNRIC_FAIL,
	F_EC_ER_UNKN_CONN,
	F_EC_ER_RX_TIMEOUT,
	F_EC_ER_GNRIC_FAIL,
}fault_ids_t;


/**< Valve IDs. */
typedef enum
{
    MFV1,
    MOV1,
}valve_ids_t;

/**
 *  \brief All subsystem definitions in the vehicle.
 *
 *  Names of all systems are defined here including the
 *  redundant systems. These names will be used in logging
 *  and message packets.
 *
 *  */
typedef enum
{
	NA = 0,
	ECU_1 = 1,        /*!< Engine Control Unit -1 */                        //!< ECU_1
	ECU_2,            /*!< Engine Control Unit -2 */                        //!< ECU_2
	ECU_3,            /*!< Engine Control Unit -3 */                        //!< ECU_3
	ECU_4,            /*!< Engine Control Unit -4 */                        //!< ECU_4
	ECU_5,            /*!< Engine Control Unit -5 */                        //!< ECU_5
	ECU_6,            /*!< Engine Control Unit -6 */                        //!< ECU_6
	ECU_7,            /*!< Engine Control Unit -7 */                        //!< ECU_7
	FC,               /*!< Flight Computer */                               //!< FC
	TELEMETRY,        /*!< Telemetry */                                     //!< TELEMETRY
	LC,				  /*!< Launchpad Computer */							//!< LC
	ECU_1_2,          /*!< Engine Control Unit -1 - Stage 2 */              //!< ECU_1 - Stage 2
	MCRC,			  /*!< Mission Control Room Computer */					//!< MCRC
	GC,				  /*!< Ground Checkout Computer*/						//!< GC
	ALL,			  /*!< Broadcast to all system */						//!< ALL
	PC,               /*!< For Laptop. Only used for debugging */           //!< PC
	LO                /*!< loopback interface - only used while debugging *///!< LO
}subsystem_t;

typedef enum
{
	computer_NA = 0,
	computer_FC,
	computer_EC,
	computer_CRIO
}computer_t;


/**< Phase ID list. */
typedef enum
{
	PHASE_1,
	PHASE_2,
}phase_id_t;


typedef enum
{
	F_EC_RX_DISCONNECTED,
	F_CRIO_RX_DISCONNECTED,
	F_TELEM_TX_DISCONNECTED,
	F_EC_TX_DISCONNECTED,
	F_CRIO_TX_DISCONNECTED,
}faultID_t;

///**
// * @brief  Data packet structure for communication between subsystems
// * @details This packet structure will be used for communications
// * between different subsystems in the vehicle.
// *
// * \internal
// * The Criticality-Compressibility-Sensor PID set shall be packed by every
// * sensor data packetization module as shown in the second diagram below:
// *
// * Version: v1.4.3
// * |-------------------------------------------------------------------------|
// * |           | Criticality     |            |          |          |        |
// * | Timestamp | Compressibility | Command ID | Fault ID |  Value   |Reserved|
// * |           | Sensor ID       |            |          |          |        |
// * |-------------------------------------------------------------------------|
// * |  8-bytes  |     2-bytes     |   1-byte   |  1-byte  | 4-bytes  | 4-byte |
// * |-----------/-------------------------------------------------------------|
// *            /
// *           /
// *          /
// *         /
// * |---------------------------------------------------|
// * |  Criticality  | Compressibility  |   Sensor ID    |
// * |---------------------------------------------------|
// * |    1-bit      |      1-bit       |   14-bits      |
// * |---------------------------------------------------|
// * | 0-Non-Critical| 0-not compressed |  Refer         |
// * | 1-Critical    | 1-compressible   |  sensor_ids_t  |
// * |---------------------------------------------------|
// * \endinternal
// * */
///*! Packetization format v1.4.3 screenshot:
// *  \image html Packetization_Format.jpg
// *  \image latex Packetization_Format.jpg
// *
// * */

/**
 * @brief Struct defining the payload data packets to be placed in
 * @details the ethernet network packet. In accordance with Internal Data packetization V2.4E
 */
typedef struct __attribute__((packed))
{
	uint8_t parameter_id;
	uint32_t data;
} datapacket_t;


#endif /* PACKETIZATION_FORMAT_H_ */

