set(GLAD_SEARCH_PATH ${DEPENDENCIES_PATH}/glad)

if(UNIX)
find_path(GLAD_INCLUDE_PATH
	NAMES
		glad/glad.h
	HINTS
		${GLAD_SEARCH_PATH}/include
	PATHS
		/usr/include/glad
)

find_library(GLAD_LIBRARY 
	NAMES
		glad.a libglad.a
	HINTS
		${GLAD_SEARCH_PATH}/build
	PATHS
		/usr/lib/glad
)
endif()

if(WIN32)
find_path(GLAD_INCLUDE_PATH
	NAMES 
		glad/glad.h
	PATHS
		${GLAD_SEARCH_PATH}/include
)

find_library(GLAD_LIBRARY 
	NAMES
		glad.lib  libglad.lib
	HINTS
		${GLAD_SEARCH_PATH}/build/Debug
		${GLAD_SEARCH_PATH}/build/Release
		${GLAD_SEARCH_PATH}/build/x64
)
endif()

if(GLAD_LIBRARY AND GLAD_INCLUDE_PATH)
	message("Library 'GLAD' found")
else()
	message("Error: library 'GLAD' not found")
endif()

