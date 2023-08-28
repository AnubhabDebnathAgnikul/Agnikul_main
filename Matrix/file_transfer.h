/**
 ******************************************************************************
 * @file           : file_transfer.h
 * @project        : Agnikul Generic Software Library
 * @brief          : Vehicle data depacketization format
 * @author         : Sai Thilak
 * @version        : v1.0
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) Agnikul Cosmos Private Limited
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

#ifndef FILE_TRANSFER_H
#define FILE_TRANSFER_H

#include "common.h"
#include "packetization_format.h"

#define EC_USR ("root")

int send_to_ec(const char* src_file_name, const char* dest_file_name);

int set_cmd_timeout(const int timeout);

#endif /* FILE_TRANSFER_H */
