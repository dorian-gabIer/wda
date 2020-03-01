#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
ll num_t,num_c,cnt,ans1=0,ans2=0;
ll m[maxn<<1],a[maxn<<1],sum[maxn<<1];
struct town
{
    ll id,population;
}
t[maxn<<1], nt[maxn<<1];
struct cloud
{
    ll center,r;
}
c[maxn];
struct New_Cloud
{
    int l,r;
} nc[maxn];
inline ll read()
{
    char c=getchar();
    ll x=0,f=1;
    while(c<'0'||c>'9') f=(c=='-'? -1:1),c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
    return x*f;
}
bool cmp2(const town &a,const town &b)
{
    return a.id<b.id;
}
bool cmp1(const cloud &a,const cloud &b)
{
    if(a.center-a.r==b.center-b.r) return a.center+a.r<b.center+b.r;
    return a.center-a.r<b.center-b.r;
}
inline void init_newtown()
{
    sort(t+1,t+num_t+1,cmp2);
    for(int i=1; i<=num_t; i++) nt[i].population=0;
    cnt=1;
    nt[1].id=1,nt[1].population+=t[1].population;
    m[1]=t[1].id;
    for(int i=2; i<=num_t; i++)
    {
        if(t[i].id!=t[i-1].id) cnt++,m[cnt]=t[i].id;
        nt[cnt].population+=t[i].population,nt[cnt].id=cnt;
    }
}
inline void init_newcloud()
{
    sort(c+1,c+num_c+1,cmp1);
    for(int i=1; i<=num_c; i++)
    {
        ll left=c[i].center-c[i].r,right=c[i].center+c[i].r;
        if(left<=m[1]) nc[i].l=1;
        else nc[i].l=lower_bound(m+1,m+cnt+1,left)-m;
        if(right>=m[cnt]) nc[i].r=cnt;
        else nc[i].r=upper_bound(m+1,m+cnt+1,right)-m-1;
    }
}
int main() {
    num_t=read();
    for(int i=1; i<=num_t; i++) t[i].population=0;
    for(int i=1; i<=num_t; i++) t[i].population=read();
    for(int i=1; i<=num_t; i++) t[i].id=read();
    init_newtown();
    num_c=read();
    for(int i=1; i<=num_c; i++) c[i].center=read();
    for(int i=1; i<=num_c; i++) c[i].r=read();
    init_newcloud();
    memset(a,0,sizeof(a));
    for(int i=1; i<=num_c; i++)
    {
        if(nc[i].r>=nc[i].l) {
            a[nc[i].l]+=1;
            if(nc[i].r+1<=cnt) a[nc[i].r+1]-=1;
        }
    }
    for(int i=1; i<=cnt; i++) a[i]+=a[i-1];
    sum[0]=0;
    for(int i=1; i<=cnt; i++)
    {
        if(!a[i]) ans1+=nt[i].population;
        sum[i]=sum[i-1]+(a[i]>1? 0:nt[i].population);
    }
    for(int i=1; i<=num_c; i++)
    {
        if(nc[i].r>=nc[i].l) ans2=max(ans2,sum[nc[i].r]-sum[nc[i].l-1]);
    }
    cout<<ans1+ans2;
    return 0;
}
