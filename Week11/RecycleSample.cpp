#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
// AC,累的一比。

int main()
{

    string s[105]; // Used to save the city

    string temp; // For the convenience of input

    while (getline(cin, temp)) // First enter the city, num records the number of cities
    {

        if (temp[0] == '#')
            break;

        int num = 0;
        s[num++] = temp;
        while (getline(cin, s[num]))
        {
            if (s[num][0] == 'e')
                break;
            else
            {
                ++num;
            }
        }

        if (num == 1)
            cout << num << endl; // When only one line is input, output 1 directly, do not follow up
        else
        {

            char a[105][6]; // Used to simplify string,
            // For example, a[i][0] records the character corresponding to r in s[i], and a[i][1] records s[i] ] in the character corresponding to o, a[i][2] records the character corresponding to y in s[i]
            // a[i][3] records the character corresponding to g in s[i], a[i][4 ] Record the character corresponding to b;
            // For example, s[i]=”r/P,o/G,y/S,g/A,b/N”, then a[i]=”PGSAN”;

            for (int i = 0; i != num; ++i)
            {
                int j = s[i].find('r');
                a[i][0] = s[i][j + 2];

                j = s[i].find('o');
                a[i][1] = s[i][j + 2];

                j = s[i].find('y');
                a[i][2] = s[i][j + 2];

                j = s[i].find('g');
                a[i][3] = s[i][j + 2];

                j = s[i].find('b');
                a[i][4] = s[i][j + 2];

            }
            int result = 1000, pos = 0;
            for (int i = 0; i != num; ++i) // for each a[i], see if the hold a[i] does not change, how many times does all other a[j] need to be changed in the corresponding position
            {
                int result1 = 0; // When recording a[i] does not change, how many times to change other cities
                for (int j = 0; j != num;)
                {
                    if (j == i)
                        ++j; // When j==i, no need to process
                    else
                    {
                        for (int k = 0; k != 5; ++k)
                        {
                            if (a[j][k] != a[i][k])
                                ++result1;
                        }
                        ++j;
                    }
                }
                if (result > result1)
                {
                    result = result1;
                    pos = i;
                }
            }
            cout << pos + 1 << endl;
        }
    }
    return 0;
}