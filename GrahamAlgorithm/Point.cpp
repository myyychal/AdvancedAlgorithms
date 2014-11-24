#include "Point.h"

Point::Point(){
    this->x = 0;
    this->y = 0;
    this->label = "";
}

Point::Point(float x, float y){
    this->x = x;
    this->y = y;
    this->label = "";
}

Point::Point(float x, float y, std::string label){
    this->x = x;
    this->y = y;
    this->label = label;
}

float Point::calculateAngleRelativeToOrigin()const {
    return (atan2(this->y, this->x)*180)/PI;
}

float Point::calculateAngleRelativeToPoint(Point p) {
    float deltaY = this->y - p.y;
    float deltaX = this->x - p.x;
    return atan2(deltaY, deltaX) * 180 / PI;
}

void Point::normalizeToPoint(Point p) {
    this->x -= p.x;
    this->y -= p.y;
}

float Point::calculateRadiusVector()const {
    return sqrt(pow(this->x, 2)+pow(this->y,2));
}

bool operator== (const Point &cP1, const Point &cP2) {
    return (cP1.x == cP2.x &&
            cP1.y == cP2.y);
}

bool operator!= (const Point &cP1, const Point &cP2) {
    return !(cP1 == cP2);
}

bool operator> (const Point &cC1, const Point &cC2) {
    if (cC1.y > cC2.y){
        return true;
    } else if (cC1.y == cC2.y){
        if (cC1.x > cC2.x){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator<= (const Point &cC1, const Point &cC2) {
    if (cC1.y <= cC2.y){
        return true;
    } else {
        return false;
    }
}

bool operator< (const Point &cC1, const Point &cC2) {
    if (cC1.y < cC2.y){
        return true;
    } else if (cC1.y == cC2.y){
        if (cC1.x < cC2.x){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator>= (const Point &cC1, const Point &cC2) {
    if (cC1.y >= cC2.y){
        return true;
    } else {
        return false;
    }
}