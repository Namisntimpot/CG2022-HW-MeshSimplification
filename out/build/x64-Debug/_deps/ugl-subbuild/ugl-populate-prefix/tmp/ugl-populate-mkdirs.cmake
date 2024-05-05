# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix/tmp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix/src/ugl-populate-stamp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix/src"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix/src/ugl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-subbuild/ugl-populate-prefix/src/ugl-populate-stamp/${subDir}")
endforeach()
