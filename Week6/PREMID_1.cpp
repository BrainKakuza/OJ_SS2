/*
假設我們有一個函數：

image.png

請依下列指示定義並實作類別F用來代表這個函數。

1.類別F有兩個私有的資料成員a跟b用來代表函數中的a及b。

2.類別F有一個公開的建構子，該建構子需要兩個參數，依序代表a跟b。

3.類別F有一個公開的函數S代表S(x)，該函數需要傳入一個參數然後會回傳S(x)的值。

4.類別F有一個公開的函數G代表G(x, y)，該函數需要傳入兩個參數然後會回傳G(x, y)的值。

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
  int a, b, j;

  std::cin >> a >> b;
  F f(a, b);

  for (j = 0; j < 10; j++)
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << f.S(x) << std::endl;
    std::cout << f.G(x, y) << std::endl;
  }
  return 0;
}
