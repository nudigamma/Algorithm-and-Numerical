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


int rgb2gray(int r, int g, int b);











#endif // RGB2GRAY_HXX