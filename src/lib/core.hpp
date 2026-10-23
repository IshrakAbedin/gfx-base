#pragma once

#include <concepts>
#include <numbers>
#include <string>
#include <type_traits>

#include <Eigen/Dense>
#include <fmt/format.h>

constexpr auto deg_to_rad(auto d)
    requires std::is_arithmetic_v<decltype(d)>
{
    using cmn_t = std::common_type_t<float, decltype(d)>;
    return d * (std::numbers::pi_v<cmn_t> / static_cast<cmn_t>(180));
}

std::string simple_string_format(const std::string& fmt, auto arg)
{
    return fmt::format(fmt::runtime(fmt), arg);
}

void print_messages();

Eigen::Matrix2d simple_mat2x2_mult(Eigen::Matrix2d A, Eigen::Matrix2d B);
