/*
Description

Please write a program to read in a floating point number and output it.

Input

For each test case, there will be multiple floating point number as input.

Output

Display to third decimal place.

Sample Input 1 
123.2345
1.123
51.456778

Sample Output 1
123.235
1.123
51.457
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float var;
    float input[100];
    int counter = 0;

    while (cin >> var)
    {
        input[counter++] = var;
    }

    for (int i = 0; i < counter; i++)
    {
         cout << fixed << setprecision(3) << round(input[i] * 1000) / 1000 << endl;
    }
    
    return 0;
}