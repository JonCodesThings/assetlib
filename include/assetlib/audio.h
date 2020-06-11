#ifndef ASSETLIB_AUDIO_H
#define ASSETLIB_AUDIO_H

#include <stdbool.h>


//NOTE: @Jon
//Struct to store audio data.
typedef struct
{
	int channels;
	long sampleRate;
	long byteRate;
	int blockAlign;
	int bitsPerSample;
	unsigned char *data;
} AudioBuffer;

//NOTE: @Jon
//Function that clears an audio data structure.
void ClearAudioBuffer(AudioBuffer* buffer);

//NOTE: @Jon
//Function that creates a new audio data structure from the parameters.
AudioBuffer *CreateAudioBuffer(unsigned int channels, long sampleRate, long byteRate, int blockAlign, int bitsPerSample, unsigned char *data);

//NOTE: @Jon
//Function that creates a new audio data structure.
AudioBuffer *CreateBlankAudioBuffer();

//NOTE: @Jon
//Function that deletes an audio data structure and any related data.
void DeleteAudioBuffer(AudioBuffer *buffer);

#endif
