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
inline char readC(){
    char c = getchar();
    while (!(c == '('||c == '['||c == '{' || c == ')'||c == ']'||c == '}')) c = getchar();
    return c;
}

inline void Write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

int T, n;
char c;
inline bool check() {
    stack<char> b;
    n = read();
    for (int i = 0; i < n; i++) {
        c = readC();
        if (c == '('||c == '['||c == '{') {
            b.push(c);
        } else {
            if (b.empty()) return false;
            if (c == ')') {
                if (b.top() == '(') b.pop();
                else return false;
            }
            if (c == ']') {
                if (b.top() == '[') b.pop();
                else return false;
            }
            if (c == '}') {
                if (b.top() == '{') b.pop();
                else return false;
            }
        }
    }
    if (b.empty()) return true;
    return false;
}

inline void solution() {
    T = read();
    for (; T > 0; T--) {
        if (check()) printf("YES");
        else printf("NO");
        ln;
    }
    
}

signed main() {
    solution();
    Please AC;
}

