#ifndef VEC3_H
#define VEC3_H

#include "Helpers.h"
#include <cmath>

namespace Math {

struct Vec3 {
    float x, y, z;

    constexpr Vec3() : x(0), y(0), z(0) {}
    constexpr Vec3(float v) : x(v), y(v), z(v) {}
    constexpr Vec3(float a, float b, float c) : x(a), y(b), z(c) {}

    // operators
    Vec3 operator+(const Vec3& a) const { return Vec3(x + a.x, y + a.y, z + a.z); }
    Vec3 operator-(const Vec3& a) const { return Vec3(x - a.x, y - a.y, z - a.z); }
    Vec3 operator*(float a) const { return Vec3(x * a, y * a, z * a); }
    Vec3 operator/(float a) const {
        if (IsZero(a))
            return Vec3(0);
        return Vec3(x / a, y / a, z / a);
    }

    Vec3 operator-() const { return Vec3(-x, -y, -z); }

    // compound operators
    Vec3& operator+=(const Vec3& a) {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& a) {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }

    Vec3& operator*=(float a) {
        x *= a;
        y *= a;
        z *= a;
        return *this;
    }

    Vec3& operator/=(float a) {
        if (IsZero(a))
            return *this;
        x /= a;
        y /= a;
        z /= a;
        return *this;
    }

    // length
    inline constexpr float LengthSq() const {
        return x*x + y*y + z*z;
    }

    inline float Length() const {
        return std::sqrt(LengthSq());
    }

    // normalize
    Vec3 Normalized() const {
        float len = Length();
        if (IsZero(len))
            return Vec3(0);
        return Vec3(x/len, y/len, z/len);
    }

    Vec3& Normalize() {
        float len = Length();
        if (IsZero(len))
            return *this;

        x /= len;
        y /= len;
        z /= len;

        return *this;
    }

    // dot product
    static constexpr float Dot(const Vec3& a, const Vec3& b) {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }

    // cross product
    static constexpr Vec3 Cross(const Vec3& a, const Vec3& b) {
        return Vec3(
            a.y*b.z - a.z*b.y,
            a.z*b.x - a.x*b.z,
            a.x*b.y - a.y*b.x
        );
    }

    // distance
    static constexpr float DistanceSq(const Vec3& a, const Vec3& b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        float dz = a.z - b.z;

        return dx*dx + dy*dy + dz*dz;
    }

    static float Distance(const Vec3& a, const Vec3& b) {
        return std::sqrt(DistanceSq(a,b));
    }
};

}

#endif