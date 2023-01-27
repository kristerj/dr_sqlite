#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

void print_name(const char* type);

int main(int argc, char** argv)
{
    void *handle;
    void *handle2;
    void (*func_print_name)(const char*);


    handle = dlopen("./sqlite3.so", RTLD_LAZY);
    handle2 = dlopen("./ext_libsqlite3.so", RTLD_LAZY);
    if (!handle || !handle2) {
        /* fail to load the library */
        fprintf(stderr, "Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }
    dlclose(handle);
    dlclose(handle2);

    return EXIT_SUCCESS;
}
