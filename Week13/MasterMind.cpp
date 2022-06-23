/*
Description

MasterMind is a game for two players. One of them, Designer, selects a secret code. The other, Breaker,

tries to break it. A code is no more than a row of colored dots. At the beginning of a game, the players

agree upon the length N that a code must have and upon the colors that may occur in a code.

In order to break the code, Breaker makes a number of guesses, each guess itself being a code. After

each guess Designer gives a hint, stating to what extent the guess matches his secret code.

In this problem you will be given a secret code s1 . . . sn and a guess g1 . . . gn, and are to determine

the hint. A hint consists of a pair of numbers determined as follows.

A match is a pair (i, j), 1 ≤ i ≤ n and 1 ≤ j ≤ n, such that si = gj . Match (i, j) is called strong

when i = j, and is called weak otherwise. Two matches (i, j) and (p, q) are called independent when

i = p if and only if j = q. A set of matches is called independent when all of its members are pairwise

independent.

Designer chooses an independent set M of matches for which the total number of matches and the

number of strong matches are both maximal. The hint then consists of the number of strong followed

by the number of weak matches in M. Note that these numbers are uniquely determined by the secret

code and the guess. If the hint turns out to be (n, 0), then the guess is identical to the secret code.

Input

The input will consist of data for a number of games. The input for each game begins with an integer

specifying N (the length of the code). Following these will be the secret code, represented as N integers,

which we will limit to the range 1 to 9. There will then follow an arbitrary number of guesses, each

also represented as N integers, each in the range 1 to 9. Following the last guess in each game will be

N zeroes; these zeroes are not to be considered as a guess.

Following the data for the first game will appear data for the second game (if any) beginning with a

new value for N. The last game in the input will be followed by a single ‘0’ (when a value for N would

normally be specified). The maximum value for N will be 1000.

Output

The output for each game should list the hints that would be generated for each guess, in order, one hint

per line. Each hint should be represented as a pair of integers enclosed in parentheses and separated by

a comma. The entire list of hints for each game should be prefixed by a heading indicating the game

number; games are numbered sequentially starting with 1. Look at the samples below for the exact

format.


Sample Input 1 
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0

Sample Output 1
Game 1:
(1,1)
(2,0)
(1,2)
(1,2)
(4,0)
Game 2:
(2,4)
(3,2)
(5,0)
(7,0)
*/

#include <iostream>
#include <cstring>
using namespace std;
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int code[1001], guess[1001], same[10], a[10], b[10];
    int n, sn, dn, g = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << "Game " << g++ << ":" << endl;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> code[i];
            a[code[i]]++;
        }

        while (1)
        {
            memset(b, 0, sizeof(b));
            memset(same, 0, sizeof(same));
            sn = 0;
            dn = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> guess[i];
                b[guess[i]]++;
            }

            if (guess[0] == 0)
                break;
            for (int i = 0; i < n; i++)
            {
                if (code[i] == guess[i])
                {
                    same[code[i]]++;
                }
            }

            for (int i = 1; i < 10; i++)
            {
                sn = sn + same[i];
                dn = dn + min(a[i], b[i]) - same[i];
            }

            cout << "(" << sn << "," << dn << ")" << endl;
        }
    }
}