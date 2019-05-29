#include "include\model.h"

#include <stddef.h>
#include <stdlib.h>

void clear_model_data(struct model_data* model_data)
{
	//free all vertex, texture co-ordinate and normal data as required
	if (model_data->vertices)
		free(model_data->vertices);
	if (model_data->tex_coords)
		free(model_data->tex_coords);
	if (model_data->normals)
		free(model_data->normals);

	//set pointers to NULL
	model_data->vertices = NULL;
	model_data->tex_coords = NULL;
	model_data->normals = NULL;

	//set other data to default
	model_data->vertex_count = 0;
	model_data->tex_coord_count = 0;
	model_data->normal_count = 0;
}

struct model_data* create_model_data(float * vertices, float * tex_coords, float * normals, unsigned int vertex_count, unsigned int tex_coord_count, unsigned int normal_count)
{
	//create blank structure
	struct model_data* model_ = create_blank_model_data();

	if (!model_)
		return NULL;

	//set properties based on parameters
	model_->vertices = vertices;
	model_->tex_coords = tex_coords;
	model_->normals = normals;
	model_->vertex_count = vertex_count;
	model_->tex_coord_count = tex_coord_count;
	model_->normal_count = normal_count;

	return model_;
}

struct model_data* create_blank_model_data()
{
	//manually allocate the model structure
	struct model_data* model_ = malloc(sizeof(struct model_data));

	//set pointers to NULL
	model_->vertices = NULL;
	model_->tex_coords = NULL;
	model_->normals = NULL;

	if (!model_)
		return NULL;

	//set properties to default
	clear_model_data(model_);

	return model_;
}

void delete_model_data(struct model_data* model_data)
{
	//clear and free the model data
	clear_model_data(model_data);
	free(model_data);
}
