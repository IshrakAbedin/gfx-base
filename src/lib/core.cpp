#include "core.hpp"

#include <Eigen/Dense>
#include <fmt/base.h>

#include "fmt_eigen_bridge.hpp"

void print_messages()
{
    constexpr auto theta = 90.0;
    Eigen::Matrix3d m{
        {sin(deg_to_rad(theta)), -cos(deg_to_rad(theta)), 0},
        {cos(deg_to_rad(theta)), sin(deg_to_rad(theta)), 0},
        {0, 0, 1}
    };

    Eigen::Vector3d v{1, 0, 0};

    fmt::println(
        "Hello from the setup template!\n"
        "If you rotate the vector:\n"
        "{}\n"
        "by {} degrees, it becomes:\n"
        "{}\n"
        "[This is all this executable has to say!]",
        v, theta, m * v
    );
}

Eigen::Matrix2d simple_mat2x2_mult(Eigen::Matrix2d A, Eigen::Matrix2d B)
{
    return A * B;
}
