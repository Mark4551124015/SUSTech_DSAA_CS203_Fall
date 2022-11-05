#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull M=131;
const ull N=1e6+10;
ull H1[N],H2[N],p[N];

ull f1(int l,int r)
{
    return H1[r]-H1[l-1]*p[r-l+1];
}

ull f2(int l,int r)
{
    return H2[l]-H2[r+1]*p[r-l+1];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int l,r;
    //初始化
    p[0]=1;
    for(int i=1;i<s.length();i++)
      {
           p[i]=p[i-1]*M;
      }
      s=" "+s;
        H1[0]=0;
        H2[s.length()]=0;
    for(int i=1;i<s.length();i++)
    {
        H1[i]=H1[i-1]*M+s[i]-'a';
        H2[s.length()-i]=H2[s.length()-i+1]*M+s[s.length()-i]-'a';
    }
    while(q--)
    {
        cin>>l>>r;
        bool f=(f1(l,r)==f2(l,r));
        if((r-l+1)%2==0||f)
            cout<<"Budada\n";
        else cout<<"Putata\n";
    }
    return 0;
}
