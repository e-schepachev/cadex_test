#ifndef CURVE_H
#define CURVE_H

#include <array>

constexpr double PI = 3.141592653589793238462643383279502884L;

struct Point
{
    double x;
    double y;
    double z;
};

using Vector3D = Point;

class Curve
{
public:
    virtual ~Curve();

    virtual Point GetPoint(double t) const = 0;
    virtual Vector3D GetDerivative(double t) const = 0;
};

#endif // CURVE_H
