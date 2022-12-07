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
#define N (int)1000
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
int T,n,tmp,cnt;

struct Node{
    int val;
    Node(int in);
};
Node::Node(int in){
    val = in;
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

inline void solution() {
    T = read();
    
    for(;T>0;T--) {
        n = read();
        cnt = 0;
        for (int i = 0; i < n; i++) {
            H.push(Node(read()));
        }
        while (H.h.size()>2) {
            tmp = H.pop().val+H.pop().val;
            H.push(Node(tmp));
            cnt += tmp;
        }
        Write(cnt);
        H.pop();
        ln;
    }

}
signed main() {
    solution();
    Please AC;
}
