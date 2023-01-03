#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 200005
#define size 26
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
inline int readStr(char str[]) {
    char c;
    c= getchar();
    ll i = 0;
	while (!isalpha(c)) {
	    c = getchar();
	}
    while (isalpha(c)) {
        str[i++] = c;
        c = getchar();
    }
    return i;
}

inline void Write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

int T;
int len, L;
int nextArr[N];
char str[N];

inline int getID(char c) {
    return c-97;
}

inline void KMP () {
    memset(nextArr, 0, sizeof nextArr);
    int k = -1, j = 0;
    nextArr[0] = -1;
    while (j < len) {
        if (k==-1 || str[j] == str[k]) {
            ++j;++k;nextArr[j]=k;
        } else {
            k = nextArr[k];
        }
    }
    L = len - nextArr[len];
}

inline void solution() {
    T = read();
    for (; T > 0; T--) {
        len = readStr(str);
        KMP();
        bool flag = (len % L) == 0 && L != len;
        if (flag) Write(0);
        else Write(L-(nextArr[len]%L));        
        ln;
    }
    
}

signed main() {
    solution();
    Please AC;
}

