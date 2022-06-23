/*
Description

We have a square board with 64 places, numbered from 0 to 63, see Figure 1.

There are two pieces: A king and a queen. The pair of king’s place and queen’s place is called the

state. A state is legal if the pieces are not at the same place. The king and queen move alternately.

The king can move one step in a horizontal or vertical direction, as long as it does not arrive at the

place of the queen. The queen can move one or more steps in a horizontal or vertical direction, as long

as it does not encounter the king. All these moves are called legal. Please note that the pieces may not

move diagonally.

image.png

For example, suppose we have a state with a king at place 17 and a queen at place 49, as in Figure

2. The legal moves of the king are to places 9, 16, 18, and 25 and the queen can legally move to place

25, 33, 41, 48, 50, 51, 52, 53, 54, 55, or 57. We impose, however, an extra restriction: A piece may not

move to a place where the other one can also move to. Legal moves satisfying this restriction are called

allowed. In Figure 2, all possible places the king and the queen can move to by an allowed move, are

denoted with a circle (◦) and a dot (•), respectively. In Figure 3, the king cannot move, it is locked in.

image.png

This problem requires you to write a program that does some checking related to the movement of

the queen.


Input
The input for your program resides in a text file that ends with the standard end-of-file marker. Each

line ends with the standard end-of-line marker and contains a sequence of three integers in the range

O..63, separated by one space. The first two integers denote the place of the king and the queen,

respectively. Together they form a state. The third integer denotes a new place for the queen. You

may think of it as computed by some function move queen. Your program determines whether:

• the given state is legal

• the queen’s move is legal

• the queen’s move is allowed.

Furthermore, if these requirements are met, your program determines whether the move of the queen

results in a state where the king is locked in.


Output
The output is also a textflle. For each input line, your program produces one output line with one of

the following messages:

• Illegal state

• Illegal move

• Move not allowed

• Continue

• Stop

‘Illegal state’ indicates that the given state is not legal, i.e. the pieces are at the same place.

‘Illegal move’ means that the given state is legal, but the queen’s move is illegal.

‘Move not allowed’ applies if both the given state and the queen’s move are legal, but the queen’s

move is not allowed.

Both ‘Continue’ and ‘Stop’ mean that the given state is legal and the queen’s move is allowed. If

the king can do an allowed move in the resulting state, the message is ‘Continue’, otherwise the king

is locked in and you reply ‘Stop’.


Sample Input 1 

17 17 49
17 49 56
17 49 9
17 49 17
17 49 25
17 49 33
17 49 41
17 49 49
56 48 49

Sample Output 1
Illegal state
Illegal move
Illegal move
Illegal move
Move not allowed
Continue
Continue
Illegal move
Stop
*/

#include <iostream>

using namespace std;

/*
numberAvailable
- 0 (free)
- 1 (king)
- 2(queen)
- 3(king path)
- 4(queen path)
- 5(interfere path)
- 6 (new queen spot)
- 7 (new queen path)
*/

int numberSpot[8][8];
int numberAvailable[8][8];

class board
{
public:
};

int main()
{
    int king, queen, newQueen, spotI, spotJ, spotKI, spotKJ;

    while (cin >> king >> queen >> newQueen)
    {
        int num = 0;
        
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                numberSpot[i][j] = num;
                numberAvailable[i][j] = 0;
                num++;
            }
        }

        if (king == queen)
        {
            cout << "Illegal state" << endl;
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == king)
                    {
                        spotKI = i;
                        spotKJ = j;

                        numberAvailable[i][j] = 1;

                        if (numberAvailable[i][j - 1] == 0 && j - 1 >= 0)
                        {
                            numberAvailable[i][j - 1] = 3;
                        }

                        if (numberAvailable[i][j + 1] == 0 && j + 1 < 8)
                        {
                            numberAvailable[i][j + 1] = 3;
                        }

                        if (numberAvailable[i + 1][j] == 0 && i + 1 < 8)
                        {
                            numberAvailable[i + 1][j] = 3;
                        }

                        if (numberAvailable[i - 1][j] == 0 && i - 1 >= 0)
                        {
                            numberAvailable[i - 1][j] = 3;
                        }
                    }
                }
            }

            // for (int i = 0; i < 8; i++)
            // {
            //     for (int j = 0; j < 8; j++)
            //     {
            //         cout << numberAvailable[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // cout << endl;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == queen)
                    {
                        numberAvailable[i][j] = 2;

                        for (int k = j + 1; k < 8; k++)
                        {
                            if (numberAvailable[i][k] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[i][k] == 3)
                            {
                                numberAvailable[i][k] = 5;
                            }
                            else
                            {
                                numberAvailable[i][k] = 4;
                            }
                        }

                        for (int k = j - 1; k >= 0; k--)
                        {
                            if (numberAvailable[i][k] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[i][k] == 3)
                            {
                                numberAvailable[i][k] = 5;
                            }
                            else
                            {
                                numberAvailable[i][k] = 4;
                            }
                        }

                        for (int k = i + 1; k < 8; k++)
                        {
                            if (numberAvailable[k][j] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[k][j] == 3)
                            {
                                numberAvailable[k][j] = 5;
                            }
                            else
                            {
                                numberAvailable[k][j] = 4;
                            }
                        }

                        for (int k = i - 1; k >= 0; k--)
                        {
                            if (numberAvailable[k][j] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[k][j] == 3)
                            {
                                numberAvailable[k][j] = 5;
                            }
                            else
                            {
                                numberAvailable[k][j] = 4;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == newQueen)
                    {
                        spotI = i;
                        spotJ = j;
                    }
                }
            }

            // for (int i = 0; i < 8; i++)
            // {
            //     for (int j = 0; j < 8; j++)
            //     {
            //         cout << numberAvailable[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // cout << endl;

            if (numberAvailable[spotI][spotJ] == 0 || numberAvailable[spotI][spotJ] == 1 || numberAvailable[spotI][spotJ] == 2 || numberAvailable[spotI][spotJ] == 3)
            {
                cout << "Illegal move" << endl;
            }
            else if (numberAvailable[spotI][spotJ] == 5)
            {
                cout << "Move not allowed" << endl;
            }
            else if (numberAvailable[spotI][spotJ] == 4)
            {
                numberAvailable[spotI][spotJ] = 6;

                for (int k = spotJ + 1; k < 8; k++)
                {
                    if (numberAvailable[spotI][k] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[spotI][k] = 7;
                    }
                }

                for (int k = spotJ - 1; k >= 0; k--)
                {
                    if (numberAvailable[spotI][k] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[spotI][k] = 7;
                    }
                }

                for (int k = spotI + 1; k < 8; k++)
                {
                    if (numberAvailable[k][spotJ] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[k][spotJ] = 7;
                    }
                }

                for (int k = spotI - 1; k >= 0; k--)
                {
                    if (numberAvailable[k][spotJ] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[k][spotJ] = 7;
                    }
                }

                // for (int i = 0; i < 8; i++)
                // {
                //     for (int j = 0; j < 8; j++)
                //     {
                //         cout << numberAvailable[i][j] << " ";
                //     }
                //     cout << endl;
                // }

                // cout << endl;

                if (
                    (numberAvailable[spotKI][spotKJ + 1] == 3 && spotKJ + 1 < 8) ||
                    (numberAvailable[spotKI][spotKJ - 1] == 3 && spotKJ - 1 >= 0) ||
                    (numberAvailable[spotKI + 1][spotKJ] == 3 && spotKI + 1 < 8) ||
                    (numberAvailable[spotKI - 1][spotKJ] == 3 && spotKI - 1 >= 0))
                {
                    cout << "Continue" << endl;
                }
                else
                {
                    cout << "Stop" << endl;
                }
            }
        }
    }

    return 0;
}