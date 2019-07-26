#include <include/assetlib/audio.h>

#include <stddef.h>
#include <stdlib.h>

void clear_audio_data(audio_data* data)
{
	//set to defaults of 0
	data->bits_per_sample = 0;
	data->block_align = 0;
	data->byte_rate = 0;
	data->channels = 0;
	data->sample_rate = 0;

	//free any residual memory for the raw data
	if (data->data != NULL)
		free(data->data);

	data->data = NULL;
}

audio_data* create_audio_data(unsigned int channels, long sample_rate, long byte_rate, int block_align, int bits_per_sample, unsigned char* data)
{
	//create a blank audio data structure
    audio_data* audio_data_ = create_blank_audio_data();

	if (!audio_data_)
		return NULL;

	//set all data using parameters
	audio_data_->bits_per_sample = bits_per_sample;
	audio_data_->block_align = block_align;
	audio_data_->byte_rate = byte_rate;
	audio_data_->channels = channels;
	audio_data_->data = data;
	audio_data_->sample_rate = sample_rate;

	return audio_data_;
}

audio_data* create_blank_audio_data()
{
	//malloc the memory and create the structure
    audio_data* audio_data_ = malloc(sizeof(audio_data));

	if (!audio_data_)
		return NULL;

	//set the data to NULL
	audio_data_->data = NULL;

	//reset everything to make the structure blank
	clear_audio_data(audio_data_);

	return audio_data_;
}

void delete_audio_data(audio_data* audio_data)
{
	//clear and delete the structure
	clear_audio_data(audio_data);
	free(audio_data);
}

