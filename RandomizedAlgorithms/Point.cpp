#include <time.h>
#include <stdlib.h>
#include "Point.h"

Point::Point(){
    this->x = 0;
    this->y = 0;
    this->label = "";
}

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
    this->label = "";
}

Point::Point(int x, int y, std::string label){
    this->x = x;
    this->y = y;
    this->label = label;
}

Point* Point::getRandomPoint(int from, int to) {
    int x = rand() * to / (double)RAND_MAX + from;
    int y = rand() * to / (double)RAND_MAX + from;
    return new Point(x,y);
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