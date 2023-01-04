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
#define N 5005
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
int T, n, m, u, v;

bool isDAG;
vi arr;
bool visit[N];
vi con[N];



inline void dfs(int node, int start, int dep) {
    visit[node] = true;
    for (int child : con[node]) {
        if (child == start && dep != 0) isDAG = false;
        if (!visit[child]) dfs(child, start, dep+1);
    }
    arr.pb(node);con[node].clear();
}

inline void clear()
{
    memset(visit, 0, sizeof(visit));
    arr.clear();
}

inline void solution()
{
    n = read(); m = read();
    for (int i = 0; i < m; i++)
    {
        u = read(); v = read();
        con[v].pb(u);
    }
    isDAG = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        dfs(i, i, 0);
    }
    if (isDAG)
    {
        for (int i = 0; i < n; i++) {
            Write(arr[i]); sp;
        }
    }
    else
    {
        printf("impossible");
    }

}

inline void testcase()
{
    T = read();
    for (; T > 0; T--)
    {
        solution();ln;
        clear();
    }
}

signed main()
{
    testcase();
    Please AC;
}
