#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<char, vector<char>> airlineSample;
map<char, vector<char>> sampleInput;

map<char, vector<char>> airlineTest;
map<char, vector<char>> testInput;

class Flight
{
public:
    bool checkFlight(char a, char b, vector<char> visited, map<char, vector<char>> airline)
    {
        bool connect = false;

        visited.push_back(a);

        auto sec = airline[a];
        int size = sec.size();

        //cout << "Now in city: " << a << endl;

        // for (map<char, vector<char>>::iterator itr = airline.begin(); itr != airline.end(); itr++)
        // {
        // if (itr->first == a)
        // {
        // int size = itr->second.size();

        for (int i = 0; i < size; i++)
        {
            if (sec[i] == b)
            {
                //cout << "Can go to city " << b << endl;
                return true;
            }
            else if (i < size)
            {
                //cout << "first " << sec[i] << " "
                     //<< "second " << b << endl;
                char newdest = sec[i];

                if (find(visited.begin(), visited.end(), newdest) == visited.end())
                {
                    //cout << "Going to city: " << newdest << endl;
                    //cout << "Destination: " << b << endl;
                    connect = checkFlight(newdest, b, visited , airline);
                    if (connect)
                    {
                        return true;
                    }
                }
                else
                {
                    // cout << "City " << newdest << " has already been visited\n";
                }
            }
        }

        return false;
    }
};

int main(void)
{
    int testCase;

    cin >> testCase;

    for (int i = testCase; i > 0; i--)
    {
        int sampleLine;

        cin >> sampleLine;

        while (sampleLine--)
        {
            char a, b;

            cin >> a >> b;

            sampleInput[a].push_back(b);

            airlineSample[a].push_back(b);
            airlineSample[b].push_back(a);
        }

        int testflight;
        cin >> testflight;

        while (testflight--)
        {
            char a, b;

            cin >> a >> b;

            testInput[a].push_back(b);

            airlineTest[a].push_back(b);
            airlineTest[b].push_back(a);
        }

        bool connectSample = true;
        bool connectTest = true;

        int sampleNum = airlineSample.size();
        int testNum = airlineTest.size();

        vector<char> visited;

        for (map<char, vector<char>>::iterator itr = sampleInput.begin(); itr != sampleInput.end(); itr++)
        {
            Flight flight;

            visited.clear();

            connectSample = flight.checkFlight(itr->first, itr->second[0], visited, airlineTest);

            if (!connectSample)
            {
                break;
            }
        }

        visited.clear();

        cout << endl;

        for (map<char, vector<char>>::iterator itr = testInput.begin(); itr != testInput.end(); itr++)
        {
            Flight flight;

            visited.clear();

            connectTest = flight.checkFlight(itr->first, itr->second[0], visited, airlineSample);

            if (!connectTest)
            {
                break;
            }
        }

        // while (sampleNum)
        // {
        //     Flight flight;

        //     visited.clear();
        //     //cout << "Elements in visited:\n" << endl;
        //     // for (auto element : visited) {
        //     //     cout << element << " ";
        //     // }
        //     // cout << endl;
        //     connectSample = flight.checkFlight(a,b, visited);

        //     if (!connectSample)
        //     {
        //         break;
        //     }
        // }

        if (connectSample && connectTest)
        {
            cout << "YES" << endl
                 << endl;
        }
        else
        {
            cout << "NO" << endl
                 << endl;
        }

        airlineSample.clear();
        sampleInput.clear();
        airlineTest.clear();
        testInput.clear();
    }
}