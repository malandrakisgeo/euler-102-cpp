
#include <iostream>
using namespace std;

#include "mafs.hpp"
#include <cassert>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>


int main(){

    std::ifstream input("0102_triangles.txt");
    int l= 0;
    for( std::string line; getline( input, line ); )
    {
        std::vector<int> vect;
        std::stringstream ss(line);

        for (int i; ss >> i;) {
            vect.push_back(i);    
            if (ss.peek() == ',')
                ss.ignore();
        }
        Point a =  Point(vect.at(0), vect.at(1));
        Point b =  Point(vect.at(2), vect.at(3));
        Point c =  Point(vect.at(4), vect.at(5));
        bool positive_x_cut = ( x_axis_intersected(a, b, false) || x_axis_intersected(b, c, false) || x_axis_intersected(a, c, false) );
        bool positive_y_cut = ( y_axis_intersected(a, b, true) || y_axis_intersected(b, c, true) || y_axis_intersected(a, c, true) );
        bool negative_x_cut = ( x_axis_intersected(a, b, true) || x_axis_intersected(b, c, true) || x_axis_intersected(a, c, true));
        bool negative_y_cut = ( y_axis_intersected(a, b, false) || y_axis_intersected(b, c, false) || y_axis_intersected(a, c, false) );


        if (positive_x_cut && positive_y_cut && negative_x_cut && negative_y_cut) {
           ++l;
        }

    }
    
    cout << "Triangles containing (0,0): ";
    cout << l;
    cout << "\n";

}


