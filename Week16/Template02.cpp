/*
Description

Please write a template classpoint.

classpointhave two membersx&y.

You need provide two constructorspoint()&point(T a, T b)

And overloading<<&+, output format isa b\n

Input
None

Output
None

Sample Input 1 
None

Sample Output 1
1 2
2 4
3.34 5.12
*/

#include<iostream>

using namespace std;

template <class T>
class point
{
private:
    T num01 , num02;
public:
    point()
    {
        num01 = 0;
        num02 = 0;
    }

    point(T a , T b): num01(a) , num02(b)
    {

    }

    friend std::ostream& operator << (std::ostream& stream , point<T>& p)
    {
        stream << p.num01 << " " << p.num02 << "\n";
        return stream;
    } 

    point operator + (point &p)
    {
        return point(num01 + p.num01 , num02 + p.num02);
    } 
};



int main()
{
    point <int> p1(10 , 15);

    cout << p1;

   
    return 0;
}