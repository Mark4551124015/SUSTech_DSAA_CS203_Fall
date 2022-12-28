#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 100100
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define isDebug false
#define debugLn if(isDebug)putchar('\n')

//Fast RW
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}
inline void debug(string a){
    if (isDebug) printf("%s",a.c_str());
}
inline void debug(int a){
    if (isDebug) printf("%lld ",a);
}
inline void debug(string a, int b){
    if (isDebug) printf("%s: %lld\n",a.c_str(),b);
}

int n, m;
int con[N][N];
struct node{
    bool isSure;
    int dist = 0x3f;
}g[N];

inline void solution() {
    while () {
        
    }
    g[1].isSure = true;
    g[1].dist = 0;
    for (int i = 1; i <= n; i++) {

    }
}

signed main() {
    solution();
    Please AC;
}
