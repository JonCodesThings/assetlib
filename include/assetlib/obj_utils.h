#ifndef ASSETLIB_OBJ_UTILS_H
#define ASSETLIB_OBJ_UTILS_H

#include <stdbool.h>

#include <include/assetlib/model.h>

//TODO: @Jon
//Move this into the source file because it isn't used anywhere else.
//NOTE: @Jon
//Struct to store data about OBJ models.
typedef struct
{
    unsigned int vertices;
    unsigned int normals;
    unsigned int texCoords;
    unsigned int faces;
} OBJInfo;

//NOTE: @Jon
//Function that loads an obj into an model struct. Returns true if successful.
bool LoadOBJModel(const char *filepath, Model *model);

#endif
