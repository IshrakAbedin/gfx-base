add_library(core STATIC)
target_sources(core
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/core.cpp
)
target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(core PUBLIC
    Eigen3::Eigen
    fmt::fmt
    mpix::mpix
)