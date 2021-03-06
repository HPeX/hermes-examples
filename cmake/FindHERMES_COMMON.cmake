INCLUDE(FindPackageHandleStandardArgs)
FIND_LIBRARY(HERMES_COMMON_LIBRARY NAMES hermes_common hermes_common-debug PATHS ${HERMES_DIRECTORY} /usr/lib /usr/local/lib)
FIND_PATH(HERMES_COMMON_INCLUDE hermes_common.h ${HERMES_COMMON_INCLUDE_PATH} /usr/include /usr/local/include)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(HERMES_COMMON DEFAULT_MSG HERMES_COMMON_LIBRARY HERMES_COMMON_INCLUDE)
