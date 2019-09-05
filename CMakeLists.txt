cmake_minimum_required (VERSION 3.0.0)
 
project (Test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if (MSVC OR MSYS OR MINGW)
    if(NOT "${CMAKE_GENERATOR}" MATCHES "(Win64|IA64)")
        set(ARCH "x86")
    else()
        set(ARCH "x64")
    endif()

    set(DEP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs")
    set(DEP_LIB_DIR  "${DEP_INCLUDE_DIR}/SDL2/lib/${ARCH}")
   
    set(SDL2_INCLUDE_DIRS "${DEP_INCLUDE_DIR}/SDL2/include")
    set(SDL2_LIBRARIES "${DEP_LIB_DIR}/sdl2.lib" "${DEP_LIB_DIR}/sdl2main.lib")
else()
    find_package(SDL2 REQUIRED)
endif()


include_directories(${SDL2_INCLUDE_DIRS})
include_directories("${PROJECT_BINARY_DIR}/")
link_directories($"SDL2_LIB_DIR")

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})
 
file(
    GLOB_RECURSE
    MY_SOURCE_FILES
    src/*
) 

add_executable (${PROJECT_NAME} ${MY_SOURCE_FILES})
target_link_libraries(Test ${SDL2_LIBRARIES})
