#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T > 0) {
        int N;
        cin>>N;
        long long *pile = new long long[N];
        for(int i = 0; i < N; i++) {
            cin>>pile[i];
        }
        if(N == 1) {
            cout<<"Second\n";
            T--;
            continue;
        }
        long long nimSum = 0;
        for(int i = 1; i < N; i++) {
            if(pile[i] % 2 == 1) {
                nimSum ^= i;
            }
        }
        if(nimSum != 0) {
            cout<<"First\n";
        } else {
            cout<<"Second\n";
        }
        T--;
    }
    return 0;
}
