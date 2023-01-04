#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 200100
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define MAX 1000000001
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
int top, root;
int cnt;
int minEdge=MAX;
struct node{
    bool isV;
    int pos;
    int data = MAX;
    vector<pii> con;        //x is node, y is cost
}g[N];

struct heap{
    vector<int> h;
    void push(int node);
    int pop();
    int top();
    void adjust(int pos);
    void adjustUp(int pos);
    bool isEmpty();
    void swapNode(int a, int b);
}H;
inline void heap::swapNode(int a, int b){
    swap(g[h[a]].pos, g[h[b]].pos);
    swap(h[a],h[b]);
}
inline bool cmp(int a, int b) {
    return (g[a].data < g[b].data);
}
inline void heap::push(int node){
    if (h.empty()) {
        h.pb(0);
    }
    h.pb(node);
    int i = h.size()-1;
    g[node].pos = i;
    adjustUp(i);
}
inline int heap::pop(){
    int out = h[1];
    swapNode(1,h.size()-1);
    h.pop_back();
    g[out].isV = true;
    adjust(1);
    return out;
}
inline int heap::top(){
    return h[1];
}
inline void heap::adjust(int pos){
    int i=pos,j;
    while (i < h.size()) {
        j = 2*i;
        if (j >= h.size()) break;
        if (j+1 < h.size() && cmp (h[j+1], h[j])) j++;
        if (cmp(h[j], h[i])) {
            swapNode(i,j);
            i = j;
        } else {
            break;
        }
    }
}
inline void heap::adjustUp(int pos){
    int i=pos;
    while (cmp(h[i], h[i/2])&& i > 1) {
        swapNode(i,i/2);
        i /= 2;
    }
}
inline bool heap::isEmpty() {
    return h.size() <= 1;
}

inline void solution() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        u = read(); v = read(); w = read(); 
        g[u].con.pb({v,w});
        g[v].con.pb({u,w});
        if (w < minEdge) {
            minEdge = w;
            root = u;
        }
    }

    g[root].data = minEdge;
    H.push(root);

    while (!H.isEmpty()) {
        top = H.pop();
        cnt += g[top].data;
        for (pii con : g[top].con) {
            int node = con.x; int weight = con.y;
            if (!g[node].isV && weight < g[node].data) {
                g[node].data = weight;
                if (g[node].pos < 1) H.push(node);
                else H.adjustUp(g[node].pos);
            }
        }
    }
    Write(cnt - minEdge);
}

signed main() {
    solution();
    Please AC;
}