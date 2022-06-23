/*
Description

Previous week we done the class coordinate, today please using class coordinate doing a new class "Segment".

class Segment // using two Coordinate to represent a segment

{

public:

Segment(Coordinate _a, Coordinate _b)

{
// doing
}

// return the intersection with another segment if exist, return NULL when there are no intersection.
Coordinate *getIntersection(Segment s) 

{
// doing
}

float length() // return the length of segment

{
// doing
}

Coordinate getCoordinateA() { return a; }

Coordinate getCoordinateB() { return b; }

private:

Coordinate a, b;

};

Please finish the two method getIntersection and length, and constructor.

You only need to submit the function code, do not submit the whole class.

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

class Coordinate
{
public:
    // Default Constructure
    Coordinate()
    {
        x = 0;
        y = 0;
    }

    // Copy Constructure
    Coordinate(const Coordinate &b)
    {
        x = b.x;
        y = b.y;
    }

    // Constructure that set the value
    Coordinate(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // Set the x value method
    void setX(int val)
    {
        x = val;
    }

    // Set the y value method
    void setY(int val)
    {
        y = val;
    }

    // Print coordinate mehthod
    void showCoordInfo()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // get x method
    int getX()
    {
        return x;
    }

    // get y method
    int getY()
    {
        return y;
    }

private:
    int x;
    int y;
};

class Segment
{
private:
    Coordinate a, b;

public:
    Segment(Coordinate _a, Coordinate _b)
    {
        this->a = _a;
        this->b = _b;
    }

    bool betweenOrNot(float x1, float y1, float x2, float y2, float interX, float interY)
    {
        float leftX, rightX;
        float topY, downY;

        if (x1 > x2)
        {
            rightX = x1;
            leftX = x2;
        }
        else
        {
            rightX = x2;
            leftX = x1;
        }

        if (y1 > y2)
        {
            topY = y1;
            downY = y2;
        }
        else
        {
            topY = y2;
            downY = y1;
        }

        if ((interX  >= leftX && interX <= rightX) && (interY >= downY && interY <= topY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Coordinate *getIntersection(Segment s)
    {
        float firstCoor_X = s.a.getX();
        float firstCoor_Y = s.a.getY();
        float secondCoor_X = s.b.getX();
        float secondCoor_Y = s.b.getY();

        // Find the first equation in first segment
        float dy1 = a.getY() - b.getY();
        float dx1 = a.getX() - b.getX();

        float m1 = (float)dy1 / dx1;
        float b1 = (float)a.getY() - m1 * a.getX();

        float dy2 = firstCoor_Y - secondCoor_Y;
        float dx2 = firstCoor_X - secondCoor_X;

        // Find the second equation in first segment
        float m2 = (float)dy2 / dx2;
        float b2 = (float)firstCoor_Y - m2 * firstCoor_X;

        float IntersectX = (float)(b2 - b1) / (m1 - m2);
        float IntersectY = m1 * IntersectX + b1;

        if ((m2 - m1) == 0)
        {
            return NULL;
        }
        else if (
            (betweenOrNot(a.getX(), a.getY(), b.getX(), b.getY(), IntersectX, IntersectY) && betweenOrNot(firstCoor_X, firstCoor_Y, secondCoor_X, secondCoor_Y, IntersectX, IntersectY)))
        {
            cout << IntersectX << " " << IntersectY << endl;
            Coordinate *ans = new Coordinate(IntersectX, IntersectY);
            return ans;
        }
        {
            return nullptr;
        }
    }

    float length()
    {
        //cout << sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2)) << endl;
        return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
    }
};
int main()
{
    Coordinate c1(0, 5);
    Coordinate c2(20, 5);
    Coordinate c3(10, 10);
    Coordinate c4(10, 0);

    Segment s1(c1, c2);
    Segment s2(c3, c4);

    s1.getIntersection(s2);

    return 0;
}
