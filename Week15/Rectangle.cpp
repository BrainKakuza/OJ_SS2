/*
Description

Please reference w15Q2 create a class Rectangle.

class Rectangle : public Shape
{
public:
  Rectangle(Segment *);
  float getArea();
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

// class Point
// {
// private:
//     float x;
//     float y;

// public:
//     Point();
//     Point(float a, float b);
//     void printPoint();
//     float getX();
//     float setX(float c);
//     float getY();
//     float setY(float d);
//     float getDistance(Point e);
// };
// class Segment
// {
// private:
//     Point point1;
//     Point point2;

// public:
//     Segment();
//     Segment(Point p1, Point p2);
//     float getLength();
// };
// class Shape
// {
// public:
//     Shape();
//     Shape(Segment *, int); // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
//     virtual float getArea() = 0;
//     float getPerimeter();
//     Segment &getSeg(int index)
//     {
//         return seg[index];
//     }

// private:
//     Segment seg[10];
//     int edgeCount;
// };
// class Square : public Shape
// {
// public:
//     Square(Segment *seg) : Shape(seg, 4)
//     {
//     }
//     float getArea()
//     {
//         return seg[0].getLength() * seg[0].getLength();
//     }
// };
// class Rectangle : public Shape
// {
// public:
//     Rectangle(Segment *);
//     float getArea();
// };
