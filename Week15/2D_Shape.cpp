/*
Description

Please reference W15Q1 create a class Shape represent a 2D shape.

class Shape
{
public:
  Shape();
  Shape(Segment *, int ); // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
  virtual float getArea() = 0;
  float getPerimeter();
private:
  Segment [10];
  int edgeCount;
};

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>
#include <math.h>

using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(float a, float b) : x(a), y(b) {}

    void printPoint()
    {
        cout << "\"(" << x << ", " << y << ")\"" << endl;
    }

    float getDistance(Point &point)
    {
        return sqrt(pow(x - point.getX(), 2) + pow(y - point.getY(), 2));
    }

    float setX(float val)
    {
        x = val;
        return 0;
    }

    float setY(float val)
    {
        y = val;
        return 0;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }
};

class Segment
{
private:
    Point point1;
    Point point2;

public:
    Segment()
    {
        point1.setX(0.0);
        point1.setY(0.0);
        point2.setY(0.0);
        point2.setY(0.0);
    }

    Segment(Point p1, Point p2) : point1(p1), point2(p2) {}

    float getLength()
    {
        return sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
    }
};

class Shape
{
public:
    Shape();
    Shape(Segment *_seg, int ); // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
    virtual float getArea() = 0;
    float getPerimeter();
    Segment &getSeg(int index)
    {
        return seg[index];
    }

private:
    Segment seg[10];
    int edgeCount;
};
