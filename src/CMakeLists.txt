cmake_minimum_required(VERSION 3.13)  # CMake version check
project(ffmpegdecoder)                # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

set(CMAKE_PREFIX_PATH D:/decentraland/ffmpeg-dep/lib D:/decentraland/ffmpeg-dep/include)

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h)
find_library(AVCODEC_LIBRARY avcodec)

find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
find_library(AVFORMAT_LIBRARY avformat)

find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h)
find_library(AVUTIL_LIBRARY avutil)

find_path(AVDEVICE_INCLUDE_DIR libavdevice/avdevice.h)
find_library(AVDEVICE_LIBRARY avdevice)

find_path(SWRESAMPLE_INCLUDE_DIR libswresample/swresample.h)
find_library(SWRESAMPLE_LIBRARY swresample)

find_path(SWSCALE_INCLUDE_DIR libswscale/swscale.h)
find_library(SWSCALE_LIBRARY swscale)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES
    AVHandler.cpp
    DecoderFFmpeg.cpp
    Logger.cpp
    ViveMediaDecoder.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

target_include_directories(${PROJECT_NAME} PUBLIC ${AVCODEC_INCLUDE_DIR} ${AVFORMAT_INCLUDE_DIR} ${AVUTIL_INCLUDE_DIR} ${AVDEVICE_INCLUDE_DIR} ${SWRESAMPLE_INCLUDE_DIR} ${SWRESAMPLE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${AVCODEC_LIBRARY} ${AVFORMAT_LIBRARY} ${AVUTIL_LIBRARY} ${AVDEVICE_LIBRARY} ${SWRESAMPLE_LIBRARY} ${SWSCALE_LIBRARY})

target_link_libraries(${PROJECT_NAME}_Test PRIVATE ${PROJECT_NAME})
