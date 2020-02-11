cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(IterateImageData)

find_package(VTK COMPONENTS 
  vtkCommonCore
  vtkIOImage
  vtkInteractionImage
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  vtkCommonDataModel QUIET)
if (NOT VTK_FOUND)
  message("Skipping IterateImageData: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(IterateImageData MACOSX_BUNDLE IterateImageData.cxx )
  target_link_libraries(IterateImageData PRIVATE ${VTK_LIBRARIES})
  add_executable(JPEGReader MACOSX_BUNDLE JPEGReader.cxx )
  target_link_libraries(JPEGReader PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  add_executable(IterateImageData MACOSX_BUNDLE IterateImageData.cxx )
  target_link_libraries(IterateImageData PRIVATE ${VTK_LIBRARIES})
  add_executable(JPEGReader MACOSX_BUNDLE JPEGReader.cxx )
  target_link_libraries(JPEGReader PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS IterateImageData
    MODULES ${VTK_LIBRARIES}
    )
endif () 