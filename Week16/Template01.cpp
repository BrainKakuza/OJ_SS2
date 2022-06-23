/*
Description

Please write a template functionvoid swap(T *a, T *b), this function is use to swap the content of variable.

Input
None

Output
None

Sample Input 1 
None

Sample Output 1
None
*/

#include<iostream>

using namespace std;

template <class T>

void swap(T *a, T *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
   
   
    return 0;
}