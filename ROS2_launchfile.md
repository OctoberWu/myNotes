ROS2 launch file
TOC
- Create ROS2 launch file
- Install ROS2 launch file 
- Run ROS2 launch file

---
### Create ROS2 launch file

foxy & newer

```python
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            namespace='turtlesim1',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='turtlesim',
            namespace='turtlesim',
            executable='turtlesim_node',
            name='mimic',
            remappings=[
                ('/input/pose', '/turtlesim1/turtle1/pose'),
                ('/output/cmd_vel', '/turtlesim1/turtle1/cmd_vel'),
            ]
        )
    ])

# Another way
# 不同寫法(ld)，組織程式結構。 Make the application much more scalable
def generate_launch_description():
    ld = LaunchDescription()

    talker_node = Node(
        package="demo_nodes_cpp",
        executalbe="talker",
    )

    listener_node = Node(
        package="demo_nodes_py",
        executalbe="listener",
    )

    ld.add_action(talker_node)
    ld.add_action(listener_node)

    return ld
```

Command line 寫法
```sh
$ros2 launch <package> <executable>
```

Recap:
Main points:
1. Two Common modules, 'launch' & 'launch_ros'
   * from launch import LaunchDescription
   * from launch_ros.actions import Node 
2. function name convention
   * generate_launch_description
   Launch file must contain function, **generate_launch_description()**, and must return a **LaunchDescription** object.
 
Customize points:
1. Rename node. 
2. parameters
3. Topic/Service remapping. 
``` py 
# launch file
talker_node = Node(
    package="demo",
    executable="talker",
    name="my_talker",
    parameters=[
        {"background_color": 'blue'}
    ],
    remappings=[
        ("chatter", "my_chatter")
    ]
)
```

Note:

---
### Install the ROS2 launch file
* Add (pakcages) dependencies
```xml
<!--package.xml-->
...
  <exec_depend>demo_nodes_cpp<exec_depend>
  <exec_depend>demo_nodes_py<exec_depend>
...
```

* Install from a cpp packages
```txt
#CMakeList.txt
...
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)
...
```

