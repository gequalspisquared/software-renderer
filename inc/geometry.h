#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

template<typename T> 
class Vec2 {
public:
    T x, y;
    
    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}

    inline Vec2<T> operator +(const Vec2<T> &v) const { return Vec2<T>(x + v.x, y + v.y); }
    inline Vec2<T> operator -(const Vec2<T> &v) const { return Vec2<T>(x - v.x, y - v.y); }
    inline Vec2<T> operator *(float f)          const { return Vec2<T>(x * f, y * f); }
};

#endif
