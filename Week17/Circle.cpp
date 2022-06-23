/*
Description

Please reference w15Q2 create a class Circle.

class Circle : public Shape
{
public:
  Circle (float r);
  float getArea();
  float getPerimeter();
};

You may need define new data member in class Circle

pi = 3.141592

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

    Shape(Segment *s, int count) : seg(s), edgeCount(count); // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
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

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r) : Shape(), radius(r) {}
    float getArea()
    {
        return 3.141592 * radius * radius;
    }

    float getPerimeter()
    {
        return 2 * 3.141592 * radius;
    }
};
