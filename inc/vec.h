#ifndef NDC_VEC_H
#define NDC_VEC_H

#include <cmath>
#include <iostream>

template<typename T>
class Vec2 {
public:
    T x, y;

    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}

    inline Vec2<T> operator +(const Vec2<T> &v) const { return Vec2<T>(x + v.x, y + v.y); }
    inline Vec2<T> operator -(const Vec2<T> &v) const { return Vec2<T>(x - v.x, y - v.y); }
    inline Vec2<T> operator *(float scale) const { return Vec2<T>(x*scale, y*scale); }
    inline Vec2<T> operator /(float scale) const { return Vec2<T>(x/scale, y/scale); }

    inline float operator *(const Vec2<T> &v) const { return x*v.x + y*v.y; } // dot product

    inline void operator +=(const Vec2<T> &v) { x += v.x; y += v.y; }
    inline void operator -=(const Vec2<T> &v) { x -= v.x; y -= v.y; }
    inline void operator *=(float scale) { x *= scale; y *= scale; }
    inline void operator /=(float scale) { x /= scale; y /= scale; }

    inline float mag2() const { return this*this; }
    inline float mag()  const { return std::sqrt(mag2()); }
    inline float dist2(const Vec2<T> &v) const { return (v - this).mag2(); }
    inline float dist(const Vec2<T> &v)  const { return (v - this).mag(); }

    inline void normalize() { return this / mag(); }

    template<class U>
    friend
    std::ostream& operator <<(std::ostream &s, Vec2<T>& v);
};

template<typename T>
class Vec3 {
public:
    T x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    inline Vec3<T> operator +(const Vec3<T> &v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
    inline Vec3<T> operator -(const Vec3<T> &v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
    inline Vec3<T> operator ^(const Vec3<T> &v) const { return Vec3<T>(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); } // cross product
    inline Vec3<T> operator *(float scale) const { return Vec3<T>(x*scale, y*scale, z*scale); }
    inline Vec3<T> operator /(float scale) const { return Vec3<T>(x/scale, y/scale, z/scale); }

    inline float operator *(const Vec3<T> &v) const { return x*v.x + y*v.y + z*v.z; } // dot product

    inline void operator +=(const Vec3<T> &v) { x += v.x; y += v.y; z += v.z; }
    inline void operator -=(const Vec3<T> &v) { x -= v.x; y -= v.y; z -= v.z; }
    inline void operator *=(float scale) { x *= scale; y *= scale; z *= scale; }
    inline void operator /=(float scale) { x /= scale; y /= scale; z /=scale; }

    inline float mag2() const { return this*this; }
    inline float mag()  const { return std::sqrt(mag2()); }
    inline float dist2(const Vec3<T> &v) const { return (v - this).mag2(); }
    inline float dist(const Vec3<T> &v)  const { return (v - this).mag(); }

    inline void normalize() { return this / mag(); }

    template<class U>
    friend
    std::ostream& operator <<(std::ostream &s, Vec3<T>& v);
};

typedef Vec2<double> Vec2d;
typedef Vec2<float>  Vec2f;
typedef Vec2<int>    Vec2i;
typedef Vec3<double> Vec3d;
typedef Vec3<float>  Vec3f;
typedef Vec3<int>    Vec3i;

template<class T>
std::ostream& operator <<(std::ostream &s, Vec2<T>& v) {
    s << "(" << v.x << ", " << v.y << ")\n";
    return s;
}

template<class T>
std::ostream& operator <<(std::ostream &s, Vec3<T>& v) {
    s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return s;
}

#endif
