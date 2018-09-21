cmake_minimum_required(VERSION 3.10)
project(assetlib C)

set(CMAKE_C_STANDARD 11)

find_package(PNG)
if(PNG_FOUND)
	include_directories(PNG_INCLUDE_DIRS)
endif()

include_directories(.)

set(SOURCE_FILES
	image.c
	image.h
	model.h
	obj_utils.c
	obj_utils.h
	png_utils.c
	png_utils.h)

add_library(assetlib STATIC ${SOURCE_FILES})
set_target_properties(assetlib PROPERTIES PREFIX "")


