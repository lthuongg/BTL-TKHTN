/*
 * sensor.h
 *
 *  Created on: Nov 3, 2024
 *      Author: LE TUAN THANH
 */

#ifndef SENSOR_SENSOR_H_
#define SENSOR_SENSOR_H_
#include "main.h"

#include <stdint.h>
volatile float wind_Speed(uint32_t wind_count);
volatile int rain(uint32_t rain_count);

#endif /* SENSOR_SENSOR_H_ */
