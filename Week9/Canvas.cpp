#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int SIZE = 500;
// Area matrix
char **screen;

int icons[50][3];
int nIcons = 0;

int nearest[50];
int num_near;

void fillRegion(int x0, int y0, int x1, int y1);
void findNearestIcon(int x, int y);
float distance(int x0, int y0, int x1, int y1);

int main() {

    // Initialize the screen matrix

    screen = new char*[SIZE];

    for (int i=0; i<SIZE; i++) {
        screen[i] = new char[SIZE];
        for (int j=0; j<SIZE; j++) {
            screen[i][j] = '_';
        }
    }

    char type;
    cin >> type;

    int x0, y0, x1, y1;

    while (type != 'M') {
        cin >> x0 >> y0;

        // Input is a Region
        if (type == 'R') {
            cin >> x1 >> y1;
          
            if (x0 > x1) swap(x0, x1);
            if (y0 > y1) swap(y0, y1);
          
            fillRegion(x0, y0, x1, y1);

        // Input is an Icon
        } else {
            icons[nIcons][0] = x0;
            icons[nIcons][1] = y0;
            nIcons++;
        }

        // Read type
        cin >> type;
    }

    // First mouse click, end of regions and icons
    // Check visibility of each icon
    for (int k=0; k<nIcons; k++) {
        int x = icons[k][0];
        int y = icons[k][1];

        // The icon is visible
        icons[k][2] = screen[x][y] == '_';

        // If the icon is visible, mark it on screen
        if (icons[k][2]) {
            screen[x][y] = k + 1;
            //cout << k + 1 << endl;
        }
    }

    while (type == 'M') {
        cin >> x0 >> y0;

        char s = screen[x0][y0];

        // If clicked over a region
        if ('A' <= s && s <= 'Z') {
            cout << s << endl;

        // If clicked on icon
        } else if (1 <= s && s <= 50) {
            cout << setw(3) << s << endl;
        // Find the nearest icon(s)
        } else {
            findNearestIcon(x0, y0);
            // Print icon(s)
            for (int d=0; d<num_near; d++)
                cout << setw(3) << nearest[d];
            cout << endl;
        }

        // Read type
        cin >> type;
    }

    // Delete screen matrix after
    for (int i=0; i<SIZE; i++) {
        delete [] screen[i];
    }
    delete [] screen;

    return 0;
}


void fillRegion(int x0, int y0, int x1, int y1) {
    if (!screen) return;

    static char letter = 'A';

    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            screen[i][j] = letter;          // Overwrite past regions and icons
        }
    }

    // Use the next letter of the alphabet
    letter = letter + 1;
}

void findNearestIcon(int x, int y) {

    int first = 0;

    while (first < nIcons && !icons[first][2]) {
        first++;
    }
    
    float mindis = distance(x, y, icons[first][0], icons[first][1]);
    nearest[0] = 1 + first;
    num_near = 1;
    float dis;

    for (int i = first + 1; i<nIcons; i++) {

        // Skip icons that are not visible
        if (!icons[i][2]) continue;

        dis = distance(x, y, icons[i][0], icons[i][1]);
      
        if (dis < mindis) {
            mindis = dis;
            num_near = 1;
            nearest[0] = 1 + i;
        } else if (dis == mindis) {
            nearest[num_near++] = 1 + i;
        }
    }
}

float distance(int x0, int y0, int x1, int y1) {
    return sqrtf(pow(x0-x1, 2) + pow(y0-y1, 2));
}