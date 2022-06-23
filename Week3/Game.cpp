/*
Description

Please create a class "Player".

You need provide two private member "number" in integer type & "name" in string type.

Two constructor:

1. Player()

2. Player(int num, string name) "the first argument must bigger than 0 & small than 5, if exceed range please using cerr print messge "out of range\n", if have any symbol is not English alphabet or its length is bigger than or equal to 20), please using cerr print "your name is illegal\n""

Four public function:

1. int getPlayerNum(), return the value of member munber.

2. string getPlayerName(), return the value of member name.

3. bool setPlayerNum(int n), using n to set the value of member number. if the range is valid return true; otherwise return false;

4. bool setPlayerName(string n), using n to set the value of member name. The limit as the above. if valid return true; otherwise return false.

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

class Player
{
public:
  
  	//Defalut constructure
    Player() {}

  	//Constructure with some manipulation
    Player(int num, string name)
    {
        if (num > 5 || num < 0)
        {
            cerr << "out of range\n";
        }

        if (name.length() >= 20)
        {
            cerr << "your name is illegal\n";
        }
        else if (name.length() < 20)
        {
            for (int i = 0; i < name.length() - 1; i++)
            {
                if ((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90))
                {
                }
                else
                {
                    cerr << "your name is illegal\n";
                    break;
                }
            }
        }
    }

    int getPlayerNum()
    {
        return number;
    }

    string getPlayerName()
    {
        return Name;
    }

    bool setPlayerNum(int n)
    {
        if (n < 5 && n > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool setPlayerName(string n)
    {
        bool valid = true;

        if (n.length() >= 20)
        {
            valid = false;
        }
        else if (n.length() < 20)
        {
            for (int i = 0; i < n.length() - 1; i++)
            {
                if ((n[i] >= 97 && n[i] <= 122) || (n[i] >= 65 && n[i] <= 90))
                {
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        if(valid){
            return true;
        }else{
            return false;
        }
    }

private:
    int number;
    string Name;
};