#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    std::string str;  // string for an equation
    std::string sc;   // single character in the equation
    std::string scl;   // character before actual character
    std::string temp; // string to collect numbers 

    int eqs = 0; // amount of equations
    int cmax;    // length of current equation
    string valids = "0123456789+-=x";  // valid characters
    const int maxEqs = 5000;
    std::string results[5000];
    float result = 0;
    float fx = 0;
    float fconst = 0;
    const char* cstr;
    cin >> eqs;
    for (int i = 0; i < eqs; i++) {
        cin >> str;
        temp = "";
        cmax = str.length();
        int multiplicator = 1;
        int ix = 0;          //  sum of the values of x
        int iconst = 0;      //  sum of  the values of const
        int tempval = 0;
        int npos = 0;
        bool eqFound = false;

        for (int j = 0; j < cmax; j++) {
            sc = str.substr(j, 1);
            npos = valids.find(sc);
            if (npos < 0) {
                cout << sc << "<<<  not allowed!";
                return -1;
            }
            switch (sc[0])
            {
            case '-':
                cstr = temp.c_str();
                tempval = atoi(cstr);
                temp = "";
                if (eqFound) {
                    iconst = iconst + tempval * multiplicator;
                }
                else {
                    iconst = iconst + tempval * multiplicator * -1;
                }
                multiplicator = -1;
                break;
            case '+':
                cstr = temp.c_str();
                tempval = atoi(cstr);
                temp = "";
                if (eqFound) {
                    iconst = iconst + tempval * multiplicator;
                }
                else {
                    iconst = iconst + tempval * multiplicator * -1;
                }
                multiplicator = 1;
                break;
            case 'x':
                cstr = temp.c_str();
                tempval = atoi(cstr);
                temp = "";
                if (j == 0) {
                    if (tempval == 0) tempval = 1;
                }
                else {
                    scl = str.substr(j - 1, 1);
                    if (scl == "+" || scl == "-" || scl == "=") {
                        if (tempval == 0) tempval = 1;
                    }
                }
                if (eqFound) {
                    ix = ix + tempval * multiplicator * -1;
                }
                else {
                    ix = ix + tempval * multiplicator;
                }
                multiplicator = 1;
                break;
            case '=':
                if (j == 0) {
                    cout << "+++ Error: = is not allowed at the beginning of the line";
                    return -1;
                }
                if (j == cmax - 1) {
                    cout << "+++ Error: = is not allowed at the end of the line";
                    return -1;
                }
                if (eqFound) {
                    cout << "+++ Error: only one = is allowed.";
                    return -1;
                }
                else {
                    if (temp != "") {
                        cstr = temp.c_str();
                        tempval = atoi(cstr);
                        temp = "";
                        iconst = iconst + tempval * multiplicator * -1;
                        multiplicator = 1;
                    }
                    eqFound = true;
                }
                break;
            default:
                temp = temp + sc;
            }
        }
        if (temp != "") {
            cstr = temp.c_str();
            tempval = atoi(cstr);
            temp = "";
            iconst = iconst + tempval * multiplicator;
            multiplicator = 1;
        }

        if (ix == 0) {
            results[i] = "NO";
        }
        else {
            fconst = iconst;
            fx = ix;
            result = fconst / fx;
            if (result == -0.000000) result = 0.000000;
            results[i] = to_string(result);
        }
    }
    for (int k = 0; k < eqs; k++) {
        cout << results[k] << "\n";
    }
    return 0;
}
