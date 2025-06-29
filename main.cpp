/*
Author: Miro Rogers
Project: Ray Tracing In a Weekend
*/

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "color.h"

#define OUTPUT_DIR "output/img.ppm"

using namespace std;

// Idea: write your render to a file

int main(){

    // image
    int img_width = 256;
    int img_height = 256;
    int max_colour_val = 255;
    int intRed, intGreen, intBlue = 0 ;
    string type = "P3";


    // render
    std::cout << type << '\n' << img_width << ' ' << img_height << '\n' << max_colour_val << '\n';

    for (int col = 0 ; col < img_height ; col++ ){ // pixel column coordinate of image
        std::clog << "\rScanlines remaining: " << (img_height -col)<< ' ' << std::flush;
        
        for(int row = 0 ; row < img_width ; row++ ){ // pixel row coordiante of image

        // calculate percentage of intensity
        auto pixel_color= color(double(row)/(img_width-1), double(col)/(img_height-1),0);
        write_color(std::cout, pixel_color);
        //calculate the value intesity of each rgb pixel
        }
    }
    std::clog << "\rDone.               \n";
    

    return 0;
}