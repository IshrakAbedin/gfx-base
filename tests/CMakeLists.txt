include(Catch)

add_executable(tests)

target_sources(tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
)

target_link_libraries(tests PRIVATE
    Catch2::Catch2WithMain
    core
)

catch_discover_tests(tests)