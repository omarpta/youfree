#ifndef KEYWORDS_H_INCLUDED
#define KEYWORDS_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include "submodules/sglib/sglib.h"
#include <dmalloc.h>

//struct attribute {
//    char name[100];
//    struct attribute *next_ptr;
//};
struct keyword {
    char name[100];
    //struct attribute *attributes;
    struct keyword *next_ptr;
};

void load_keywords();
void unload_keywords();
#endif // KEYWORDS_H_INCLUDED
