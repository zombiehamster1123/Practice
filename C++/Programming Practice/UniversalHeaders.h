#ifndef UNIVERSALHEADERS_H
#define UNIVERSALHEADERS_H

#include <iostream>
#include <ostream>
#include <string>
#define UINT unsigned int
#define TEMPLATED template <class T>
#define HASH_TEMPLATE template<class T, class N>
#define ReleaseMacro(x) { if(x && x != nullptr){ delete x; x = nullptr; } }

#endif