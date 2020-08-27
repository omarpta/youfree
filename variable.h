#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED
#include <stdlib.h>
#include "submodules/sglib/sglib.h"
#include <libxml/tree.h>
#include <string.h>
#include <dmalloc.h>

typedef enum  {
    INTEGER,
    STRING,
    FLOAT,
    DOUBLE
} VARIABLE_TYPES;
struct variable {
    int intValue;
    char *stringValue;
    double doubleValue;
    float floatValue;

    char name[100];

    VARIABLE_TYPES type;
    struct variable* next_ptr;
};

void init_variable(const xmlNode *node, struct variable **variables, VARIABLE_TYPES type);

void free_variables(struct variable **variables);
#endif // VARIABLE_H_INCLUDED
