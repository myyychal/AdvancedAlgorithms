#include <string>
#include <cmath>

#define PI 3.14159265358979323846

class Point {
public:
    float x;
    float y;
    std::string label;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, std::string label);
    float calculateAngleRelativeToOrigin()const;
    float calculateAngleRelativeToPoint(Point p);
    void normalizeToPoint(Point p);
    float calculateRadiusVector()const;

    friend bool operator== (const Point &cP1, const Point &cP2);
    friend bool operator!= (const Point &cP1, const Point &cP2);
    friend bool operator> (const Point &cC1, const Point &cC2);
    friend bool operator<= (const Point &cC1, const Point &cC2);
    friend bool operator< (const Point &cC1, const Point &cC2);
    friend bool operator>= (const Point &cC1,const Point &cC2);
};