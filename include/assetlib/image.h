#ifndef ASSETLIB_IMAGE_H
#define ASSETLIB_IMAGE_H

/*!
Enum that stores the color format of the image.
author: Jonathan Duncanson
*/
enum color_format
{
    RGB,
    RGBA,
    NONE
};

/*!
Struct to store image data.
author: Jonathan Duncanson
*/
struct image
{
    unsigned int width, height;
    enum color_format format;
    unsigned char* data;
};

/*!
Function that clears an image's data.
author: Jonathan Duncanson
*/
void clear_image(struct image* image);


/*!
Function that creates a new image from the parameters.
author: Jonathan Duncanson
*/
struct image* create_image(unsigned int width, unsigned int height, enum color_format format, unsigned char* data);

/*!
Function that creates a new blank image.
author: Jonathan Duncanson
*/
struct image* create_blank_image();

/*!
Function that deletes an image and any related data.
author: Jonathan Duncanson
*/
void delete_image(struct image* image);

#endif
