// KarolsSequenz V1.0
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//
    int n, k, q;
    // n: number of different string lengths to check
    // k: the range of values in the string
    // q: 
    cin >> n >> k >> q;

//    int dp[n + 1][k + 1];
    int dp[1000][1000];

    for (int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int sum = dp[i - 1][j];
            sum %= q;
            if (j > 0) {
                sum += dp[i - 1][j - 1];
                sum %= q;
            }
            if (j < k) {
                sum += dp[i - 1][j + 1];
                sum %= q;
            }
            dp[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int d;
        cin >> d;
        for (int j = 0; j <= k; j++) {
            sum += dp[d - 1][j];
        }
         cout << sum % q << ' ';
    }
    return 0;
}
/* Sample 1
Input
3 1 10
1 2 3
Ouput
2 4 8
*/
