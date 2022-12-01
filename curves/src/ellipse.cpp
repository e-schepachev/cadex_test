#include "ellipse.h"

#include "math.h"

Ellipse::Ellipse(double radiusX, double radiusY) :
    radiusX(radiusX),
    radiusY(radiusY)
{}

Point Ellipse::GetPoint(double t) const
{
//    for ellipse 't' is not a "real" angle which specifies the point on the curve.
//    This formulas could be used to build an ellipse by the real angle from the begining of the coordinate system
//
//    const double tanT = (radiusX / radiusY) * tan(radians);
//    return {radiusX * cos(atan(tanT)), radiusY * sin(atan(tanT)), 0};
    return {radiusX * cos(t), radiusY * sin(t), 0};
}

Vector3D Ellipse::GetDerivative(double t) const
{
    return {-radiusX * sin(t), radiusY * cos(t), 0};
}

