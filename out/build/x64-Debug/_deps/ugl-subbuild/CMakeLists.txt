# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.23.22060601-MSVC_2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(ugl-populate NONE)



include(ExternalProject)
ExternalProject_Add(ugl-populate
                     "UPDATE_DISCONNECTED" "False"
                    SOURCE_DIR          "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3"
                    BINARY_DIR          "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/out/build/x64-Debug/_deps/ugl-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


