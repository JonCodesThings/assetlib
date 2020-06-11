#include <include/assetlib/model.h>

#include <stddef.h>
#include <stdlib.h>

void ClearModel(Model *model_data)
{
	//free all vertex, texture co-ordinate and normal data as required
	if (model_data->vertices)
		free(model_data->vertices);
	if (model_data->texCoords)
		free(model_data->texCoords);
	if (model_data->normals)
		free(model_data->normals);

	//set pointers to NULL
	model_data->vertices = NULL;
	model_data->texCoords = NULL;
	model_data->normals = NULL;

	//set other data to default
	model_data->vertexCount = 0;
	model_data->texCoordCount = 0;
	model_data->normalCount = 0;
}

Model *CreateModelData(float * vertices, float * tex_coords, float * normals, unsigned int vertex_count, unsigned int tex_coord_count, unsigned int normal_count)
{
	//create blank structure
    Model *model_ = CreateBlankModel();

	if (!model_)
		return NULL;

	//set properties based on parameters
	model_->vertices = vertices;
	model_->texCoords = tex_coords;
	model_->normals = normals;
	model_->vertexCount = vertex_count;
	model_->texCoordCount = tex_coord_count;
	model_->normalCount = normal_count;

	return model_;
}

Model *CreateBlankModel()
{
	//manually allocate the model structure
    Model *model_ = malloc(sizeof(Model));

	//set pointers to NULL
	model_->vertices = NULL;
	model_->texCoords = NULL;
	model_->normals = NULL;

	if (!model_)
		return NULL;

	//set properties to default
	ClearModel(model_);

	return model_;
}

void DeleteModel(Model *model_data)
{
	//clear and free the model data
	ClearModel(model_data);
	free(model_data);
}
