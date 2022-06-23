/*
Description

Please design a class Point that represents a point on the plane.

The Point class has two private data members x and y representing a position on the plane, where x and y are floating point numbers.

Create a default constructor that sets x and y to 0.

Create a constructor that takes two floating-point arguments, and sets x and y in that order.

Create a public function member printPoint that will output in the format "(x, y)".

Create public function members getX setX getY setY to access data members x and y.

Please create a public function member getDistance, the function has a parameter of type Point, and will return a floating point number representing the distance between two points.

Please design a class Segment to represent a line segment on the plane.

The Segment class has two private data members point1 and point2 representing the two endpoints of the line segment.

Create a preset constructor to preset the two endpoints at (0, 0).

Create a constructor that takes two Point objects as parameters to set point1 and point2.

Please design the following function members

float getLength(); // no parameters, returns the length of the line segment

Please design a class Point represent a point on plane coordinates.

Give this class two private data member x and y represent the location of the point, x and y are float type.

Create a default constructor to set x and y to 0.

Create a constructor with two float parameter to set x and y.

Create a public function member printPoint to display as the format like "(x, y)"

Create public function member getX, setX, getY, setY to access the data member x and y.

Create a public function member getDistance with one Point type parameter, return a float type value represent the distance of two point.

Please design a class Segment represent a segment on plane coordinates.

Give this class two private data member point1 and point2 represent the endpoint of this segment.

Create a default constructor to set the both endpoint to (0, 0).

Create a constructor with two Point object as parameter to set two endpoint.

Implement the following function member

float getLength(); //No parameter, return the length of the segment.

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

int main()
{
    Point p1(5, 10);
    Point p2(5, 5);
    Point p3;

    p1.printPoint();
    p2.printPoint();
    p3.printPoint();

    p3.setX(5);
    p3.setY(10.11);

    p3.printPoint();

    cout << p1.getDistance(p2) << endl;
    cout << p2.getDistance(p1) << endl;

    cout << p1.getDistance(p2) << endl;

    Segment seg1;
    Segment seg2(p1, p2);

    cout << seg1.getLength() << endl;
    cout << seg2.getLength() << endl;

    return 0;
}
