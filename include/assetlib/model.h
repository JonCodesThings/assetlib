#ifndef ASSETLIB_MODEL_H
#define ASSETLIB_MODEL_H

/*!
Struct to store model data.
author: Jonathan Duncanson
*/
struct model_data
{
    float* vertices;
    float* tex_coords;
    float* normals;
    unsigned int vertex_count;
    unsigned int tex_coord_count;
    unsigned int normal_count;
};

/*!
Function that clears a model data structure.
author: Jonathan Duncanson
*/
void clear_model_data(struct model_data* model_data);

/*!
Function that creates a new model data structure from the parameters.
author: Jonathan Duncanson
*/
struct model_data* create_model_data(float* vertices, float* tex_coords, float* normals, unsigned int vertex_count, unsigned int tex_coord_count, unsigned int normal_count);

/*!
Function that creates a new model data structure.
author: Jonathan Duncanson
*/
struct model_data* create_blank_model_data();

/*!
Function that deletes a model data structure and any related data.
author: Jonathan Duncanson
*/
void delete_model_data(struct model_data* model_data);

#endif
