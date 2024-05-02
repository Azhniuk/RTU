#ifndef CYLINDER_H
#define CYLINDER_H
/// Add required C++ statements to declare and define the class Cylinder

#include "Circle.h"

class Cylinder {
public:
    Cylinder(double height, double radius);

    double get_height() const;
    double get_radius() const;

    double get_volume() const;
    double get_base_area() const;
    double calculate_lateral_area() const;
    double calculate_total_surface_area() const;

private:
    double height;
    double radius;
    Circle b;
};

#endif
