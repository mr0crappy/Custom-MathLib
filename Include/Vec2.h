#ifndef VEC2_H
#define VEC2_H

#include "Helpers.h"
#include <cmath>

namespace Math {
struct Vec2 {
  float x, y;

  Vec2() : x(0), y(0) {}
  Vec2(float a, float b) : x(a), y(b) {}
  Vec2 operator+(const Vec2 &a) const { return Vec2(x + a.x, y + a.y); }
  Vec2 operator-(const Vec2 &a) const { return Vec2(x - a.x, y - a.y); }
  Vec2 operator*(float a) const { return Vec2(x * a, y * a); }
  Vec2 operator/(float a) const {
    if (IsZero(a))
      return Vec2(0, 0);
    return Vec2(x / a, y / a);
  }
  Vec2 &operator+=(const Vec2 &a) {
    x += a.x;
    y += a.y;
    return *this;
  }
  Vec2 &operator-=(const Vec2 &a) {
    x -= a.x;
    y -= a.y;
    return *this;
  }
  Vec2 &operator*=(float a) {
    x *= a;
    y *= a;
    return *this;
  }
  Vec2 &operator/=(float a) {
    if (IsZero(a))
      return *this;
    x /= a;
    y /= a;
    return *this;
  }
  inline constexpr float LengthSq() const { return x * x + y * y; }
  inline float Length() const { return std::sqrt(LengthSq()); }

  static constexpr float Dot(const Vec2 &a, const Vec2 &b) {
    return a.x * b.x + a.y * b.y;
  }

  inline Vec2 Normalized() const {
    float len = Length();
    if (IsZero(len)) {
      return Vec2(0, 0);
    }
    return Vec2(x / len, y / len);
  }

  inline Vec2 &Normalize() {
    float len = Length();
    if (IsZero(len))
      return *this;
    x /= len;
    y /= len;
    return *this;
  }

  static constexpr float DistanceSq(const Vec2& a, const Vec2& b){
    float dx = a.x-b.x;
    float dy = a.y-b.y;
    return dx*dx + dy*dy;
  }

  static float Distance(const Vec2& a, const Vec2& b){
    return std::sqrt(DistanceSq(a,b));
  }

  Vec2 operator-() const {
    return Vec2(-x,-y);
  }
  

};
} // namespace Math

#endif