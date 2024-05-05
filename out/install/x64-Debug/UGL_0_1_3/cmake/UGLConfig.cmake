message(STATUS "config UGL v0.1.3...")


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

####################################################################################


if(NOT ${FetchContent_FOUND})
	include(FetchContent)
endif()
if(NOT ${UCMake_FOUND})
	message(STATUS "find package: UCMake v0.4.1")
	find_package(UCMake 0.4.1 QUIET)
	if(NOT UCMake_FOUND)
		message(STATUS "searching _deps for UCMake v0.4.1")
			if(NOT EXISTS "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3/_deps/UCMake-0.4.1/CMakeLists.txt")
				message(FATAL_ERROR "UCMake v0.4.1 not found in _deps")
			endif()
			FetchContent_Declare(
			  UCMake
			  SOURCE_DIR "C:/Lijiaheng/RealTime_3D_Graphics/3_MeshSimplification/Project/_deps/UGL-0.1.3/_deps/UCMake-0.4.1"
			)
			FetchContent_MakeAvailable(UCMake)
			message(STATUS "UCMake v0.4.1 build done")
	endif()
endif()
Ubpa_AddDepPro(UGL UGM 0.4.1)
Ubpa_AddDepPro(UGL UDP 0.3.1)



include ( "${CMAKE_CURRENT_LIST_DIR}/UGLTargets.cmake" )

message(STATUS "config UGL v0.1.3 done")
