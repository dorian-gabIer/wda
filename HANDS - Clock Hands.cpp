#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    std::string str1T;
    std::string str2T;

    const char *cstr;
    float h1 = 0, h2 = 0, m1 = 0, m2 = 0;
    std::string sh1, sh2, sm1, sm2;
    float t1 = 0, t2 = 0;
    float diff = 0;
    int nover = 0;
    int nintervals = 0;
    int intervals[1000];
    float ovls[22];


    for (int i = 0; i < 22; i++) {
        ovls[i] = 12.0 / 11.0 * (i + 1);
    }

    cin >> nintervals;

    for (int nin = 0; nin < nintervals; nin++) {

        cin >> str1T;
        cin >> str2T;

        sh1 = str1T.substr(0, 2);
        cstr = sh1.c_str();
        h1 = atof(cstr);

        sm1 = str1T.substr(3, 2);
        cstr = sm1.c_str();
        m1 = atof(cstr);

        sh2 = str2T.substr(0, 2);
        cstr = sh2.c_str();
        h2 = atof(cstr);

        sm2 = str2T.substr(3, 2);
        cstr = sm2.c_str();
        m2 = atof(cstr);

        t1 = h1 + m1 / 60;
        t2 = h2 + m2 / 60;

        nover = 0;
        for (int i2 = 0; i2 < 22; i2++) {
            if (ovls[i2] > t1 && ovls[i2] <= t2) {
                nover++;
            }
        }
        intervals[nin] = nover;
    }
    for (int iout = 0; iout < nintervals; iout++) {
        cout << intervals[iout] << "\n";
    }
    return 0;
}
