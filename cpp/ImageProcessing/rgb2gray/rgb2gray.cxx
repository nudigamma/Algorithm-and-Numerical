/**
 * This file does the following
 * 1.  Using ITK reads a RGB 2D image from Disk [Done]
 * 2.  Using ITK to vtk glue display 2D image   [Done]
 * 3.  Do to gray scale example with pure itk one thread , lines and then regions !
 * 4   Display results
 * 5.  Creates 3 Buffers ( for R ,G and B) -> Use ImageRegionIterator example 
 * 6.  Export ImageType(itk) pixels to R , G and B host 
 * 7.  Compute the grey scale according to the formula  L = r*0.21 + g* 0.72 + b * 0.07 
 * 8.  
 * 9.  Display RGB picture with host grey scale image. 
 * 10.  Create device R, G , B and L 
 * 11.  Move memory from host R , G B to device R G B 
 * 12. Launch kernel to compute Luminance on gpu
 * 13. Fetch memory to host 
 * 14. Create itk image for luminance
 * 15. Export computed luminance to itk image
 * 16. Display host luminance, gpu luminance and rgb image
 * 17. Free up stuff and exit
 * 18. **/


// typedef , these can be moved to head most probably
#include "rgb2gray.hxx"
#include <iostream>

constexpr int DIMENSION = 2;
constexpr float R_MULTIPLIER = 0.21;
constexpr float G_MULTIPLIER = 0.72;
constexpr float B_MULTIPLIER = 0.07;
using GreyPixelType = unsigned short;
using RGBPixelType = itk::RGBPixel<unsigned char>;

using input_ImageType = itk::Image<RGBPixelType,DIMENSION>;
using output_ImageType = itk::Image<GreyPixelType,DIMENSION>;

using ImageFileReaderType = itk::ImageFileReader<input_ImageType>;
using ImageFileWriterType = itk::ImageFileWriter<output_ImageType>;

using ConstImageIteratorType = itk::ImageRegionConstIterator<input_ImageType>;
using IteratorType = itk::ImageRegionIterator<output_ImageType>;

int
main(int argc, const char * argv[])
{
  if (argc < 3)
    {    
      std::cerr << "Usage rgb2gray input_image output_image";
      std::cerr << std::endl;
      exit(-1);
    } // end of insuficient command line input condition

  ImageFileReaderType::Pointer ImageReaderPtr = ImageFileReaderType::New();
  ImageReaderPtr->SetFileName(argv[1]);

  try
  {
    ImageReaderPtr->Update();
  }
  catch (itk::ExceptionObject &err)
  {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
  } // end of try catch block of reading image from disk

  input_ImageType::Pointer rgbImage = ImageReaderPtr->GetOutput();
  //start defining output image

  output_ImageType::Pointer outputImage = output_ImageType::New();
  outputImage->SetRegions(rgbImage->GetRequestedRegion());
  // Just meta data ( I think )
  outputImage->CopyInformation(rgbImage);
  outputImage->Allocate();

  ConstImageIteratorType inputIt(rgbImage,rgbImage->GetRequestedRegion());
  IteratorType outputIt(outputImage,outputImage->GetRequestedRegion());


  inputIt.GoToBegin();
  outputIt.GoToBegin();

  while(!inputIt.IsAtEnd())
  { 

    int grey = (int) ((float) inputIt.Get().GetRed() * R_MULTIPLIER + (float)inputIt.Get().GetGreen() * G_MULTIPLIER + (float)inputIt.Get().GetBlue() * B_MULTIPLIER );
    ::std::cout<<  itk::NumericTraits<RGBPixelType::ValueType>::PrintType(inputIt.Get().GetRed())
    << std::endl;
    outputIt.Set(grey); 
  }

  QuickView viewer;
  viewer.AddImage(rgbImage.GetPointer());
  viewer.AddImage(outputImage.GetPointer());
  viewer.Visualize();


  return EXIT_SUCCESS;
}//end of function main