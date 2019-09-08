cmake_minimum_required (VERSION 3.0.0)
 
project (Test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if (MSVC OR MSYS OR MINGW)
    if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
        set(ARCH "x86")
    else()
        set(ARCH "x64")
    endif()


    if (!MINGW)
        set(DEP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs")

        set(DEP_LIB_DIR  "${DEP_INCLUDE_DIR}/SDL2/vc/lib/${ARCH}")
        set(SDL2_INCLUDE_DIRS "${DEP_INCLUDE_DIR}/SDL2/vc/include")
        set(SDL2_LIBRARIES "${DEP_LIB_DIR}/SDL2.lib" "${DEP_LIB_DIR}/sdl2main.lib")
        set(SDL2_DLL_PATH "${DEP_LIB_DIR}/SDL2.dll")

        ADD_DEFINITIONS("-DIS_WINDOWS=1")
    else()
        set(DEP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs")

        set(DEP_LIB_DIR  "${DEP_INCLUDE_DIR}/SDL2/mingw/lib")
        set(SDL2_INCLUDE_DIRS "${DEP_INCLUDE_DIR}/SDL2/mingw/include/SDL2")
        set(SDL2_LIBRARIES "${DEP_LIB_DIR}/libSDL2.dll.a" "${DEP_LIB_DIR}/libSDL2main.a")
        set(SDL2_DLL_PATH "${DEP_INCLUDE_DIR}/SDL2/mingw/bin/SDL2.dll")

        ADD_DEFINITIONS("-DIS_WINDOWS=0")
    endif()
else()
    find_package(SDL2 REQUIRED)
endif()

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})
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
target_link_libraries(Test ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES})

add_custom_command(TARGET Test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SDL2_DLL_PATH} $<TARGET_FILE_DIR:Test>)

