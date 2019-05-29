#include <include/audio.h>

#include <stddef.h>
#include <stdlib.h>

void clear_audio_data(struct audio_data* data)
{
	data->bits_per_sample = 0;
	data->block_align = 0;
	data->byte_rate = 0;
	data->channels = 0;
	
	if (data->data != NULL)
		free(data->data);

	data->data = NULL;

	data->sample_rate = 0;
}

struct audio_data* create_audio_data(unsigned int channels, long sample_rate, long byte_rate, int block_align, int bits_per_sample, unsigned char* data)
{
	struct audio_data* audio_data_ = create_blank_audio_data();

	if (!audio_data_)
		return NULL;

	audio_data_->bits_per_sample = bits_per_sample;
	audio_data_->block_align = block_align;
	audio_data_->byte_rate = byte_rate;
	audio_data_->channels = channels;
	audio_data_->data = data;
	audio_data_->sample_rate = sample_rate;

	return audio_data_;
}

struct audio_data* create_blank_audio_data()
{
	struct audio_data* audio_data_ = malloc(sizeof(struct audio_data));

	if (!audio_data_)
		return NULL;

	audio_data_->bits_per_sample = 0;
	audio_data_->block_align = 0;
	audio_data_->byte_rate = 0;
	audio_data_->channels = 0;

	if (audio_data_->data != NULL)
		free(audio_data_->data);

	audio_data_->data = NULL;

	audio_data_->sample_rate = 0;

	return audio_data_;
}

void delete_audio_data(struct audio_data* audio_data)
{
	clear_audio_data(audio_data);
	free(audio_data);
}

