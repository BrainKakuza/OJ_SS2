/*
Description

class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for (int i = 0; i < l; i++)
            to[i] = from[i];
    }

public:
    container() : box(NULL), len(1) {}
    container(int l)
    {
        int *tmp = new int[l];
        this->len = l;
        this->box = tmp;
    }
    container(const container &a)
    {
        int *tmp = new int[a.len];
        copy(a.box, tmp, a.len);
        this->len = a.len;
    }
    int getLen() const
    {
        return this->len;
    }
    virtual bool put_in(int obj) = 0;
    virtual int *take_out(void) = 0;
};

Please define a classqueueinherit fromcontainer

put_in()is add object in the tail of queue.

take_out()is take object from head of queue.

And define a classpriority_queueinherit fromqueue

priority_queuehave a memberbool order.

a consturcterpriority_queue(int len, bool f)

a public functiontake_out()

take_out(): iforder == trueyou should take out by biggest number, otherwise take out by smallest number.

Input
None

Output
None

Sample Input 1 
None

Sample Output 1
None
*/

#include <iostream>

using namespace std;

class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for (int i = 0; i < l; i++)
            to[i] = from[i];
    }

public:
    container() : box(NULL), len(1) {}
    container(int l)
    {
        int *tmp = new int[l];
        this->len = l;
        this->box = tmp;
    }
    container(const container &a)
    {
        int *tmp = new int[a.len];
        copy(a.box, tmp, a.len);
        this->len = a.len;
    }
    int getLen() const
    {
        return this->len;
    }
    virtual bool put_in(int obj) = 0;
    virtual int *take_out(void) = 0;
};

class queue : public container
{
protected:
    int index;

public:
    queue() : container(), index(-1) {}

    queue(int len) : container(len), index(-1) {}

    queue(queue &a) : container(a)
    {
        box = a.box;
        index = a.index;
        len = a.len;
    }

    bool put_in(int obj)
    {
        if (index == len - 1)
        {
            return false;
        }
        else
        {
            index++;
            box[index] = obj;

            return true;
        }
    }

    int *take_out()
    {
        if (index == -1)
        {
            return nullptr;
        }
        else
        {
            int num = box[0];
            int *point = new int;
            *point = num;

            for (int i = 0; i <= index; i++)
            {
                box[i] = box[i + 1];
            }

            index--;

            return point;
        }
    }
};

class priority_queue : public queue
{
protected:
    bool order;
public:
    priority_queue(int len, bool f) : queue(len), order(f) {}

    int *take_out()
    {
        if (index == -1)
        {
            return nullptr;
        }

        if (order)
        {
            int highIndex = 0;
            int highNum = box[0];

            for (int i = 1; i <= index; i++)
            {
                if (highNum < box[i])
                {
                    highNum = box[i];
                    highIndex = i;
                }
            }

            for (int i = highIndex; i <= index; i++)
            {
                box[i] = box[i + 1];
            }

            index--;

            int *point = new int;
            *point = highNum;

            return point;
        }
        else
        {
            int lowIndex = 0;
            int lowNum = box[0];

            for (int i = 1; i <= index; i++)
            {
                if (lowNum > box[i])
                {
                    lowNum = box[i];
                    lowIndex = i;
                }
            }

            for (int i = lowIndex; i <= index; i++)
            {
                box[i] = box[i + 1];
            }

            index--;

            int *point = new int;
            *point = lowNum;

            return point;
        }
    }
};
int main(void)
{
}
