// DllTest.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DllTest.h"

#include <random>

str
DLLTEST_API
animalGetName(void)
{
    static const str names[] = {
        "cat",
        "dog",
        "fish",
        "bird"
    };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);
    int index = dist(gen);
    return names[index];
}
