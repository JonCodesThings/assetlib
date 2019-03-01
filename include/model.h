#ifndef ASSETLIB_MODEL_H
#define ASSETLIB_MODEL_H

/*!
Struct to store model data.
author: Jonathan Duncanson
*/
struct model
{
    float* vertices;
    float* tex_coords;
    float* normals;
    unsigned int vertex_count;
    unsigned int tex_coord_count;
    unsigned int normal_count;
};

#endif
