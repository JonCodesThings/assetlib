#include <include/assetlib/audio.h>

#include <stddef.h>
#include <stdlib.h>

void ClearAudioBuffer(AudioBuffer *data)
{
	//set to defaults of 0
	data->bitsPerSample = 0;
	data->blockAlign = 0;
	data->byteRate = 0;
	data->channels = 0;
	data->sampleRate = 0;

	//free any residual memory for the raw data
	if (data->data != NULL)
		free(data->data);

	data->data = NULL;
}

AudioBuffer *CreateAudioBuffer(unsigned int channels, long sample_rate, long byte_rate, int block_align, int bits_per_sample, unsigned char* data)
{
	//create a blank audio data structure
    AudioBuffer* audio_data_ = CreateBlankAudioBuffer();

	if (!audio_data_)
		return NULL;

	//set all data using parameters
	audio_data_->bitsPerSample = bits_per_sample;
	audio_data_->blockAlign = block_align;
	audio_data_->byteRate = byte_rate;
	audio_data_->channels = channels;
	audio_data_->data = data;
	audio_data_->sampleRate = sample_rate;

	return audio_data_;
}

AudioBuffer *CreateBlankAudioBuffer()
{
	//malloc the memory and create the structure
    AudioBuffer *audio_data_ = malloc(sizeof(AudioBuffer));

	if (!audio_data_)
		return NULL;

	//set the data to NULL
	audio_data_->data = NULL;

	//reset everything to make the structure blank
	ClearAudioBuffer(audio_data_);

	return audio_data_;
}

void DeleteAudioBuffer(AudioBuffer *audio_data)
{
	//clear and delete the structure
	ClearAudioBuffer(audio_data);
	free(audio_data);
}

