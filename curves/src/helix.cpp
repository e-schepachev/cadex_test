#include "helix.h"

Helix::Helix(double radius, double step) :
    Circle(radius),
    step(step)
{}

Point Helix::GetPoint(double t) const
{
    Point point = Circle::GetPoint(t);

    point.z = step * t / (2 * PI);
    return point;
}

Vector3D Helix::GetDerivative(double t) const
{
    Vector3D derivative = Circle::GetDerivative(t);

    derivative.z = step / (2 * PI);
    return derivative;
}
