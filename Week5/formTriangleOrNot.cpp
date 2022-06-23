/*
Description

class Point
{
public:
	float x, y;
};

class Segment
{
public:
	Segment()
	{
	}
	Segment(Point _a, Point _b)
	{
		a = _a;
		b = _b;
	}
	Point getPointA() const
	{
		return a;
	}
	Point getPointB() const
	{
		return b;
	}
	void setPoint(Point _a, Point _b) const
	{
		a = _a;
		b = _b;
	}
	float getLength() const
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	float getDistance(const Point &a) const // the height from point to the line which segment lie on.
        {
          //todo
        }
private:
	Point a, b;
};

class Triangle
{
public:
	Triangle(Segment s1, Segment s2, Segment s3)
	{
		seg1 = s1;
		seg2 = s2;
		seg3 = s3;
	}
	static bool isTriangle(Segment , Segment , Segment ) 
        //to determine if three segment can construct a triangle. they must overlap at the endpoint to construct a triangle.
        {
          //todo
        }
	float getArea() const //return the area of triangle
        {
          //todo
        }	
private:
	Segment seg1, seg2, seg3;
};

Please finish getDistance, getArea and isTriangle.

Input
None

Output
None

Sample Input 1 
None

Sample Output 1
None
*/

#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    float x, y;
};

class Segment
{
public:
    Segment()
    {
    }
    Segment(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
    Point getPointA() const
    {
        return a;
    }
    Point getPointB() const
    {
        return b;
    }
    void setPoint(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
    float getLength() const
    {
        return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
    }

    float getDistance(const Point &c) const // the height from point to the line which segment lie on.
    {
        float x0 = c.x;
        float y0 = c.y;
        float x1 = a.x;
        float y1 = a.y;
        float x2 = b.x;
        float y2 = b.y;

        // formual to get a distance
        float distance = fabs(((x2 - x1) * (y1 - y0)) - ((x1 - x0) * (y2 - y1))) / sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        return distance;
    }

private:
    Point a, b;
};

class Triangle
{
public:
    Triangle(Segment s1, Segment s2, Segment s3)
    {
        this->seg1 = s1;
        this->seg2 = s2;
        this->seg3 = s3;
    }
    static bool isTriangle(Segment s1, Segment s2, Segment s3)
    // to determine if three segment can construct a triangle. they must overlap at the endpoint to construct a triangle.
    {
        float x1 = s1.getPointA().x;
        float y1 = s1.getPointA().y;
        float x2 = s1.getPointB().x;
        float y2 = s1.getPointB().y;

        float x3 = s2.getPointA().x;
        float y3 = s2.getPointA().y;
        float x4 = s2.getPointB().x;
        float y4 = s2.getPointB().y;

        float x5 = s3.getPointA().x;
        float y5 = s3.getPointA().y;
        float x6 = s3.getPointB().x;
        float y6 = s3.getPointB().y;

        float pointsX[6][6] = {{x1 , 1}, {x2 , 1}, {x3 , 1}, {x4 , 1}, {x5 , 1}, {x6 , 1}};
        float pointsY[6][6] = {{y1 , 1}, {y2 , 1}, {y3 , 1}, {y4 , 1}, {y5 , 1}, {y6 , 1}};

        // Check of X coordinates
        int countX = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if(pointsX[i][0] == pointsX[j][0] && pointsX[i][1] && pointsX[j][1] && i != j)
                {
                    pointsX[i][1] = 0;
                    pointsX[j][1] = 0;
                    countX++;

                    if(countX == 3)
                    {
                        break;
                    }
                }
            }
        }

        // Check of X coordinates
        int countY = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if(pointsY[i][0] == pointsY[j][0] && pointsY[i][1] && pointsY[j][1] && i != j)
                {
                    pointsY[i][1] = 0;
                    pointsY[j][1] = 0;
                    countY++;

                    if(countY == 3)
                    {
                        break;
                    }
                }
            }
        }

        if(countX == countY)
        {
            //cout << "1" << endl;
            return true;
        }else
        {
            //cout << "0" << endl;
            return false;
        }


    }
    float getArea() const // return the area of triangle
    {
        if (isTriangle(seg1, seg2, seg3))
        {
            float length01 = seg1.getLength();
            float length02 = seg2.getLength();
            float length03 = seg3.getLength();

            float semiperimeter = (length01 + length02 + length03) / 2;

            float area = sqrt(semiperimeter * (semiperimeter - length01) * (semiperimeter - length02) * (semiperimeter - length03));

            //cout << area << endl;
            return area;
        }else
        {
            return 0;
        }
    }

private:
    Segment seg1, seg2, seg3;
};

int main()
{
    Point p1;
    p1.x = 20;
    p1.y = 15;
    Point p2;
    p2.x = 10;
    p2.y = 5;
    Point p3;
    p3.x = 10;
    p3.y = 5;
    Point p4;
    p4.x = 30;
    p4.y = 5;
    Point p5;
    p5.x = 30;
    p5.y = 5;
    Point p6;
    p6.x = 20;
    p6.y = 15;

    Segment s1(p1, p2);
    Segment s2(p3, p4);
    Segment s3(p5, p6);

    Triangle t1(s1, s2, s3);

    t1.isTriangle(s1 , s2 , s3);
    t1.getArea();

    return 0;
}