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
#define N (int)100001
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug true
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
    vector<int64_t> con;
    int data;
    bool V;
}g[N];

inline void insertNode(int u, int v){
    g[v].con.pb(u);
    g[v].data = v;
    g[u].data = u;

}

inline void deepSearch(int node, int lastNode, int data) {
    if(g[node].V){
        return;
    }
    g[node].V = true;
    g[node].data = data;
    for (int i = 0; i < g[node].con.size(); i++) {
        if (g[node].con.at(i) == lastNode) {
            continue;
        }
        deepSearch(g[node].con[i], node, data);
    }
}

inline void solution(){
    n = read();
    m = read();
    for(int i = 1; i <= m; i++) {
        u = read();
        v = read();
        insertNode(u,v);
    }
    for (int i = n; i>0; i--) {
        deepSearch(i,0,i);
    }
    for (int i = 1; i<=n; i++) {
        Write(g[i].data); putchar(' ');
    }
}

signed main(){
    solution();
    Please AC;
}
