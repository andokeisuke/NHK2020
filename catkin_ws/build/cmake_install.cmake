# Install script for directory: /home/ando/catkin_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ando/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "”Release”")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE PROGRAM FILES "/home/ando/catkin_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE PROGRAM FILES "/home/ando/catkin_ws/build/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/setup.bash;/home/ando/catkin_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE FILE FILES
    "/home/ando/catkin_ws/build/catkin_generated/installspace/setup.bash"
    "/home/ando/catkin_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/setup.sh;/home/ando/catkin_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE FILE FILES
    "/home/ando/catkin_ws/build/catkin_generated/installspace/setup.sh"
    "/home/ando/catkin_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/setup.zsh;/home/ando/catkin_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE FILE FILES
    "/home/ando/catkin_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/ando/catkin_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ando/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ando/catkin_ws/install" TYPE FILE FILES "/home/ando/catkin_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ando/catkin_ws/build/gtest/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter11/chapter11/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter12/chapter12/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter13/chapter13/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/chapter6/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter7/chapter7/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter8/chapter8/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter9/chapter9/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter9/fourth_robot_2dnav/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/fourth_robot_control/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/fourth_robot_description/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/fourth_robot_gazebo/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/iai_kinect2/iai_kinect2/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter9/joy_control/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/my_robo/my_robo_description/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_arduino/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_mbed/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_msgs/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_python/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_tivac/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_vex_cortex/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_vex_v5/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_xbee/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_client/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/gazebo_ros_demos/rrbot_control/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/gazebo_ros_demos/rrbot_description/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/gazebo_ros_demos/rrbot_gazebo/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/sim/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/simarm/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/simc/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/urdf_example_robot/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter3/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter4/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/fusion2urdf/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/joy_twist/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter12/arrayutil_python/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter11/pluginlib_arrayutil/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter11/pluginlib_arrayutil_client/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/shagaiLaunch/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/tf_twist/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_server/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter5/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/joycon/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/iai_kinect2/kinect2_registration/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/teleop_twist_joy/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter7/test_opencv/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/gazebo_ros_demos/custom_plugin_tutorial/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/iai_kinect2/kinect2_bridge/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/iai_kinect2/kinect2_calibration/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/iai_kinect2/kinect2_viewer/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/my_odom3/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/odm/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter8/cloud_excercise/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_test/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosserial/rosserial_windows/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/rosbook_pkgs/chapter6/tf_tutorial/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/urg_test/cmake_install.cmake")
  include("/home/ando/catkin_ws/build/my_robo_2dav/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ando/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
