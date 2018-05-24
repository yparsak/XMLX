#ifndef xmlx_h__
#define xmlx_h__

  char *xml_getNodeName(xmlNode * a_node);
  xmlAttr *xml_getAttrList(xmlNode * parent_node);
  int xml_countAttr(xmlNode * parent_node);

#endif

