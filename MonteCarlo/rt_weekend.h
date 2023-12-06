#pragma once
#include <cmath>
#include <limits>
#include <memory>
#include <random>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
double random_double(double min, double max);

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline int random_int(int min, int max) {
    // Returns a random integer in [min,max].
    return static_cast<int>(random_double(min, max + 1));
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}

inline bool approx_equal(double a, double b)
{
    auto s = 1e-8;
    return (fabs(a - b) < s);
}

// Common Headers

#include "interval.h"
#include "ray.h"
#include "vec3.h"
using color = vec3;