if(NOT ${TEST_QT})
	return()
endif()

Ubpa_AddTarget(MODE "EXE" QT ON LIBS "Qt5::Widgets" TEST ON)
