#include "main.h"


#define YOUFREE_SCRIPT "examples/simple.xml"
//TODO: In the future use posix threads mutex lock to access these variables
struct variable *variables = NULL;

int main(int argc, char **argv) {
#ifdef DMALLOC
    /*
    * Get environ variable DMALLOC_OPTIONS and pass the settings string
    * on to dmalloc_debug_setup to setup the dmalloc debugging flags.
    */
    printf("* DMALLOC enabled\n");
    dmalloc_debug_setup("debug=0x4f47d03,log=logfile");
#endif
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

#ifndef YOUFREE_SCRIPT
    if (argc != 2) {
        fprintf(stderr, "** You must provide a script path\n");
        return(1);
    }
#endif // YOUFREE_SCRIPT
    LIBXML_TEST_VERSION    // Macro to check API for match with
    // the DLL we are using

#ifdef YOUFREE_SCRIPT
    char *pxml_contents = read_file(YOUFREE_SCRIPT);
#else
    char *pxml_contents = read_file(argv[1]);
#endif // YOUFREE_SCRIPT
    char final_pxml[strlen(pxml_contents) + 20];
    strcpy(final_pxml, "");

    if (strstr(pxml_contents, "<youfree>") == NULL) {
        strcat(final_pxml, "<youfree>");
    }

    strcat(final_pxml, pxml_contents);

    if (strstr(pxml_contents, "</youfree>") == NULL) {
        strcat(final_pxml, "</youfree>");
    }

    free(pxml_contents);
    //puts(final_pxml);
    load_keywords();



    doc = xmlParseDoc((const unsigned char*)final_pxml);

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);
    process_commands(root_element, "", &variables);
    xmlFreeDoc(doc);       // free document
    xmlCleanupParser();    // Free globals

    unload_keywords();
    free_variables(&variables);

    return 0;
}
