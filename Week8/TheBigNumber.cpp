/*
Description

Please design a class BigNumber to hold a very big number include decimals.

Please provide a constructor using string to construct BigNumber.

Overriding operator + and - for three BigNumber object can do a = b + c.

Overriding operator << for cout.

Input
input consist two lines, each line represent a number. Please consider negtive number.

Output
Output the result of adding two number and subtract two number.

Each result in one line.

Sample Input 1 
123456789123456789
1

Sample Output 1
123456789123456790
123456789123456788

Sample Input 2 
0.000000000010000000000100000000001
-0.1

Sample Output 2
-0.099999999989999999999899999999999
0.100000000010000000000100000000001
*/

#include <iostream>
#include <vector>

using namespace std;

class TheBigNumber
{
private:
    vector<int> container;
    int length;
    int carry;
    bool Notdecimal = true;

public:
    bool setNegative = false;
    bool decimal = false;

    TheBigNumber(vector<int> v, int _lenght, int _carry) : container(v), length(_lenght), carry(_carry)
    {
    }

    TheBigNumber(vector<int> v, int _lenght, int _carry, bool _notDecimal) : container(v), length(_lenght), carry(_carry), Notdecimal(_notDecimal)
    {
    }

    TheBigNumber operator+(TheBigNumber &numberSub)
    {
        int length01 = length;
        int length02 = numberSub.length;
        vector<int> result;

        int k = 0;
        int i = length01 - 1;
        int j = length02 - 1;

        for (; i >= 0 && j >= 0; i--, j--, k++)
        {
            int summing = (container[i] + numberSub.container[j] + carry) % 10;
            result.push_back(summing);
            carry = (container[i] + numberSub.container[j] + carry) / 10;
        }

        if (Notdecimal && numberSub.Notdecimal)
        {
            if (length01 > length02)
            {
                while (i >= 0)
                {
                    result.push_back((container[i] + carry) % 10);
                    k++;
                    carry = (container[i--] + carry) / 10;
                }
            }
            else if (length01 < length02)
            {
                while (j >= 0)
                {
                    int lol = (numberSub.container[j] + carry) % 10;
                    result.push_back((numberSub.container[j] + carry) % 10);
                    k++;
                    carry = (numberSub.container[j--] + carry) / 10;
                }
            }

            if (carry > 0)
            {
                result.push_back(carry);
                k++;
            }
        }

        return TheBigNumber(result, k, carry);
    }

    TheBigNumber operator-(TheBigNumber &numberSub)
    {
        // We need to check how large the number first
        int lenght01 = length;
        int length02 = numberSub.length;
        vector<int> result;

        int k = 0;
        int i = lenght01 - 1;
        int j = length02 - 1;
        int total;

        for (; i >= 0 && j >= 0; i--, j--, k++)
        {
            total = (container[i] - numberSub.container[j] - carry);

            if (total < 0)
            {
                total += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            result.push_back(total);
        }

        for (; i >= 0; i--, k++)
        {
            total = (container[i] - carry);

            if (total < 0)
            {
                total += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            result.push_back(total);
        }

        return TheBigNumber(result, k, carry);
    }

    friend ostream &operator<<(ostream &os, const TheBigNumber &b)
    {
        bool zero = true;
        int k = b.length;

        if (b.decimal)
        {
            for (--k; k >= 0; k--)
            {
                os << b.container[k];
            }
        }
        else
        {
            if (b.setNegative)
            {
                os << "-";
            }

            for (--k; k >= 0; k--)
            {
                if (zero)
                {
                    if (b.container[k] == 0)
                    {
                        continue;
                    }
                    else
                    {
                        zero = false;
                        os << b.container[k];
                    }
                }
                else
                {
                    os << b.container[k];
                }
            }
        }

        return os;
    }

    int getCarry()
    {
        return carry;
    }

    vector<int> getVector() const
    {
        return container;
    }
};

int main()
{
    // Try to use vector to make it easier
    vector<int> num1, num2;
    vector<int> deci01, deci02;
    string numberOne, numberTwo;
    bool noDecimal01 = true, noDecimal02 = true;

    cin >> numberOne >> numberTwo;

    int length01 = numberOne.length();
    int length02 = numberTwo.length();

    // Check if there's a decimal number or not
    // First Number
    for (int i = 0; i < length01; i++)
    {
        if (noDecimal01)
        {
            // Input number part
            if (numberOne[i] == '.')
            {
                noDecimal01 = false;
                continue;
            }
            num1.push_back(numberOne[i] - '0');
        }
        else
        {
            // Input decimal part
            deci01.push_back(numberOne[i] - '0');
        }
    }

    // Check if there's a decimal number or not
    // Second Number
    for (int i = 0; i < length02; i++)
    {
        if (noDecimal02)
        {
            // Input number part
            if (numberTwo[i] == '.')
            {
                noDecimal02 = false;
                continue;
            }
            num2.push_back(numberTwo[i] - '0');
        }
        else
        {
            // Input decimal part
            deci02.push_back(numberTwo[i] - '0');
        }
    }

    if (noDecimal01 && noDecimal02)
    {
        bool equal = true;
        TheBigNumber first(num1, num1.size(), 0);
        TheBigNumber second(num2, num2.size(), 0);
        TheBigNumber resultSum = first + second;

        if (resultSum.getVector()[0] == 0 && resultSum.getVector().size() == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << resultSum << endl;
        }

        // We need to determine which number is bigger and the subtract both of them
        if (length01 > length02)
        {
            TheBigNumber resultSub = first - second;
            cout << resultSub << endl;
        }
        else if (length01 < length02)
        {
            TheBigNumber resultSub = second - first;
            resultSub.setNegative = true;
            cout << resultSub << endl;
        }
        else
        {
            for (int i = 0; i < length01; i++)
            {
                if (num1[i] > num2[i])
                {
                    TheBigNumber resultSub = first - second;
                    equal = false;
                    cout << resultSub << endl;
                    break;
                }
                else if (num1[i] < num2[i])
                {
                    TheBigNumber resultSub = second - first;
                    resultSub.setNegative = true;
                    equal = false;
                    cout << resultSub << endl;
                    break;
                }
            }

            if (equal)
            {
                TheBigNumber resultSub = first - second;
                cout << "0" << endl;
            }
        }
    }
    else if (noDecimal01 || noDecimal02)
    {
        bool equal = true;

        if (noDecimal02)
        {
            for (int i = 0; i < deci02.size(); i++)
            {
                deci02.push_back(0);
            }

            // Summation
            TheBigNumber firstDec(deci01, deci01.size(), 0);
            TheBigNumber secondDec(deci02, deci02.size(), 0);
            TheBigNumber deciSum = firstDec + secondDec;
            deciSum.decimal = true;
            TheBigNumber firstNum(num1, num1.size(), 0);
            TheBigNumber secondNum(num2, num2.size(), 0);
            TheBigNumber resultSum = firstNum + secondNum;

            if (resultSum.getVector()[0] == 0 && resultSum.getVector().size() == 1)
            {
                cout << "0"
                     << "." << deciSum << endl;
            }
            else
            {
                cout << resultSum << "." << deciSum << endl;
            }

            // Subtraction
            int numlength01 = num1.size();
            int numlength02 = num2.size();

            if (numlength01 > numlength02)
            {
                TheBigNumber resultSub = firstNum - secondNum;
                cout << resultSub << "." << deciSum << endl;
            }
            else if (numlength01 < numlength02)
            {
                TheBigNumber resultSub = secondNum - firstNum;
                resultSub.setNegative = true;
                cout << resultSub << "." << deciSum << endl;
            }
            else
            {
                for (int i = 0; i < numlength01; i++)
                {
                    if (num1[i] > num2[i])
                    {
                        TheBigNumber resultSub = firstNum - secondNum;
                        equal = false;
                        cout << resultSub << "." << deciSum << endl;
                        break;
                    }
                    else if (num1[i] < num2[i])
                    {
                        TheBigNumber resultSub = secondNum - firstNum;
                        resultSub.setNegative = true;
                        equal = false;
                        cout << resultSub << "." << deciSum << endl;
                        break;
                    }
                }

                if (equal)
                {
                    TheBigNumber resultSub = firstNum - secondNum;
                    cout << "0"
                         << "." << deciSum << endl;
                }
            }
        }
        else if (noDecimal01)
        {

            for (int i = 0; i < deci02.size(); i++)
            {
                deci01.push_back(0);
            }

            // Summation
            TheBigNumber firstDec(deci01, deci01.size(), 0);
            TheBigNumber secondDec(deci02, deci02.size(), 0);
            TheBigNumber deciSum = firstDec + secondDec;
            deciSum.decimal = true;
            TheBigNumber firstNum(num1, num1.size(), 0);
            TheBigNumber secondNum(num2, num2.size(), 0);
            TheBigNumber resultSum = firstNum + secondNum;

            if (resultSum.getVector()[0] == 0 && resultSum.getVector().size() == 1)
            {
                cout << "0"
                     << "." << deciSum << endl;
            }
            else
            {
                cout << resultSum << "." << deciSum << endl;
            }

            // Subtraction
            // Subtract the decimal
            deci01.insert(deci01.begin(), 1);
            TheBigNumber deciSub = firstDec - secondDec;
            deciSub.decimal = true;

            int numlength01 = num1.size();
            int numlength02 = num2.size();

            if (numlength01 > numlength02)
            {
                TheBigNumber firstNumCarry(num1, num1.size(), 1);
                TheBigNumber resultSub = firstNumCarry - secondNum;
                cout << resultSub << "." << deciSub << endl;
            }
            else if (numlength01 < numlength02)
            {
                TheBigNumber firstNumCarry(num1, num1.size(), -1);
                TheBigNumber resultSub = secondNum - firstNumCarry;
                resultSub.setNegative = true;
                cout << resultSub << "." << deciSum << endl;
            }
            else
            {
                for (int i = 0; i < numlength01; i++)
                {
                    if (num1[i] > num2[i])
                    {
                        TheBigNumber resultSub = firstNum - secondNum;
                        equal = false;
                        cout << resultSub << "." << deciSub << endl;
                        break;
                    }
                    else if (num1[i] < num2[i])
                    {
                        TheBigNumber resultSub = secondNum - firstNum;
                        resultSub.setNegative = true;
                        equal = false;
                        cout << resultSub << "." << deciSum << endl;
                        break;
                    }
                }

                // Print decimal can't print 01 from the above setting , try to fix it
                // Don't forget to do the case if the decimal is 0
                // Finish the two decimal

                if (equal)
                {
                    TheBigNumber resultSub = firstNum - secondNum;
                    resultSub.setNegative = true;
                    cout << "-0"
                         << "." << deciSum << endl;
                }
            }
        }
    }
    else
    {
        // We need to make both of the decimal number equal
        int deciLength01 = deci01.size();
        int deciLength02 = deci02.size();

        if (deciLength01 > deciLength02)
        {
            int diff = deciLength01 - deciLength02;
            for (int i = 0; i < diff; i++)
            {
                deci02.push_back(0);
            }
        }
        else if (deciLength01 < deciLength02)
        {
            int diff = deciLength02 - deciLength01;
            for (int i = 0; i < diff; i++)
            {
                deci01.push_back(0);
            }
        }

        // Summation
        TheBigNumber firstDec(deci01, deci01.size(), 0, false);
        TheBigNumber secondDec(deci02, deci02.size(), 0, false);
        TheBigNumber deciSum = firstDec + secondDec;
        deciSum.decimal = true;
        TheBigNumber firstNum(num1, num1.size(), deciSum.getCarry());
        TheBigNumber secondNum(num2, num2.size(), 0);
        TheBigNumber resultSum = firstNum + secondNum;

        if (resultSum.getVector()[0] == 0 && resultSum.getVector().size() == 1)
        {
            cout << "0"
                 << "." << deciSum << endl;
        }
        else
        {
            cout << resultSum << "." << deciSum << endl;
        }

        bool deciEqual = true;
        bool numEqual = true;

        // We have to look at the number part first to determine if any of them are more than or less than
           
    }

    return 0;
}