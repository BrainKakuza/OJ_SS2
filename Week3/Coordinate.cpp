/*
Description

Please design a class to represent the "coordinate" in the plane.

Your class must have 2 private members, named "x" and "y". Both of them are integers.

Please provide 5 public methods

int getX(): return the value ofx.
int getY(): return the value ofy.
void setX(int val): writevaltox.
void setY(int val): writevaltoy.
void showCoordInfo(): Out put the data in format(x, y)with a line break wherexandyshould be replaced by values of current data, e.g.,(2, 3).
and 3 constructors

default constructor: Setxandyto 0.
copy constructor: Let all data members same to the source object.
coordinate(int X, int Y): set the values to correspond members.

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
  	//Default Constructure
    Coordinate(){
        x = 0;
        y = 0;
    }

  	//Copy Constructure
    Coordinate(const Coordinate &b){
        x = b.x;
        y = b.y;
    }
  
	//Constructure that set the value
    Coordinate(int X , int Y){
        x = X;
        y = Y;
    }
  
	//Set the x value method  
    void setX(int val){
        x = val;
    }

  	//Set the y value method  
    void setY(int val){
        y = val;
    }

    //Print coordinate mehthod
  	void showCoordInfo(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

  	// get x method
    int getX(){
        return x;
    }

  	// get y method
    int getY(){
        return y;
    }
private:
  	int x;
  	int y;
};
