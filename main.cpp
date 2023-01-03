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
#define N 150005
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
int T, n, u, v;
int root;
bool flag;
bool hasFather[N];
struct node
{
    int left, right;
}g[N], origin[N];

inline void clear()
{
    memcpy(&g,&origin, sizeof(g));
    memset(hasFather, false, sizeof(hasFather));
    flag = false;
    root = 0;
}

inline bool isCBT(int root)
{
    queue<int> q;
    if (root == 0) return false;
    q.push(root);
    while(!q.empty())
    {
        int node = q.front();
        if (node == 0) break;
        q.push(g[node].left);q.push(g[node].right);
        q.pop();
    }
    while(!q.empty())
    {
        int node = q.front();
        if (node != 0) return false;
        q.pop();
    }
    return true;
}

inline void solution()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        u = read(); v = read();
        g[i].left = u; g[i].right = v;
        hasFather[u] = true; hasFather[v] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!hasFather[i])  
        {
            root = i; break;
        }
    }
    if (isCBT(root)) printf("Yes");
    else printf("No");
    ln;
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
