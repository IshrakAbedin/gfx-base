include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)
set(CPM_SOURCE_CACHE "${PROJECT_SOURCE_DIR}/.cache/CPM")

# fmt
CPMAddPackage(
    URI "gh:fmtlib/fmt#12.2.0"
    GIT_SHALLOW TRUE
)

# Eigen
CPMAddPackage(
    NAME eigen
    URL https://gitlab.com/libeigen/eigen/-/archive/5.0.1/eigen-5.0.1.tar.gz
    DOWNLOAD_ONLY YES
)
if(eigen_ADDED)
    add_library(eigen_headers INTERFACE)
    target_include_directories(eigen_headers SYSTEM INTERFACE "${eigen_SOURCE_DIR}")
    add_library(Eigen3::Eigen ALIAS eigen_headers)
endif()


# Catch2
if(BUILD_TESTING)
    CPMAddPackage(
        URI "gh:catchorg/Catch2@3.16.1"
        GIT_SHALLOW TRUE
    )
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
endif()