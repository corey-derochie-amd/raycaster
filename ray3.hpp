#pragma once
#include "point3.hpp"

template <typename FloatT>
struct ray3
{
    const point3<FloatT> origin;
    const unit3<FloatT> direction;

    point3<FloatT> follow(FloatT distance)
    {
        return origin + direction * distance;
    }
};

template <typename FloatT>
typename vec3<FloatT>::point_type vec3<FloatT>::projectedOn(const typename vec3<FloatT>::ray_type& r) const
{
    return r.origin + projectedOn(r.direction);
}

template <typename FloatT>
typename point3<FloatT>::ray_type point3<FloatT>::rayThrough(const point3<FloatT>& p) const
{
    return {
        .origin = *this,
        .direction = (p - *this).unit()
    };
}
