#include <obj_utils.h>

#include <stdlib.h>
#include <stdio.h>

bool load_obj(const char* filepath, struct model* model)
{
    //opens the file in read mode
    FILE* file = fopen(filepath, "r");

    if (!file)
        return false;

    //gets the size of the file
    fseek(file, 0, SEEK_END);
    unsigned int filesize = ftell(file) + 1;
    char* whole_file = malloc(sizeof(char) * filesize);
    fseek(file, 0, SEEK_SET);

    //reads in the entire file into a memory buffer
    fread(whole_file, filesize, 1, file);
    fclose(file);

    //creates a struct to store model info
    struct obj_info model_info;
    model_info.faces = 0;
    model_info.normals = 0;
    model_info.tex_coords = 0;
    model_info.vertices = 0;

    bool comment_toggle = false;

    //preloads the number of normals, texture coordinates, vertices and faces in the file
    for (unsigned int i = 0; i < filesize - 1; i++)
    {
        switch(whole_file[i])
        {
            default:
                break;
            case 'v':
                if (!comment_toggle)
                {
                    if (whole_file[i + 1] == 'n')
                        model_info.normals++;
                    else if (whole_file[i+1] == 't')
                        model_info.tex_coords++;
                    else
                        model_info.vertices++;
                }
                break;
            case 'f':
                if (!comment_toggle)
                    model_info.faces++;
            case '#':
                comment_toggle = true;
                break;
            case '\n':
                comment_toggle = false;
                break;
        }
    }

    //allocates memory for the unsorted data

    float* unsorted_normals = malloc(sizeof(float) * model_info.normals * 3);
    if (!unsorted_normals)
        return false;

    float* unsorted_tex_coords = malloc(sizeof(float) * model_info.tex_coords * 2);
    if (!unsorted_tex_coords)
        return false;

    float* unsorted_vertices = malloc(sizeof(float) * model_info.vertices * 3);
    if (!unsorted_vertices)
        return false;

    int* faces = malloc(sizeof(int) * model_info.faces * 9);
    if (!faces)
        return false;

    unsigned int unsorted_normal_index = 0;
    unsigned int unsorted_tex_coord_index = 0;
    unsigned int unsorted_vertices_index = 0;
    unsigned int face_index = 0;

    //loads the unsorted data from the buffer
    for (unsigned int i = 0; i < filesize; i++)
    {
        switch(whole_file[i])
        {
            default:
                break;
            case 'v':
                if (!comment_toggle)
                {
                    if (whole_file[i + 1] == 'n')
                    {
                        sscanf(whole_file + i + 2, "%f %f %f\n", &unsorted_normals[unsorted_normal_index], &unsorted_normals[unsorted_normal_index + 1], &unsorted_normals[unsorted_normal_index + 2]);
                        unsorted_normal_index += 3;
                    }
                    else if (whole_file[i+1] == 't')
                    {
                        sscanf(whole_file + i + 2, "%g %g\n", &unsorted_tex_coords[unsorted_tex_coord_index], &unsorted_tex_coords[unsorted_tex_coord_index + 1]);
                        unsorted_tex_coord_index += 2;
                    }
                    else
                    {
                        sscanf(whole_file + i + 1, "%f %f %f\n", &unsorted_vertices[unsorted_vertices_index], &unsorted_vertices[unsorted_vertices_index + 1], &unsorted_vertices[unsorted_vertices_index + 2]);
                        unsorted_vertices_index += 3;
                    }
                }
                break;
            case 'f':
                if (!comment_toggle)
                {
                    sscanf(whole_file + i + 1, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &faces[face_index], &faces[face_index + 1], &faces[face_index + 2], &faces[face_index + 3],
                            &faces[face_index + 4], &faces[face_index + 5], &faces[face_index + 6], &faces[face_index + 7], &faces[face_index + 8]);
                    face_index += 9;
                }
            case '#':
                comment_toggle = true;
                break;
            case '\n':
                comment_toggle = false;
                break;
        }
    }

    //allocates memory to store the final sets of data for the model
    model->normals = malloc(sizeof(float) * 3 * 3 * model_info.faces);
    if (!model->normals)
        return false;

    model->tex_coords = malloc(sizeof(float) * 2 * 3 *model_info.faces);
    if (!model->tex_coords)
        return false;

    model->vertices = malloc(sizeof(float) * 3 * 3 * model_info.faces);
    if (!model->vertices)
        return false;

    unsigned int normal_index = 0;
    unsigned int tex_coord_index = 0;
    unsigned int vertices_index = 0;

    //organises and puts the sorted data into the appropriate arrays
    for (unsigned int i = 0; i < model_info.faces * 9; i+=3)
    {
        model->vertices[vertices_index] = unsorted_vertices[(faces[i] - 1)*3];
        model->vertices[vertices_index + 1] = unsorted_vertices[(faces[i] - 1)*3 + 1];
        model->vertices[vertices_index + 2] = unsorted_vertices[(faces[i] - 1)*3 + 2];

        model->tex_coords[tex_coord_index] = unsorted_tex_coords[(faces[i + 1] - 1)*2];
        model->tex_coords[tex_coord_index + 1] = unsorted_tex_coords[(faces[i + 1] - 1)*2 + 1];

        model->normals[normal_index] = unsorted_normals[(faces[i + 2] - 1)*3];
        model->normals[normal_index + 1] = unsorted_normals[(faces[i + 2] - 1)*3 + 1];
        model->normals[normal_index + 2] = unsorted_normals[(faces[i + 2] - 1)*3 + 2];

        vertices_index += 3;
        tex_coord_index += 2;
        normal_index += 3;
    }

    //sets the model data
    model->normal_count = model_info.faces * 3;
    model->tex_coord_count = model_info.faces * 3;
    model->vertex_count = model_info.faces * 3;

    //cleans up the memory
    free(unsorted_normals);
    free(unsorted_tex_coords);
    free(unsorted_vertices);
    free(faces);

    return true;
}
