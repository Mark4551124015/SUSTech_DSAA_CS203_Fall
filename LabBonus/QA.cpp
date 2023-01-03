#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long
// #define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 50005
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define sp putchar(' ')
#define MIN_INT -2147483648
 
 
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
 
int n, t, num;
 
 
inline void getDiff() {
    n = read();
    int maxNum = MIN_INT;
    int ans = MIN_INT;
    for (int i = 0; i < n; i++) {
        num = read();
        if (i!=0) ans = max(maxNum - num, ans);
        maxNum = max(num,maxNum);
    }
    Write(ans);sp;
}
 
inline void solution() {
    t = read();
    for (; t>0; t--) getDiff();
}
 
signed main() {
    solution();
    Please AC;
}