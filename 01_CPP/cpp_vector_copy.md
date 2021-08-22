
### [convert string to float]
```cpp
#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char** argv)
{
	std::string text = "199102.92";
	float v = std::stof(text);
	std::cout << std::setprecision(2) << std::fixed << v << std::endl;
}
```

### [split string by semicolon]
```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
main() {
   string my_str = "1.0;2.0;3.0";
   vector<string> result;
   stringstream s_stream(my_str); //create string stream from the string
   while(s_stream.good()) {
      string substr;
      getline(s_stream, substr, ';'); //get first string delimited by comma
      result.push_back(substr);
   }
   for(int i = 0; i<result.size(); i++) {    //print all splitted strings
      cout << result.at(i) << endl;
   }
}
```


## [libxml2 backup]
```cpp
  // --- Read the goal from BT task ---
  const char* bt_task = msg->bt_xml.c_str();
  int len = strlen(bt_task);
  xmlDocPtr doc = xmlParseMemory(bt_task, len);
  xmlNodePtr curNode;

  if (doc == NULL)
  {
    std::cout << "Document not parsed successfully!" << std::endl;
    return;
  }

  curNode = xmlDocGetRootElement(doc);
  if (curNode == NULL)
  {
    std::cout << "empty document.\n" << std::endl;
    xmlFreeDoc(doc);
    return;
  }
  // cout<<"xmlDocGetRootElement OK.\n"<<endl;

  if (xmlStrcmp(curNode->name, BAD_CAST "root"))
  {
    std::cerr << "root node is not 'root'" << std::endl;
    xmlFreeDoc(doc);
    return;
  }

  curNode = curNode->xmlChildrenNode;
  xmlNodePtr propNodePtr = curNode;
  xmlChar* szKey;
  bool foundGoal = false;
  while (NULL != curNode)
  {
    if ((!xmlStrcmp(curNode->name, (const xmlChar*)"Nav2Client")))
    {
      szKey = xmlNodeGetContent(curNode);
      std::cout << "Nav2Client: " << szKey << std::endl;
      xmlFree(szKey);
      // get attributes
      szKey = xmlGetProp(curNode, (const xmlChar*)"goal");
      std::cout << "Nav2Client->goal: " << szKey << std::endl;
      xmlFree(szKey);
      foundGoal = true;
      break;
    }
    curNode = curNode->next;
  }
```



## [libxml2 for cpp]

```cpp
#include <libxml/parser.h>
#include <string>

xmlDocPtr doc;
// Read XML from file
doc = xmlParseFile(xmlConfig);

// Read XML from file
int len = strlen(xmlConfig);
doc = xmlParseMemory(xmlConfig, len)
```
```cmake
include_directories(${LIBXML2_INCLUDE_DIRS})
link_libraries(${LIBXML2_LIBRARY})
add_executable(xml_parser xml_parser.cpp)
target_link_libraries(xml_parser xml2)
ament_target_dependencies(xml_parser rclcpp std_msgs far_task_msgs far_fleet_msgs
```


---

### [string to char] convert from 'std::string' to 'const char*'
```cpp
std::string filename;
const char* xmlConfig = filename.c_str();
```
---

### [arguments in main function]
```cpp
int main(int argc, char* argc)
{
}

```
```sh
$ros2 run env_builder xml_parser test
argv[0]: /home/ros/far_flm_ws/install/env_builder/lib/env_builder/xml_parser
argv[1]: test
```
---

### [raw string format]
```cpp
const char* rawStr = R"(hello /n world)";
```

我想釐清的問題：
vector assignment 複製時是怎樣的行為

考慮幾個情況
1. 
vector<int> vec0;
vector<int> vec1 = vec0;
這是同一個物件嘛？還是不同物件？
A: 不同物件

2. function argument
void myFunc(vector<int>& _vec) {
	vector<int> _vec = _vec;
}
A:創建新物件，為不同物件

3. member function in class
A:創建新物件，為不同物件

4. Primitive type vs. Object type

