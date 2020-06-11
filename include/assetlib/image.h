#ifndef ASSETLIB_IMAGE_H
#define ASSETLIB_IMAGE_H

//NOTE: @Jon
//Enum for image colour format.
enum COLOUR_FORMAT
{
	NONE,
    RGB,
    RGBA,
    COLOR_FORMAT_COUNT
};

//NOTE: @Jon
//Struct to store image data.
typedef struct
{
    unsigned int width, height;
    enum COLOUR_FORMAT format;
    unsigned char* data;
} Image;

//NOTE: @Jon
//Function that clears an image's data.
void ClearImage(Image *image);


//NOTE: @Jon
//Function that creates a new image from the parameters.
Image *CreateImage(unsigned int width, unsigned int height, enum COLOUR_FORMAT format, unsigned char* data);

//NOTE: @Jon
//Function that creates a new blank image.
Image *CreateBlankImage();

//NOTE: @Jon
//Function that deletes an image and any related data.
void DeleteImage(Image *image);

#endif
