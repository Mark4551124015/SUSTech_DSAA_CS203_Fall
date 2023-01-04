#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 1005
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define sp putchar(' ')

// Fast RW
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        Write(x / 10);
    putchar(x % 10 + '0');
}
// const
int T, n, m;
int cnt;
pii q[N*N]; int front, rear;

int c[N][N];
bool v[N][N];

inline void clear()
{
    memset(c, 0, sizeof c);
    memset(v, false, sizeof v);
    cnt = 0;
}

inline bool isV(pii pos){
    return v[pos.x][pos.y];
}

inline void setV(pii pos){
    v[pos.x][pos.y] = true;
}


inline bool sameC(pii a, pii b)
{
    return c[a.x][a.y] == c[b.x][b.y];
}


inline void bfs(pii root)
{
    front = 0; rear = 0;
    q[rear++] = root;
    while (front!=rear) {
        pii node = q[front++];
        if (isV(node)) continue;
        setV(node);
        pii left,right,up,down;
        if (node.y == 1) left = {node.x, m};
        else left = {node.x, node.y - 1};
        if (node.y == m) right = {node.x, 1};
        else right = {node.x, node.y + 1};
        up = {node.x - 1, node.y};
        down = {node.x + 1, node.y};

        if (sameC(left, node)) q[rear++] = (left);
        if (sameC(right, node)) q[rear++] = (right);
        if (node.x != 1 && sameC(up, node)) q[rear++] = (up);
        if (node.x != n && sameC(down, node)) q[rear++] = (down);
    }
}

inline void solution()
{
    n = read(); m = read();
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++)
        {
            c[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++)
        {
            if (isV({i,j})) continue;
            bfs({i,j});
            cnt++;
        }
    }
    Write(cnt);ln;

}

inline void testcase()
{
    T = read();
    for (; T > 0; T--)
    {
        solution();
        clear();
    }
}

signed main()
{
    testcase();
    Please AC;
}
