#ifndef RAY_H
#define RAY_H

#include "../src/vec3.h"

class ray {
public:
    __device__ ray() {}
    __device__ ray(const vec3& origin, const vec3& direction)
        { orig = origin; dir = direction; tm = 0.0f;}
    __device__ ray(const vec3& origin, const vec3& direction, float time)
        { orig = origin; dir = direction; tm = time;}
    __device__ vec3 origin() const       { return orig; }
    __device__ vec3 direction() const    { return dir; }
    __device__ float time() const        { return tm;}

    __device__ vec3 point_at_parameter(float t) const {
        return orig + t*dir;
    }

private:
    vec3 orig;
    vec3 dir;
    float tm;
};

#endif