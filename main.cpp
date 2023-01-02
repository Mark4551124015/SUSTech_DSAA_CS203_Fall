#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#define ll long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 50005
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


int n, m, s;
int u,v;

int top; 
bool visit[N], SCC[N];

struct node{
    vector<int> fr;
    vector<int> to;
    int scc;
}g[N];

int front, rear;
inline void solution() {
    n = read(); m = read(); s = read();
    for (int i = 0; i < m; i++) {
        u = read(); v = read();
        g[u].to.pb(v);
        g[v].fr.pb(u);
    }
    stack<int> stk;
    vi arr;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        stk.push(i); visit[i]=true;
        while (!stk.empty()) {
            top = stk.top();
            bool isScc = true;
            for (int last : g[top].fr) {
                if (visit[last]) continue;
                stk.push(last); visit[last] = true;
                isScc = false;
                break;
            }
            if (isScc) arr.pb(stk.top()); stk.pop();
        }
    }
    int scc = 0;
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; i++) {
        int node = arr[n-i+1];
        if (visit[node]) continue;
        visit[node] = true;
        stk.push(node);
        while (!stk.empty()) {
            int tmp = stk.top();
            bool flag = true;
            for (int next : g[tmp].to) {
                if (visit[next]) continue;
                visit[next] = true;
                stk.push(next);
                flag = false;
                break;
            }
            if (flag) {
                g[stk.top()].scc = scc;
                stk.pop();
            }
        }
        scc++;
    }


    for (int i = 1; i <= n; i++) {
        for (int next : g[i].to) {
            if (g[i].scc != g[next].scc) SCC[g[next].scc] = true;

        }
    }
    SCC[g[s-1].scc] = true;
    int cnt = 0;
    for (int i = 0; i < scc; i++) {
        if (!SCC[i]) cnt++;
    }
    Write(cnt);
}

signed main() {
    solution();
    Please AC;
}