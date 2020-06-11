#include <include/assetlib/image.h>

#include <stddef.h>
#include <stdlib.h>

void ClearImage(Image *image)
{
	//free data as required
	if (image->data != NULL)
		free(image->data);

	//set properties to default
    image->width = 0;
    image->height = 0;
    image->format = NONE;
}

Image* CreateImage(unsigned int width, unsigned int height, enum color_format format, unsigned char *data)
{
	//create a new blank image
    Image *image_ = CreateBlankImage();

    if (!image_)
        return NULL;

	//set properties based on parameters
    image_->width = width;
    image_->height = height;
    image_->format = format;
    image_->data = data;

    return image_;
}

Image *CreateBlankImage()
{
	//manually allocate the memory
    Image* image_ = malloc(sizeof(Image));

    if (!image_)
        return NULL;

	//set data to NULL
    image_->data = NULL;

	//clear any odd data to defaults
	ClearImage(image_);

    return image_;
}

void DeleteImage(Image *image)
{
	//clear and delete the image data
    ClearImage(image);
    free(image);
}
