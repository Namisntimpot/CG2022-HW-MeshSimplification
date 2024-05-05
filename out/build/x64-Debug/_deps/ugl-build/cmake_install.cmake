# Install script for directory: C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugm-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/include/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/data/textures/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/data/textures/skybox/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/EMPTY/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/_deps/glad/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/00_UB_Packer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/1_hello/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/2_tri/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/3_shader/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/4_tex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/6_cs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/1/7_cam/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/4/5_fb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/4/6_cm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/src/test/LOGL/camera/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake/UGLTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake/UGLTargets.cmake"
         "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/CMakeFiles/Export/UGL_0_1_3/cmake/UGLTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake/UGLTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake/UGLTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake" TYPE FILE FILES "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/CMakeFiles/Export/UGL_0_1_3/cmake/UGLTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake" TYPE FILE FILES "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/CMakeFiles/Export/UGL_0_1_3/cmake/UGLTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UGL_0_1_3/cmake" TYPE FILE FILES
    "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/UGLConfig.cmake"
    "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build/UGLConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UGL_0_1_3" TYPE DIRECTORY FILES "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3/include")
endif()

