INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SIMPLE_INT simple_int)

FIND_PATH(
    SIMPLE_INT_INCLUDE_DIRS
    NAMES simple_int/api.h
    HINTS $ENV{SIMPLE_INT_DIR}/include
        ${PC_SIMPLE_INT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SIMPLE_INT_LIBRARIES
    NAMES gnuradio-simple_int
    HINTS $ENV{SIMPLE_INT_DIR}/lib
        ${PC_SIMPLE_INT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SIMPLE_INT DEFAULT_MSG SIMPLE_INT_LIBRARIES SIMPLE_INT_INCLUDE_DIRS)
MARK_AS_ADVANCED(SIMPLE_INT_LIBRARIES SIMPLE_INT_INCLUDE_DIRS)

