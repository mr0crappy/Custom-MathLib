#ifndef VEC2_H
#define VEC2_H

#include "Helpers.h"

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
  inline constexpr float LengthSq() const {
    return x * x + y * y;
}
};
} // namespace Math

#endif