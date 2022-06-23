/*
Description

Please design a class Convert to convert string into different type.

Class Convert should inherit class string, yes you can inherit a class provide by C++ and use all the method it had.

Implement two method toInt and toDouble.

toInt will convert the instance to an integer and return it if it can be convert

toDouble will convert the instance to a double and return it if it can be convert

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include<iostream>

using namespace std;

class Convert: public string
{
    Convert()
    {
        this->clear();
    }

    Convert(string str)
    {
        this->append(str);
        this->clear();
    }

    int toInt()
    {
        int num = 0 , s = 1 , i = 0;

        if((*this)[0] == '-')
        {
            s = -1;
            i = 1;
        }

        for(; i < length(); i++)
        {
            num = num * 10 + ((*this)[i] - '0');
        }

        num *= s;

        return num;
    }

    double toDouble()
    {
        double num;
        int s = 1 , i = 0 , base = 1;
        bool change = false;

        if((*this) == '-')
        {
            s = -1;
            i = 1;
        }

        for(; i < length(); i++)
        {
            if((*this)[i] == '.')
            {
                change = true;
                continue;
            }

            num = num * 10 + ((*this)[i] - '0');

            if(change)
            {
                base *= 10;
            }
        }

        num *= s;
        num = num / base;

        return num;
    }
};
