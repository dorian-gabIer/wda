#include <iostream>
#include <algorithm>

using namespace std;

struct egz
{
    int dni_nauki;
    int dzien_egz;
};

bool porownaie(egz left, egz right) {
    return left.dzien_egz > right.dzien_egz;
}

int main()
{
    int p;
    cin >> p;
    while (p--) {

        egz egzaminy[100000];

        int ilosc;
        cin >> ilosc;
        for (int i = 0; i < ilosc; ++i) {
            cin >> egzaminy[i].dzien_egz >> egzaminy[i].dni_nauki;
        }

        sort(egzaminy, egzaminy + ilosc, porownaie);

        int poczatek = egzaminy[0].dzien_egz + 1;

        for (int i = 0; i < ilosc; ++i) {
            if (poczatek > egzaminy[i].dzien_egz) {
                poczatek = egzaminy[i].dzien_egz - egzaminy[i].dni_nauki + 1;
            }
            else{
                poczatek -= egzaminy[i].dni_nauki;
            }
        }
        cout << egzaminy[ilosc - 1].dzien_egz - poczatek << endl;
    }
    return 0;
}
