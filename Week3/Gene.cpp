/*
Description

For many years, the Genetic Evolution Laboratory (GEL) has been studying the evolution of various genetic diseases
, by collecting, for each disease, data from a large population, over several generations.For each person
, it is known whether the gene is dominant, recessive, or non-existent. 
Based on this data, scientists formulate an hypothesis on how the disease is transmitted from parents to children.However
, it is tedious to check by hand if the data matches the hypothesis, so GEL asked you to automate this task for them.
The idea is simple: the program will, given the parent-child relationships and a fixed hypothesis,
calculate for all people whether they have the gene or not, and in the former case whether it is dominant or not. 
This result is written to a text file, which will later be compared (using a standard file differentiating tool) with the data that GEL collected.
 If there are no differences, the hypothesis is valid. 
 Any mismatch will give clues to GEL’s scientists on how they should improve the hypothesis.
 Given a set of parent-child relationships, and the status of the gene for all those people whose parents are not in the data set
 , compute the status of the gene for all people in the data set, according to the following hypothesis:

• the child has the gene if, and only if, both parents have it or it is dominant in one of the parents;and

• the child’s gene is dominant if, and only if, the gene is dominant in both parents or dominant in one and recessive in the other parent.

Input

The first line contains an integer N (1 ≤ N ≤ 3100), which is the number of lines of the data set.
Each of the following N lines contains a pair of non-empty strings, separated by a space. 
All strings are at most 20 characters long, and no string contains a blank (tab or space).The first string is the name of a person. 
The second string is either

1. ‘non-existent’, ‘recessive’, or ‘dominant’; or

2. the name of another person (the child).

The first case is to indicate the status of the gene for a person whose parents are not part of the data set. 
The second case is to indicate that the first person is a parent of the second one.
 All people have distinct names and none is “non-existent”, “recessive”, or “dominant”.For each person
 , either both or none of the parents are part of the data set.

Output

The output consists of one line per person occurring in the data set.Each line has two strings, separated by a space. The first string is the name of the person, and the second string indicates the status of the gene, in the same way as in the input.The output must be ordered alphabetically by name.

Sample Input 1 
7
John dominant
Mary recessive
John Susan
Mary Susan
Peter non-existent
Susan Marta
Peter Marta

Sample Output 1
John dominant
Marta recessive
Mary recessive
Peter non-existent
Susan dominant
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const string D = "dominant";
const string R = "recessive";
const string N = "non-existent";

map<string , string> gene;
map<string , vector<string>> parent;

using namespace std;

class GENE{
    private:
        int Input;
    public:

        void getData();
        void findGene();
        void getGene(string child , string P1 , string P2);
        void printData();

        GENE(int input)
        {
            Input = input;
        }  
};

void GENE::getData()
{
    while (Input--)
    {
        string a , b;
        cin >> a >> b;

        if(b == D || b == R || b == N)
        {
            gene[a] = b;
        }else
        {
            parent[b].push_back(a);
        }
    }   
}

void GENE::getGene(string child , string P1 , string P2)
{
    if (gene.find(P1) == gene.end())
    {
        getGene(P1, parent[P1][0], parent[P1][1]);
    }

    if (gene.find(P2) == gene.end())
    {
        getGene(P2, parent[P2][0], parent[P2][1]);
    }

    if((gene[P1] == D && gene[P2] == D) ||
       (gene[P1] == D && gene[P2] == R) ||
       (gene[P1] == R && gene[P2] == D))
    {
        gene[child] = D;
    }else if(
       (gene[P1] == R && gene[P2] == R) ||
       (gene[P1] == D && gene[P2] == N) ||
       (gene[P1] == N && gene[P2] == D))

        gene[child] = R;
    else
    {
        gene[child] = N;
    }
}

void GENE::findGene()
{
    for(map<string , vector<string>> :: iterator itr = parent.begin(); itr != parent.end(); ++itr)
    {
        if (gene.find(itr->first) == gene.end())
        {
            getGene(itr->first , itr->second[0] , itr->second[1]);
        }
   }

}

void GENE::printData()
{
    for (map<string, string>::iterator itr = gene.begin(); itr != gene.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    
}


int main()
{
    int samples;
    cin >> samples;
    GENE result(samples);

    result.getData();
    result.findGene();
    result.printData();

    
    return 0;
}