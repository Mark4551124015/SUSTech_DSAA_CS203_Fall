#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 1048581
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
int T, m, n;
int shop[N]; // shop
int cnt, item, drop;

struct node
{
    int L;
    int index = -1;
    int pos;
}g[N], origin[N];

struct heap
{
    vector<int> h;
    void push(int node);
    int pop();
    int top();
    void adjust(int pos);
    void adjustUp(int pos);
    bool isEmpty();
    int size();
    void swapNode(int a, int b);
    void clear();
}H;
inline void heap::swapNode(int a, int b)
{
    swap(h[a], h[b]);
    swap(g[h[a]].pos, g[h[b]].pos);
}
inline bool cmp(int k1, int k2)
{
    return (g[k1].L > g[k2].L) || (g[k1].L == g[k2].L && g[k1].index < g[k2].index);
}
inline void heap::push(int node)
{
    if (h.empty())
    {
        h.pb(0);
    }
    h.pb(node);
    int i = h.size() - 1;
    g[node].pos = i;
    adjustUp(i);
}
inline int heap::pop()
{
    if (isEmpty()) return -1;
    int out = h[1];
    swapNode(1, h.size() - 1);
    h.pop_back();
    adjust(1);
    g[out].pos = 0;
    g[out].index = -1;
    g[out].L = 0;
    return out;
}
inline int heap::top()
{
    return h[1];
}
inline void heap::adjust(int pos)
{
    if (pos == 0)
        return;
    int i = pos, j;
    while (i < h.size())
    {
        j = 2 * i;
        if (j >= h.size())
            break;
        if (j + 1 < h.size() && cmp(h[j + 1], h[j]))
            j++;
        if (cmp(h[j], h[i]))
        {
            swapNode(i, j);
            i = j;
        }
        else
        {
            break;
        }
    }
}
inline void heap::adjustUp(int pos)
{
    if (pos == 0)
        return;
    int i = pos;
    while (cmp(h[i], h[i / 2]) && i > 1)
    {
        swapNode(i, i / 2);
        i /= 2;
    }
}
inline bool heap::isEmpty()
{
    return h.size() <= 1;
}
inline int heap::size()
{
    if (h.size()>1) return h.size()-1;
    else return 0;
}
inline void heap::clear()
{
    h.clear();
}


inline void solution()
{
    m = read(); n = read(); cnt = 0; drop=0; H.clear();
    memcpy(&g,&origin,sizeof(g));
    for (int i = 0; i < n; i++)
    {
        item = read();
        if (cnt < m)
        {
            if (g[item].L == 0) 
            {
                g[item].L++;
                g[item].index = i;
                H.push(item);
                cnt++;
            }
            else
            {
                g[item].L++;
                H.adjustUp(g[item].pos);
            }
        }
        else
        {
            if (g[item].L == 0) 
            {
                ++drop;
                H.pop();
                // Write(H.pop());sp;
                g[item].L++;
                g[item].index = i;
                H.push(item);
                cnt++;
            }
            else
            {
                g[item].L++;
                H.adjustUp(g[item].pos);
            }

        }
    }
    Write(drop);
    ln;
}

inline void testcase()
{
    T = read();
    for (; T > 0; T--)
    {
        solution();
    }
}

signed main()
{
    testcase();
    Please AC;
}
