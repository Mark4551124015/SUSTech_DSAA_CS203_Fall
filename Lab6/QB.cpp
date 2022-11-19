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
int n,u,v,m;
struct Node{
    vector<int> con;
    bool G,V;
    int data;
}g[N];
vector<int> giant;
queue<int> tmp;
inline void init() {
    n = read();
    rep(i,1,n-1) {
        u = read();
        v = read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    m = read();
    rep(i,1,m) {
        g[read()].G=true;
    }
}

inline void bfs(){
    g[1].V=true;
    tmp.push(1);
    g[1].data = g[1].G-1;

    while (!tmp.empty()) {
        g[tmp.front()].data++;
        if (g[tmp.front()].G) giant.push_back(g[tmp.front()].data);

        for (int i : g[tmp.front()].con) {
            if (!g[i].V) {
                g[i].V=true;
                tmp.push(i);
                g[i].data=g[tmp.front()].data;
            }
        }
        tmp.pop();
    }

    for (int i : giant) {
        printf("%lld ", i);
    }




}

signed main() {
    init();
    bfs();
    

}
