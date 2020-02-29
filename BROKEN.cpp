#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;

int main(){
  int n,i,j,k;
  string s;
  cin>>n;
  while(n!=0){
    getchar();
    getline(cin,s);
    map<char,int> m;
    set<char> mySet;
    for(i=0;i<s.length() && i<n;i++){
      if(!m[s[i]]){
    m[s[i]]=1;
    mySet.insert(s[i]);
      }
      else{
    m[s[i]]++;
      }
    }
    j=0;
    k = i-j;
    while( i < s.length() ){
      mySet.insert(s[i]);
      m[s[i]]++;
      if( mySet.size() > n){
    while( m[s[j]]>1)
      m[s[j++]]--;
    m[s[j]]=0;
    mySet.erase(s[j++]);
      }
      i++;
      k = max(k,i-j);
    }
    cout<<k<<endl;
    cin>>n;
  }
}
