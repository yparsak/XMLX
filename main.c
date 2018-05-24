#include <stdio.h>
#include <libxml/parser.h>
#include "xmlx.h"

int main(void) {

    xmlNodePtr n;
    xmlDocPtr doc;
    xmlChar *xmlbuff;
    int buffersize;

    doc = xmlNewDoc(BAD_CAST "1.0");
    n = xmlNewNode(NULL, BAD_CAST "root");
    xmlNodeSetContent(n, BAD_CAST "content");
    xmlDocSetRootElement(doc, n);

    char *name = xml_getNodeName(n);
    puts(name);
  
    xmlDocDumpFormatMemory(doc, &xmlbuff, &buffersize, 1);
    printf("%s", (char *) xmlbuff);

    xmlFree(xmlbuff);
    xmlFreeDoc(doc);


  return(0);
}
