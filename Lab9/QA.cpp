#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 100100
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define MAX 1000000000000000
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


int n, m;
int u,v,w;
int top;

struct node{
    bool isSure = false;
    int data = MAX;
    vector<pii> con;        //x is node, y is cost
}g[N];

struct cmp
{
    bool operator()(int a, int b) {
        return g[a].data > g[b].data;
    };
};

inline void solution() {
    priority_queue<int,vector<int>,cmp> heap;
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        u = read(); v = read(); w = read(); 
        g[u].con.pb({v,w});
    }
    g[1].data = 0;
    heap.push(1);
    while (!heap.empty()) {
        top = heap.top();
        if (g[top].isSure) {
            heap.pop(); continue;
        } 
        g[top].isSure = true;
        for (pii con : g[top].con) {
            int node = con.x; int cost = con.y;
            if (g[node].isSure) continue;
            g[node].data = min(g[node].data,g[top].data + cost);
            heap.push(node);
        }
        heap.pop();
    }
    
    if (g[n].data == MAX)  Write(-1); 
    else  Write( g[n].data);

    
}

signed main() {
    solution();
    Please AC;
}