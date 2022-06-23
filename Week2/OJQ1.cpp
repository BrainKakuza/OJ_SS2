/*
Description

In C language, we using scanf and peintf for input and output. Now we promote to C++ language and use cin/cout to instead of scanf/printf.

The C code like below

image.png

will become C++ code like below.

image.png

Please using C++ language to finish the following question:

A man walks X km in Y hours  in the same direction.

What is the man's velocity inkm/hfor the journey?

Input

Input contain two number in a line and separate by a single space, first number stand for distance in km
, second number stand for time in hour.

Output

A number stand for velocity in km/h.

Sample Input 1 
7 2

Sample Output 1
3.5
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    float distance , speed ;
    cin >> distance >> speed;

    cout << distance / speed << endl;


    return 0;
}