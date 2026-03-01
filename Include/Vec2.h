#ifndef VEC2_H
#define VEC2_H

namespace Math {
struct Vec2 {
  float x, y;

  Vec2(): x(0), y(0){}
  Vec2(float a, float b) : x(a), y(b){}
  Vec2 operator+(const Vec2& a) const{
    return Vec2(x+a.x, y+a.y);
  }
  Vec2 operator-(const Vec2& a) const{
        return Vec2(x-a.x, y-a.y);

  }
  Vec2 operator*(float a) const{
    return Vec2(a*x, a*y);
  }
  Vec2 operator/(float a) const{
    return Vec2(x/a, y/a);
  }
};
} // namespace Math

#endif