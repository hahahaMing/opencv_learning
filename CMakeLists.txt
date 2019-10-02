cmake_minimum_required(VERSION 2.8)
project( Opencv_test )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}")


#add_executable( Opencv_test v01_Open_camera.cpp)
#add_executable( Opencv_test v02_Read_image.cpp )
add_executable( Opencv_test v03_Image_binarization.cpp)

target_link_libraries( Opencv_test ${OpenCV_LIBS} )
