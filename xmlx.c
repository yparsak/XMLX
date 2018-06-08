#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

char *xml_getNodeName(xmlNode *node)
{
    if (node == NULL) return("");
    return( (char *) node->name );
}

char *xml_getNodeContent(xmlNode *node)
{
    if ((node == NULL) || (node->children == NULL)) { return(""); }
    
    if ((node->children->type = XML_TEXT_NODE) && (node->children->content)) {
        return((char *)xmlEncodeEntitiesReentrant(node->doc, node->children->content));
    }
    return("");
}

int xml_isTextNode(xmlNode *node)
{
    if ((node == NULL) || (node->children == NULL)) { return(0); }
 
    if (node->children->type == XML_TEXT_NODE) {
       return(1);
    }
    return(0);
}

xmlAttr *xml_getAttrList(xmlNode *node) {
    return(node->properties);
}

int xml_countAttr(xmlNode *node) {
    xmlAttr *cur_attr = NULL;
    int count = 0;
    for (cur_attr = node->properties; cur_attr; cur_attr = cur_attr->next) {
      count++;
    }
    return(count);
}

/*
    xmlNodePtr	    xmlAddChild                (xmlNodePtr parent, xmlNodePtr cur)
    xmlNodePtr	    xmlAddNextSibling          (xmlNodePtr cur, xmlNodePtr elem)
    xmlNodePtr	    xmlAddPrevSibling          (xmlNodePtr cur, xmlNodePtr elem)
    xmlNodePtr      xmlAddSibling              (xmlNodePtr cur, xmlNodePtr elem)
    xmlBufferPtr    xmlBufferCreate            (void)
    xmlChar *       xmlBufContent              (const xmlBuf * buf)
    void            xmlBufferFree              (xmlBufferPtr buf)
    unsigned long   xmlChildElementCount       (xmlNodePtr parent)
    xmlDocPtr       xmlCopyDoc                 (xmlDocPtr doc, int recursive)
    xmlNodePtr      xmlCopyNode                (xmlNodePtr node, int extended)
    int	            xmlDocDump                 (FILE * f, xmlDocPtr cur)
    xmlNodePtr      xmlDocGetRootElement       (const xmlDoc * doc)
    xmlNodePtr      xmlDocSetRootElement       (xmlDocPtr doc, xmlNodePtr root)
    xmlNodePtr      xmlFirstElementChild       (xmlNodePtr parent)
    void            xmlFreeDoc                 (xmlDocPtr cur)
    void            xmlFreeNode                (xmlNodePtr cur)
    void            xmlFreeProp                (xmlAttrPtr cur)
    xmlNodePtr	    xmlPreviousElementSibling  (xmlNodePtr node)
    xmlNodePtr      xmlNextElementSibling      (xmlNodePtr node)
    xmlNodePtr      xmlGetLastChild            (const xmlNode * parent)
    xmlNodePtr      xmlLastElementChild        (xmlNodePtr parent)
    xmlChar *       xmlGetNodePath             (const xmlNode * node)
    xmlChar *       xmlGetProp                 (const xmlNode * node, const xmlChar * name)
    xmlAttrPtr      xmlHasProp                 (const xmlNode * node, const xmlChar * name)
    int             xmlIsBlankNode             (const xmlNode * node)
    xmlNodePtr      xmlNewChild                (xmlNodePtr parent, xmlNsPtr ns, const xmlChar * name, const xmlChar * content)
    xmlNodePtr      xmlNewComment              (const xmlChar * content)
    xmlDocPtr       xmlNewDoc                  (const xmlChar * version)
    xmlNodePtr      xmlNewDocComment           (xmlDocPtr doc, const xmlChar * content)
    xmlAttrPtr      xmlNewProp                 (xmlNodePtr node, const xmlChar * name, const xmlChar * value)
    xmlNodePtr      xmlNewText                 (const xmlChar * content)
    void            xmlNodeAddContent          (xmlNodePtr cur, const xmlChar * content)
    void            xmlNodeSetContent          (xmlNodePtr cur, const xmlChar * content)
    int             xmlNodeDump                (xmlBufferPtr buf, xmlDocPtr doc, xmlNodePtr cur, int level, int format)
    xmlChar *	    xmlNodeGetContent          (const xmlNode * cur)
    int	            xmlNodeIsText              (const xmlNode * node)
    void            xmlNodeSetName             (xmlNodePtr cur, const xmlChar * name)
    int             xmlRemoveProp              (xmlAttrPtr cur)
    xmlNodePtr      xmlReplaceNode             (xmlNodePtr old, xmlNodePtr cur)
    int             xmlSaveFile                (const char * filename, xmlDocPtr cur)
    xmlAttrPtr      xmlSetProp                 (xmlNodePtr node, const xmlChar * name, const xmlChar * value)
    int             xmlTextConcat              (xmlNodePtr node, const xmlChar * content, int len)
    void            xmlUnlinkNode              (xmlNodePtr cur)
    int             xmlUnsetProp               (xmlNodePtr node, const xmlChar * name)
*/


