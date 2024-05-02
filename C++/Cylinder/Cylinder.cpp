#include "Cylinder.h"
Cylinder::Cylinder(double height, double radius) : height(height), radius(radius), b(radius) {}

double Cylinder::get_height() const {
    return height;
}

double Cylinder::get_radius() const {
    return radius;
}

double Cylinder::get_volume() const {
    return M_PI * radius * radius * height;
}

double Cylinder::get_base_area() const {
    return  M_PI * radius * radius;
}

double Cylinder::calculate_lateral_area() const {
    return 2 * M_PI * radius * height;
}

double Cylinder::calculate_total_surface_area() const {
    return 2 * get_base_area() + calculate_lateral_area();
}