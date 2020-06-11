#ifndef ASSETLIB_MODEL_H
#define ASSETLIB_MODEL_H

//NOTE: @Jon
//Struct to store model data.
typedef struct
{
    float *vertices;
    float *texCoords;
    float *normals;
    unsigned int vertexCount;
    unsigned int texCoordCount;
    unsigned int normalCount;
} Model;

//NOTE: @Jon
//Function that clears a model data structure.
void ClearModel(Model *model);

//NOTE: @Jon
//Function that creates a new model data structure from the parameters.
Model *CreateModel(float* vertices, float* texCoords, float* normals, unsigned int vertexCount, unsigned int texCoordCount, unsigned int normalCount);

//NOTE: @Jon
//Function that creates a new model data structure.
Model *CreateBlankModel();

//NOTE: @Jon
//Function that deletes a model data structure and any related data.
void DeleteModel(Model *model_data);

#endif
