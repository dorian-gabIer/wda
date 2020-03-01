#include <iostream>
using namespace std;
int main()
{
    char symbol, temp, temp2;
    bool lineComment = false;
    bool blockComment = false;
    bool cString = false;
    while (cin.get(symbol))
    {
        if (lineComment)
        {
            if (symbol == '\n')
            {
                lineComment = false;
                cout << symbol;
            }
        }
        else if (blockComment)
        {
            while (symbol == '*')
            {
                if (cin.get(symbol))
                {
                    if (symbol == '/')
                        blockComment = false;
                }
                else
                    break;
            }
        }
        else
        {
            if (cString)
            {
                cout << symbol;
                if ((symbol == '\n' && temp != '\\') || (symbol == '"' && temp != '\\') || (symbol == '"' && temp == '\\' && temp2 == '\\'))
                // zamiana symbol na temp - zalicza 3, nie zalicza 10 i 11;
                // moze spacje po symbolu ucieczki?
                // zrobic flage escape ktora sie wylacza po dowolnej literce
                // po escape.
                    cString = false;
            }
            else
            {
                if (symbol == '/')
                {
                    temp = symbol;
                    if (cin.get(symbol))
                    {
                        if (symbol == '/')
                        {
                            lineComment = true;
                        }
                        else if (symbol == '*')
                        {
                            blockComment = true;
                        }
                        else
                        {
                            cout << temp << symbol;
                        }
                    }
                    else
                    {
                        cout << temp;
                        break;
                    }
                }
                else
                {
                    if (symbol == '"' && temp != '\'')
                        cString = true;
                    cout << symbol;
                }
            }
        }
        temp2 = temp;
        temp = symbol;
    }
    return 0;
}
