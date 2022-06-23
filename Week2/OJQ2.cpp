/*
Description

Please using "cin" to read in a word and output it reverse (the word will be ended with '.' character)

You can only use one variable with type char and array is forbidden.

Input

one word ended with '.' character.

Output

output the word reverse without '.'

Sample Input 1 
1234.

Sample Output 1
4321
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   char word; 
   string text , reverse;

   while (1)
   {
       cin >> word;
       if(word == '.'){
           break;
       }else{
           text.push_back(word);
       }
   }
    
   for (int i = text.length() - 1; i >= 0; i--)
   {
       reverse.push_back(text[i]);
   }

   cout << reverse;
   




    return 0;
}