#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
//Pinezk1
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    int skip = 0, maxskip = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 0) {
            if (skip > maxskip) {
                maxskip = skip;
            }
            skip = 0;
        }
        else {
            skip++;
        }
    }
    if (skip > maxskip) {
            maxskip = skip;
    }
    cout << maxskip << endl;
    return 0;
}
