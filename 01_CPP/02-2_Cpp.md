
### struct constructor shorthand

### Ref Websites:
* Heresy's Space
* Dr. doob

### Rx cpp of Rx (Reaction Programming)
* Keywords:
  * Observer pattern 
  * Iterator patter 
  * functional programming 


#### std::function
* Similar to function pointer in C

##### enable_shared_from_this
* Fix the situation. that shared_ptr plans to shared the objects as an argument.

##### shared_ptr (ordinary pointer)
* which implements a reference-counted smart ponter.
[lifetime of objects]
* shared_ptr<Ty> can be much simler than similar code that uses ordinary pointes because the controlled resource will be released when the last of those objects is destroyed, without any explicit bookkeeping in the app. The code is also more **robust** 
* using **shared_ptr** objects correctly guarantees that a resource will be released when it is no longer needed, but not before.
* the rigid control of the life time of a resource is usually just eaht's needed.

#### weak_ptr
* a pointer that doesn't affect the lifetime of the resource it points to.
* ordinary one can do this, but not safely.
* Sometimes, an app nees a pointer that doesn't affect the liftime of the resource it points to.

* C++ Technical Report 1(TR1). 內容提出對C++標準函式庫的追加項目
* pointers are defined in <memory>

#### About Cpp pointer
1. weak pointer: 生命週期與實體不連動
1. shared pointer: 生命週期與實體不連動
```CMakeList.txt
add_libraray(STATIC): 產生static lib(*.a)
add_libraray(SHARED): 產生share object(*.so)
```


#### How to tranverse a standard `priority_queue` in c++ wiht an iterator
A: `priority_queue` doesn't allow iteration through all the members.


#### C++ compile-error message `dicards qulifiers [-fpermissive]` 
Condition 1:
A: only can access the const member function of oject.
A: Member function with `const` modifier, can not access non-const member function.
A: `... dicards qualifiers` means that lacks 限定符


#### unordered_map emplace() in C++ STL
1. effectively increased the container size by one.
2. If the same key is emplaced more than once, the map sotres the 1st element only as the map is a container.
3. Difference from unordered_map insert()
   * The advantage of emplace is, it does in-place insertion and avoids an unneccary copy of object. For primitive data types, it does not matter which one we use


#### Copy, Move, or Construct
1. insert() or push_back() are either copy or move data object
2. emplace() constrcut directly to the container memory
3. emplace(obj) just invoke the copy constructor, somewhat the benefit of emplace() is defeated. 


### bind (callback function)

bind is a function wrapper
```cpp
// phase 1
int add(int x, int y) {
    return x+y;    
}

// phase2
int add12(){
    return 1+2;
}

// phase3
auto add12 = bind(add, 1, 2);
cout << add12() << endl; // print3
```

So here comes the problem: How to wrapper the arguments?
=> the placeholder!

```c++
// new design
auto add2 = bind(add, placehoders::_1, 2);
cout << add2(6) << endl; // print 8

auto add_second_third_arg = bind(add, placeholders::_3, placeholders::_2);
cout << add_seconde_third_arg(6, 4, 3) << endl; // print 7
```

---

### Priority queue

[ref GeeksforGeeks](https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/)

### STL Priority Queue for Structure or Class
1. STL priority_queue is the implementation fo Heap Data-structure

```cpp
#include <queue>

using namespace std;

struct Persion{
    int age;
    float height;

    Person(int age, float height)
        :age(age), height(height)
    {}
};

struct CompareHeight{
    bool operator()(Person const& p1, Person const& p2)
    {
        // return "true" if "p1" is ordered before "p2"
        return p1.height < p2.height;
    }
}

priority_queue<Person> pq;


int main()
{
    priority_queue<Person, vector<Persion>, CompareHeight> Q;

    Person p = Q.top(); // no Q.front();
    Q.pop();

}

```


---

##### unordered_map
Q: Update element value in unordered_map 
A: DON'T NEED! The value with same key will be overwritten.
if needed:
ex.
```cpp
  std::unordered_map<std::string,double>::const_iterator got = mymap.find (input);

  if ( got == mymap.end() )
    std::cout << "not found";
  else
    std::cout << got->first << " is " << got->second;

  std::cout << std::endl;
```

Q: Insert elements in unordered_map
A: 
<unordered_map>.emplace(key, value);
<unordered_map>.insert({key, value});
ex.
```cpp
// unordered_map::emplace
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  mymap.emplace("NCC-1701", "J.T. Kirk");
  mymap.emplace("NCC-1702", "J.L. Pica");
  mymap.emplace("NCC-1703", "J.K. Jane");

  std::cout << "mymap contains:" << std::endl;
  for (auto& x: mymap)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}
```

Q: Size of unordered_map
A: <unordered_map>.size();


#### Type Conversion
Q: Convert int to string by C++11 
A:
```cpp
#include <string> 

std::string s = std::to_string(42);
is therefore the shortest way I can think of. You can even omit naming the type, using the auto keyword:

auto s = std::to_string(42);
```

Sorting:
```cpp
// For Vector 
std::sort(this->begin(), this->end(), myCompare);
// For List
this->sort(myCompare);
```


```cpp
// --- Task Update (TaskSummary) ---
 for (Task& it : task_manager_)
 {
   if (it.task_id != msg->task_id)
     continue;

   it.robot_name = msg->duty_robot;
   it.state = msg->state;
 }
```


Q: list duplicate element doubts.
how to make sure the customized object would nont duplicated in list container.