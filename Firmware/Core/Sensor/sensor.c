#include "sensor.h"

volatile float wind_Speed(uint32_t wind_count)
{
	return 0.4396*wind_count;
}
volatile int rain(uint32_t rain_count);
