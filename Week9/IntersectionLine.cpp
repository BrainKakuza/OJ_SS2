/*s
Description

In a 2-D Cartesian space, a straight line segment A is defined by two points A0 = (x0, y0), A1 = (x1, y1).
The intersection of line segments A and B (if there is one), together with the initial four points
, defines four new line segments. In Figure, the intersection P between lines B and C defines four new segments. As a result
, the total amount of line segments after the evaluation of intersections is five. Given an initial set of lines segments
, determine the number of line segments resulting from the evaluation of all the possible intersections. It is assumed
, as a simplification, that no coincidences may occur between coordinates of singular points (intersections or end points).

image.png

Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following
, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 
The first line of the input contains the integer number N of line segments. 
Each of the following N lines contains four integer values x0 y0 x1 y1, separated by a single space, that define a line segment.

Figure corresponds to the sample below.

image.png

Output
For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. The integer number of lines segments after all the possible intersections are evaluated.


Sample Input 1 
1
5
3 1 3 8
4 1 4 8
2 4 9 4
8 7 5 7
5 6 10 1

Sample Output 1
11
*/

#include <iostream>
#include <cmath>

using namespace std;

int totalSegment = 0;

class Point
{
private:
    float x, y;

public:
    Point(float _x, float _y) : x(_x), y(_y) {}

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
    Point pointF, pointS;

public:
    Segment(Point p1, Point p2) : pointF(p1), pointS(p2) {}

    bool betweenOrNot(float x1, float y1, float x2, float y2, float intersectX, float intersectY)
    {
        float longX;
        float shortX;
        float topY;
        float lowY;

        // longX = max(x1, x2);
        // shortX = min(x1, x2);

        if (x1 > x2)
        {
            longX = x1;
            shortX = x2;
        }
        else if (x1 < x2)
        {
            longX = x2;
            shortX = x1;
        }else
        {
            longX = x2;
            shortX = x2;
        }

        if (y1 > y2)
        {
            topY = y1;
            lowY = y2;
        }
        else if (y1 < y2)
        {
            topY = y2;
            lowY = y1;
        }else
        {
            topY = y2;
            lowY = y2;
        }

        if (
            (shortX <= intersectX && intersectX <= longX) &&
            (lowY <= intersectY && intersectY <= topY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IntersectionOrNot(Segment seg)
    {
        float x1 = pointF.getX();
        float y1 = pointF.getY();
        float x2 = pointS.getX();
        float y2 = pointS.getY();

        float x3 = seg.pointF.getX();
        float y3 = seg.pointF.getY();
        float x4 = seg.pointS.getX();
        float y4 = seg.pointS.getY();

        float intersectX, intersectY;

        float dx12 = (x2 - x1);
        float dx34 = (x4 - x3);

        if (dx12 == 0 && dx34 == 0) return false;

        // Find the first slope and b1
        float slope1 = (y2 - y1) / dx12;
        float b1 = y2 - (slope1 * x2);

        // Find the second slope and b2
        float slope2 = (y4 - y3) / dx34;
        float b2 = y4 - (slope2 * x4);

        if (slope1 == slope2) return false;

        float D = ((x1 - x2)*(y3 - y4)) - ((y1 - y2)*(x3 - x4));

        intersectX = ((x1*y2 - y1*x2)*(x3-x4) - (x1 - x2)*(x3*y4 - y3*x4)) / D;
        intersectY = ((x1*y2 - y1*x2)*(y3-y4) - (y1 - y2)*(x3*y4 - y3*x4)) / D;

        //cout << "Intersection with segment at (" << intersectX << ", " << intersectY << ") - "; 

        if (betweenOrNot(x1, y1, x2, y2, intersectX, intersectY) && betweenOrNot(x3, y3, x4, y4, intersectX, intersectY))
        {
            //cout << "in bounds\n";
            return true;
        }
        else
        {
        //cout << "not in bounds\n";
            return false;
        }
    }
};

int main(void)
{
    int testCase;
    int counter = 0;

    cin >> testCase;

    int totalResult[testCase];

    while (testCase--)
    {
        int totalInput;

        cin >> totalInput;

        float segment[totalInput][4];

        for (int i = 0; i < totalInput; i++)
        {
            totalSegment++;

            cin >> segment[i][0] >> segment[i][1] >> segment[i][2] >> segment[i][3];

            Point p1(segment[i][0], segment[i][1]);
            Point p2(segment[i][2], segment[i][3]);

            Segment seg(p1, p2);

            for (int j = i - 1; j >= 0; j--)
            {
                bool result = false;

                Point p3(segment[j][0], segment[j][1]);
                Point p4(segment[j][2], segment[j][3]);

                Segment comSeg(p3, p4);

                result = seg.IntersectionOrNot(comSeg);

                if (result)
                {
                    totalSegment += 2;
                }
            }

        }

        cout << totalSegment << endl << endl;

        totalSegment = 0;
    }

    return 0;
}