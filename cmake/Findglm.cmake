set(GLM_SEARCH_PATH ${DEPENDENCIES_PATH}/glm)

if(UNIX)
find_path(GLM_INCLUDE_PATH
	NAMES
		glm/glm.hpp
	HINTS
		${GLM_SEARCH_PATH}
	PATHS
		/usr/include/glm
)

find_library(GLM_LIBRARY
	NAMES
		glm.a libglm.a
	HINTS
		${GLM_SEARCH_PATH}/glm
	PATHS
		/usr/lib/glm
)
endif()

if(WIN32)
find_path(GLM_INCLUDE_PATH
	NAMES 
		glm/glm.hpp
	PATHS
		${GLM_SEARCH_PATH}
)

find_library(GLM_LIBRARY
	NAMES
		glm.lib  libglm.lib
	PATHS
		${GLM_SEARCH_PATH}/glm/Debug
		${GLM_SEARCH_PATH}/glm/x64
)
endif()

if(GLM_LIBRARY AND GLM_INCLUDE_PATH)
	message("Library 'GLM' found")
else()
	message("Error: library 'GLM' not found")
endif()

