#pragma once
#include "point3.hpp"
#include "ray3.hpp"
#include <optional>

template <typename FloatT>
class RayTrace
{
    ray3<FloatT> _ray;
    std::optional<point3<FloatT>> _terminator;


};
