#include "circle.h"

#include <math.h>
#include <numbers>

Circle::Circle(double radius) :
    radius(radius)
{}

Point Circle::GetPoint(double t) const
{
    return {radius * std::cos(t), radius * std::sin(t), 0};
}

Vector3D Circle::GetDerivative(double t) const
{
    return {-radius * std::sin(t), radius * std::cos(t), 0};
}

