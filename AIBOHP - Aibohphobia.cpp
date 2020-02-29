#include<bits/stdc++.h>
using namespace std;
int dp[6110][6110];
int findMinInsertion(string &str) {
    for(int i=0;i<str.length();i++)
        dp[i][i] = 0;
    for(int i=2;i<=str.length();i++) {
        for(int j=0;j<str.length()-i+1;j++) {
            int e = j + i - 1;
            if(str[e] == str[j] && i == 2)
                dp[j][e] = 0;
            else if(str[e] == str[j])
                dp[j][e] = dp[j+1][e-1];
            else
                dp[j][e] = 1 + min(dp[j+1][e],dp[j][e-1]);
        }
    }
    return dp[0][str.length()-1];
}
int main() {
    int t;
    cin>>t;
    string str;
    while(t--) {
        cin>>str;
        for(int i=0;i<str.length()+1;i++)
            for(int j=0;j<str.length()+1;j++)
                dp[i][j] = INT_MAX;
        cout<<findMinInsertion(str)<<endl;
    }

    return 0;
}
