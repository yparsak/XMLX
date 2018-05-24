#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

char *xml_getNodeName(xmlNode * a_node)
{
    if (NULL == a_node) return("");
    return((char *)a_node->name);
}



