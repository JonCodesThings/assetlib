#ifndef ASSETLIB_AUDIO_H
#define ASSETLIB_AUDIO_H

#include <stdbool.h>

/*!
Struct to store audio data.
author: Jonathan Duncanson
*/
struct audio_data
{
	int channels;
	long sample_rate;
	long byte_rate;
	int block_align;
	int bits_per_sample;
	unsigned char* data;
};

/*!
Function that clears an audio data structure.
author: Jonathan Duncanson
*/
void clear_audio_data(struct audio_data* audio_data);

/*!
Function that creates a new audio data structure from the parameters.
author: Jonathan Duncanson
*/
struct audio_data* create_audio_data(unsigned int channels, long sample_rate, long byte_rate, int block_align, int bits_per_sample, unsigned char* data);

/*!
Function that creates a new audio data structure.
author: Jonathan Duncanson
*/
struct audio_data* create_blank_audio_data();

/*!
Function that deletes an audio data structure and any related data.
author: Jonathan Duncanson
*/
void delete_audio_data(struct audio_data* audio_data);

#endif
