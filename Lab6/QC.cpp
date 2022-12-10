#include <cstdio>
#include <cstring>
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
#define N (int)400010
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug false
#define ln putchar('\n');
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
int n,u,v,w,m;
int root, ans, l ,r, mid;
int checked[N];
bool good=true;
vector<pair<pii,int>> query;
struct Node{
    vector<int> con;
    pii range;
    int parent;
    int size;
}g[N],origin[N];

inline int dfsSize(ll node, ll lastNode) {
    int cnt = 0;
    g[node].parent = lastNode;
    for (ll i = 0; i < g[node].con.size(); i++) {
        if (g[node].con.at(i) == lastNode) {
            continue;
        }
        cnt += dfsSize(g[node].con.at(i), node);
    }
    g[node].size = cnt+1;
    g[node].range = {0,g[node].size};
    return g[node].size;
}

inline pii cross(pii a, pii b) {
    pii p = {max(a.x,b.x), min(a.y,b.y)};
    if (p.x > p.y) {
        good = false;
    }
    return p;
}

inline pii sumR(pii a, pii b) {
    pii p = {a.x+b.x, a.y+b.y};
    if (p.x > p.y) {
        good = false;
    }
    return p;
}

inline pii getRange(int node) {
    pii tmp = {0,0};
    for (int i : g[node].con) {
        if (i == g[node].parent) {
            if (g[node].con.size()==1) {
                return g[node].range;
            }
            continue;
        }
        tmp = sumR(tmp, getRange(i));
    }
    tmp.y = tmp.y+1;
    if (!checked[node]) {
        g[node].range = cross(tmp, {0,g[node].size});
        checked[node] = 1;
    } else {
        g[node].range = cross(tmp, g[node].range);
    }
    return g[node].range;
}

inline bool check (int input) {
    pii range;
    memset(checked,0,sizeof(checked));
    good = true;
    for (pair<pii,int> p : query) {
        if (g[p.x.x].parent == p.x.y) {
            int node = p.x.x;
            if (!checked[node]) {
                g[node].range = cross( {p.y, g[node].size}, {0,g[node].size});
                checked[node] = 1;
            } else {
                g[node].range = cross(g[node].range, {p.y, g[node].size});
            }
            
        } else {
            int node = p.x.y;
            if (!checked[node]) {
                g[node].range = cross(  {0, input - p.y}, {0,g[node].size});
                checked[node] = 1;
            } else {
                g[node].range = cross(g[node].range,  {0, input - p.y});
            }
        }
    }
    
    range = getRange(root);
    // showRange(root,0);
    // ln;
    if (input >= range.x && input <= range.y && good) {
        return true;
    }
    return false;
}

inline void solution() {
    n = read();
    for(int i = 0; i < n-1; i++) {
        u = read();v = read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    root = u;
    m = read();
    dfsSize(root,0);
    for (int i = 0; i < m; i++) {
        u = read();v = read();w= read();
        query.pb({{u,v},w});
    }

    l = 0; r = n; 
    mid = (l+r)/2;
    while (l<=r) {
        mid = (l+r)/2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }   
    }

    if (ans) {
        Write(ans);
    }else {
        Write (-1);
    }
}

signed main() {
    solution();
    Please AC;
}
