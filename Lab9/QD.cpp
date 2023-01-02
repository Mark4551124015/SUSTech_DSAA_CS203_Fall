#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 50000
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')

//Fast RW
inline int read(){
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}


int n, m, s, u ,v;
int scc, cnt;

bool visit[N], inScc[N];
vi arr;

struct node{
    int scc;
    vector<int> fr;
    vector<int> to;
}g[N];

inline void buildArr(int node) {
    visit[node] = true;
    for (int child : g[node].fr) {
        if (!visit[child]) buildArr(child);
    }
    arr.pb(node);
}

inline void buildScc(int node, int scc) {
    visit[node] = true;
    for (int child : g[node].to) {
        if (!visit[child]) buildScc(child, scc);
    }
    g[node].scc = scc;
}


inline void solution() {
    n = read(); m = read(); s = read();
    for (int i = 0; i < m; i++) {
        u = read(); v = read();
        g[u].to.pb(v);
        g[v].fr.pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        buildArr(i);
    }
    memset(visit, false, sizeof(visit));
    for (int i = n - 1 ; i >= 0; i--) {
        if (visit[arr[i]]) continue;
        buildScc(arr[i], scc);
        scc++;
    }

    for (int i = 1; i <= n; i++) {
        for (int next : g[i].to) {
            if (g[i].scc != g[next].scc) inScc[g[next].scc] = true;
        }
    }
    inScc[g[s].scc] = true;

    for (int i = 0; i < scc; i++) {
        if (!inScc[i]) cnt++;
    }
    Write(cnt);
}

signed main() {
    solution();
    Please AC;
}

