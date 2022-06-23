/*
Description

Please overloading these operate><+-=, in the "Lab of programming(2) week3Q1 coordinate"

>: a.x > b.x & a.y > b.y

<: a.x < b.x & a.y < b.y

+: a.x + b.x & a.y + b.y

-: a.x - b.x & a.y - b.y

=: a.x = b.x & a.y = b.y

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

 	//Overloading the > operation
    bool operator > (const Coordinate &b)
    {
        if (x > b.x && y > b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

  	//Overloading the < operation
    bool operator < (const Coordinate &b)
    {
        if (x < b.x && y < b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

  	//Overloading the + operation
    const Coordinate operator + (const Coordinate &b)
    {
        int sumX = x + b.x;
        int sumY = y + b.y;

        return Coordinate(sumX , sumY);
    }

  	//Overloading the - operation
    const Coordinate operator - (const Coordinate &b)
    {
        int minusX = x - b.x;
        int minusY = y - b.y;

        return Coordinate(minusX , minusY);
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
    void showCoordInfo() const
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