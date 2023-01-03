#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
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

//Fast RW
inline int read(){
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

struct node{
    int prev, next;
    int coe;
    int exp;
}gA[N], gB[N], origin[N];

int nodeA, nodeB;
int T, n, m;
int headA, headB;
bool first;
vector<pii> input;

inline void clear() {
    memcpy(&gA, &origin, sizeof(gA));
    memcpy(&gB, &origin, sizeof(gB));
    nodeA = 0;
    nodeB = 0;
}


inline void printPolymer(int coe, int exp) {
    if (coe == 0) return;
    if (!first && coe > 0) putchar('+');
    if (abs(coe)!=1 || (abs(coe) == 1 && exp == 0) ) printf("%lld", coe);
    if (exp != 0) {
        if (coe == -1) putchar('-');
        putchar('x');
        if (exp != 1) printf("^%lld", exp);
    }
    first = false;
}

inline void init() {
    n = read();
    headA = 1;
    for (int i = 0; i < n; i++) {
        ++nodeA;
        gA[nodeA].prev = nodeA - 1;
        gA[nodeA].next = nodeA + 1;
        gA[nodeA].coe = read();
        gA[nodeA].exp = read();
    }
    gA[headA].prev = 0;
    gA[nodeA].next = 0;

    m = read();
    headB = n + 1;
    nodeB = headB-1;
    for (int i = 0; i < m; i++) {
        ++nodeB;
        gB[nodeB].prev = nodeB - 1;
        gB[nodeB].next = nodeB + 1;
        gB[nodeB].coe = read();
        gB[nodeB].exp = read();
    }
    gB[headB].prev = 0;
    gB[nodeB].next = 0;
}


inline void getAns() {
    int indexA = headA;
    int indexB = headB;
    first = true;
    while (indexA != 0 && indexB != 0) {
        if (gA[indexA].exp < gB[indexB].exp) {
            printPolymer(gA[indexA].coe, gA[indexA].exp);
            indexA = gA[indexA].next;
        } else if (gA[indexA].exp > gB[indexB].exp) {
            printPolymer(gB[indexB].coe, gB[indexB].exp);
            indexB = gB[indexB].next;
        } else {
            printPolymer(gA[indexA].coe + gB[indexB].coe, gA[indexA].exp);
            indexA = gA[indexA].next;
            indexB = gB[indexB].next;
        }
    }


    while (indexA != 0 ) {
        printPolymer(gA[indexA].coe, gA[indexA].exp);
        indexA = gA[indexA].next;
    }
    while (indexB != 0) {
        printPolymer(gB[indexB].coe, gB[indexB].exp);
        indexB = gB[indexB].next;
    }
    if (first) Write(0);
    ln;
}

inline void solution() {
    T = read();
    for (; T > 0; T--) {
        init();
        getAns(); 
        clear();
    }
    
}

signed main() {
    solution();
    Please AC;
}

