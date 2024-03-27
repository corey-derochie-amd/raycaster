#pragma once
#include "vec3.hpp"

template <typename FloatT>
struct unit3
{
    using vec_type = vec3<FloatT>;
    using point_type = point3<FloatT>;
    using ray_type = ray3<FloatT>;

    static const unit3 I, J, K;

    const FloatT& x, y, z;

    static unit3 from(const vec_type& v)
    {
        return unit3(v);
    }

    operator const vec_type&() const
    {
        return _v;
    }

    unit3 operator -() const
    {
        return unit3(-_v);
    }

    vec_type operator *(FloatT scalar) const
    {
        return _v * scalar;
    }

    vec_type cross(const vec_type& rhs) const
    {
        return _v.cross(rhs);
    }

    FloatT dot(const vec_type& rhs) const
    {
        return _v.dot(rhs);
    }

    vec_type projectedOn(const vec_type& rhs) const
    {
        return _v.projectedOn(rhs);
    }

    point_type projectedOn(const ray_type& r) const
    {
        return _v.projectedOn(r);
    }

private:
    const vec_type _v;

    unit3() : x(_v.x), y(_v.y), z(_v.z) {}
    unit3(const vec_type& v) : unit3(), _v(v) {}
};

template <typename FloatT>
vec3<FloatT> vec3<FloatT>::reflectedIn(const typename vec3<FloatT>::unit_type& normal) const
{
    return *this - (2 * dot(normal)) * normal;
}

template <typename FloatT>
vec3<FloatT> vec3<FloatT>::projectedOn(const vec3<FloatT>& rhs) const
{
    return rhs.unit() * dot(rhs);
}
