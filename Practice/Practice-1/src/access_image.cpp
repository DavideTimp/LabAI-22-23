#include <iostream>

#include "image.h"

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch)
{

  /*
    [][][][][][]  [][][][][][]  [][][][][][]    //example
        ch 1          ch 2          ch 3
    
    add the number of cell equal to n_channel
    add many rows as x
    add many elements as y
  */

  int address = 0; 

  address += ch * (im.w * im.h); 
  address += y * im.w; 
  address += x; 

  return address;
}

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {
    int clamped_x = x, clamped_y = y, clamped_ch = ch;
    float clamped_value = 0.0;

    if (clamped_x <= 0) { clamped_x = 0; }
    else if (clamped_x >= im.w-1) { clamped_x = im.w-1; }
    
    if (clamped_y <= 0) { clamped_y = 0; }
    else if (clamped_y >= im.h-1) { clamped_y = im.h-1; }
    
    clamped_value = im(clamped_x, clamped_y, clamped_ch);
    return clamped_value;
  }


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
      im(x, y, c) = value;    
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
    // allocating data for the new image
    to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
    to.c=from.c;
    
    // TODO: populate the remaining fields in 'to' and copy the data
    // You might want to check how 'memcpy' function works
    to.w = from.w;
    to.h = from.h;

    memcpy(to.data, from.data, (from.w*from.h*from.c)*sizeof(float));  
  }
