#ifndef ASSETLIB_PNG_UTILS_H
#define ASSETLIB_PNG_UTILS_H

#include <stdbool.h>

#include <include/assetlib/audio.h>

/*!
Function that determines if a file is a wav. Returns true if it is.
author: Jonathan Duncanson
*/
bool is_wav(const char* filepath);

/*!
Function that loads a wav into an audio_data struct. Returns true if successful.
author: Jonathan Duncanson
*/
bool load_wav(const char* filepath, audio_data* data);

#endif
