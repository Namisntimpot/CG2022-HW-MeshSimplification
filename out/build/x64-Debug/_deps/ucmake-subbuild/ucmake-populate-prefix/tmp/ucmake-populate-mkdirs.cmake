# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UCMake-0.4.1"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-build"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/tmp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp/${subDir}")
endforeach()
