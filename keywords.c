#include "keywords.h"




struct keyword *keywords;


void load_keywords() {
    keywords = NULL;
    //struct attribute *attribute = NULL;
    struct keyword* keyword = NULL;

    //stringvariable
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "stringvariable");
//    keyword->attributes = NULL;
//
//    attribute = malloc(sizeof(struct attribute));
//    strcpy(attribute->name, "value");
//    SGLIB_LIST_ADD(struct attribute, keyword->attributes, attribute, next_ptr);
//
//    attribute = malloc(sizeof(struct attribute));
//    strcpy(attribute->name, "variable");
//    SGLIB_LIST_ADD(struct attribute, keyword->attributes, attribute, next_ptr);

    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //integervariable
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "integervariable");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //function
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "function");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //mathematicaloperation
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "mathematicaloperation");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //callfunction
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "callfunction");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //inttostring
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "inttostring");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //display
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "display");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);

    //waitkey
    keyword = malloc(sizeof(struct keyword));
    strcpy(keyword->name, "waitkey");
    SGLIB_LIST_ADD(struct keyword, keywords, keyword, next_ptr);
}


void unload_keywords() {
    struct keyword *k;
    //struct attribute *a;
    SGLIB_LIST_MAP_ON_ELEMENTS(struct keyword, keywords, k, next_ptr, {
        //puts(k->name);
//        SGLIB_LIST_MAP_ON_ELEMENTS(struct attribute, k->attributes, a, next_ptr, {
//            printf("\t%s\n", a->name);
//            free(a);
//        });
        if (k != NULL)
        free(k);
    });
}
