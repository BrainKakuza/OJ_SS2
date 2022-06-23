/*
Description

//Complete the following program as described

//Finish the following code as description.

class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double x, y;
};

class Triangle
{
public:
    Triangle(Point a, Point b, Point c)
    {
        point[0] = a;
        point[1] = b;
        point[2] = c;
    }
    //override operator* with one parameter which is also a object of Triangle and return true if two triangle collision, return false if not.
    //Two triangle collision if they overlap or share the same point or segment.
    //多載 *號，如果兩個三角形有碰撞的話就回傳 true ，否則就回傳 dalse。
    //如果兩個三角形有重疊或是共用某個線段或是點的話就是兩個三角形有碰撞。
    operator*
private:
    Point point[3];
};

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
    Triangle t1(a, b, c), t2(a2, b2, c2);
    std::cout<<t1 * t2<<std::endl;
}

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
#include <cmath>

class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double x, y;
};

class Triangle
{
public:
    Triangle(Point a, Point b, Point c)
    {
        point[0] = a;
        point[1] = b;
        point[2] = c;
    }
    // override operator* with one parameter which is also a object of Triangle and return true if two triangle collision, return false if not.
    // Two triangle collision if they overlap or share the same point or segment.
    //多載 *號，如果兩個三角形有碰撞的話就回傳 true ，否則就回傳 dalse。
    //如果兩個三角形有重疊或是共用某個線段或是點的話就是兩個三角形有碰撞。
    bool operator*(Triangle triangle)
    {
        bool collide = false;

        double totalArea = fabs((point[0].x * (point[1].y - point[2].y) 
        + point[1].x * (point[2].y - point[0].y) 
        + point[2].x * (point[0].y - point[1].y))/2);

        //std::cout << totalArea << std::endl;

        for (int i = 0; i < 3; i++)
        {
            double centerX = triangle.point[i].x;
            double centerY = triangle.point[i].y;

            //std::cout << centerX << " " << centerY << std::endl;

            double areaOne = fabs((centerX * (point[0].y - point[1].y) 
            +  point[0].x * (point[1].y - centerY) 
            + point[1].x * (centerY - point[0].y))/2);

            double areaTwo = fabs((centerX * (point[1].y - point[2].y) 
            +  point[1].x * (point[2].y - centerY) 
            + point[2].x * (centerY - point[1].y))/2);

            double areaThree = fabs((centerX * (point[0].y - point[2].y) 
            +  point[0].x * (point[2].y - centerY) 
            + point[2].x * (centerY - point[0].y))/2);

            
            //std::cout << areaOne << " " << areaTwo << " " << areaThree << std::endl;

            if(totalArea == areaOne + areaTwo + areaThree)
            {
                collide = true;
                break;
            }
        }

        return collide;
        
    }

private:
    Point point[3];
};

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
    Triangle t1(a, b, c), t2(a2, b2, c2);
    std::cout << t1 * t2 << std::endl;
}