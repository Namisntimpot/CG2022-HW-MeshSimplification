# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UDP-0.3.1"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-build"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix/tmp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix/src/udp-populate-stamp"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix/src"
  "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix/src/udp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/udp-subbuild/udp-populate-prefix/src/udp-populate-stamp/${subDir}")
endforeach()
