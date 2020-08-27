#include "process_commands.h"



void process_commands(xmlNode * a_node, char *parent, struct variable **variables) {
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node =
                cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {

            if (strcmp((char*)cur_node->name, "youfree") != 0) {

                printf("Parent: %s name: %s\n", parent, cur_node->name);
                if (strcmp((char*)cur_node->name, "integervariable") == 0) {
                    init_variable(cur_node, variables, INTEGER);
                } else if (strcmp((char*)cur_node->name, "stringvariable") == 0) {
                    init_variable(cur_node, variables, STRING);
                }
                //create a function to load all functions before run another commands
                // because POSXML allows call a function before its declaration;
            }
            else {
                process_commands(cur_node->children, (char*)cur_node->name, variables);
            }
        }


    }
}


