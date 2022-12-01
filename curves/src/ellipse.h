#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class Ellipse : public Curve
{
public:
    Ellipse(double radiusX, double radiusY);

private:
    Point GetPoint(double t) const override;
    Vector3D GetDerivative(double t) const override;

private:
    double radiusX;
    double radiusY;
};

#endif // ELLIPSE_H
