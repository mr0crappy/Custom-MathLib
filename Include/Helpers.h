    #ifndef HELPERS_H
    #define HELPERS_H

    namespace Math {

    // constants
    constexpr float EPSILON = 1e-6f;

    // Abs: Absolute value
    inline constexpr float Abs(float x) { return (x < 0.0f) ? -x : x; }

    // Clamp: Clamp a no. to a given range
    inline constexpr float Clamp(float x, float min, float max) {
    if (x > max) {
        return max;
    }
    if (x < min) {
        return min;
    }
    return x;
    }

    // Lerp: returns a no. between a and b n=based on t
    inline constexpr float Lerp(float a, float b, float t) { return a + (t * (b - a)); }

    // SmoothStep: Smooth transition between two values
    inline float SmoothStep(float e0, float e1, float x) {
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
    }

    #endif
