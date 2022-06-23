/*
Description

A typical windowing system on a computer will provide a number of icons on the screen as well as some defined regions
. When the mouse button is clicked, the system has to determine where the cursor is and what is being selected. 
For this problem we assume that a mouse click in (or on the border of) a region selects that region
, otherwise it selects the closest visible icon (or icons in the case of a tie).

Consider the following screen:

image link: https://onlinejudge.org/external/1/142.pdf

A mouse click at ‘a’ will select region A. A mouse click at ‘b’ will select icon 1. 
A mouse click at ‘c’ will select icons 6 and 7. A mouse click at ‘d’ is ambiguous. 
The ambiguity is resolved by assuming that one region is in front of another. 
In the data files, later regions can be assumed to be in front of earlier regions. 
Since regions are labelled in order of appearance (see later) ‘d’ will select C. 
Note that regions always overlap icons so that obscured icons need not be considered and that the origin (0,0) is at the top left corner.

Write a program that will read in a series of region and icon definitions followed by a series of mouse clicks 
and return the selected items. Coordinates will be given as pairs of integers in the range 0..499 and you can assume 
that all icons and regions lie wholly within the screen. Your program must number all icons (even invisible ones) 
in the order of arrival starting from 1 and label regions alphabetically in the order of arrival starting from ‘A’.


Input
Input will consist of a series of lines. Each line will identify the type of data: ‘I’ for icon, 
‘R’ for region and ‘M’ for mouse click. There will be no separation between the specification part and the event part
, however no icon or region specifications will follow the first mouse click. An ‘I’ will be followed by the coordinates of the centre of the icon
, ‘R’ will be followed by the coordinates of the top left and bottom right corners respectively 
and ‘M’ will be followed by the coordinates of the cursor at the time of the click. There will always be at least 
one visible icon and never more than 25 regions and 50 icons. The entire file will be terminated by a line consisting of a single ‘#’.

Output
Output will consist of one line for each mouse click, containing the selection(s) for that click. 
Regions will be identified by their single character identifier, icon numbers will be written out right justified in a field of width 3
, and where there is more than one icon number they will appear in increasing numerical order.

Sample Input 1 
I       216     28
R       22      19      170     102
I       40      150
I       96      138
I       36      193
R       305     13      425     103
I       191     184
I       387     200
R       266     63      370     140
I       419     134
I       170     102
M       50      50
M       236     30
M       403     167
M       330     83
#

Sample Output 1
A
  1
  6  7
C

*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int SIZE = 500;

char **Screen;

int icons[50][3];
int numIcons = 0;

int nearestIcon[50];
int numNear;

void fillRegion(int x0, int y0, int x1, int y1)
{
    if (!Screen)
        return;

    static char letter = 'A';

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            Screen[i][j] = letter; // Overwrite past regions and icons
        }
    }

    // Use the next letter of the alphabet
    letter = letter + 1;
}

float distance(int x0, int y0, int x1, int y1)
{
    return sqrtf(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

void findNearestIcon(int x, int y)
{
    int first = 0;

    while (first < numIcons && !icons[first][2])
    {
        first++;
    }

    float mindis = distance(x, y, icons[first][0], icons[first][1]);
    nearestIcon[0] = 1 + first;
    numNear = 1;
    float dis;

    for (int i = first + 1; i < numIcons; i++)
    {
        // Skip icons that are not visible
        if (!icons[i][2])
            continue;

        dis = distance(x, y, icons[i][0], icons[i][1]);

        if (dis < mindis)
        {
            mindis = dis;
            numNear = 1;
            nearestIcon[0] = 1 + i;
        }
        else if (dis == mindis)
        {
            nearestIcon[numNear++] = 1 + i;
        }
    }
}

int main(void)
{
    // fill in the canvas
    Screen = new char *[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        Screen[i] = new char[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            Screen[i][j] = '_';
        }
    }

    char type;
    cin >> type;

    int x1, y1, x2, y2;
    
    while (type != 'M')
    {
        cin >> x1 >> y1;

        if (type == 'R')
        {
            cin >> x2 >> y2;

            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);

            fillRegion(x1, y1, x2, y2);
        }
        else
        {
            icons[numIcons][0] = x1;
            icons[numIcons][1] = y1;
            numIcons++;
        }

        cin >> type;
    }

    // Check visibility
    for (int k = 0; k < numIcons; k++)
    {
        int x = icons[k][0];
        int y = icons[k][1];

        // The icon is visible
        icons[k][2] = Screen[x][y] == '_';

        // If the icon is visible, mark it on screen
        if (icons[k][2])
        {
            Screen[x][y] = k + 1;
            //cout << k + 1 << endl;
        }
    }

    while (type == 'M')
    {
        cin >> x1 >> y1;

        char result = Screen[x1][y1];

        // If clicked over a region
        if ('A' <= result && result <= 'Z')
        {
            cout << result << endl;

            // If clicked on icon
        }
        else if (1 <= result && result <= 50)
        {
            cout << setw(3) << result << endl;
            // Find the nearest icon(s)
        }
        else
        {
            findNearestIcon(x1, y1);
            // Print icon(s)
            for (int d = 0; d < numNear; d++)
                cout << setw(3) << nearestIcon[d];
            cout << endl;
        }

        cin >> type;
    }

    return 0;
}