/**
 * This file does the following
 * 1.  Using ITK reads a RGB 2D image from Disk
 * 2.  
 * 3.  Creates 3 Buffers ( for R ,G and B) 
 * 4.  Export ImageType(itk) pixels to R , G and B host 
 * 5.  Compute the grey scale according to the formula  L = r*0.21 + g* 0.72 + b * 0.07 
 * 6.  
 * 7.  Display RGB picture with host grey scale image. 
 * 8.  Create device R, G , B and L 
 * 9.  Move memory from host R , G B to device R G B 
 * 10. Launch kernel to compute Luminance on gpu
 * 11. Fetch memory to host 
 * 12. Create itk image for luminance
 * 13. Export computed luminance to itk image
 * 14. Display host luminance, gpu luminance and rgb image
 * 15. Free up stuff and exit
 * 16. **/


// typedef , these can be moved to head most probably
#include "rgb2gray.hxx"
#include <iostream>

constexpr int DIMENSION = 2;
using GreyPixelType = unsigned short;
using RGBPixelType = itk::RGBPixel<unsigned char>;

using input_ImageType = itk::Image<RGBPixelType,DIMENSION>;
using output_ImageType = itk::Image<GreyPixelType,DIMENSION>;

using ImageFileReaderType = itk::ImageFileReader<input_ImageType>;
using ImageFileWriterType = itk::ImageFileWriter<output_ImageType>;

//using ConvertVTKToITKType = itk::ImageToVTKImageFilter<input_ImageType>;

//using RescaleFilterType = itk::RescaleIntensityImageFilter<input_ImageType,input_ImageType>;
int
main(int argc, const char * argv[])
{
    if (argc < 3)
    {    
        std::cerr << "Usage rgb2gray input_image output_image";
        std::cerr << std::endl;
        exit(-1);
    }
ImageFileReaderType::Pointer ImageReaderPtr = ImageFileReaderType::New();
ImageReaderPtr->SetFileName(argv[1]);
ImageReaderPtr->Update();

input_ImageType::Pointer rgbImage = ImageReaderPtr->GetOutput();

//RescaleFilterType::Pointer rescaleFilterPtr = RescaleFilterType::New();

//rescaleFilterPtr->SetInput(ImageReaderPtr->GetOutput());
//rescaleFilterPtr->SetOutputMinimum(0);
//rescaleFilterPtr->SetOutputMaximum(255);

QuickView viewer;
viewer.AddImage(ImageReaderPtr->GetOutput());
//viewer.AddImage(RescaleFilterPtr->GetOutput());
viewer.Visualize();
/*
ImageFileWriterType::Pointer ImageWriterPtr = ImageFileWriterType::New();

ImageWriterPtr->SetFileName(argv[2]);
ImageWriterPtr->SetInput(ImageReaderPtr->GetOutput());


try
    {
        ImageWriterPtr->Update();
    }
catch (const itk::ExceptionObject &exp)
    {
        std::cerr <<"Writing image to disk exception caugh";
        std::cerr << exp << std::endl;
        return EXIT_FAILURE;
    }
**/

return EXIT_SUCCESS;
}//end of function main