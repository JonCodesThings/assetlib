#include <image.h>

#include <stddef.h>
#include <stdlib.h>

void clear_image(struct image* image)
{
    free(image->data);
    image->width = 0;
    image->height = 0;
    image->format = NONE;
}

struct image* create_image(unsigned int width, unsigned int height, enum color_format format, unsigned char* data)
{
    struct image* image_ = malloc(sizeof(struct image));

    if (!image_)
        return NULL;

    image_->width = width;
    image_->height = height;
    image_->format = format;
    image_->data = data;

    return image_;
}

struct image* create_blank_image()
{
    struct image* image_ = malloc(sizeof(struct image));
    if (!image_)
        return NULL;

    image_->width = 0;
    image_->height = 0;
    image_->format = NONE;
    image_->data = NULL;

    return image_;
}

void delete_image(struct image* image)
{
    clear_image(image);
    free(image);
}
