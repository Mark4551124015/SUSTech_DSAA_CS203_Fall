#include <cstdio>
#include <vector>
#include<iostream>
#include<queue>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define pii pair<int, int>
#define N (int)500100
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
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
int n,u,v,m,out;

struct Node{
    vector<int> con;
    bool G,V;
    int data;
}g[N];
queue<int> tmp;
vector<int> giant;

inline void init() {
    // n = read();
    scanf("%lld",&n);
    rep(i,1,n-1) {
        // u = read();
        // v = read();
        scanf("%lld%lld",&u,&v);
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    m = read();
    rep(i,1,m) {
        g[read()].G=true;
    }
}

inline int bfs(int startP){
    giant.clear();
    g[startP].V=true;
    tmp.push(startP);
    g[startP].data = g[startP].G-1;
    while (!tmp.empty()) {
        int cur = tmp.front();
        g[cur].data++;
        if (g[cur].G) giant.push_back(g[cur].data);
        for (int i : g[cur].con) {
            if (!g[i].V) {
                g[i].V=true;
                tmp.push(i);
                g[i].data=g[cur].data;
            }
        }
        tmp.pop();
    }
    rep(i,0,giant.size()-1) {
        if (giant[i]<=giant[i-1] && i > 0) {
            giant[i] = giant[i-1]+1;
        }
        // printf("%lld ", giant[i]);
    }
    // putchar('\n');
    return giant.back();
}

signed main() {
    init();
    g[1].V=true;
    for (int i : g[1].con) {
        out = max(bfs(i),out);
    }
    Write(out);
}
