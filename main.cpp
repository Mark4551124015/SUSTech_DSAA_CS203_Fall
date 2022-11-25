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
#define N (int)200010
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
int n,u,v,p;
int root, maxP,sum;
vector<int> leaf;
struct Node{
    vector<int> con;
    int data;
    int maxData;
}g[N];

inline void debug(int x) {
    if (isDebug) printf("%lld ",x);
}

//debugged
inline int dfsMaxSon(int node, int lastNode) {
    if (g[node].con.size()==1 && node != root) {
        g[node].maxData = g[node].data;
        return g[node].data;
    }

    for (int i : g[node].con) {
        if (i == lastNode) {
            continue;
        }
        g[node].maxData = max(dfsMaxSon(i,node),g[node].maxData);
    }
    return g[node].maxData;
}


inline void dfsOperation (int node, int lastNode, int maxNode) {
    maxNode = max (maxNode,g[node].data);

    if (g[node].con.size()==1 && node != root) {
        g[node].data = maxNode;
        sum+=maxNode;
        leaf.pb(node);
    }
    
    for (int i : g[node].con) {
        if (i == lastNode) {
            continue;
        }
        if (g[i].maxData == g[node].maxData) {
            dfsOperation(i,node, maxNode);
        } else {
            dfsOperation(i,node, 0);
        }
    }
}


inline void solution() {
    n=read(); 
    g[u].con.pb(v);
    g[v].con.pb(u);
    for(int i = 0; i < n-1; i++) {
        u=read();v=read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    for (int i = 1; i <= n; i++) {
        p = read();
        g[i].data = p;
        if (p > g[maxP].data) {
            maxP = i;
        }
    }
    root = maxP;
    dfsMaxSon(root,0);
    dfsOperation(root,0,0);
    pii t;
    if (! (g[root].con.size() == 1)) {
        for (int i : leaf) {
            if (t.y>t.x) {
                swap(t.x,t.y);
            }
            if (g[t.y].data < g[i].data) {
                t.y = i;
            }
        }
        sum += g[root].data - g[t.y].data;
        sum += g[root].data - g[t.x].data;
    }
    Write(sum);
}
signed main() {
    solution();
    Please AC;
}
