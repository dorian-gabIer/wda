#include <iostream>
using namespace std;
int nwd(int a, int b) {
    if (b == 0) 
        return a;
    return nwd(b, (a % b));
}
int main() {
    int cases;
    std::cin >> cases;
    for(int i = 0; i < cases; ++i) {
        int first, last;
        cin >> first >> last;
        std::cout << nwd(first, last) << "\n";
    }
}
