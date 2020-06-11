#ifndef ASSETLIB_PNG_UTILS_H
#define ASSETLIB_PNG_UTILS_H

#include <stdbool.h>

#include <include/assetlib/image.h>

//NOTE: @Jon
//Function that determines if a file is a PNG. Returns true if it is.
bool IsPNG(const char *filepath);

//NOTE: @Jon
//Function that loads a PNG image from file. Returns true if successful.
bool LoadPNG(const char *filepath, Image* image);

#endif
