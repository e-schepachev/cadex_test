#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <type_traits>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

constexpr double TEST_ANGLE = PI / 4;
constexpr double TEST_COUNT = 20;

constexpr int CIRCLE_MAX_RADIUS = 200;

constexpr int ELLIPSE_MAX_RADIUS_X = 200;
constexpr int ELLIPSE_MAX_RADIUS_Y = 200;

constexpr int HELIX_MAX_RADIUS = 200;
constexpr int HELIX_MAX_STEP = 200;

std::shared_ptr<Curve> GenerateCircle()
{
    const double radius = rand() % CIRCLE_MAX_RADIUS;

    std::cout << "Circle. Radius: " << radius << std::endl;
    return std::make_shared<Circle>(radius);
}

std::shared_ptr<Curve> GenerateEllipse()
{
    const double radiusX = rand() % ELLIPSE_MAX_RADIUS_X;
    const double radiusY = rand() % ELLIPSE_MAX_RADIUS_Y;

    std::cout << "Ellipse. RadiusX: " << radiusX << " RadiusY: " << radiusY << std::endl;
    return std::make_shared<Ellipse>(radiusX, radiusY);
}

std::shared_ptr<Curve> GenerateHelix()
{
    const double radius = rand() % HELIX_MAX_RADIUS;
    const double step = rand() % HELIX_MAX_STEP;

    std::cout << "Helix. Radius " << radius << " Step "<< step << std::endl;
    return std::make_shared<Helix>(radius, step);
}

std::vector<std::shared_ptr<Curve>> GenerateCurves(size_t size)
{
    std::cout << "Generate " << size << " curves"<< std::endl;
    auto now = std::chrono::system_clock::now();
    int time = std::chrono::system_clock::to_time_t(now);

    srand(time);

    std::vector<std::shared_ptr<Curve>> curves;
    curves.reserve(size);
    for (size_t i = 0 ; i < size; ++i)
    {
        const int random = rand();
        const int curveType = random % 3;
        std::cout << i << ": " ;

        switch (curveType)
        {
            case 0: curves.emplace_back(GenerateCircle()); break;
            case 1: curves.emplace_back(GenerateEllipse()); break;
            case 2: curves.emplace_back(GenerateHelix()); break;
        }
    }

    return curves;
}

void PrintCurvesPoints(const std::vector<std::shared_ptr<Curve>>& curves, double angle)
{
    std::cout << std::endl << "Curve points at '" << angle << "':" << std::endl;
    for (size_t i = 0 ; i < curves.size(); ++i)
    {
        const auto& curve = curves[i];
        std::cout << i << ": {" << curve->GetPoint(angle).x << ", " << curve->GetPoint(angle).y << ", " << curve->GetPoint(angle).z << "} " << std::endl;
    }

}

void PrintCurvesDerivativesValue(const std::vector<std::shared_ptr<Curve>>& curves, double angle)
{
    std::cout << std::endl << "Curve derivatives at '" << angle << "':" << std::endl;
    for (size_t i = 0 ; i < curves.size(); ++i)
    {
        const auto& curve = curves[i];
        std::cout << i << "{" << curve->GetDerivative(angle).x << ", " << curve->GetDerivative(angle).y << ", " << curve->GetDerivative(angle).z << "} " << std::endl;
    }
}

std::vector<std::shared_ptr<Circle>> ShareCircles(const std::vector<std::shared_ptr<Curve>>& curves)
{
    std::vector<std::shared_ptr<Circle>> circles;
    circles.reserve(curves.size());

    for (const auto& curve : curves)
    {
        if (typeid(*curve.get()) == typeid(Circle))
            circles.emplace_back(std::static_pointer_cast<Circle>(curve));
    }

    return circles;
}

void PrintCirclesRadius(const std::vector<std::shared_ptr<Circle>>& circles)
{
    std::cout << std::endl << "Circles raiduses:" << std::endl;
    for (const auto& circle : circles)
    {
        std::cout << circle->GetRadius() << " " ;
    }

    std::cout << std::endl;
}

int main()
{
    const std::vector<std::shared_ptr<Curve>> curves = GenerateCurves(TEST_COUNT);
    PrintCurvesPoints(curves, TEST_ANGLE);
    PrintCurvesDerivativesValue(curves, TEST_ANGLE);

    std::vector<std::shared_ptr<Circle>> circles = ShareCircles(curves);
    std::sort(circles.begin(), circles.end(), [](const auto& left, const auto& right){ return left->GetRadius() < right->GetRadius();});

    PrintCirclesRadius(circles);

    const double total = std::accumulate(circles.begin(), circles.end(), 0., [] (double sum, const auto& circle ){return circle->GetRadius() + sum;});

    std::cout << "Circles radius sum: " << total << std::endl;

    return 0;
}
