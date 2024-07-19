#include "AddLibInterface.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

AddLibInterface* loadPlugin(const char* libraryName)
{
#ifdef _WIN32
    HMODULE library = LoadLibraryA(libraryName);
    if (!library)
        return nullptr;
    typedef AddLibInterface* (*CreateInstanceFunc)();
    CreateInstanceFunc createInstance = (CreateInstanceFunc)GetProcAddress(library, "CreateMyClassInstance");
#else
    void* library = dlopen(libraryName, RTLD_LAZY);
    if (!library) return nullptr;
    typedef MyInterface* (*CreateInstanceFunc)();
    CreateInstanceFunc createInstance = (CreateInstanceFunc)dlsym(library, "CreateMyClassInstance");
#endif
    if (!createInstance) return nullptr;
    return createInstance();
}

int main(int argc, char *argv[])
{
    AddLibInterface* instance = loadPlugin("E:\\GitHub\\CMakeTest\\x64\\Release\\AddLib\\AddLib");
    if (instance)
    {
        instance->InitData();
        instance->Start();
    }

    while(1){};
    return 0;
}
