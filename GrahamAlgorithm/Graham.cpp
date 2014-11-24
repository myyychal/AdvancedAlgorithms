#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>
#include "Point.h"

using namespace std;

enum DIRECTION {left = -1, same = 0, right = 1};

void printPoint(Point p);
void printPoints(vector<Point> points);
vector<Point> changePointsCoordinates(Point p, vector<Point> points);
Point getSecondPointFromStack(stack<Point> stack);
Point getStartPoint(vector<Point> points);
bool compareAngles(const Point &cC1, const Point &cC2);
DIRECTION getDirection(const Point &p1, const Point &p2, const Point &p3);

int main(int argc, char *argv[]){

    int MAX;
    int RAND_RANGE;

    vector<Point> points;

    cout << "(R)andom, (M)anual or (F)ile?" << endl;
    char key;
    cin >> key;
    if (tolower(key) == 'r'){
        cout << "How many points?" << endl;
        cin >> MAX;
        cout << "What range? \n(-RANGE; RANGE)" << endl;
        cin >> RAND_RANGE;

        // initialize vector of Points with data
        for (int i=0; i<MAX; i++){
            Point *point = new Point(-RAND_RANGE + rand() % (2* RAND_RANGE),RAND_RANGE + rand() % (2* RAND_RANGE),string (1, (char)(i+65)));
            points.push_back(*point);
        }
    } else if (tolower(key) == 'm'){
        float x,y;
        int number;
        cout << "How many points?" << endl;
        cin >> number;
        for (int i=0; i< number; i++){
            cout << "Point nr: " << i << endl;
            cout << "point.x = ";
            cin >> x;
            cout << endl << "point.y = ";
            cin >> y;
            Point *point = new Point(x,y);
            points.push_back(*point);
        }
    } else if (tolower(key) == 'f'){
        string line;
        ifstream myfile("points.txt");
        if (myfile.is_open()) {
            while ( getline (myfile,line) ) {
                string xS = line.substr(line.find('{')+1, line.find(",")-1);
                string yS = line.substr(line.find(",")+1, line.find('}')-1);
                int x = atoi(xS.c_str());
                int y = atoi(yS.c_str());
                Point *point = new Point(x,y);
                points.push_back(*point);
            }
            myfile.close();
        } else {
            cout << "Could not open the file.";
        }
    }

    if (points.size() == 0){
        return -1;
    }

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    // MATLAB printout
    cout << "x = [";
    for (int i=0; i<points.size(); i++){
        cout << points.at(i).x << ", ";
    }
    cout << "];\n";

    // MATLAB printout
    cout << "y = [";
    for (int i=0; i<points.size(); i++){
        cout << points.at(i).y << ", ";
    }
    cout << "];\n";

    /*
    cout << "Original points: " << endl;
    printPoints(points);
    cout << endl;
    */

    Point firstPoint = getStartPoint(points);

    /*
    cout << "Chosen as first point: " << endl;
    printPoint(firstPoint);
    cout << endl;
    */

    vector<Point> newPoints = changePointsCoordinates(firstPoint, points);
    sort(newPoints.begin(), newPoints.end(), compareAngles);
    firstPoint.x = -firstPoint.x;
    firstPoint.y = -firstPoint.y;
    points = changePointsCoordinates(firstPoint, newPoints);

    /*
    cout << "Sorted points: " << endl;
    printPoints(points);
    cout << endl;
    */

    stack<Point> stack;

    if (points.size() >= 2){
        stack.push(points.at(0));
        stack.push(points.at(1));
        stack.push(points.at(2));
    } else {
        for (int i=0; i<points.size(); i++){
            stack.push(points.at(i));
        }
    }

    for (int i=2; i<points.size(); i++){
        while (stack.size() >= 2 && (getDirection(getSecondPointFromStack(stack), stack.top(), points.at(i)) == 1
                || (getDirection(getSecondPointFromStack(stack), stack.top(), points.at(i)) == 0) )){
            stack.pop();
        }
        stack.push(points.at(i));
    }

    vector<Point> chosenPoints;

    //cout << "Stack: " << endl;
    while(stack.size() != 0){
        chosenPoints.push_back(stack.top());
        //printPoint(stack.top());
        stack.pop();
    }

    chosenPoints.insert(chosenPoints.begin(), chosenPoints.at(chosenPoints.size()-1));

    // MATLAB printout
    cout << "xx = [";
    for (int i=0; i<chosenPoints.size(); i++){
        if (i != chosenPoints.size()-1){
            cout << chosenPoints.at(i).x << ", ";
        } else {
            cout << chosenPoints.at(i).x;
        }
    }
    cout << "];\n";

    // MATLAB printout
    cout << "yy = [";
    for (int i=0; i<chosenPoints.size(); i++){
        if (i != chosenPoints.size()-1){
            cout << chosenPoints.at(i).y << ", ";
        } else {
            cout << chosenPoints.at(i).y;
        }
    }
    cout << "];\n";

    cout << "plot(x,y,'*');" << endl << "hold on;" << endl <<"plot(xx,yy,'r*');" << endl << "line(xx,yy);" << endl;

    cout << "axis([min(xx)-2 max(xx)+2 min(yy)-2 max(yy)+2]);";

    return 0;
}

void printPoint(Point p){
    cout << p.label << " x: " << p.x << ", y: " << p.y << ", alfa: " << p.calculateAngleRelativeToOrigin() << endl;
}

void printPoints(vector<Point> points){
    for_each(points.begin(), points.end(), printPoint);
}

Point getStartPoint(vector<Point> points){
    Point *foundPoint = &points.at(0);
    for (int i=1; i<points.size(); i++){
        Point *startPoint = &points.at(i);
        if (*startPoint < *foundPoint){
            *foundPoint = *startPoint;
        }
    }
    return *foundPoint;
}

Point getSecondPointFromStack(stack<Point> stack){
    Point topPoint = stack.top();
    stack.pop();
    Point secondPoint = stack.top();
    return secondPoint;
}

vector<Point> changePointsCoordinates(Point p, vector<Point> points){
    vector<Point> newPoints;
    for (int i=0; i < points.size(); i++){
        Point currentPoint = points.at(i);
        currentPoint.normalizeToPoint(p);
        newPoints.push_back(currentPoint);
    }
    return newPoints;
}

bool compareAngles(const Point &cC1, const Point &cC2) {
    float c1Angle = cC1.calculateAngleRelativeToOrigin();
    float c2Angle = cC2.calculateAngleRelativeToOrigin();
    if (c1Angle != c2Angle){
        return c1Angle < c2Angle;
    } else {
        return cC1.calculateRadiusVector() < cC2.calculateRadiusVector();
    }
}

DIRECTION getDirection(const Point &p1, const Point &p2, const Point &p3){
    float det = p1.x*p2.y + p1.y*p3.x + p2.x*p3.y - p3.x*p2.y - p3.y*p1.x - p2.x*p1.y;
    if (det < 0){
        return DIRECTION::right;
    } else if (det > 0){
        return DIRECTION::left;
    } else {
        return DIRECTION::same;
    }
}