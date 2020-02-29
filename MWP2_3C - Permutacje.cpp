#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<string> words;
    std::string word;
    int t = 0;
    int n = 0;
    int i = 0;
    int j = 0;
    int l = 0;
    long long int perm = 1;
    long long int maxperm = 1;
    long long int perms[10];
    const int maxTestCases = 10;
    cin >> t;
    if (t > 0 && t <= maxTestCases) {
        for (j = 0; j < t; j++) {
            perm = 1;
            maxperm = 1;
            cin >> n;
            if (n < 1 || n > 5000) return -1;
            for (i = 0; i < n; i++) {
                cin >> word;
                words.push_back(word);
            }
            sort(words.begin(), words.end());
            
            for (i = 0; i < n; i++) {
                std::sort(words[i].begin(), words[i].end());
            }
              sort(words.begin(), words.end());
             for (i = 0; i < n -1; i++) {
                l = words[i].length();
                if (l > 0) { 
                    if (words[i] == words[i + 1]) {
                        perm++;
                        if (perm > maxperm) maxperm = perm;
                    }
                    else {
                        if (perm > maxperm) maxperm = perm;
                        perm = 1;
                    }
                }
            }
            perms[j] = maxperm;
            words.clear();
        }
        for (j = 0; j < t; j++) {
            cout << perms[j] << "\n";
        }
    }
    return 0;
}
