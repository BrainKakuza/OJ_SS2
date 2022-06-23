/*
Description

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"

countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

Constraints:1 <= n <= 30

Input
A positive integer n.

Output
Return the nth term of the count-and-say sequence.

Sample Input 1 
1
2
3
4

Sample Output 1
1
11
21
1211
*/

#include <iostream>
using namespace std;

string toString(int n)
{
    if(n == 0)
        return "";

    if(n == 1)
        return "1";

   string res = "1";

   while (--n)
   {
       string cur = "";
       for(int i = 0; i < res.length(); i++)
       {
           int count = 1;
           while(res[i] == res[i + 1] && i < res.length())
           {
               count++;
               i++;
           }
           cur += to_string(count) + res[i];
       }
       res = cur;
   }

   return res;
   
    
}


int main()
{
   int num;

   while(cin >> num)
   {
       string output = toString(num);
       cout << output << endl;
   }
   

	return 0;
}
