#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
// <GL/gl.h>
#define GL_VENDOR                              0x1F00
int main(int argc, char** argv)
{
    void *handle;
    char* (*func_glGetString)(int);

//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s animal_type\n", argv[0]);
//         return EXIT_FAILURE;
//     }
#ifdef _WIN32
    handle = dlopen("opengl32.dll", RTLD_LAZY);
#else
    handle = dlopen("libOpenGL.so", RTLD_LAZY); 
#endif
    if (!handle) {
        /* fail to load the library */
        fprintf(stderr, "Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    *(void**)(&func_glGetString) = dlsym(handle, "glGetString");
    if (!func_glGetString) {
        /* no such symbol */
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return EXIT_FAILURE;
    }

    char * gl_str = func_glGetString(GL_VENDOR);
    if (!gl_str)
    {
      fprintf(stderr, "Error: glGetString returned NULL\n");
      return EXIT_FAILURE;
    }
      printf("%s\n", gl_str);
    dlclose(handle);

    return EXIT_SUCCESS;
}
