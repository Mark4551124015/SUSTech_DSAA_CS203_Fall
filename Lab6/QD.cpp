#include <cstdio>
#include <vector>
#include <queue>
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
int n,u,v,p;
int root,sumAll;
struct Node{
    vector<int> con;
    int data;
    int maxSon;
}g[N];

inline void dfsMax(int node, int lastNode) {
    if (g[node].con.size()==1 && node != root) {
        g[node].maxSon = node;
    }
    for (int i : g[node].con) {
        if (i == lastNode) {
            continue;
        }
        dfsMax(i,node);
        if (g[i].data > g[node].data) {
            g[node].data = g[i].data;
        }
        if (g[i].data > g[g[node].maxSon].data) {
            g[node].maxSon = i;
        }   
    }     
}

inline void specialCondition(){
    int secMax = 0;
    for (int i : g[root].con) {
        if (i!=g[root].maxSon && g[i].data > g[secMax].data) {
            secMax = i;
        }
    }
    if (g[secMax].data) {
        g[secMax].data = g[root].data;
    } else {
        sumAll += g[root].data;
    }
}

inline void dfsOp(int node, int lastNode) {
    if (g[node].con.size()==1 && node != root) {
        sumAll+=g[node].data;
        return;
    }
    g[g[node].maxSon].data = g[node].data;
    for (int i : g[node].con) {
        if (i == lastNode) {
            continue;
        }
        dfsOp(i,node);
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
        if (p > g[root].data) {
            root = i;
        }
    }
    dfsMax(root,0);
    specialCondition();
    dfsOp(root,0);
    Write(sumAll);
}
signed main() {
    solution();
    Please AC;
}
