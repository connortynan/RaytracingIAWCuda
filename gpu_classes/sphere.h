#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"

class sphere: public hitable  {
public:
    __device__ sphere() {};

    __device__ sphere(vec3 cen, float r, material *m)
        : center0(cen), radius(r), mat_ptr(m), is_moving(false)  {};

    __device__ sphere(vec3 cen1, vec3 cen2, float r, material *m)
            : center0(cen1), radius(r), mat_ptr(m), is_moving(true)  {
        center_vec = cen2 - cen1;
    };

    __device__ virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;

    __device__ vec3 sphere_center(float time) const {
        // Lerp from center1 to center2
        return center0 + time*center_vec;
    }

    vec3 center0;
    float radius;
    material *mat_ptr;
    bool is_moving;
    vec3 center_vec;
};

__device__ bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    vec3 center = is_moving ? sphere_center(r.time()) : center0;
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    return false;
}

#endif