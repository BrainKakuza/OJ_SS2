/*
Description

Kerbside recycling has come to New Zealand, and every city from Auckland to Invercargill has leapt on to the band wagon. 
The bins come in 5 different colours — red, orange, yellow, green and blue —and 5 wastes have been identified for recycling 
— Plastic, Glass, Aluminium, Steel, and Newspaper.Obviously there has been no coordination between cities
, so each city has allocated wastes to bins in an arbitrary fashion. 
Now that the government has solved the minor problems of today (such as reorganising Health, Welfare and Education)
, they are looking around for further challenges. The Minister for Environmental Doodads wishes to 
introduce the “Regularisation of Allocation of Solid Waste to Bin Colour Bill” to Parliament
, but in order to do so needs to determine an allocation of his own.
 Being a firm believer in democracy (well some of the time anyway), 
 he surveys all the cities that are using this recycling method. 
 From these data he wishes to determine the city whose allocation scheme (if imposed on the rest of the country) 
 would cause the least impact, that is would cause the smallest number of changes in the allocations of the other cities. 
 Note that the sizes of the cities is not an issue, after all this is a democracy with the slogan “One City, One Vote”.
 Write a program that will read in a series of allocations of wastes to bins and determine which city’s allocation 
 scheme should be chosen. Note that there will always be a clear winner.

Input
Input will consist of a series of blocks. Each block will consist of a series of lines and each line will contain a 
series of allocations in the form shown in the example. There may be up to 100 cities in a block. 
Each block will be terminated by a line starting with ‘e’. 
The entire file will be terminated by a line consisting of a single ‘#’.

Output
Output will consist of a series of lines, one for each block in the input. 
Each line will consist of the number of the city that should be adopted as a national example.

Sample Input 1 
r/P,o/G,y/S,g/A,b/N
r/G,o/P,y/S,g/A,b/N
r/P,y/S,o/G,g/N,b/A
r/P,o/S,y/A,g/G,b/N
e
r/G,o/P,y/S,g/A,b/N
r/P,y/S,o/G,g/N,b/A
r/P,o/S,y/A,g/G,b/N
r/P,o/G,y/S,g/A,b/N
ecclesiastical
#

Sample Output 1
1
4
*/

#include <iostream>

using namespace std;

int main()
{
    string city[105]; // The total city in the input

    string temp; // Template for each city

    while (getline(cin, temp)) // First enter the city, num records the number of cities
    {

        // if # just finish the program
        if (temp[0] == '#')
            break;

        // Input all the city
        int num = 0;
        city[num++] = temp;
        while (getline(cin, city[num]))
        {
            if (city[num][0] == 'e')
                break;
            else
            {
                num++;
            }
        }

        if (num == 1)
            cout << num << endl; // When only one city is input just output 1
        else
        {
            // Rearrange Everything

            char sortedCity[105][6]; // To simplify string
            // Try to arrange everything in this form r o y g b
            // For example, s[i]=”r/P,o/G,y/S,g/A,b/N”, then a[i]=”PGSAN”;

            // r/P,o/G,y/S,g/A,b/N
            // r/G,o/P,y/S,g/A,b/N
            // r/P,y/S,o/G,g/N,b/A
            // r/P,o/S,y/A,g/G,b/N

            // R O Y G B

            // P G S A N
            // G P S A N
            // P G S N A
            // P S A G N

            for (int i = 0; i != num; ++i)
            {
                int j = city[i].find('r');
                sortedCity[i][0] = city[i][j + 2];

                j = city[i].find('o');
                sortedCity[i][1] = city[i][j + 2];

                j = city[i].find('y');
                sortedCity[i][2] = city[i][j + 2];

                j = city[i].find('g');
                sortedCity[i][3] = city[i][j + 2];

                j = city[i].find('b');
                sortedCity[i][4] = city[i][j + 2];
            }

            int result = 1000, candidate = 0;
            for (int i = 0; i != num; ++i)
            {

                // P G S A N
                // G P S A N
                // P G S N A
                // P S A G N

                int resultCom = 0; // how many changes need to apply
                for (int j = 0; j != num;)
                {
                    if (j == i)
                        ++j; // When j==i, no need to process
                    else
                    {
                        for (int k = 0; k != 5; ++k)
                        {
                            if (sortedCity[j][k] != sortedCity[i][k])
                                resultCom++;
                        }
                        j++;
                    }
                }

                if (result > resultCom)
                {
                    result = resultCom;
                    candidate = i;
                }
            }
            cout << candidate + 1 << endl;
        }
    }
    return 0;
}