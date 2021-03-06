/*
 * AnalogInput.h
 *
 *  Created on: 2 Apr 2016
 *      Author: David
 */

#ifndef ANALOGIN_H_
#define ANALOGIN_H_

#ifdef __cplusplus

#include "compiler.h"

// Module initialisation
void AnalogInInit();

// Enable or disable a channel. Use AnalogCheckReady to make sure the ADC is ready before calling this.
void AnalogInEnableChannel(AnalogChannelNumber channel, bool enable);

// Return the number of bits provided by a call to AnalogInReadChannel
#if SAME70
static constexpr unsigned int AdcBits = 14;
#else
static constexpr unsigned int AdcBits = 12;
#endif

// Read the most recent result from a channel
uint16_t AnalogInReadChannel(AnalogChannelNumber channel);

typedef void (*AnalogCallback_t)(void);

// Set up a callback for when all conversions have been completed. Returns the previous callback pointer.
AnalogCallback_t AnalogInSetCallback(AnalogCallback_t);

// Start converting the enabled channels, to include the specified ones. Disabled channels are ignored.
void AnalogInStartConversion(uint32_t channels = 0xFFFFFFFF);

// Finalise a conversion
#if SAME70
void AnalogInFinaliseConversion();
#else
static inline void AnalogInFinaliseConversion() { }
#endif

// Check whether all conversions of the specified channels have been completed since the last call to AnalogStartConversion.
// Disabled channels are ignored
bool AnalogInCheckReady(uint32_t channels = 0xFFFFFFFF);

// Convert a pin number to an AnalogIn channel
extern AnalogChannelNumber PinToAdcChannel(uint32_t pin);

// Get the temperature measurement channel
extern AnalogChannelNumber GetTemperatureAdcChannel();

#endif

#endif /* CORES_ARDUINO_ANALOGIN_H_ */
