#include <iostream>

using namespace std;

class container
{
private:
  int *box;
  int len;
  int index;
  static int count;

  bool reallocate(int size)
  {

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = box[i];
    }

    delete[] box;

    box = arr;

    return 0;
  }

  static void increase()
  {
    count++;
  }

  static void decrease()
  {
    count--;
  }

public:
  container(void) : box(NULL), len(0), index(0) {}

  container(int len) : box(NULL), len(len), index(-1)
  {
    // The address of box
    box = new int[len];
    increase();
  }

  void traversal()
  {
    if (index != -1)
    {
      for (int i = 0; i < index + 1; i++)
      {
        cout << box[i] << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "empty\n";
    }
  }

  bool push(int data)
  {
    if (index == len - 1)
    {
      len = len * 2;
      reallocate(len);
      push(data);
    }
    else
    {
      index += 1;
      box[index] = data;
    }

    return 0;
  }

  int pop()
  {
    if (index == -1)
    {
      return 0;
    }
    else
    {
      int num = box[0];
      box++;
      index -= 1;
      cout << num << endl;
      return num;
    }

  }

  static int getCount()
  {
    cout << count << endl;
    return count;
  }

  int getLen()
  {
    cout << len << endl;
    return len;
  }

  int getIndex()
  {
    cout << index << endl;
    return index;
  }

  ~container()
  {
    decrease();
  }
};

int container::count = 0;

int main()
{
  container c1(5);

  c1.push(10);
  c1.push(0);
  c1.push(5);
  c1.push(11);
  c1.push(20);

  c1.traversal();

  c1.push(10);

  c1.traversal();

  c1.pop();
  c1.getLen();

  c1.traversal();

  c1.getIndex();

  c1.getCount();

  c1.getCount();
  c1.getLen();

  

  return 0;
}
