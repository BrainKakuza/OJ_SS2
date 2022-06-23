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

  //return the area of this triangle
  //回傳三角形的面積
  double getArea()
  {
  }

  //override operator+ with one parameter which is also a object of Triangle and return the sum of their area.
  //多載+號，相加兩個Triangle物件，並回傳兩個Triangle的面積和。
  operator+
private:
  Point point[3];
};

int main()
{
  double x1, y1, x2, y2, x3, y3;
  std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
  Point a(x1, y1), b(x2, y2), c(x3, y3);
  std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
  std::cout<<fixed<<setprecision(2);
  Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
  Triangle t1(a, b, c), t2(a2, b2, c2);
  std::cout<<t1 + t2<<std::endl;
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
#include <iomanip>

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

    // return the area of this triangle
    //回傳三角形的面積
    double getArea()
    {
        double length01 = sqrt(pow(point[0].x - point[1].x , 2) + pow(point[0].y - point[1].y , 2));
        double length02 = sqrt(pow(point[1].x - point[2].x , 2) + pow(point[1].y - point[2].y , 2));
        double length03 = sqrt(pow(point[0].x - point[2].x , 2) + pow(point[0].y - point[2].y , 2));

        //Angle of triangle with 3 sides formula
        double semiperimeter = (length01 + length02 + length03)/2;

        return sqrt(semiperimeter * (semiperimeter - length01) * (semiperimeter - length02) * (semiperimeter - length03));

    }

    // override operator+ with one parameter which is also a object of Triangle and return the sum of their area.
    //多載+號，相加兩個Triangle物件，並回傳兩個Triangle的面積和。
    double operator + (Triangle tri)
    {
        return getArea() + tri.getArea();
    }
private : 
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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << t1.getArea() << std::endl;
    std::cout << t2.getArea() << std::endl;
    std::cout << t1 + t2 << std::endl;
}
