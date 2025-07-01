#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
    public:
        ray() {}
        
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        point3 at(double t) const {
            return orig + t*dir; // same as P(t) = A + t*b, where P(t) is our ray. The origin of the ray is A, and b is the direction the ray is going.

        }
    private:
        point3 orig;
        vec3 dir;
};

#endif