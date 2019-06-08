#ifndef ASSETLIB_PNG_UTILS_H
#define ASSETLIB_PNG_UTILS_H

#include <stdbool.h>

#include <include/assetlib/image.h>

/*!
Function that determines if a file is a png. Returns true if it is.
author: Jonathan Duncanson
*/
bool is_png(const char* filepath);

/*!
Function that loads a png into an image struct. Returns true if successful.
author: Jonathan Duncanson
*/
bool load_png(const char* filepath, struct image* image);

#endif
