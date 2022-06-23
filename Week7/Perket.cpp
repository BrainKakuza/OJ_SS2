#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int max , smallest = 1000000000;

    cin >> max;

    int array[max][2];

    for (int i = 0; i < max; i++)
    {
        cin >> array[i][0] >> array[i][1];
    }

    int possiblilty = pow(2,max) - 1;

    for (int i = 1; i <= possiblilty; i++)
    {
        int temp = i;
        int baseSecond = 0 , mixSweet = 1 , mixBitter = 0;

        for (int j = max - 1; j >= 0 ; j--)
        {
            if(temp - pow(2,j) >= 0 && temp > 0){
                baseSecond += pow(10,j);
                temp -= pow(2,j);
            }
        }

        //cout << "Base: "<<baseSecond << endl;

        for (int j = max - 1; j >= 0; j--)
        {
            if(baseSecond - pow(10,j) >= 0 && baseSecond > 0){
                mixSweet *= array[j][0];
                mixBitter += array[j][1];
                baseSecond -= pow(10,j);
            } 
        }

        int result = abs(mixBitter - mixSweet);

        // if(result == 1){
        //     cout << "mixSweet: " << mixSweet << endl;
        //     cout << "mixBitter: " << mixBitter << endl;
        // }

        //cout << result << endl;

        if(result < smallest){
            smallest = result;
        }
        
        
    }

    //cout << endl;
    cout << smallest << endl;
        
    
    
    
    return 0;
}