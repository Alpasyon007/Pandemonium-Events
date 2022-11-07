set_target_properties(PandemoniumEvents PROPERTIES LINKER_LANGUAGE CXX)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
	PandemoniumEvents
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/headers/Event.h
	${CMAKE_CURRENT_SOURCE_DIR}/headers/KeyEvent.h
)

target_include_directories(
	PandemoniumEvents
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/headers
	${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Core/headers
)