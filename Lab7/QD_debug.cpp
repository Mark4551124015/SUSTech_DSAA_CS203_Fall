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
#define N (int)200010
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define isDebug false
#define debugLn if(isDebug)putchar('\n')

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
int n, c, tail, root, m, u, v, cnt;
vi freeNode;
pii road;
struct node {
    int l, r, direction; //-1 is left, 1 is right, 0 is none
    int size, key, h;
    int Offset;
    pii range;
}g[N], none;
inline void restoreNode(int node) {
    memcpy(&g[node], &none, sizeof(g[node]));
}
inline void debugNode(int node) {
    if (!isDebug) return;
    printf("node: %lld, key: %lld, h: %lld, size: %lld\n", node, g[node].key, g[node].h, g[node].size);
    printf("left: %lld, right: %lld\n", g[node].l, g[node].r);
    printf("range: %lld %lld, offset: %lld\n", g[node].range.x, g[node].range.y, g[node].Offset);
    debugLn;
}

inline bool inRange(int x, pii range) {
    return (x <= range.y && x >= range.x);
}

inline pii validRange(pii p) {
    if (p.x > c) p.x = c;
    if (p.x < 0) p.x = 0;
    if (p.y > c) p.y = c;
    if (p.y < 0) p.y = 0;
    return p;
}
inline int validInt(int a) {
    if (a > road.y) {
        return road.y;
    }
    if (a < -road.y) {
        return -road.y;
    }
    return a;
}

inline pii sumR(pii a, pii b) {
    pii p = {a.x+b.x, a.y+b.y};
    return  validRange(p);
}
inline pii sumR(pii a, int b) {
    pii p = {a.x+b, a.y+b};
    return  validRange(p);
}
inline pii cross(pii a, pii b) {
    pii p = {max(a.x,b.x), min(a.y,b.y)};
    return validRange(p);
}


inline int getDes(int x, pii range, int offSet) {
    int out;
    if (inRange(x,range)) {
        debug(x);
        out = x+offSet;
    }
    if (x < range.x) {
        out = range.x+offSet;
    }
    if (x > range.y) {
        out = range.y+offSet;
    }
    return validInt(out);
} 

inline pii sumRange(pii a, pii b, int offSet) {
    pii out;
    out.x = getDes(a.x, b, offSet);
    out.y = getDes(a.y, b, offSet);
    return out;
}




inline void originRange(int node) {
    g[node].range = {sumR(road, {g[node].key, g[node].key})};
    g[node].Offset = g[node].key;
    g[node].range = sumR(g[node].range, {-g[node].key, -g[node].key});
}
//waiting to debug
inline void updateRange(int node) {
    // return;

    originRange(node);
    // return;

    int left = g[node].l; int right = g[node].r; 
    pii tmp;
    if (left) {
        tmp = sumR(g[left].range, g[left].Offset);
        if (tmp.y < g[node].range.x ) {
            g[node].Offset = validInt(g[node].Offset);
            g[node].range = {g[node].range.x,g[node].range.x};

        } else if (tmp.x > g[node].range.y) {
            g[node].Offset = validInt(g[node].Offset);
            g[node].range = {g[node].range.y,g[node].range.y};

        } else {
            g[node].range = cross(tmp,g[node].range);
            g[node].range = sumR(g[node].range,g[node].Offset);
            g[node].Offset = validInt(g[node].Offset + g[left].Offset);
            g[node].range = sumR(g[node].range,-g[node].Offset);
        }
    }

    if (right) {
        tmp = sumR(g[node].range, g[node].Offset);
        if (tmp.y < g[right].range.x ) {
            g[node].Offset = validInt(g[right].Offset);
            g[node].range = {g[right].range.x,g[right].range.x};
        } else if (tmp.x > g[right].range.y) {
            g[node].Offset = validInt(g[right].Offset);
            g[node].range = {g[right].range.y,g[right].range.y};
        } else {
            tmp = cross(tmp,g[right].range);
            tmp = sumR(tmp,g[right].Offset);
            g[node].Offset = validInt(g[node].Offset + g[right].Offset);
            g[node].range = sumR(tmp,-g[node].Offset);
        }
    }
}


inline void updateSize(int node){
    g[node].size = g[g[node].l].size + g[g[node].r].size + 1;
}
inline void updateHight(int node) {
    g[node].h = max(g[g[node].l].h, g[g[node].r].h) + 1;
}
inline void update(int node) {
    if (!node) return;
    updateHight(node);
    updateSize(node);
    updateRange(node);
}
inline int newNode(int val) {
    int out;
    if (freeNode.empty()) {
        out= ++tail;
    } else {
        out = freeNode.back(); freeNode.pop_back();
    }
    restoreNode(out);
    g[out].key = val;
    g[out].h = 1;
    g[out].size = 1;
    originRange(out);
    return out;
}

//turns
inline void LL(int * node) {
    debug("doing LL, node", *node);
    int tmp = g[*node].l;
    g[*node].l = g[tmp].r;
    g[tmp].r = *node;
    *node =tmp;
    update(g[*node].l);
    update(g[*node].r);
    update(*node);
}
inline void RR(int * node) {
    debug("doing RR, node", *node);
    int tmp = g[*node].r;
    g[*node].r = g[tmp].l;
    g[tmp].l = *node;
    *node = tmp;
    update(g[*node].l);
    update(g[*node].r);
    update(*node);
}
inline void LR(int * node) {
    RR(&g[*node].l);
    LL(node);
}
inline void RL(int * node) {
    LL(&g[*node].r);
    RR(node);
}

inline bool doLL(int node) {
    return g[g[node].l].l;
}

inline bool doRR(int node) {
    return g[g[node].r].r;
}


inline bool insertBST(int * node, int val, int k) {
    // debug("insert BST now node ", *node);
    // debug("value", val);
    if (!g[root].h) {
        root = 1;
        restoreNode(1);
        g[root].key = val;
        g[root].h = 1;
        g[root].size = 1;
        tail = 1;
        freeNode.clear();
        originRange(root);
        return true;
    }
    if (!*node) {
        *node = newNode(val);
         // debug("inserting to node", *node);
        return true;
    }
    bool flag;
    if (k <= g[g[*node].l].size + 1) {
        g[*node].direction = -1;
        // debug("go left, k=", k);
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
        // debug("go right, k=", k);
       flag = insertBST(&g[*node].r, val, k);
        if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
            if (g[g[*node].r].direction == 1) {
                RR(node);
            } else {
                RL(node);
            }
        }
    }
    if(flag) update(*node);
    return flag;
}
inline void debugInorderTranversal(int node) {
    if (!isDebug) return;
    if (!node) return;
    debugInorderTranversal(g[node].l);
    Write(g[node].key);
    putchar(' ');
    debugNode(node);
    debugInorderTranversal(g[node].r);
}

inline void deleteNode(int * node, int *tmp) {
    if (!g[*node].r) {
        debug("deleting node", *tmp);
        g[*tmp].key = g[*node].key;
        int temp = *node;
        *node = g[*node].l;
        debug(g[*tmp].l);
        debug(g[*tmp].r);
        restoreNode(temp);
        freeNode.pb(temp);
    } else {
        debug("going to", g[*node].r);
        deleteNode(&g[*node].r, tmp);
        if (g[g[*node].l].h - g[g[*node].r].h > 1) {
            LL(node);
        }
    }
    update(*node);

}


inline bool deleteBST(int * node, int k) {
    if (!*node) {
        return false;
    }
    bool flag = true;
    //deleteNode
    if (k == g[g[*node].l].size +1) {
        if (!g[*node].l) {
            debug("deleting node", *node);
            int tmp = *node;
            *node = g[*node].r;
            restoreNode(tmp);
            freeNode.pb(tmp);
        } else if (!g[*node].r) {
            debug("deleting node", *node);
            int tmp = *node;
            *node = g[*node].l;
            restoreNode(tmp);
            freeNode.pb(tmp);
        } else {
            deleteNode(&g[*node].l,node);
        }
    } else if (k < g[g[*node].l].size + 1) {
        debug("go left, k=", k);
        g[*node].direction = 1;
        flag = deleteBST(&g[*node].l, k);
        if (flag && g[g[*node].l].h - g[g[*node].r].h > 1) {
            if ( doLL(*node)) {
                LL(node);
            } else {
                LR(node);
            }
        } else if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
            if ( doRR(*node)) {
                RR(node);
            } else {
                RL(node);
            }
        }
    
    } else {
        k -= g[g[*node].l].size + 1;
        debug("go right, k=", k);
        g[*node].direction = -1;
        flag = deleteBST(&g[*node].r, k);
        // if (flag && g[g[*node].l].h - g[g[*node].r].h > 1) {
        //     if (g[g[*node].l].direction == -1 && doLL(*node)) {
        //         LL(node);
        //     } else {
        //         LR(node);
        //     }
        // } else if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
        //     if (g[g[*node].r].direction == 1 && doRR(*node)) {
        //         RR(node);
        //     } else {
        //         RL(node);
        //     }
        // }
        if (flag && g[g[*node].l].h - g[g[*node].r].h > 1) {
            if ( doLL(*node)) {
                LL(node);
            } else {
                LR(node);
            }
        } else if (flag && g[g[*node].l].h - g[g[*node].r].h < -1) {
            if ( doRR(*node)) {
                RR(node);
            } else {
                RL(node);
            }
        }
        
    }
    if (flag) {
        update(*node);
    }
    return flag;
}


inline void inorderTranversal(int node) {
    if (!node) return;
    inorderTranversal(g[node].l);
    Write(g[node].key);
    putchar(' ');
    debugNode(node);
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
     root = 1;
    scanf("%lld%lld",&c,&n);
    // c = read(); n = read();
    road = {0,c}; cnt = n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&u);insertBST(&root,u,i);
        // insertBST(&root,read(),i);
    }
    m = read();
    string op; op.resize(3);
    for (;m>0;m--) {
        scanf("%s", &op[0]);
        if (op == "ins") {
            debug("---------------insert--------------");debugLn;
            // u = read(); v = read();
            scanf("%lld%lld",&u,&v);
            insertBST(&root, v, u);
            cnt++;
            debug("---------------inserted--------------");debugLn;
        }
        else if (op == "rem") {
            debug("---------------remove--------------");debugLn;
            // u = read();
            scanf("%lld",&u);
            deleteBST(&root, u);
            debugInorderTranversal(root);debugLn;

            cnt--;
            debug("---------------removed--------------");debugLn;
        }
        else if (op == "ask") {
            // u = read();
            debug("---------------asking--------------");debugLn;
            debugInorderTranversal(root);debugLn;
            scanf("%lld",&u);
            if (!cnt) {
                Write(u);ln;
            } else {
                Write(getDes(u, g[root].range, g[root].Offset));ln;
            }
            debug("---------------asked--------------");debugLn;
        }
        else if (op == "nod") {
            // u = read();
            m++;
            debug("---------------nodes--------------");debugLn;
            ln;inorderTranversal(root);ln;
            debug("---------------noded--------------");debugLn;

        }
        else if (op == "her") {
            // u = read();
            m++;
            debug("<------------------------here------------------------>");debugLn;
        }
    }
    debugInorderTranversal(root);

}   
signed main() {
    solution();
    Please AC;
}
