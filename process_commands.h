#ifndef PROCESS_COMMANDS_H_INCLUDED
#define PROCESS_COMMANDS_H_INCLUDED

#include <libxml/tree.h>
#include <string.h>
#include "variable.h"
#include <dmalloc.h>


void process_commands(xmlNode * a_node, char *parent, struct variable **variables);

#endif // PROCESS_COMMANDS_H_INCLUDED
