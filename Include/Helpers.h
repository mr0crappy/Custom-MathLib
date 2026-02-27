#ifndef HELPERS_H
#define HELPERS_H

namespace Math {

// constants
constexpr float EPSILON = 1e-6f;
constexpr float PI = 3.14159265358979323846f;
constexpr float TAU = 2.0f*PI;


// Abs: Absolute value
inline constexpr float Abs(float x) { return (x < 0.0f) ? -x : x; }

// Clamp: Clamp a no. to a given range
inline constexpr float Clamp(float x, float min=0, float max=1) {
  if (x > max) {
    return max;
  }
  if (x < min) {
    return min;
  }
  return x;
}

// Lerp: returns a no. between a and b n=based on t
inline constexpr float Lerp(float a, float b, float t) {
  return a + (t * (b - a));
}

// SmoothStep: Smooth transition between two values
inline constexpr float SmoothStep(float e0, float e1, float x) {
  float range = e1 - e0;

  // Prevent division by zero
  if (Abs(range) < EPSILON)
    return 0.0f;

  float t = (x - e0) / range;
  t = Clamp(t, 0.0f, 1.0f);

  return t * t * (3.0f - 2.0f * t);
}

// Min: return minimum
inline constexpr float Min(float a, float b) {
  if (a < b)
    return a;
  return b;
}

// Max: return maximum
inline constexpr float Max(float a, float b) {
  if (a < b)
    return b;
  return a;
}

//Sign: Return the sign(+ve or -ve) of a no.
inline constexpr int Sign(int x) {
  if (x > 0)
    return 1;
  else if (x < 0)
    return -1;
  return 0;
}

inline constexpr float Sign(float x) {
  if (x > 0.0f)
    return 1.0f;
  else if (x < 0.0f)
    return -1.0f;
  return 0.0f;
}

//Floor: Floor funciton
inline constexpr float Floor(float x) {
  int int_x = (int)x;

  if (x < int_x) {
    return static_cast<float>(int_x - 1);
  }
  return static_cast<float>(int_x);
}

//Ceil: Ceiling Function
inline constexpr float Ceil(float x) {
  int int_x = (int)x;

  if (x > int_x) {
    return static_cast<float>(int_x + 1);
  }
  return static_cast<float>(int_x);
}

//Round: Round off of a number
inline constexpr float Round(float x) {
  if (x >= 0)
    return Floor(x + 0.5);
  else
    return Ceil(x - 0.5);
}

//Fract: Fractional part of a float no.
inline constexpr float Fract(float x) { return x - Floor(x); }



//Angle Helpers

//Deg to Rad
inline constexpr float DegToRad(float Deg){
    return Deg*(PI/180.0f);
}

//Rad to Deg
inline constexpr float RadToDeg(float Rad){
    return Rad*(180.0f/PI);
}

//IsZero
inline constexpr bool IsZero(float x){
    return Abs(x)<EPSILON;
}

//Nearly Equal
inline constexpr bool NearlyEqual(float a, float b){
    return Abs(a-b)<EPSILON*Max(1.0f, Max(Abs(a), Abs(b)));
}

//floating modulo
inline constexpr float Mod(float x, float y){
    if(IsZero(y))
        return 0;
    return x-y*Floor(x/y);
}

//Wrap Angle
inline constexpr float WrapToTAU(float x){
    x = Mod(x, TAU);
    if(x<0){
        x+=TAU;
    }
    return x;
}

inline constexpr float WrapToPI(float x){
    x = Mod(x+PI, TAU);
    if(x<0)
        x+=TAU;
    return x-PI;
}

} // namespace Math

#endif
