/*
Description

Given a strings, find the length of the longest substring without repeating characters. 
(sconsists of English letters, digits, symbols and spaces. 0 \le s.length \le 10000≤s.length≤1000)

Input

ASCII characters end up with line-break or end-of-file.

Output
Length of longest substring.

Sample Input 1 
abcabcbb

Sample Output 1
3
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string input;

    getline(cin , input);
    int lenght = input.length();

    int longestSub = 0;

    string array[lenght][lenght];

    for (int i = 0; i <= lenght; i++)
    {
        for (int j = 1; j <= lenght - i; j++)
        {
            bool notsame = true;
            int going = 1;
            
            string subString = input.substr(i, j);

            for (int m = 0; m < subString.length(); m++)
            {
                for (int n = m - 1; n >= 0; n--)
                {

                    char main = subString[m];
                    char check = subString[n];
                    
                    if(subString[m] == subString[n])
                    {
                        notsame = false;
                        going = 0;
                        break;
                    }
                }

                 if(going == 0)
                {
                    break;
                }
            }
            
            if (notsame)
            {
                array[i][j - 1] = subString;
            }else
            {
                break;
            }

        }
    }

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            string temp = array[i][j];

            if(temp.length() > longestSub)
            {
                longestSub = temp.length();
            }
        }
    }

    cout << longestSub << endl;

    return 0;
}
