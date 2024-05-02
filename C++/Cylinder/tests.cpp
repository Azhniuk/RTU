/// Below are commented asserts.
/// Remove a comment from these lines as you finish the appropriate function to test its correctness.
/// If uncommented asserts work correctly, then there will not be any output.
/// Don't modify assert expressions - only uncomment the lines if a particular function is implemented!

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>
#include "Cylinder.h"

int main()
{
    constexpr double HEIGHT{ 15.5 };
    constexpr double EPS{ 0.05 };
    
    Cylinder c0{ HEIGHT, M_PI }; // base height and a radius

    /// Task 4: Retrieve height
    assert(std::abs(HEIGHT - c0.get_height()) < EPS);

    /// Task 4: Retrieve base radius
    assert(std::abs(M_PI - c0.get_radius()) < EPS);

    /// Task 5: Retrieve volume
    assert(std::abs(480.6 - c0.get_volume()) < EPS);

    /// Task 5: Retrieve base area
    assert(std::abs(31 - c0.get_base_area()) < EPS);

    /// Task 5: Retrieve lateral area
    //assert(std::abs(306 - c0.get_lateral_area()) < EPS);

    /// Task 5: Retrieve total surface area
//    assert(std::abs(368 - c0.get_total_area()) < EPS);

    std::cout << "OK\n";

    return 0;
}