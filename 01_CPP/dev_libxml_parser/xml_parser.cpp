#include "far_amr_mock.hpp"

#include <libxml/parser.h>
#include <iostream>
#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;
using namespace std;

// const char* xmlConfig = "create.xml";

int main(int argc, char* argv[])
// int main()
{
  xmlDocPtr doc;
  xmlNodePtr curNode;
  xmlChar* szKey;

  const char* xmlConfig = R"(<root>
              <IP> 192.168.1.116 </IP> <Port> 65535 </Port> <num> 1000 </num>
              <node2 attribute = "yes"> NODE CONTENT</node2><son><grandson> This is a grandson node</grandson></son>
              </root>)";

  // doc = xmlParseFile(xmlConfig);
  int len = strlen(xmlConfig);
  doc = xmlParseMemory(xmlConfig, len);
  if (doc == NULL)
  {
    cout << "Document not parsed successfully!" << endl;
    return -1;
  }

  curNode = xmlDocGetRootElement(doc);
  if (curNode == NULL)
  {
    cout << "empty document.\n" << endl;
    xmlFreeDoc(doc);
    return -1;
  }
  // cout<<"xmlDocGetRootElement OK.\n"<<endl;

  if (xmlStrcmp(curNode->name, BAD_CAST "root"))
  {
    cerr << "root node is not 'root'" << endl;
    xmlFreeDoc(doc);
    return -1;
  }

  curNode = curNode->xmlChildrenNode;
  xmlNodePtr propNodePtr = curNode;
  while (NULL != curNode)
  {
    if ((!xmlStrcmp(curNode->name, (const xmlChar*)"Nav2Client")))
    {
      szKey = xmlNodeGetContent(curNode);
      cout << "IP:" << szKey << endl;
      // string s((char*)szKey);
      xmlFree(szKey);
      // cout<<s<<endl;
    }
    else if ((!xmlStrcmp(curNode->name, (const xmlChar*)"node2")))
    {
      szKey = xmlNodeGetContent(curNode);
      cout << "node2:" << szKey << endl;
      xmlFree(szKey);
      // get attributes
      szKey = xmlGetProp(curNode, (const xmlChar*)"attribute");
      cout << "node2->attribute:" << szKey << endl;
      xmlFree(szKey);
    }

    curNode = curNode->next;
  }

  return 0;
}
