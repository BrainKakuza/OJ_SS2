/*
Description

//Complete the following program as described

//Finish the following code as description.

class PokerCard
{
public:
    PokerCard(std::string s, int f)
    {
        suit = s;
        face = f;
    }
    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
    {
        out<<"["<<p.face<<" of "<<p.suit<<"]";
        return out;
    }

    //Please finish the operator override
    //請完成運算子多載
    //spade > heart > diamond > club
    //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    bool operator>(PokerCard &b)
    {
    }
    bool operator<(PokerCard &b)
    {
    }
    bool operator==(PokerCard &b)
    {
    }

private:
    std::string suit;
    int face;
};

int main()
{
    PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

    std::string s[] = {"spade", "heart", "diamond", "club"};
    int j, k;
    for(j = 0;j < 4;j ++)
        for(k = 1;k <= 13;k ++)
            card[j * 13 + k - 1] = new PokerCard(s[j], k);
    for(j = 0;j < 52;j ++)
    {
        for(k = 0;k < 52;k ++)
        {
            std::cout<<*(card[j])<<">"<<*(card[k])<<":"<<(*(card[j])>*(card[k]))<<std::endl;
            std::cout<<*(card[j])<<"<"<<*(card[k])<<":"<<(*(card[j])<*(card[k]))<<std::endl;
            std::cout<<*(card[j])<<"=="<<*(card[k])<<":"<<(*(card[j])==*(card[k]))<<std::endl;
        }
    }
}

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
//#include <fstream>

//using namespace std;

const std::string S = "spade";
const std::string H = "heart";
const std::string D = "diamond";
const std::string C = "club";

class PokerCard
{
public:
    int scoreOne, scoreTwo;

    PokerCard(std::string s, int f)
    {
        suit = s;
        face = f;
    }
    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
    {
        out << "[" << p.face << " of " << p.suit << "]";
        return out;
    }

    int cardTypeCheck(std::string Card)
    {
        int cardLevel = 0;
        // Determine the level of it
        if (Card == C)
        {
            cardLevel = 0;
        }
        else if (Card == D)
        {
            cardLevel = 1;
        }
        else if (Card == H)
        {
            cardLevel = 2;
        }
        else if (Card == S)
        {
            cardLevel = 3;
        }

        return cardLevel;
    }

    int cardNumCheck(int num)
    {
        if (num == 1)
        {
            return 13;
        }
        else
        {
            return num - 1;
        }
    }

    // Please finish the operator override
    //請完成運算子多載
    // spade > heart > diamond > club
    // 1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    bool operator>(PokerCard &b)
    {
        // Check the type of card first the check the number
        int numOne = cardNumCheck(face);
        int numTwo = cardNumCheck(b.face);

        if (numOne > numTwo)
        {
            return true;
        }
        else if (numOne == numTwo)
        {
            int faceOne = cardTypeCheck(suit);
            int faceTwo = cardTypeCheck(b.suit);

            if (faceOne > faceTwo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator<(PokerCard &b)
    {
        // Check the type of card first the check the number
        int numOne = cardNumCheck(face);
        int numTwo = cardNumCheck(b.face);

        if (numOne < numTwo)
        {
            return true;
        }
        else if (numOne == numTwo)
        {
            int faceOne = cardTypeCheck(suit);
            int faceTwo = cardTypeCheck(b.suit);

            if (faceOne < faceTwo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator==(PokerCard &b)
    {
        // Check the type of card first the check the number
        int numOne = cardNumCheck(face);
        int numTwo = cardNumCheck(b.face);

        if (numOne == numTwo)
        {
            int faceOne = cardTypeCheck(suit);
            int faceTwo = cardTypeCheck(b.suit);

            if (faceOne == faceTwo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

private:
    std::string suit;
    int face;
};

int main()
{
    //ofstream fileOut;
    PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

    //fileOut.open("output.txt");

    std::string s[] = {"spade", "heart", "diamond", "club"};
    int j, k;
    for (j = 0; j < 4; j++)
        for (k = 1; k <= 13; k++)
            card[j * 13 + k - 1] = new PokerCard(s[j], k);
    for (j = 0; j < 52; j++)
    {
        for (k = 0; k < 52; k++)
        {
            std::cout << *(card[j]) << ">" << *(card[k]) << ":" << (*(card[j]) > *(card[k])) << std::endl;
            std::cout << *(card[j]) << "<" << *(card[k]) << ":" << (*(card[j]) < *(card[k])) << std::endl;
            std::cout << *(card[j]) << "==" << *(card[k]) << ":" << (*(card[j]) == *(card[k])) << std::endl;
        }
    }

    //fileOut.close();
}
