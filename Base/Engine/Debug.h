#pragma once

#include <iostream>

#ifdef _DEBUG

#define DEBUG(T,X) std::cerr << T << " | " << X << std::endl;

#else

#define DEBUG(T,X)

#endif