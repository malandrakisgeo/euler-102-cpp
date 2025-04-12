
#include <cmath>
using namespace std;

#pragma once
#ifndef _POINT_H
#define _POINT_H
#include "point.hpp"
#endif


    bool is_within_bounds(double p, double a, double b){
        double min = a>b ? b : a;
        double max = min == a ? b : a;
        return (p>=min && p<=max);
    }

    //X axis intersected by line segment between p1, p2
    bool x_axis_intersected(Point &p1,  Point &p2, bool on_negative){
        if((p1.y >= 0.0 && p2.y <= 0.0) || (p1.y <= 0.0 && p2.y >= 0.0)){
            double x =  p1.x + (0.0 - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
            return (on_negative ? x <=0.0 : x>=0.0) && is_within_bounds(x, p1.x, p2.x);
        }
        return false;
    }

    bool y_axis_intersected(Point &p1, Point &p2, bool on_negative){
        if((p1.x >= 0.0 && p2.x <= 0.0) || (p1.x <= 0.0 && p2.x >= 0.0)){
            double y =  p1.y + (0.0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x);
            return (on_negative ? y <=0.0 : y>=0.0) && is_within_bounds(y, p1.y, p2.y);
        }
        return false;
    }

