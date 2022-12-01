#ifndef HELIX_H
#define HELIX_H

#include "circle.h"

class Helix : public Circle
{
public:
    Helix(double radius, double step);

    Point GetPoint(double t) const override;
    Vector3D GetDerivative(double t) const override;

private:
    double step;
};

#endif // HELIX_H
