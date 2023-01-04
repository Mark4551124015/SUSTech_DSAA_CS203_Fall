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
int q[N], front, rear;
bool hasPre[N];
vi course;
struct node{
    int pre;
    vi son;
    int depth;
    int root;
}g[N], origin[N];

inline void push(int node)
{
    q[rear++] = node;
}
inline int pop()
{
    return q[front++];
}

inline void clear()
{
    memcpy(&g, &origin, sizeof(g));
    memset(hasPre, false, sizeof(hasPre));
    course.clear();
    front = 0;
    rear = 0;
}


inline void bfs(int start, int root)
{
    push(start);
    while(front!=rear)
    {
        int node = pop();
        g[node].root = root;
        for (int child : g[node].son) 
        {
            if (g[child].pre == 0)
            {
                continue;
            }
            g[child].pre--;
            if (g[child].pre == 0)
            {
                push(child);
                g[child].depth = g[node].depth+1;
                course.pb(child);
            }
        }
    }
}

inline bool cmp(int a, int b)
{
    if (g[a].root!=g[b].root) 
    {
        return a<b;
    } 
    else
    {
        if (g[a].depth < g[b].depth)
        {
            return true;
        }
        else if (g[a].depth == g[b].depth)
        {
            return a<b;
        }
        else
        {
            return false;
        }
    } 
}

inline void solution()
{
    n = read(); m = read(); 
    for (int i = 0; i < m; i++)
    {
        u = read(); v = read();
        hasPre[v] = true;
        g[u].son.pb(v);
        g[v].pre++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!hasPre[i]) {
            course.pb(i);
            bfs(i,i);
        }
    }
    sort(all(course), cmp);
    if (course.empty()) {
        printf("impossible");
    }
    for (int i = 0; i < course.size(); i++) {
        Write(course[i]); sp;
    }
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
