#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define pii pair<int, int>
#define vi vector<int>
#define N (int)500010
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug true
#define ln if(isDebug)putchar('\n');

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
inline void debug(string a){
    if (isDebug) printf("%s",a.c_str());
}
inline void debug(int a){
    if (isDebug) printf("%lld ",a);
}
inline void debug(string a, int b){
    if (isDebug) printf("%s: %lld\n",a.c_str(),b);
}
int n, c, cnt, root;
vi freeNode; 
struct node {
    int l, r, direction; //-1 is left, 1 is right, 0 is none
    int size, key, h;
}g[N];
inline void debugNode(int node) {
    if (!isDebug) return;
    printf("node: %lld, key: %lld, h: %lld\n", node, g[node].key, g[node].h);
    printf("left: %lld, right: %lld\n", g[node].l, g[node].r);
    ln;
}

inline void updateSize(int * node){
    g[*node].size = g[g[*node].l].size + g[g[*node].r].size + 1;
}

inline void updateHight(int * node) {
    g[*node].h = max(g[g[*node].l].h, g[g[*node].r].h) + 1;
}

inline void update(int * node) {
    updateHight(node);
    updateSize(node);
}

//turns
inline void LL(int * node) {
    debug("doing LL, node", *node);
    int tmp = g[*node].l;
    g[*node].l = g[tmp].r;
    g[tmp].r = *node;
    *node =tmp;
    update(&g[*node].l);
    update(&g[*node].r);
    update(node);
}
inline void RR(int * node) {
    debug("doing RR, node", *node);
    int tmp = g[*node].r;
    g[*node].r = g[tmp].l;
    g[tmp].l = *node;
    *node = tmp;
    update(&g[*node].l);
    update(&g[*node].r);
    update(node);
}
inline void LR(int * node) {
    RR(&g[*node].l);
    LL(node);
}
inline void RL(int * node) {
    LL(&g[*node].r);
    RR(node);
}

inline void restoreNode(int node) {
    g[node].size = 0;
    g[node].h = 0;
    g[node].l = 0;
    g[node].r = 0;
    g[node].key = 0;
    g[node].direction = 0;
}

inline void deleteNode(int * node, int tmp) {
    if (!g[*node].r) {
        restoreNode(*node);
        freeNode.pb(*node);
        g[tmp].key = g[*node].key;
        *node =g[*node].l;

    } else {
        deleteNode(&g[*node].r, tmp);
        if (g[g[*node].l].h - g[g[*node].r].h > 1) {
            LL(node);
        }
    }
    update(node);
}

inline bool insertBST(int * node, int val, int k) {
    debug("now node", *node);
    if (!*node) {
        *node = ++cnt;
        debug("inserting to node", *node);
        g[*node].key = val;
        g[*node].h = 1;
        g[*node].size = 1;
        return true;
    }
    bool flag;
    if (k <= g[g[*node].l].size) {
        g[*node].direction = -1;
        debug("go left, k=", k);
        flag = insertBST(&g[*node].l, val, k);
        if (flag && g[g[*node].l].h - g[g[*node].r].h > 1) {
            if (g[g[*node].l].direction == -1) {
                LL(node);
            } else {
                LR(node);
            }
        }
    } else if (k > g[g[*node].l].size) {
        g[*node].direction = 1;
        k -= g[g[*node].l].size + 1; //through left tree and root
        debug("go right, k=", k);
       flag = insertBST(&g[*node].r, val, k);
        if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
            if (g[g[*node].r].direction == 1) {
                RR(node);
            } else {
                RL(node);
            }
        }
    }
    if(flag) update(node);
    return flag;
}

inline bool deleteBST(int * node, int k) {
    if (!*node) {
        return false;
    }
    bool flag = true;
    //deleteNode
    if (g[g[*node].l].size + 1 == k) {
        if (!g[*node].l) {
            *node = g[*node].r;
        } else if (!g[*node].r) {
            *node = g[*node].l;
        } else {
            deleteNode(&g[*node].l, *node);
        }
    } else if (k < g[g[*node].l].size + 1) {
        flag = deleteBST(&g[*node].l, k);
    } else {
        k -= g[g[*node].l].size + 1;
        flag = deleteBST(&g[*node].r, k);
    }
    //turning
    if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
        if (g[g[*node].l].direction == 1) {
            RR(node);
        } else {
            RL(node);
        }
    } else if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
        if (g[g[*node].r].direction == 1) {
            RR(node);
        } else {
            RL(node);
        }
    }
    //update height and size
    if (flag) {
        update(node);
    }
    return flag;
}

inline void inorderTranversal(int node) {
    if (!node) return;
    inorderTranversal(g[node].l);
    Write(g[node].key);
    putchar(' ');
    inorderTranversal(g[node].r);
}

inline void bfs(int root) {
    queue<int> tmp;
    tmp.push(root);
    int node;
    while (!tmp.empty()) {
        node = tmp.front();
        Write(g[node].key);
        putchar(' ');
        tmp.pop();
        if (g[node].l) {
            tmp.push(g[node].l);
        }
        if (g[node].r) {
            tmp.push(g[node].r);
        }
    }
}

inline void solution() {
    c = read(); n = read(); root = 1;
    g[root].key = read(); cnt++;
    for (int i = 2; i <= n; i++) {
        insertBST(&root,read(),i);
    }
    ln;
    for (int i = 1; i <= n; i++) {
        debugNode(i);
    }
    deleteBST(&root, 10);
    // deleteBST(&root, 10);
    // deleteBST(&root, 10);
    // deleteBST(&root, 10);
    // deleteBST(&root, 10);

    inorderTranversal(root);

}

signed main() {
    solution();
    Please AC;
}
