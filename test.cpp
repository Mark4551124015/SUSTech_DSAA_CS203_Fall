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
}gA[N], origin[N];

int n;
int u, v;
bool first;
vector<pii> input;



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



inline void solution() {
    n = read();
    first = true;
    for (int i = n; i >=0; i--) {
        printPolymer(read(), i);
    }
    
}

signed main() {
    solution();
    Please AC;
}

