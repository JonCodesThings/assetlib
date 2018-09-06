#include <png_utils.h>

#include <stdlib.h>
#include <stdio.h>
#include <png.h>

bool is_png(const char* filepath)
{
    FILE* file = fopen(filepath, "rb");

    if (!file)
        return false;

    unsigned char png_header[8];
    fread(png_header, 1, 8, file);

    fclose(file);

    if (png_sig_cmp(png_header, 0, 8))
        return false;

    return true;
}

bool load_png(const char* filepath, struct image* image)
{
    if (!is_png(filepath))
        return false;

    //creates a png read struct
    png_structp png_struct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_struct)
    {
        png_destroy_read_struct(&png_struct, NULL, NULL);
        return false;
    }

    //creates a png info struct
    png_infop png_info = png_create_info_struct(png_struct);

    if (!png_info)
    {
        png_destroy_read_struct(&png_struct, &png_info, NULL);
        return false;
    }

    //for libpng error handling
    if (setjmp(png_jmpbuf(png_struct)))
    {
        png_destroy_read_struct(&png_struct, &png_info, NULL);
    }

    //opens the file and sets up libpng's io
    FILE* file = fopen(filepath, "rb");

    png_init_io(png_struct, file);
    png_set_sig_bytes(png_struct, 0);

    png_read_info(png_struct, png_info);

    //sets up the image object's data
    image->width = png_get_image_width(png_struct, png_info);
    image->height = png_get_image_height(png_struct, png_info);
    unsigned char png_color_format = png_get_color_type(png_struct, png_info);

    //unsigned char png_bit_depth = png_get_bit_depth(png_struct, png_info);


    //defines the image's format
    switch(png_color_format)
    {
        default:
            png_destroy_read_struct(&png_struct, &png_info, NULL);
            return false;
        case PNG_COLOR_TYPE_RGB:
            image->format = RGB;
            break;
        case PNG_COLOR_TYPE_RGBA:
            image->format = RGBA;
            break;
    }

    png_read_update_info(png_struct, png_info);

    unsigned int row_size = png_get_rowbytes(png_struct, png_info);

    //allocates memory for the image data
    image->data = (unsigned char*)malloc(row_size * sizeof(unsigned char) * image->height);

    //list of row pointers for libpng
    unsigned char** row_pointers = malloc(image->height * sizeof(unsigned char*));

    //flips the data to make it easier to use as a texture
    for (int i = 0; i < image->height; i++)
        row_pointers[image->height - 1 - i] = image->data + row_size * i;

    if (setjmp(png_jmpbuf(png_struct)))
    {
        png_destroy_read_struct(&png_struct, &png_info, NULL);
    }

    //reads in the entire image
    png_read_image(png_struct, row_pointers);

    //frees the row pointers
    free(row_pointers);

    //libpng cleanup
    png_destroy_read_struct(&png_struct, &png_info, NULL);

    return true;
}
