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
#define N (int)1000000000
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
int n,m,k;
vi A,B;

struct Node{
    pii p;
    int val;
    Node(pii in);
};
Node::Node(pii in){
    p = in;
    val = A[in.x]*B[in.y];
}

struct heap{
    vector<Node> h;
    void push(Node a);
    Node pop();
    Node top();
    int swapNode(Node a);

}H;

int heap::swapNode(Node a) {
    int out = h[1].val;
    h[1] = a;
    int i=1,j;
    while (i < h.size()) {
        j = 2*i;
        if (j >= h.size()) {
            break;
        }
        if (j+1 < h.size() && h[j].val > h[j+1].val) {
            j++;
        }
        if (h[i].val>h[j].val) {
            swap(h[i],h[j]);
            i = j;
        } else {
            break;
        }
    }
    return out;
}

void heap::push(Node a){
    if (h.empty()) {
        h.pb(a);
    }
    h.pb(a);
    int i = h.size()-1;
    while (a.val < h[i/2].val && i != 1) {
        swap(h[i],h[i/2]);
        i /= 2;
    }
}

Node heap::pop(){
    Node out = h[1];
    if (h.size()<1) {
        return out;
    } 
    swap(h[1],h[h.size()-1]);
    h.pop_back();
    int i=1,j;
    while (i < h.size()) {
        j = 2*i;
        if (j >= h.size()) {
            break;
        }
        if (j+1 < h.size() && h[j].val > h[j+1].val) {
            j++;
        }
        if (h[i].val>h[j].val) {
            swap(h[i],h[j]);
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

inline void init() {
    n = read();
    m = read();
    k = read();
    for (int i  = 0; i < n; i++) {
        A.pb(read());
    }
    for (int i  = 0; i < m; i++) {
        B.pb(read());
    }
    sort(all(A));
    sort(all(B));
    for (int i = 0; i < B.size(); i++) {
        H.push(Node({0,i}));
    }
}

inline int getK(){
    Node out = H.top();
    pii p = out.p;
    p.x++;
    if (p.x < A.size()) {
        H.swapNode(Node(p));
    } else {
        H.pop();
    }
    return out.val;
}
inline void solution() {
    init();
    for (int i = 0; i < k; i++) {
        Write(getK());
        putchar(' ');
    }
}
signed main() {
    solution();
    Please AC;
}
