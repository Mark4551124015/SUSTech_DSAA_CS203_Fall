#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define pii pair<int, int>
#define vi vector<int>
#define N (int)500000
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
int T,n,tmp,nodeCnt;

struct Node{
    int val, pos, ser;
    int p,n;
    void join();
}g[N];



struct heap{
    vector<Node> h;
    void push(int node);
    Node popPos(int node);
    Node top();
    void adjust(int pos);
}H;

inline void swapNode(int a, int b) {
    swap (g[a].pos, g[b].pos);
}

inline bool cmp(Node a, Node b) {
    return (a.val < b.val) || ( a.val == b.val && a.ser < b.ser);
}

void heap::push(int node){
    if (h.empty()) {
        h.pb(g[node]);
    }
    h.pb(g[node]);
    int i = h.size()-1;
    while (cmp(h[i], h[i/2])&& i != 1) {
        swap(h[i],h[i/2]);
        swapNode(i,i/2);
        i /= 2;
    }
}

Node heap::popPos(int node){
    Node out = h[node];
    swap(h[node],h[h.size()-1]);
    swapNode(node,h.size()-1);
    h.pop_back();
    int i=node,j;
    while (i < h.size()) {
        j = 2*i;
        if (j >= h.size()) {
            break;
        }
        if (j+1 < h.size() && h[j].val > h[j+1].val || (h[j+1].val==h[j].val && h[j+1].ser<h[j].ser)) {
            j++;
        }
        if (h[i].val>h[j].val || (h[i].val==h[j].val && h[i].ser>h[j].ser)) {
            swap(h[i],h[j]);
            swapNode(i,j);
            i = j;
        } else {
            break;
        }
    }
    return out;
}

Node heap::top(){
    return h[1];
}

inline void printHeap() {
    int a = 1 ,b = 0;
    for (int i = 1; i < H.h.size(); i++) {
        b++;
        printf("%lld ", H.h[i].val);
        if (a == b) {
            ln;
            a*=2;
            b = 0;
        }
    }
    ln;
}

void heap::adjust(int pos){
    int i=pos,j;
    while (i < h.size()) {
        j = 2*i;
        if (j >= h.size()) {
            break;
        }
        if (j+1 < h.size() && cmp (h[j+1], h[j])) {
            j++;
        }
        if (cmp(h[j], h[i])) {
            swap(h[i],h[j]);
            swapNode(i,j);
            i = j;
        } else {
            break;
        }
    }
}

inline void pop(int node){
    if (g[node].p) {
        g[g[node].p].n = g[node].n;
    }
    if (g[node].n) {
        g[g[node].n].p = g[node].p;
    }
    H.popPos(g[node].pos);
}

inline void join(int node){
    int a=0,b=0;
    if (g[node].p) {
        a = (g[g[node].p].val ^ g[node].val) +1;
    }
    if (g[node].n) {
        b = (g[g[node].n].val ^ g[node].val) +1;
    }
    if (a>=b) {
        pop(g[node].p);
        g[node].val = a;
    } else {
        pop(g[node].n);
        g[node].val = b;

    }        
    H.adjust(1);
}




inline void solution() {
    n = read();
    for (int i = 1; i <= n; i++) {
        ++nodeCnt;
        g[nodeCnt].val = read();
        g[nodeCnt].ser = i;
        g[nodeCnt].pos = i;
        g[nodeCnt].p = i - 1;
        g[nodeCnt].n = 0;

        H.push(nodeCnt);
    }
    for (int i = H.h.size() - 1; i > 0; i--) {
        H.adjust(i);
    }
    while (H.h.size() > 2) {
        join(H.top().pos);
        printHeap();


    }
    




}
signed main() {
    solution();
    Please AC;
}
