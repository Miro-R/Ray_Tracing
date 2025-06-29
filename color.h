#ifndef COLOR_H
#define COLOR_H
#define MAX_BYTE_RANGE 255.999
#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color){

    //REFACTOR THIS
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // convert the vector components from a [0,1] range to a [0,255] range
    int rbyte = int(MAX_BYTE_RANGE * r); 
    int gbyte = int(MAX_BYTE_RANGE * g); 
    int bbyte = int(MAX_BYTE_RANGE * b); 

    // write out the converted sample (vector) components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';

}

// int vector_to_color( ){
//
// }

#endif