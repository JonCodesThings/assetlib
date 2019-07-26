cmake_minimum_required(VERSION 3.10)
project(assetlib C)

set(CMAKE_C_STANDARD 11)

find_package(PNG)
if(PNG_FOUND)
	include_directories(${PNG_INCLUDE_DIRS})
endif()

include_directories(.)

set(SOURCE_FILES
	src/audio.c
	src/image.c
	src/model.c
	src/obj_utils.c
	src/png_utils.c
	src/wav_utils.c
	include/assetlib/audio.h
	include/assetlib/image.h
	include/assetlib/model.h
	include/assetlib/obj_utils.h
	include/assetlib/png_utils.h
	include/assetlib/wav_utils.h)

add_library(assetlib STATIC ${SOURCE_FILES})
set_target_properties(assetlib PROPERTIES PREFIX "")


