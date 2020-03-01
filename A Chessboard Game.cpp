#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    bool chess[32][32];
    chess[0][0] = false;
    chess[0][1] = false;
    chess[0][2] = true;
    chess[1][0] = false;
    chess[1][1] = false;
    chess[2][0] = true;
    for(int i = 3; i < 32; i++) {
        int tmp = i;
        for(int j = 0; j <= i; j++) {
            if(tmp - 2 >= 0 && j + 1 < 15 && chess[tmp-2][j+1] == false) {
                chess[tmp][j] = true;
            } else if(tmp - 2 >= 0 && j - 1 >= 0 && chess[tmp-2][j-1] == false) {
                chess[tmp][j] = true;
            } else if(tmp + 1 < 15 && j - 2 >= 0 && chess[tmp+1][j-2] == false) {
                chess[tmp][j] = true;
            } else if(tmp - 1 >= 0 && j - 2 >= 0 && chess[tmp-1][j-2] == false) {
                chess[tmp][j] = true;
            } else {
                chess[tmp][j] = false;
            }
            tmp--;
        }
    }
    while(T > 0) {
        int x, y;
        cin>>x>>y;
        if(chess[x-1][y-1]) {
            cout<<"First\n";
        } else {
            cout<<"Second\n";
        }
        T--;
    } 
    return 0;
}
