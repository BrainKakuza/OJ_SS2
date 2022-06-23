/*
Description

Last week we done the container, In this week we will add more function in to container.

int len: length of the array.

int index: store the last value index of array.

Please add one private member:

static int count: initialize it value to zero.(count is the number of object container)

Please add one constructor:

container(int len): please using dynamic memory allocation get an integer type array, its length islen
, and let pointerboxsaved the first address of the array.

Please add one destructor:

~container()

Please add one private function:

bool reallocate(int size): allocate new integer type array, copy the data from the original array to the new array and delete the old array
, setboxdirect to the new array.

Please add three public functions:

void traversal(): print all data in the array, if array is empty print "empty\n". 
(print format: display the space after each value and put\nin the end)

bool push(int data): push the data in tail, if accept returntrueotherwisefalse. (when array is full please call the functionreallocate()
, new array size is twice the original)

int pop(): pop the data from head, if the array is empty return0, otherwise remove the data and return it.

Please add two private static functions:

static void increase(): when a new container object created, call this function.

static void decrease(): when a container object destroy, call this function.

Please add one public static function:

static int getCount(): return the value of count;

Input
None

Output
None

Sample Input 1 
none

Sample Output 1
none
*/

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
    for (int i = 0; i <= index; i++)
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
  container(void) : box(NULL), len(0), index(-1)
  {
    container::increase();
  }

  container(int len) : box(NULL), len(len), index(-1)
  {
    // The address of box
    box = new int[len];
    container::increase();
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
    if (box == NULL)
    {
      len = 10;
      reallocate(len);
      push(data);
    }
    else if (index == len - 1)
    {
      len = len * 2;
      reallocate(len);
      push(data);
    }
    else
    {
      index += 1;
      // cout << index << endl;
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
      len--;
      // cout << num << endl;
      return num;
    }
  }

  static int getCount()
  {
    // cout << count << endl;
    return count;
  }

  int getLen()
  {
    // cout << len << endl;
    return len;
  }

  int getIndex()
  {
    // cout << index << endl;
    return index;
  }

  ~container()
  {
    container::decrease();
  }
};

int container::count = 0;

int main()
{
  container c1(2);

  c1.push(5);
  c1.push(6);
  c1.pop();
  c1.traversal();




  return 0;
}