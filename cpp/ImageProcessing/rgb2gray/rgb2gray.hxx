#ifndef RGB2GRAY_HXX
#define RGB2GRAY_HXX
#include "itkImage.h"
#include "itkRGBPixel.h"

#include "itkImageRegionIterator.h"
#include "itkImageRegionIteratorWithIndex.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"


#include "itkTimeProbe.h"
#include "itkNumericTraits.h"

#include "itkImageToVTKImageFilter.h"
#include "QuickView.h"

#include <vector>
#include <iterator>

constexpr int DIMENSION = 2;


template<typename T> int 
rgb2gray(T red, T green, int blue)
/**This function shouldn't care if it takes basic c++ int or ITK **/
{
  constexpr float R_MULTIPLIER = 0.21;
  constexpr float G_MULTIPLIER = 0.72; 
  constexpr float B_MULTIPLIER = 0.07;
  auto r =  red;
  auto g =  green;
  auto b =  blue;
  auto result = (R_MULTIPLIER*r + G_MULTIPLIER*g + B_MULTIPLIER*b);
  return result;
}













#endif // RGB2GRAY_HXX