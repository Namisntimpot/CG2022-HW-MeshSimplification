# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# 设定项目
project(HW3_MeshSimplification VERSION 1.0)
message(STATUS "[Project] ${PROJECT_NAME}")

# 在 Debug 模式下自动对 dll 和 lib 文件名后边加 d，但 exe 仍然需要手动设置
set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 将生成的 exe, dll, lib 等放置在 bin, lib 目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/lib")

# 开启 VS 的文件夹功能
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)

set(UCMake_VERSION 0.4.1)
message(STATUS "find package: UCMake ${UCMake_VERSION}")
find_package(UCMake ${UCMake_VERSION} QUIET)
if(NOT UCMake_FOUND)
   message(STATUS "searching _deps for UCMake v${UCMake_VERSION}")
   if(NOT EXISTS "${CMAKE_SOURCE_DIR}/_deps/UCMake-${UCMake_VERSION}/CMakeLists.txt")
       message(FATAL_ERROR "UCMake v${UCMake_VERSION} not found in ${CMAKE_SOURCE_DIR}/_deps")
   endif()
   FetchContent_Declare(
       UCMake
       SOURCE_DIR "${CMAKE_SOURCE_DIR}/_deps/UCMake-${UCMake_VERSION}"
   )
   FetchContent_MakeAvailable(UCMake)
   message(STATUS "UCMake v${UCMake_VERSION} build done")
endif()

# 修改默认的安装路径前缀
Ubpa_InitInstallPrefix()

message(STATUS "----------")
find_package(glfw3 REQUIRED)
if(TARGET glfw)
	message(STATUS "glfw3_FOUND: ${glfw3_FOUND}")
	message(STATUS "glfw3_DIR: ${glfw3_DIR}")
endif()



Ubpa_AddDep(UGL 0.1.3)

Ubpa_AddSubDirsRec(src)
