#include <include/assetlib/image.h>

#include <stddef.h>
#include <stdlib.h>

void clear_image(struct image* image)
{
	//free data as required
	if (image->data != NULL)
		free(image->data);

	//set properties to default
    image->width = 0;
    image->height = 0;
    image->format = NONE;
}

struct image* create_image(unsigned int width, unsigned int height, enum color_format format, unsigned char* data)
{
	//create a new blank image
	struct image* image_ = create_blank_image();

    if (!image_)
        return NULL;

	//set properties based on parameters
    image_->width = width;
    image_->height = height;
    image_->format = format;
    image_->data = data;

    return image_;
}

struct image* create_blank_image()
{
	//manually allocate the memory
    struct image* image_ = malloc(sizeof(struct image));

    if (!image_)
        return NULL;

	//set data to NULL
    image_->data = NULL;

	//clear any odd data to defaults
	clear_image(image_);

    return image_;
}

void delete_image(struct image* image)
{
	//clear and delete the image data
    clear_image(image);
    free(image);
}
