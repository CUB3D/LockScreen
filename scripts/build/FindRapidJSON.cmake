# Locate rapidjson library
# This module defines
# RAPIDJSON_FOUND, if false, do not try to include Rapidjson
# RAPIDJSON_INCLUDE_DIR, where to find rapidjson.h

SET(RAPIDJSON_SEARCH_PATHS
		/usr/
)

FIND_PATH(RAPIDJSON_INCLUDE_DIR rapidjson.h
	HINTS
	PATH_SUFFIXES include/rapidjson include
	PATHS ${RAPIDJSON_SEARCH_PATHS}
)

set(RAPIDJSON_FOUND true)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(RAPIDJSON REQUIRED_VARS RAPIDJSON_INCLUDE_DIR)
