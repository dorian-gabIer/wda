#include<stdio.h>
#include<algorithm>
using namespace std;
int stalls[100001] , n , c;
bool check(int gap)
{
    int i , pre = stalls[0], cnt = 1;
    for(i=1;i<n;i++)
        if(stalls[i] -pre>= gap)
            pre = stalls[i] , cnt++;
    return cnt >= c;
}
int main()
{
    int i, cases;
    int s , e, ret;

    scanf("%d",&cases);
    while(cases--)
    {

        scanf("%d %d",&n,&c);
        for(i=0;i<n;i++)
            scanf("%d",&stalls[i]);
        sort(stalls,stalls+n);

        s = 0, e = 1e9;
        while(s <= e)
        {
            int mid = (s+e)/2;
            if(check(mid))
                s = mid+1 , ret = mid;
            else
                e = mid-1;
        }
        printf("%d\n",ret);
    }
}
