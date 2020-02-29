#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{

    // Array with 1000 lines and 3 columns (xyz)
    int xyz[1000][3];
    int tempx = 0, tempy = 0, tempz = 0;

    int t = 0; // amount of points
    int i = 0; // counter for lines of points
    int j = 0; // counter for inner bubbleSortLoop
    const int maxpoints = 1000;
    const int maxnumber = 1001;
    //Input
    cin >> t;
    if (t > 0 && t <= maxpoints) {
        for (int i = 0; i < t; i++) {
            cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
            if (xyz[i][0] > maxnumber || xyz[i][1] > maxnumber || xyz[i][2] > maxnumber) {
                cout << "You have entered a number higher than " << maxnumber << "\n";
                return 1;
            }
        }
    }
    else {
        cout << "Wrong number of test case! \n";
        return 1;
    }

    // bubbleSort 
    for (int i = 0; i < t-1; i++) {
        for (j=0; j < t-i-1;j++) {
            // based on 1st column
            if (xyz[j][0] > xyz[j + 1][0]) {
                // swap both
                int tempx = xyz[j][0];
                int tempy = xyz[j][1];
                int tempz = xyz[j][2];

                xyz[j][0] = xyz[j + 1][0];
                xyz[j][1] = xyz[j + 1][1];
                xyz[j][2] = xyz[j + 1][2];

                xyz[j + 1][0] = tempx;
                xyz[j + 1][1] = tempy;
                xyz[j + 1][2] = tempz;
            }
            // based on 2nd column
            if (xyz[j][0] == xyz[j + 1][0] && 
                xyz[j][1] >  xyz[j + 1][1]) {

                // swap both
                int tempx = xyz[j][0];
                int tempy = xyz[j][1];
                int tempz = xyz[j][2];

                xyz[j][0] = xyz[j + 1][0];
                xyz[j][1] = xyz[j + 1][1];
                xyz[j][2] = xyz[j + 1][2];

                xyz[j + 1][0] = tempx;
                xyz[j + 1][1] = tempy;
                xyz[j + 1][2] = tempz;
            }
            // based on 3rd column
            if (xyz[j][0] == xyz[j + 1][0] && 
                xyz[j][1] == xyz[j + 1][1] && 
                xyz[j][2] > xyz[j + 1][2]) {

                // swap both
                int tempx = xyz[j][0];
                int tempy = xyz[j][1];
                int tempz = xyz[j][2];

                xyz[j][0] = xyz[j + 1][0];
                xyz[j][1] = xyz[j + 1][1];
                xyz[j][2] = xyz[j + 1][2];

                xyz[j + 1][0] = tempx;
                xyz[j + 1][1] = tempy;
                xyz[j + 1][2] = tempz;
            }

        }
    }
    for (int i = 0; i < t; i++) {
        cout  << xyz[i][0] << " " << xyz[i][1] << " " << xyz[i][2] << "\n";
    }
    return 0;
}
