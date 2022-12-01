#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

class Circle : public Curve
{
public:
    Circle(double radius);

    Point GetPoint(double t) const override;
    Vector3D GetDerivative(double t) const override;

    double GetRadius() const {return radius;}

private:
    double radius;
};

#endif // CIRCLE_H
