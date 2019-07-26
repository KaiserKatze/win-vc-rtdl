// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

void end(HMODULE module)
{
    system("pause");
    if (module != NULL)
        FreeLibrary(module);
}

int main()
{
    HMODULE module = LoadLibraryA("DllTest.dll");
    if (module == NULL)
    {
        fprintf(stderr, "Failed to load library!\n");
        goto error;
    }
    else
    {
        printf("Successfully load library ...\n");
    }

    // Decorated Name
    str sProcName = "?animalGetName@@YGPBDXZ";
    ANIMALGETNAME animalGetName = (ANIMALGETNAME) GetProcAddress(module, sProcName);
    if (animalGetName == NULL)
    {
        fprintf(stderr, "Failed to locate function!\n");
        goto error;
    }
    else
    {
        printf("Successfully get proc address: %d ...\n", (int)animalGetName);
    }

    for (int i = 0; i < 10; i++)
    {
        str name = animalGetName();
        printf("Name: %s\n", name);
    }

    end(module);
    return 0;
error:
    end(module);
    return -1;
}