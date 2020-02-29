#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string text[100];
    char temp;
    int c,
        a = 0,
        nchar = 0,
        Words = 0,
        nTests = 0,
        nNumbers =0,
        offset = 0;
       bool aWord = false;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            aWord = false;
            a++;
            if (c == '\n') {
                text[a] = text[a] + "\n";
            }
        }
        else
        {
            if (aWord == false) {
                Words++;
            }
            temp = c;
            text[a] = text[a] + temp;
            aWord = true;
        }
    }
    nTests = atoi(text[0].c_str());
    for (int j = 1; j <= nTests; j++)
    {
        nNumbers = atoi(text[j+offset].c_str());
        for (int k=1; k <= nNumbers; k++)
        {
            cout << text[j + offset + 1 + nNumbers - k] + " ";
            
        }
        offset = offset + nNumbers;
        cout << " \n";
    }
    return 0;
}
