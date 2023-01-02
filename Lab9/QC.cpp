#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <queue>
#define ll long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 100100
#define maxK 105
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
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


int n, m, k, c;
int u,v;
bool vis[N];

vector<int> color[N];
struct node{
    vector<int> con;        
    int colorDist[maxK];
}g[N];
int q[2*N];
int front, rear;
inline void solution() {
    n = read(); m = read(); k = read(); c = read();
    for (int i = 1; i <= n; i++) {
        int index = read();
        color[index].pb(i);
    }

    for (int i = 0; i < m; i++) {
        u = read(); v = read();
        g[u].con.pb(v);
        g[v].con.pb(u);
    }
    for (int i = 1; i <= k; i++) {
        memset(vis, false, sizeof vis);
        front= 0; rear = 0;
        int curColor = i;
        for (int node : color[curColor]) {
            q[rear++] = node;
            vis[node] = true;
        }
        while (front!=rear) {
            int node = q[front++];
            for (int child : g[node].con) {
                if (vis[child] == true) continue;
                g[child].colorDist[curColor] = g[node].colorDist[curColor] + 1;
                vis[child] = true;
                q[rear++] = child;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].colorDist + 1, g[i].colorDist + k + 1);
        int sum = accumulate(g[i].colorDist + 1, g[i].colorDist + 1 + c, 0);
        Write(sum); putchar(' ');
    }
}

signed main() {
    solution();
    Please AC;
}