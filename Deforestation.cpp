#include <bits/stdc++.h>
template<typename T> T gcd(T a, T b)
{
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}
template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;
const int MAXN = 550;
int T, N;
vector<int> G[MAXN];
int dfs(int node, int parent)
{
    int x = 0;
    for (int i = 0; i < (int) G[node].size(); i++)
    {
        int u = G[node][i];
        if (u != parent)
        {
            x ^= (dfs(u, node) + 1);
        }
    }
    return x;            
}
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 0; i <= N; i++)
        {
            G[i].clear();
        }
        for (int i = 0; i < N - 1; i++)
        {
            int U, V;
            cin >> U >> V;

            G[U].push_back(V);
            G[V].push_back(U);
        }
        int val = dfs(1, -1);
        if (val)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
