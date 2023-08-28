/**
 ******************************************************************************
 * @file           : depacketizer.h
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

#ifndef DEPACKETIZER_FORMAT_H_
#define DEPACKETIZER_FORMAT_H_

#include <stdint.h>
#include <stdio.h>

#define BIT16_PARAMETER_START (100)

#define BIT32_PARAMETER_START (150)

typedef struct  __attribute__((packed))
{
    uint8_t param_id;
    uint32_t data;
}packet_body_t;

uint8_t depacketize_from_buffer(const uint8_t* buffer, packet_body_t* packet_bodies, uint8_t packet_count);

size_t get_size(int param_id);

#endif /* DEPACKETIZER_FORMAT_H_ */