/*
Author: Miro Rogers
Project: Ray Tracing In a Weekend
*/

#include <iostream>
#include <fstream>
using namespace std;

// Idea: write your render to a file

int main(){
    // open file
    ofstream ppm;
    ppm.open("output/img.ppm");


    // image
    int img_width = 256;
    int img_height = 256;
    int max_colour_val = 255;
    int intRed, intGreen, intBlue = 0 ;
    string type = "P3";


    // render
    ppm << type << '\n' << img_width << ' ' << img_height << '\n' << max_colour_val << '\n';

    for (int col = 0 ; col < img_height ; col++ ){ // pixel column coordinate of image
        ppm << '\n';
        
        for(int row = 0 ; row < img_width ; row++ ){ // pixel row coordiante of image
        // calculate percentage of intensity
        auto r = double(row)/(img_width-1);
        auto g = double(col)/(img_height-1);
        auto b = 0;
        
        intRed = int(255.999 * r); // REFACTOR
        intGreen = int(255.999 * g);
        intBlue = int(255.999 * b);

        ppm << intRed << ' ' << intGreen << ' ' << intBlue << '\n'; 
        //calculate the value intesity of each rgb pixel
        }
    }

    ppm.close();

    return 0;
}