/*
Given a function F,

Assure that we have a function F,

image.png

Please follow the instructions below to design and implement Class F:

1. Define two private members a and r. Both a and r belong to the double type.

2. Define a constructor with two parameters, and assign values ​​to a and r with the two parameters in sequence.

3. Define a function "at" of double type, "at" has a parameter representing x, and "at" will return the value of F(x).

4. Define a function "S" of double * type. If S(x) exists, "S" will return a pointer to the value of S(x)
, and if S(x) does not exist, it will return nullptr.

Please define and implement a class F as followingdescription.

1.Define two private members aand r in double type.

2.Define a constructor with two parameterto set a and r as given order.

3.Define a function ‘at’ with oneparameter represent x and return the value F(x) in double type.

4.Define a function ‘S’ with noparameter and return a pointer point to value S(x) in double * type if S(x)exist or nullptr if not.

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

class F
{
private:
    double a, r;

public:
    F(double _a, double _r) : a(_a), r(_r) {}

    double at(int x)
    {
        return a * pow(r, x);
    }

    double * S()
    {
        if (r > -1 && r < 1)
        {
            double * answer = new double;
            double result = a / (1 - r);
            *answer = result;
            return answer;
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    int j, k;
    double a, r;
    cin >> a >> r;
    F f(a, r);
    for (k = 0; k < 3; k++)
        printf("%.2lf\n", f.at(k));
    double *s = f.S();
    if (s == NULL)
        printf("NULL\n");
    else
        printf("%.2lf\n", *s);
}
