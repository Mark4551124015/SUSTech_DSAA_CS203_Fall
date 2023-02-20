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
#define N (int)1000

#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')

pii org,des;
int arr[N][N];

//Fast RW

inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}


signed main() {
    org.x = read();
    org.y = read();
    des.x = read();
    des.y = read();
    int m  = read();
    int defX = des.x-org.x;
    int defY = des.y-org.y;
    for (int i = 0; i <= defX; i++) {
        for (int j = 0; j <= defY; j++) {
            if (j==0||i==0) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j]+arr[i][j-1];
            arr[i][j] = arr[i][j]%m;
        }
    }
    Write(arr[defX][defY]);



}