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
#include <unordered_map>

//Urlop
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    char a;
    int sun = 0, maxsun = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 'P') {
            if (sun > maxsun) {
                maxsun = sun;
            }
            sun = 0;
        }
        else {
            sun++;
        }
    }
    if (sun > maxsun) {
        maxsun = sun;
    }
    cout << maxsun << endl;
    return 0;
}
