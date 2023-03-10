#include <cmath>
#include "image.h"

using namespace std;

// HW1 #1
// float x,y: inexact coordinates
// int c: channel
// returns the nearest neighbor to pixel (x,y,c)
float Image::pixel_nearest(float x, float y, int c) const
{
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)
  
  // TODO: Your code here  
  
  return clamped_pixel(x, y, c);
}

// HW1 #1
// float x,y: inexact coordinates
// int c: channel
// returns the bilinearly interpolated pixel (x,y,c)
float Image::pixel_bilinear(float x, float y, int c) const
  {
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)
  
  
  // TODO: Your code here
  
    int left, right, top, bottom;    
    float tl, tr, bl, br;
    float tl_a, tr_a, bl_a, br_a;

    left = floorf(x);
    right = ceilf(x);
    top = floorf(y);
    bottom = ceilf(y);

    tl = clamped_pixel(left, top, c);
    tr = clamped_pixel(right, top, c);
    bl = clamped_pixel(left, bottom, c);
    br = clamped_pixel(right, bottom, c);

    tl_a = (x - left) * (y - top);
    tr_a = (right - x) * (y - top);
    bl_a = (x - left) * (bottom - y);
    br_a = (right - x) * (bottom - y);
  
    return tl_a * br + tr_a * bl + bl_a + tr + br_a * tl;
  }

// HW1 #1
// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image nearest_resize(const Image& im, int w, int h)
  {
  Image ret(w,h,im.c);
  
  NOT_IMPLEMENTED();
  
  return ret;
  }


// HW1 #1
// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image bilinear_resize(const Image& im, int w, int h)
  {
  
   
  return Image();
  }


