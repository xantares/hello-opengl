

cmake_minimum_required (VERSION 2.8.12)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type")

if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()

project (hello C)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable (gears gears.c)
target_link_libraries(gears ${OPENGL_opengl_LIBRARY} ${OPENGL_gl_LIBRARY} ${GLUT_glut_LIBRARY})

if (UNIX)
  target_link_libraries(gears m)
endif ()

install (TARGETS gears DESTINATION bin)
# 
# find_library(LIBDL_LIBRARY NAMES dl)
# add_executable (dlopen_opengl dlopen_opengl.c)
# target_link_libraries(dlopen_opengl ${LIBDL_LIBRARY})
