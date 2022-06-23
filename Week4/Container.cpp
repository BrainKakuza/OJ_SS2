/*
Description

Please implement a class named "container".

This class have three private data:

int *box;

int len;

int index;

One constructor:

container(void): box(NULL), len(0), index(0){}
Two public function:

int getLen()
int getIndex()

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

class container
{
public:
  
  container(void): box(NULL) , len(0) , index(0)
  {
  }
  
  int getLen()
  {
  	return len;
  }
  
  int getIndex()
  {
  	return index;
  }
 
private:
	int *box;
  	int len;
  	int index;
};
