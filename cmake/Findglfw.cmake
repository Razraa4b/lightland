set(GLFW_SEARCH_PATH ${DEPENDENCIES_PATH}/glfw)

if(UNIX)
find_path(GLFW_INCLUDE_PATH
	NAMES
		GLFW/glfw3.h
	HINTS
		${GLFW_SEARCH_PATH}/include
	PATHS
		/usr/include/glfw  /usr/include/GLFW
		/usr/include/glfw3 /usr/include/GLFW3
)

find_library(GLFW_LIBRARY
	NAMES
		glfw.a  libglfw.a
		glfw3.a libglfw3.a
	PATHS
		${GLFW_SEARCH_PATH}/src
)
endif()

if(WIN32)
find_path(GLFW_INCLUDE_PATH
	NAMES 
		GLFW/glfw3.h
	HINTS
		${GLFW_SEARCH_PATH}/include
)

find_library(GLFW_LIBRARY
	NAMES
		glfw.lib  libglfw.lib
		glfw3.lib libglfw3.lib
	HINTS
		${GLFW_SEARCH_PATH}/src/Debug
		${GLFW_SEARCH_PATH}/src/x64
)
endif()


if(GLFW_LIBRARY AND GLFW_INCLUDE_PATH)
	message("Library 'GLFW' found")
else()
	message("Error: library 'GLFW' not found")
endif()

