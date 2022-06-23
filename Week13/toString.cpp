/*
Description

Please design a class Convert to converting object to string. The definition of the class Convert is as follow.

class Convert
{
public:
static string toString(int );
static string toString(char );
static string toString(double );
static string tostring(Point );
};
The definition of class Point is as follow.

class Point
{
public:
int x, y;
}

Input
NONE

Output
The format of Point should be like "(X, Y)"

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Convert
{
public:
    static string toString(int n)
    {
        stringstream ss;

        ss << n;

        return ss.str();
    }
    static string toString(char c)
    {
        stringstream ss;

        ss << c;

        return ss.str();
    }
    static string toString(double d)
    {
        stringstream ss;

        ss << d;

        return ss.str();
    }
    static string toString(Point p)
    {
        stringstream ss;

        ss << "(" << p.x << ", " << p.y << ")";

        return ss.str();
    }
};
