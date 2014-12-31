#include <string>
#include <cmath>

#define PI 3.14159265358979323846

class Point {
public:
    int x;
    int y;
    std::string label;

public:
    Point();
    Point(int x, int y);
    Point(int x, int y, std::string label);

    static Point* getRandomPoint(int from, int to);

    friend bool operator== (const Point &cP1, const Point &cP2);
    friend bool operator!= (const Point &cP1, const Point &cP2);
    friend bool operator> (const Point &cC1, const Point &cC2);
    friend bool operator<= (const Point &cC1, const Point &cC2);
    friend bool operator< (const Point &cC1, const Point &cC2);
    friend bool operator>= (const Point &cC1,const Point &cC2);
};