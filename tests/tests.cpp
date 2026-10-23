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

TEST_CASE("mpix modify, resize and flip an image in memory works", "[mpix]")
{
    using namespace mpix;

    Image<ColorFormat::RGB> img{4, 6, ColorRGB{10, 20, 30}};
    img.Pixel(0, 0) = ColorRGB{255, 0, 0}; // modify a pixel

    REQUIRE(img.Pixel(0, 0).R == 255);
    REQUIRE(img.Pixel(3, 5).B == 30); // others untouched

    auto flipped = img.VFlip(); // top-left red pixel moves to bottom-left
    REQUIRE(flipped.Pixel(3, 0).R == 255);
    REQUIRE(flipped.Pixel(0, 0).R == 10);

    auto small = img.Resize(2, 3);
    REQUIRE(small.Height() == 2);
    REQUIRE(small.Width() == 3);

    REQUIRE_THROWS_AS(img.Pixel(4, 0), std::out_of_range);
}

TEST_CASE("mpix writing an image to disk and reading it back works", "[mpix]")
{
    using namespace mpix;

    const auto path = std::filesystem::temp_directory_path() / "mpix_smoke.png";

    Image<ColorFormat::RGBA> img{3, 4, ColorRGBA{1, 2, 3, 255}};
    img.Pixel(2, 3) = ColorRGBA{200, 100, 50, 128};
    img.Write<ImageFormat::PNG>(path);

    auto loaded = read_image_from_file(path);
    std::filesystem::remove(path);

    REQUIRE(std::holds_alternative<Image<ColorFormat::RGBA>>(loaded));
    const auto& out = std::get<Image<ColorFormat::RGBA>>(loaded);
    REQUIRE(out.Height() == 3);
    REQUIRE(out.Width() == 4);
    REQUIRE(out.Pixel(0, 0).R == 1);
    REQUIRE(out.Pixel(2, 3).R == 200);
    REQUIRE(out.Pixel(2, 3).A == 128);
}
