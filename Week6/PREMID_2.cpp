/*
Description

Submitted to the question above, overloading the operator + -

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>
class F
{
private:
  int a, b;

public:
  F(int numOne, int numTwo) : a(numOne), b(numTwo) {}

  F operator + (F &second)
  {
    return F(a + second.a , b + second.b);
  }

  F operator - (F &second)
  {
    return F(a - second.a , b - second.b);
  }

  int S(int x)
  {
    int result = 0;
    for (int i = 0; i <= x; i++)
    {
      result += (a * i) + b;
    }

    return result;
  }

  int G(int x, int y)
  {
    int result = 0;
    for (int i = x; i <= y; i++)
    {
      result += (a * i) + b;
    }

    return result;
  }
};
int main()
{

  int a, b, c, d, j;
  std::cin >> a >> b >> c >> d;
  F f(a, b), f2(c, d);
  for (j = 0; j < 10; j++)
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << (f + f2).S(x) << std::endl;
    std::cout << (f - f2).G(x, y) << std::endl;
  }

  return 0;
}
