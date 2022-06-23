/*
Description

An airline catalog consists of a list of flights between pairs of cities. A trip may be built by sequencing flights. 
Two airline companies are equivalent if they offer connections between the same pairs of cities
,irrespective of the number of scales in between.

Given the catalogs of two airline companies, determine if they are equivalent or not.

Input
The input begins with a single positive integer on a line by itself indicating the number of the cases following
, each of them as described below.This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The input contains:

• First line: the number N of flights in the catalog of the first company;

• N subsequent lines: two uppercase alphabet characters separated by one space
, for the names of the origin and destination cities of a flight;

• Line N + 2: the number M of flights in the catalog of the second company;

• M subsequent lines: two uppercase alphabet characters separated by one space, for the names of the origin and destination cities of a flight.


Output
For each test case, the output must follow the description below. 
The outputs of two consecutive cases will be separated by a blank line.

One line containing ‘YES’ or ‘NO’

Sample Input 1 
1
6
A B
B E
AE
C F
E C
D A
7
A B
D A
E C
C F
D B
B E
D F

Sample Output 1
YES
*/

// Airline Comparison
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::swap;

bool **a1, **a2;

void transitiveClosure(bool **m);
bool areEquivalent(bool **m1, bool **m2);

int main() {
    //Test cases
    int T;
    cin >> T;

    // Create and initialize matrices for the airlines
    // value a[i][j] of the matrix will be true if there
    // is a connection between cities i and j

    // airline 1
    a1 = new bool*[26];
    for (int i = 0; i < 26; i++)
        a1[i] = new bool[26];

    // airline 2
    a2 = new bool*[26];
    for (int i = 0; i < 26; i++)
        a2[i] = new bool[26];

    char c1, c2;

    // Go over every test case
    for (; T-->0;) {

        // Every connection is set to false at the beginning
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++) {
                a1[i][j] = false;
                a2[i][j] = false;
            }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            // Read connections for airline 1
            cin >> c1;
            cin >> c2;

            a1[c1 - 'A'][c2 - 'A'] = true;
            a1[c2 - 'A'][c1 - 'A'] = true;
            // cout << i+1 << ". Connection: " << city1 << " " << city2 << endl;
        }

        cin >> n;
        for (int i = 0; i < n; i++) {
            // Read connections for airline 2
            cin >> c1;
            cin >> c2;

            a2[c1 - 'A'][c2 - 'A'] = true;
            a2[c2 - 'A'][c1 - 'A'] = true;
        }

        // Calculate transitive closure of each matrix
        transitiveClosure(a1);
        transitiveClosure(a2);

        if (areEquivalent(a1, a2))
            cout << "YES\n\n";
        else
            cout << "NO\n\n";
    }

    // Delete matrices for both airlines

    // airline 1
    for (int i = 0; i < 26; i++)
        delete[] a1[i];
    delete[] a1;

    // airline 2
    for (int i = 0; i < 26; i++)
        delete[] a2[i];
    delete[] a2;

    return 0;
}

void transitiveClosure(bool **m) {
    if (m == nullptr) return;

    for (int k=0; k<26; k++) {
        for (int i = 0; i < 26; i++) {
            if (i == k ||  !m[i][k]) continue;
            for (int j = 0; j < 26; j++) {
                if (i == j  && j == k  && !m[k][j]) continue;
                if (!m[i][j]) {
                    m[i][j] = true;
                }
            }
        }
    }

}

bool areEquivalent(bool **m1, bool **m2) {
    if(!m1 || !m2) return false;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (m1[i][j] != m2[i][j]) return false;
    return true;
}