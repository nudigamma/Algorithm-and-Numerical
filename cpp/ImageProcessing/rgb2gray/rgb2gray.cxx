/**
 * This file does the following
 * 1.  Using ITK reads a RGB 2D image from Disk [Done]
 * 2.  Using ITK to vtk glue display 2D image   [Done]
 * 3.  Do to gray scale example with pure itk  [Done]
 * 4   Display results [Done]
 * 5.  Time it [Done]
 * 6.  Make Rgb2gray templated [Done]
 * 7.  Compute the grey scale according to the formula  L = r*0.21 + g* 0.72 + b * 0.07 [Done]
 * 8.  Export ImageType(itk) pixels to R , G and B host [Done] 
 * 9.  Create an image class to handle basic images meta handling
 * 10. Do to rgb2gray example with C++ 
 * 11. import back rgb2gray image to itk
 * 12. Display RGB picture with non itk grey scale image. 
 * 13. Create device R, G , B and L 
 * 14. Move memory from host R , G B to device R G B 
 * 15. Launch kernel to compute Luminance on gpu
 * 16. Fetch memory to host 
 * 17. Create itk image for luminance
 * 18. Export computed luminance to itk image
 * 19. Display host luminance, gpu luminance and rgb image
 * 20. Compare GPU versus CPU multiple runs using itk::TimeProbe
 * 21. Free up stuff and exit
 * 22. Rinse and repeat, make sure things are const and passed by reference and ... 
 * 23. ... other cool stuff 
 * 24. **/


// typedef , these can be moved to head most probably
#include "rgb2gray.hxx"
#include <iostream>


using GreyPixelType = unsigned short;
using RGBPixelType = itk::RGBPixel<unsigned char>;

using input_ImageType = itk::Image<RGBPixelType,DIMENSION>;
using output_ImageType = itk::Image<GreyPixelType,DIMENSION>;

using ImageFileReaderType = itk::ImageFileReader<input_ImageType>;
using ImageFileWriterType = itk::ImageFileWriter<output_ImageType>;

using ConstImageIteratorType = itk::ImageRegionConstIterator<input_ImageType>;
using IteratorType = itk::ImageRegionIterator<output_ImageType>;



int *  itkRGB2CbufferRGB (input_ImageType::Pointer RGB)
{ /** Implementing the RGB c++ buffer as implemented in the book Programmign Massively
      Parellel Computing page 52 Figure 3.4 , the R, G and B values are contiguous in memory**/

  std::vector<int> CPPBuffRGB;
  // not needed
  ConstImageIteratorType inputIt(RGB ,RGB->GetRequestedRegion());
  inputIt.GoToBegin();
  while(!inputIt.IsAtEnd())
  
  {
    CPPBuffRGB.push_back(inputIt.Get().GetRed());
    CPPBuffRGB.push_back(inputIt.Get().GetGreen());
    CPPBuffRGB.push_back(inputIt.Get().GetBlue());
  }
  return &CPPBuffRGB[0];
}


// Main starts here
int
main(int argc, const char * argv[])
{

  itk::TimeProbe clock;

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
  clock.Start();
  while(!inputIt.IsAtEnd())
  { 

    int grey = rgb2gray(inputIt.Get().GetRed(),inputIt.Get().GetGreen() ,inputIt.Get().GetBlue() );
    
    outputIt.Set(grey); 
    ++inputIt;
    ++outputIt;
  }
  clock.Stop();
  std::cout <<"Total " << clock.GetTotal() << std::endl;
  clock.Report();
  QuickView viewer;
  viewer.AddImage(rgbImage.GetPointer());
  viewer.AddImage(outputImage.GetPointer());
  viewer.Visualize();


  return EXIT_SUCCESS;
}//end of function main