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
#define N (int)400100
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug true

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
int root, ans, com, tmp;
vector<pair<pii,int>> query;
struct Node{
    vector<int> con;
    bool cutted;
    int parent;
    int size;
}g[N];

vector<int> T[N];

inline void debug(int x) {
    if (isDebug) printf("%lld ",x);
}

inline bool isCutted(int node) {
    if (g[node].cutted) {
        return true;
    }
    if (tmp!=root && node == root) {
        com = 0;
        return true;
    }

    if (g[node].parent == tmp) {
        return false;
    }
    return isCutted(g[node].parent);
}

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
    // debug(cnt+1);
    return g[node].size;
}

inline void findCom(){
    for (pair<pii,int> index : query) {
        printf("now cutting: %d\n", index.x.y);

        if (!com) {

            break;
        }
        if (isCutted(index.x.y)) {
            debug(111);
            continue;
        }
        g[index.x.y].cutted = true;

        if (g[index.x.x].parent == index.x.y) {
            tmp = index.x.x;
            com = g[tmp].size;
            continue;
        }
        com -= g[index.x.y].size;
    }

    // debug(com);




}

bool handle(int u, int v, int na) {
    if (g[u].parent == v) {
        swap(u,v);
    } 
    int rem = g[root].size - g[v].size;
    if (ans >= na && rem >= na) {
        return true;
    } else {
        ans = -1;
        return false;
    }
    return false;


    
}

inline void solution() {
    n=read();
    for(int i = 0; i < n-1; i++) {
        u=read();v=read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    int comSize = g[root].size;
    m=read();
    for (int i = 0; i < m; i++) {
        u = read(); v = read(); w = read();
        query.pb({{u,v},w});
    }
    root = query.front().x.x;

    tmp = root;
    com = dfsSize(root, root);
    findCom();




}

signed main() {
    solution();
    Please AC;
}
