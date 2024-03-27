#pragma once
#include <cmath>

template <typename FloatT> struct unit3;
template <typename FloatT> struct point3;
template <typename FloatT> struct ray3;

template <typename FloatT>
struct vec3
{
    using unit_type = unit3<FloatT>;
    using point_type = point3<FloatT>;
    using ray_type = ray3<FloatT>;

    const FloatT x, y, z;

    vec3(FloatT x_, FloatT y_, FloatT z_)
        : x(x_), y(y_), z(z_)
    {}

    FloatT magnitude() const
    {
        return sqrt(dot(*this));
    }

    FloatT sqrMagnitude() const
    {
        return dot(*this);
    }

    unit_type unit() const;

    vec3 operator *(FloatT scalar) const
    {
        return {
            x * scalar,
            y * scalar,
            z * scalar
        };
    }

    vec3 operator /(FloatT denominator) const
    {
        return operator *(1 / denominator);
    }

    vec3 operator +(const vec3& rhs) const
    {
        return {
            x + rhs.x,
            y + rhs.y,
            z + rhs.z
        };
    }

    vec3 operator -(const vec3& rhs) const
    {
        return {
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        };
    }

    vec3 operator -() const
    {
        return {
            -x,
            -y,
            -z
        };
    }

    vec3 cross(const vec3& rhs) const
    {
        return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        };
    }

    FloatT dot(const vec3& rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    vec3 reflectedIn(const unit_type& normal) const;

    vec3 projectedOn(const vec3& rhs) const;

    point_type projectedOn(const ray_type& r) const;
};

template <typename FloatT>
vec3<FloatT> operator *(FloatT scalar, const vec3<FloatT>& v)
{
    return v * scalar;
}
