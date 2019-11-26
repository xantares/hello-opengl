

cmake_minimum_required (VERSION 2.8.12)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type")

if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()

if(POLICY CMP0028)
  cmake_policy(SET CMP0028 NEW)
endif()

if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()

project (hello)

find_package(OpenGL REQUIRED)
find_package(GLUT)
find_package(SDL2)
#find_package(glfw3)

if (GLUT_FOUND)
  add_executable (gears gears.c)
  target_link_libraries(gears ${OPENGL_opengl_LIBRARY} ${OPENGL_gl_LIBRARY} ${GLUT_glut_LIBRARY})

  if (UNIX)
    target_link_libraries(gears m)
  endif ()

  install (TARGETS gears DESTINATION bin)
endif ()
# 
# find_library(LIBDL_LIBRARY NAMES dl)
# add_executable (dlopen_opengl dlopen_opengl.c)
# target_link_libraries(dlopen_opengl ${LIBDL_LIBRARY})

if (SDL2_FOUND)
  add_executable (gears_sdl gears_sdl.c)
  if (MINGW)
    target_link_libraries(gears_sdl mingw32)
  endif ()
  target_link_libraries(gears_sdl SDL2main SDL2 ${OPENGL_opengl_LIBRARY} ${OPENGL_gl_LIBRARY})

  if (UNIX)
    target_link_libraries(gears_sdl m)
  endif ()

  install (TARGETS gears_sdl DESTINATION bin)
endif ()

# if (glfw3_FOUND)
# 
#   add_executable (square_glfw square_glfw.c)
#   target_link_libraries(square_glfw glfw ${OPENGL_opengl_LIBRARY} ${OPENGL_gl_LIBRARY})
# endif ()


find_package(Qt5Gui NO_MODULE)
find_package (Qt5Widgets NO_MODULE)
if (Qt5Gui_FOUND)
  add_executable (gl2_qt gl2_qt.cxx)
  target_link_libraries(gl2_qt ${OPENGL_opengl_LIBRARY} ${OPENGL_gl_LIBRARY} ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES})
  target_include_directories (gl2_qt PRIVATE ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Test_INCLUDE_DIRS})
endif ()
