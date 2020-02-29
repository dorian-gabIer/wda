#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iterator>
#include <numeric>
#include <string.h>
#include <stdio.h>
#define _WIN32_WINNT 0x0502
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#define FALSE 0
#define TRUE  1
using namespace std;
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

string encrypt(string tekst)
{
    int i = 0;
    int klucz = 3;
    int ilosc_liter = 'Z' - 'A' + 1;
    klucz = klucz % ilosc_liter;
    while( tekst[ i ] != '\0')
    {
        tekst[ i ] += klucz;
        if(( unsigned char ) tekst[ i ] > 'Z') tekst[ i ] -= ilosc_liter;
        
        if(( unsigned char ) tekst[ i ] < 'A') tekst[ i ] += ilosc_liter;

        i++;
    }
    return tekst;
}
int main() {
    /*string s;
    cin >> s;
    cout << split(s, " ");
    return 0;*/
        string text[100];
    char temp;
    int c,
        aWord = FALSE,
        a = 0,
        Words = 0; // amount of words

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\n' || c == '\t') {
            aWord = FALSE;
            if(text[a] != " " && text[a] != "\t")
            {
                a++;
            }
            if(c == '\n')
            {
                
                text[a] = text[a] + "\n";
                a++;
            }
        }
        else {
            if (aWord == FALSE) {
                Words++;
            }
            temp = c;
            text[a] = text[a] + temp;
            aWord = TRUE;
        }
    }
    for(int i = 0; i <= a; i++)
    {
        if(text[i] != "\n")
        {
            cout << encrypt(text[i]) + " ";
        }
        if(text[i] == "\n")
        {
            cout << text[i];
        }
    }
}
