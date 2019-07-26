#ifndef ASSETLIB_OBJ_UTILS_H
#define ASSETLIB_OBJ_UTILS_H

#include <stdbool.h>

#include <include/assetlib/model.h>

/*!
Struct to store data about obj models.
author: Jonathan Duncanson
*/
typedef struct
{
    unsigned int vertices;
    unsigned int normals;
    unsigned int tex_coords;
    unsigned int faces;
} obj_info;

/*!
Function that loads an obj into an model struct. Returns true if successful.
author: Jonathan Duncanson
*/
bool load_obj(const char* filepath, model_data* model);

#endif
