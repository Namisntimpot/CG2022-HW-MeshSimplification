set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MeshSimplification.cpp
	${PROJECT_SOURCE_DIR}/data/shaders/p3n3.vert
	${PROJECT_SOURCE_DIR}/data/shaders/light.frag
)

set(eigenTargetName ${PROJECT_NAME}_Eigen)


Ubpa_GetTargetName(tool "${PROJECT_SOURCE_DIR}/src/tool")
Ubpa_AddTarget(MODE "EXE" SOURCES ${src} LIBS "Ubpa::UGL_core;glfw;${tool};${eigenTargetName}")
