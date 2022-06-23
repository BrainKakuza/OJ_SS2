/*
Description

A square number is an integer number whose square root is also an integer. For example 1, 4, 81 are

some square numbers. Given two numbers a and b you will have to find out how many square numbers

are there between a and b (inclusive).

Input

The input file contains at most 201 lines of inputs. Each line contains two integers a and b (0 < a ≤

b ≤ 100000). Input is terminated by a line containing two zeroes. This line should not be processed.

Output

For each line of input produce one line of output. This line contains an integer which denotes how

many square numbers are there between a and b (inclusive).

Sample Input 1 
1 4
1 10
0 0

Sample Output 1
2
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a , b;
    int squareNum = 0;

    while (1)
    {
        cin >> a >> b;

        if(a == 0 && b == 0)
        {
            break;
        }

        for (int i = a; i <= b; i++)
        {
            double square = sqrt(i);
            if(square - floor(square) == 0)
            {
                squareNum++;
            }
        }

        cout << squareNum << endl;
        
        squareNum = 0;

    }

    return 0;
}