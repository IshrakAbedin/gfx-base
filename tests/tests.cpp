#include <catch2/catch_test_macros.hpp>

#include <numbers>

#include "core.hpp"

TEST_CASE("Basic C++20 lib works", "[C++20]")
{
    auto expected_val = deg_to_rad(180.0);
    REQUIRE(expected_val == std::numbers::pi);
}

TEST_CASE("fmtlib works", "[fmt]")
{
    auto s = simple_string_format("Hello, {}!", 42);
    REQUIRE(s == "Hello, 42!");
}

TEST_CASE("Eigen works", "[eigen]")
{
    Eigen::Matrix2d m{{2, 0}, {0, 3}};
    Eigen::Matrix2d n{{2, 0}, {0, 3}};
    Eigen::Matrix2d r{{4, 0}, {0, 9}};

    REQUIRE(m * n == r);
}
