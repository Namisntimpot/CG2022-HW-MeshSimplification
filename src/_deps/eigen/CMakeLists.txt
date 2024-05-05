
message(STATUS "Eigen: ${CMAKE_CURRENT_SOURCE_DIR}")


set(eigenTargetName ${PROJECT_NAME}_Eigen)
Ubpa_PackageName(package_name)
message(STATUS "----------")
	message(STATUS "- name: ${eigenTargetName}")
	message(STATUS "- folder : ${PROJECT_NAME}/src/_deps/eigen")

add_library(${eigenTargetName} INTERFACE)
message(STATUS ">>>> ${PROJECT_SOURCE_DIR}/src/_deps/eigen  ${package_name}/{package_name}/eigen")
target_include_directories(${eigenTargetName} INTERFACE
        $<BUILD_INTERFACE: ${PROJECT_SOURCE_DIR}/src/_deps/eigen>
        $<INSTALL_INTERFACE: ${package_name}/{package_name}/eigen>
      )

