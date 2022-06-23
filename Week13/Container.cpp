/*
Description

We have a class Container as below.

class Container
{
public:
    Container()
    {
        index = 0;
    }
    void insert(int n)
    {
        if(n >= 0)
        {
            data[index] = n;
            index ++;
        }
    }
    virtual int remove() = 0;  //remove an element from container
    void display()
    {
        int j;
        if(index == 0)
            return;
        for(j = 0; j < index - 1; j ++)
            cout<<data[j]<<", ";
        cout<<data[j];
    }
protected:
    int data[100];
    int index;
};
Please design two class RemoveFromBig and RemoveFromSmall which inherited from Container 
and implement the virtual function in Container.

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

using namespace std;

class Container
{
public:
    Container()
    {
        index = 0;
    }
    void insert(int n)
    {
        if (n >= 0)
        {
            data[index] = n;
            index++;
        }
    }

    virtual int remove() = 0; // remove an element from container

    void display()
    {
        int j;
        if (index == 0)
            return;
        for (j = 0; j < index - 1; j++)
            cout << data[j] << ", ";
        cout << data[j];
    }

protected:
    int data[100];
    int index;
};

class RemoveFromBig : public Container
{
public:
    int remove() override
    {
        int max = 0;

        for (int i = 1; i < index; i++)
        {
            if (data[i] > data[max])
            {
                max = i;
            }
        }

        for (int i = max; i < index; i++)
        {
            data[i] = data[i + 1];
        }

        index--;

        return data[max];
    }
};

class RemoveFromSmall : public Container
{
public:
    int remove() override
    {
        int min = 0;

        for (int i = 1; i < index; i++)
        {
            if (data[i] < data[min])
            {
                min = i;
            }
        }

        for (int i = min; i < index; i++)
        {
            data[i] = data[i + 1];
        }

        index--;

        return data[min];
    }
};
