Ubpa_GlobGroupSrcs(RST sources PATHS
	${CMAKE_CURRENT_SOURCE_DIR}
	"${PROJECT_SOURCE_DIR}/include"
)

Ubpa_AddTarget(MODE "EXE" TEST ON SOURCES ${sources})
