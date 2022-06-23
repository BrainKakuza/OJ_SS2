/*
Description

Your new company is building a robot that can hold small lightweight objects. The robot will have

the intelligence to determine if an object is light enough to hold. It does this by taking pictures of the

object from the 6 cardinal directions, and then inferring an upper limit on the object’s weight based

on those images. You must write a program to do that for the robot.

You can assume that each object is formed from an N × N × N lattice of cubes, some of which

may be missing. Each 1 × 1 × 1 cube weighs 1 gram, and each cube is painted a single solid color. The

object is not necessarily connected.


Input
The input for this problem consists of several test cases representing different objects. Every case

begins with a line containing N, which is the size of the object (1 ≤ N ≤ 10). The next N lines are

the different N × N views of the object, in the order front, left, back, right, top, bottom. Each view

will be separated by a single space from the view that follows it. The bottom edge of the top view

corresponds to the top edge of the front view. Similarly, the top edge of the bottom view corresponds

to the bottom edge of the front view. In each view, colors are represented by single, unique capital

letters, while a period (.) indicates that the object can be seen through at that location.

Input for the last test case is followed by a line consisting of the number ‘0’.


Output
For each test case, print a line containing the maximum possible weight of the object, using the format

shown below.


Sample Input 1 
3
.R. YYR .Y. RYY .Y. .R.
RBY GYB BYB BYB GRB
.R. YRR .Y. RRY .R. .Y.
2
ZZ ZZ ZZ ZZ ZZ ZZ
ZZ ZZ ZZ ZZ ZZ ZZ
0

Sample Output 1
Maximum weight: 11 gram(s)
Maximum weight: 8 gram(s)
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
const int inf = 0xfffffff;
typedef long long ll;
using namespace std;

const int S = 15;
char a[S][S][S], b[S][S][S];
int N, x, y, z;

void chag(int i, int j, int k, int l)
{
    if (j == 0)
    {
        x = i;
        y = k;
        z = l;
    }
    if (j == 1)
    {
        x = i;
        y = l;
        z = N - 1 - k;
    }
    if (j == 2)
    {
        x = i;
        y = N - 1 - k;
        z = N - 1 - l;
    }
    if (j == 3)
    {
        x = i;
        y = N - 1 - l;
        z = k;
    }
    if (j == 4)
    {
        x = l;
        y = k;
        z = N - 1 - i;
    }
    if (j == 5)
    {
        x = N - 1 - l;
        y = k;
        z = i;
    }
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
                a[i][j][k] = '#';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < N; k++)
            {
                scanf("%c", &b[i][j][k]);
                if (b[i][j][k] == '.')
                {
                    for (int l = 0; l < N; l++)
                    {
                        chag(i, j, k, l);
                        a[x][y][z] = '.';
                    }
                }
            }
            getchar();
        }
    }
}

void solve()
{
    while (1)
    {
        int test = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (b[i][j][k] != '.')
                    {
                        for (int l = 0; l < N; l++)
                        {
                            chag(i, j, k, l);
                            if (a[x][y][z] == '.')
                                continue;
                            if (a[x][y][z] == '#')
                                a[x][y][z] = b[i][j][k];
                            if (a[x][y][z] == b[i][j][k])
                                break;
                            a[x][y][z] = '.';
                            test = false;
                        }
                    }
                }
            }
        }
        if (test)
            break;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (a[i][j][k] != '.')
                    ans++;
            }
        }
    }
    printf("Maximum weight: %d gram(s)\n", ans);
}

int main()
{
    // freopen("in", "r", stdin);
    while (~scanf("%d%*c", &N))
    {
        if (N == 0)
            break;
        init();
        solve();
    }
    return 0;
}