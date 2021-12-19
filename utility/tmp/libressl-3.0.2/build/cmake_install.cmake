# Install script for directory: /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/pkgconfig")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/crypto/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/ssl/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/apps/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tls/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/include/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/man/cmake_install.cmake")
  include("/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
