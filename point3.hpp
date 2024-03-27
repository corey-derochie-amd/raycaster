#pragma once
#include "vec3.hpp"

template <typename FloatT> struct ray3;

template <typename FloatT>
struct point3
{
    using vec_type = vec3<FloatT>;
    using ray_type = ray3<FloatT>;

    static const point3 Origin;

    const FloatT x, y, z;

    point3(FloatT x_, FloatT y_, FloatT z_)
        : x(x_), y(y_), z(z_)
    {}

    point3 operator +(const vec_type& v) const
    {
        return {
            x + v.x,
            y + v.y,
            z + v.z
        };
    }

    vec_type operator -(const point3& rhs) const
    {
        return {
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        };
    }

    ray_type rayThrough(const point3& p) const;

    point3 atDistanceToward(const point3& p, FloatT distance) const
    {
        return *this + (p - *this).unit() * distance;
    }
};
