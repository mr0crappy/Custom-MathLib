#ifndef MAT4_H
#define MAT4_H

#include "Vec3.h"
#include <cmath>

namespace Math {

struct Mat4 {

    float m[16];

    Mat4()
    {
        for(int i=0;i<16;i++)
            m[i] = 0.0f;
    }

    static Mat4 Identity()
    {
        Mat4 r;

        r.m[0] = 1.0f;
        r.m[5] = 1.0f;
        r.m[10] = 1.0f;
        r.m[15] = 1.0f;

        return r;
    }

    // Translation
    static Mat4 Translate(const Vec3& v)
    {
        Mat4 r = Identity();

        r.m[12] = v.x;
        r.m[13] = v.y;
        r.m[14] = v.z;

        return r;
    }

    // Scale
    static Mat4 Scale(const Vec3& v)
    {
        Mat4 r = Identity();

        r.m[0] = v.x;
        r.m[5] = v.y;
        r.m[10] = v.z;

        return r;
    }

    // Rotation X
    static Mat4 RotateX(float angle)
    {
        Mat4 r = Identity();

        float c = std::cos(angle);
        float s = std::sin(angle);

        r.m[5] = c;
        r.m[6] = s;
        r.m[9] = -s;
        r.m[10] = c;

        return r;
    }

    // Rotation Y
    static Mat4 RotateY(float angle)
    {
        Mat4 r = Identity();

        float c = std::cos(angle);
        float s = std::sin(angle);

        r.m[0] = c;
        r.m[2] = -s;
        r.m[8] = s;
        r.m[10] = c;

        return r;
    }

    // Rotation Z
    static Mat4 RotateZ(float angle)
    {
        Mat4 r = Identity();

        float c = std::cos(angle);
        float s = std::sin(angle);

        r.m[0] = c;
        r.m[1] = s;
        r.m[4] = -s;
        r.m[5] = c;

        return r;
    }

    // Perspective Projection
    static Mat4 Perspective(float fov, float aspect, float near, float far)
    {
        Mat4 r;

        float tanHalfFov = std::tan(fov / 2.0f);

        r.m[0] = 1.0f / (aspect * tanHalfFov);
        r.m[5] = 1.0f / tanHalfFov;
        r.m[10] = -(far + near) / (far - near);
        r.m[11] = -1.0f;
        r.m[14] = -(2.0f * far * near) / (far - near);

        return r;
    }

    // LookAt Camera
    static Mat4 LookAt(const Vec3& eye, const Vec3& center, const Vec3& up)
    {
        Vec3 f = (center - eye).Normalized();
        Vec3 s = Vec3::Cross(f, up).Normalized();
        Vec3 u = Vec3::Cross(s, f);

        Mat4 r = Identity();

        r.m[0] = s.x;
        r.m[4] = s.y;
        r.m[8] = s.z;

        r.m[1] = u.x;
        r.m[5] = u.y;
        r.m[9] = u.z;

        r.m[2] = -f.x;
        r.m[6] = -f.y;
        r.m[10] = -f.z;

        r.m[12] = -Vec3::Dot(s, eye);
        r.m[13] = -Vec3::Dot(u, eye);
        r.m[14] = Vec3::Dot(f, eye);

        return r;
    }

    // Matrix multiplication
    Mat4 operator*(const Mat4& o) const
    {
        Mat4 r;

        for(int row=0; row<4; row++)
        {
            for(int col=0; col<4; col++)
            {
                r.m[row*4 + col] =
                    m[row*4 + 0] * o.m[0*4 + col] +
                    m[row*4 + 1] * o.m[1*4 + col] +
                    m[row*4 + 2] * o.m[2*4 + col] +
                    m[row*4 + 3] * o.m[3*4 + col];
            }
        }

        return r;
    }

};

}

#endif