#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    long long int sum =0, a[n];
    int i=n;

    while(i)
    {
            cin>>a[i];
            sum=sum+a[i];
            i--;

    }

    cout<<sum;
}
