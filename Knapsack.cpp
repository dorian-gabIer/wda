#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2001
int dp[MAX];
int main()
{ 
    int T;
    cin >> T;
    int a[MAX];
    int n, k;
    while(T--)
    {
        fill_n(dp, MAX, 0);
        cin >> n >> k;
        for(int i = 0;i < n; ++i)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= k; ++j)
            {
                if(j >= a[i])
                    dp[j] = max(dp[j-a[i]] + a[i], dp[j]);
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
