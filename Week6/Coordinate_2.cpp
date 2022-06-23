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

    bool operator>(const Coordinate &b)
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

    bool operator<(const Coordinate &b)
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

    const Coordinate operator + (const Coordinate &b)
    {
        int sumX = x + b.x;
        int sumY = y + b.y;

        return Coordinate(sumX , sumY);
    }

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

int main()
{
    Coordinate c1(5, 1);
    Coordinate c2(6, 7);
    Coordinate c3 = c1 - c2;

    cout << c3.getX() <<  " " << c3.getY() << endl;

    

    

    return 0;
}