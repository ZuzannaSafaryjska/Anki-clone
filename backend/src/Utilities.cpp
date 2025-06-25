/**
* @file Utilities.cpp
* @brief implementation of Utilities.
*/
#include "../inc/Utilities.h"

int id = 1;

namespace Utilities {
    int GenerateId() {
    return id++;
}
}

