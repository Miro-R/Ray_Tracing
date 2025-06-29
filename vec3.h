// IDEA: We are instantiating linear algebra operations for our 3 point vector class

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{
    public:
        double e[3]; // TODO: REFACTOR TO MAKE PRIVATE

        // constructor : member initializer 
        vec3() :e{0,0,0} {} // constructor definition
        vec3(double e0, double e1, double e2) :e{e0, e1, e2} {} // constructor definition 

        double x() const { return e[0];}
        double y() const { return e[1];}
        double z() const { return e[2];}
    
        vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
        double operator[](int i) const {return e[i]; }
        double& operator[](int i) {return e[i];}

        // override the += operator to translate every element in vec3 by t
        vec3& operator+=(const vec3& v){
            e[0] +=v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        // override the * operator to scale every element in vec3 by t
        vec3& operator*=(double t){
            e[0] *=t;
            e[1] *=t;
            e[2] *=t;
            return *this;

        }
        // override the / operator to shrink every element in vec3 by t
        vec3& operator/=(double t){
            return *this *= 1/t;

        }

        // calculate the "length" (i.e the norm) of vec3
        // see the mathmatical definition of a vector's norm: sqrt([(x_1)^2] + [(x_2)^2] + ... + [(x_n)^2])
        double length() const{
            return std::sqrt(length_squared());
        }

        // calculating the squared sum of the norm (i.e the thing under the squared root)
        double length_squared() const {
            return e[0]*e[0] +e[1]*e[1] + e[2]*e[2];
        }

};


using point3 = vec3;

//TODO: Vector utility functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// On addition of two vectors: add together their coresponding elements and create a new vector containing the sum of those elements
inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// On subtraction of two vectors
inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u.e[0]-v.e[0], u.e[1]-v.e[1], u.e[2]-v.e[2]);
}

// Multiply vector u by vector v (i.e scale one vector by another)
// Think: Stretch one vector by another
inline vec3 operator*(const vec3& u, const vec3& v){    
    return vec3(u.e[0]*v.e[0], u.e[1]*v.e[1], u.e[2]*v.e[2]);
}

// Scale a vector v by constant t (i.e scale one vector by another)
// Think stretch (or squish) a vector by t
inline vec3 operator*(double t, const vec3& v){
    return vec3(t*v.e[0],t*v.e[1], t*v.e[2]);
}

// Ensure vector scaling by a constant t is commutitive. (ensuring proper behaviour of multiplication)
// see above function
inline vec3 operator*(const vec3& v, double t){
    return t * v;
}

// divide all elements of vector v by t
// Think: Squish
inline vec3 operator/(const vec3& v, double t){
    return (1/t)*v;
}

// The dot product behaviour of vector v and u
// i.e innerproduct
inline double dot(const vec3& u, const vec3& v){
    return (u.e[0]*v.e[0])
            +(u.e[1]*v.e[1]) 
            +(u.e[2]*v.e[2]);
}

//The cross product of vector u and v
// i.e outerproduct
// NOTE: "The magnitude of the cross product equals the area of a parallelogram" SOURCE: Wikipedia
inline vec3 cross(const vec3& u, const vec3& v){
    return 
    vec3(
        (u.e[1]*v.e[2]) - (u.e[2] * v.e[1]),
        (u.e[2]*v.e[0]) - (u.e[0] * v.e[2]),
        (u.e[0]*v.e[1]) - (u.e[1] * v.e[0])
    );

}

// The unitvector calculation of vector v
inline vec3 unit_vector(const vec3 v){
    return v/v.length();

}



#endif