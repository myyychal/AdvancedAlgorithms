#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Point.h"

using namespace std;

bool isInCircle(Point middlePoint, int radius, Point chosenPoint);

int pmain() {

    srand(time(NULL));

    cout << "Radius: " << endl;

    int radius;

    cin >> radius;

    Point *middlePoint = new Point(radius, radius);

    cout << "Number of points: " << endl;

    int noOfPoints;

    cin >> noOfPoints;

    int howManyInside = 0;

    for (int i=0; i<noOfPoints; i++){
        Point *newPoint = Point::getRandomPoint(0, 2*radius);
        if (isInCircle(*middlePoint, radius, *newPoint)){
            howManyInside++;
        }
        delete newPoint;
    }

    float ratio = (float)howManyInside/(float)noOfPoints;

    cout << 4*ratio << endl;

    return 0;
}

bool isInCircle(Point middlePoint, int radius, Point chosenPoint){
    long xDiff = chosenPoint.x - middlePoint.x;
    long yDiff = chosenPoint.y - middlePoint.y;
    long diffPowered = xDiff*xDiff + yDiff*yDiff;
    if (diffPowered <= radius*radius){
        return true;
    } else {
        return false;
    }
}