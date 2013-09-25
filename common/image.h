//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2013 Andrew Duncan
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#ifndef IMAGE_H
#define IMAGE_H

//-------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "bcm_host.h"
    
//-------------------------------------------------------------------------

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} RGBA8_T;

//-------------------------------------------------------------------------

typedef struct IMAGE_T_
{
    VC_IMAGE_TYPE_T type;
    int32_t width;
    int32_t height;
    int32_t pitch;
    int32_t alignedHeight;
    uint16_t bytesPerPixel;
    uint32_t size;
    void *buffer;
    void (*setPixel)(struct IMAGE_T_*, int, int, RGBA8_T*);
    void (*getPixel)(struct IMAGE_T_*, int, int, RGBA8_T*);
} IMAGE_T;

//-------------------------------------------------------------------------

typedef struct
{
    const char *name;
    VC_IMAGE_TYPE_T type;
    bool hasAlpha;
} IMAGE_TYPE_INFO_T;

typedef enum
{
    IMAGE_TYPES_WITH_ALPHA = 1,
    IMAGE_TYPES_WITHOUT_ALPHA = 2,
    ALL_IMAGE_TYPES = 3
} IMAGE_TYPE_SELECTOR_T;

//-------------------------------------------------------------------------

bool
initImage(
    IMAGE_T *image,
    VC_IMAGE_TYPE_T type,
    int32_t width,
    int32_t height);

void
clearImage(
    IMAGE_T *image,
    RGBA8_T *rgb);

void destroyImage(IMAGE_T *image);

//-------------------------------------------------------------------------

bool
findImageType(
    IMAGE_TYPE_INFO_T *typeInfo,
    const char *name,
    IMAGE_TYPE_SELECTOR_T selector);

void
printImageTypes(
    FILE *fp,
    const char *before,
    const char *after,
    IMAGE_TYPE_SELECTOR_T selector);

//-------------------------------------------------------------------------

#endif
