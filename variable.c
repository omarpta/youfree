#include "variable.h"


void init_variable(const xmlNode *node, struct variable **variables, VARIABLE_TYPES type) {
    unsigned char *value = xmlGetProp(node, (const xmlChar*) "value");
    unsigned char *variable = xmlGetProp(node, (const xmlChar*) "variable");
    assert(value != NULL);
    assert(variable != NULL);
    const char *val = (const char*)value;

    struct variable *v = malloc(sizeof(struct variable));
    switch (type) {
        case INTEGER:
            v->intValue = atoi(val);
            break;
        case STRING:
            v->stringValue = malloc((strlen(val) + 1) *sizeof(char));
            strcpy(v->stringValue, val);
        break;
        default:
            break;
    }

    strcpy(v->name, (const char*)variable);

    SGLIB_LIST_ADD(struct variable, *variables, v, next_ptr);
}



void free_variables(struct variable **variables) {
    struct variable *v = NULL;
    SGLIB_LIST_MAP_ON_ELEMENTS(struct variable, *variables, v, next_ptr, {
        printf("Deleting: %s\n", v->name);
        if (v->type == STRING) {
            free(v->stringValue);
        }
        free(v);
    });
}
