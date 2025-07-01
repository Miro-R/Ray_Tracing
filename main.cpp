/*
Author: Miro Rogers
Project: Ray Tracing In a Weekend
*/

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

#define OUTPUT_DIR "output/img.ppm"

using namespace std;

// Idea: write your render to a file

color ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0); // return a linear interpolation of blue or white
}

int main(){

    // image
    auto aspect_ratio = 16.0/9.0; // ideal aspect ratio
    int img_width = 400;
    int img_height = int(img_width/aspect_ratio);
    int max_colour_val = 255;
    int intRed, intGreen, intBlue = 0 ;
    string type = "P3";

    //ensure that our image height is at least 1 pixle
    img_height = (img_height < 1) ? 1 : img_height; // set img height to 1 if it is currently less than 1.

    // camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(img_width/img_height)); // calculate the ACTUAL aspect ratio
    auto camera_centre = point3(0,0,0);

    auto viewport_u = vec3(viewport_width,0,0);
    auto viewport_v = vec3(0,-viewport_height,0);

    auto pixel_delta_u = viewport_u/ img_width;
    auto pixel_delta_v = viewport_v/ img_height;

    auto viewport_upper_left =  camera_centre 
                                - vec3(0,0,focal_length) 
                                - viewport_u/2 
                                - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // render
    std::cout << type << '\n' << img_width << ' ' << img_height << '\n' << max_colour_val << '\n';

    for (int col = 0 ; col < img_height ; col++ ){ // pixel column coordinate of image
        std::clog << "\rScanlines remaining: " << (img_height -col)<< ' ' << std::flush;
        
        for(int row = 0 ; row < img_width ; row++ ){ // pixel row coordiante of image

        
        auto pixel_centre = pixel00_loc + (row * pixel_delta_u) + (col * pixel_delta_v);
        auto ray_direction = pixel_centre - camera_centre;
        ray r(camera_centre, ray_direction);

        auto pixel_color= ray_color(r);
        write_color(std::cout, pixel_color);
        //calculate the value intesity of each rgb pixel
        }
    }
    std::clog << "\rDone.               \n";
    

    return 0;
}