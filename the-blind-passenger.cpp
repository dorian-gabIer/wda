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
using namespace std;
int main() {
    int test_count;
    std::cin >> test_count;
    for (int i = 0; i < test_count; ++i)
    {
        int seat_number;
        std::cin >> seat_number;
        if (seat_number == 1)
        {
            std::cout << "poor conductor\n";
        }
        else
        {
            static constexpr char side[] =   { 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', };
            static constexpr char column[] = { 'W', 'A', 'A', 'M', 'W', 'W', 'M', 'A', 'A', 'W' };
            const int idx = ((seat_number - 2) % 10);
            const int row = ((seat_number - 2) / 5) + 1;
            std::cout << row << " " << column[idx] << " " << side[idx] << "\n";
        }
    }
    return 0;
}
