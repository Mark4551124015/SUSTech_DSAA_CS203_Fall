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
#define N (int)1001

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
int n, m, q, u, v;
bool arr[N][N];

inline void solution() {
    n = read();
    m = read();
    q = read(); 
    for(;m>0;m--) {
        u = read();
        v = read();
        if (u>v) {
            swap(u,v);
        }
        arr[u][v] = true;
    }
    for (;q>0;q--) {
        u = read();
        v = read();
        if (u>v) {
            swap(u,v);
        }
        if (arr[u][v]) {
            printf("Yes");
        } else {
            printf("No");
        }
        ln;
    }

}
signed main() {
    solution();
    Please AC;
}
