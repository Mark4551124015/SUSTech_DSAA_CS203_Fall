#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define pii pair<int, int>
#define vi vector<int>
#define N (int)100010
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug false
#define ln putchar('\n');
ll n, m, cnt, u,v;
//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void read(int& a)
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	a = s * w;
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

struct Node {
    vector<int> con;
    bool V;
}g[N];

inline bool deepSearch(int node, int lastNode) {
    if(g[node].V) return true;
    
    g[node].V = true;
    bool ring = false;
    for (int i : g[node].con) {
        if (i == lastNode) continue;
        if (deepSearch(i, node)) ring = true;
    }
    return ring;
}

inline void solution(){
    n = read(); m = read();
    for(int i = 0; i < m; i++) {
        u = read();
        v = read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    bool ring = false;
    for (int i = 1; i<=n; i++) {
        if (g[i].V) continue;

        if (deepSearch(i, 0)) {
            ring = true;
            break;
        } 
    }
    if(ring)printf("Bad");
    else printf("Good");
}

signed main(){
    solution();
    Please AC;
}
