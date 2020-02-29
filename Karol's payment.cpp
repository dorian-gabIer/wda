//Karol´s Payment
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int* amount = NULL;
    long long int* wanted_money = NULL;
    int t = 0, days = 0, i = 0, ii = 0;
    long long int daily_money = 0, earned_money = 0, temp = 0;
    cin >> t;
    amount = new int[t];
    wanted_money = new long long int[t];
    for (i = 0; i < t; i++)
    {
        cin >> amount[i] >> wanted_money[i];
    }
    for (ii = 0; ii < t; ii++)
    {
        days = 1;
        earned_money = amount[ii];
        daily_money = amount[ii];
        while (earned_money < wanted_money[ii])
        {
            days++;
            temp = earned_money;
            daily_money = daily_money * 2;
            earned_money = temp + daily_money;
        }
        cout << days << endl;
    }
    return 0;
    }
