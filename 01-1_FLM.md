## rx_cpp

1. rx_cpp scheduler, worker
1. schduler owns a timeline
 

`scheduler` owns a timeline that is exposed by the `now()` method. scheduler is also a factory for workers in that timeline. since a scheduler owns a timeline it is possible to build schedulers that time-travel. the virtual-scheduler is a base for the test-scheduler that uses this to make multi-second tests complete in ms.

`worker` owns a queue of pending schedulables for the timeline and has a lifetime. when the time for an schedulable is reached the schedulable is run. The queue maintains insertion order so that when N schedulables have the same target time they are run in the order that they were inserted into the queue. The worker guarantees that each schedulable completes before the next schedulable is started. when the worker's lifetime is unsubscribed all pending schedulables are discarded.

`schedulable` owns a function and has a worker and a lifetime. when the schedulable's lifetime is unsubscribed the schedulable function will not be called. the schedulable is passed to the function and allows the function to reschedule itself or schedule something else on the same worker.

The new concepts are coordination and coordinator. I added these to simplify operator implementations and to introduce pay-for-use in operator implementations. Specifically, in Rx.NET and RxJava, the operators use atomic operations and synchronization primitives to coordinate messages from multiple streams even when all the streams are on the same thread (like UI events). The identity_. . . coordinations in rxcpp are used by default and have no overhead. The syncronize_. . . and observe_on_. . . coordinations use mutex and queue-onto-a-worker respectively, to interleave multiple streams safely.

coordination is a factory for coordinators and has a scheduler.

coordinator has a worker, and is a factory for coordinated observables, subscribers and schedulable functions.

All the operators that take multiple streams or deal in time (even subscribe_on and observe_on) take a coordination parameter, not scheduler.

Here are some supplied functions that will produce a coordination using a particular scheduler.

identity_immediate()
identity_current_thread()
identity_same_worker(worker w)
serialize_event_loop()
serialize_new_thread()
serialize_same_worker(worker w)
observe_on_event_loop()
observe_on_new_thread()
There is no thread-pool scheduler yet. A thread-pool scheduler requires taking a dependency on a thread-pool implementation since I do not wish to write a thread-pool. My plan is to make a scheduler for the windows thread-pool and the apple thread-pool and the boost asio executor pool.. One question to answer is whether these platform specific constructs should live in the rxcpp repo or have platform specific repos.



---

## rmf_traffic


std::shared_ptr<rmf_traffic::agv::Graph> graph;
std::shared_ptr<rmf_traffic::agv::VehicleTraits> traits;


1. fleet->add_robot()
   rmf_traffic::agv::**compute_plan_starts**() 


1. update_state()
   * estimate_state()
   * estimate_path_traveling()
   * estimate_waypoint()


## rmf_traffic::agv::Graph 
which contains:
1. waypoints 
    * num_waypoints()
    * get_waypoints()
    * waypoint.get_location()
2. lanes 
    * num_lanes()
    * get_lanes()

與tuw相同，計算機器人在車道的位置，靠起點 or 終點比較近。
利用向量內積工具(dot)

如果在車道中間，則計算機器人位置離車道的距離。

```cpp
check_path_finish(_node, state, _travel_info)
estimate_path_traveling(_node, state, _travel_info)
```
The 2 API have the same interface.


## Assumptions
1. If we have a path_finish_callback, then the robot should be following a path.
2. When the stage path is empty, that means the robot believes it has arrived at its destination.
3. If we don't have a finishing callback, then the robot is not under out command.


### What's ArrivalEstimator?
1. It's from RobotCommandHandle.hpp

```cpp
// Use this callback function to update fleet adapter on how long 
// the robot will take to reach its next destination. 

// param[in] path_index
//   The index of the path element that the robot is currently heading towards. 

// param[in] remaining_time 
//   The index of the path element that the robot is currently heading towards. 

using ArrivalEstimator = std::function<void(std::size_t path_index, Duration remaining_time)>;
```

rmf_core
[Single pickup multiple dropoff workflow](https://github.com/osrf/rmf_core/issues/134)

---

### FAQ
Issue:
  eigen cannot have the rosdep key resolved 

ERROR: the following packages/stacks could not have their rosdep keys resolved
to system dependencies:
rmf_traffic: No definition of [eigen] for OS version []
rmf_fleet_adapter: No definition of [yaml-cpp] for OS version []
rmf_traffic_ros2: No definition of [eigen] for OS version []

Fix:
  $sudo apt-get install -y google-mock libboost-all-dev libeigen3-dev libgflags-dev libgoogle-glog-dev liblua5.2-dev libprotobuf-dev libsuitesparse-dev libwebp-dev ninja-build protobuf-compiler python-sphinx ros-eloquent-tf2-eigen
Ref:
  https://github.com/cartographer-project/cartographer/issues/1484

---


