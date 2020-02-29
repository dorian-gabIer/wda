#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int tests = n;
  int ostatnia = 1;
  for(int k=1; k<=tests; ++k)
  {
    n=0;
    cin >> n;
    for (int i=1; i <= n; i++)
    {
      ostatnia *= i;
      while(ostatnia%10 == 0)
      {
        ostatnia = ostatnia/10;
      }
      ostatnia %= 10000;
      }
ostatnia %= 10;
cout << ostatnia << "\n";
ostatnia = 1;
}
}
