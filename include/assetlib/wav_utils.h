#ifndef ASSETLIB_PNG_UTILS_H
#define ASSETLIB_PNG_UTILS_H

#include <stdbool.h>

#include <include/assetlib/audio.h>

//NOTE: @Jon
//Function that determines if a file is a wav. Returns true if it is.
bool IsWAV(const char *filepath);

//NOTE: @Jon
//Function that loads WAV audio data from a file. Returns true if successful.
bool LoadWAV(const char *filepath, AudioBuffer *data);

#endif
