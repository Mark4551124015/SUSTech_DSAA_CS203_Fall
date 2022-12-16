#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define int ll
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define N 100100
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define isDebug false
#define debugLn if(isDebug)putchar('\n')

//Fast RW
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
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

int n, sum, k, sumA, sumB, sumC;
int arr[N], postFix[N];

inline bool checkFirst() {
    return (!(postFix[1]&1));
}

inline bool checkSecond() {
    k = n; sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        for (;k > i && arr[k] < i-1; k--); 
        if (k < i) k = i;
        sumA = i*(i-1);
        sumB = i*(k-i);
        sumC = postFix[k+1];
        if (k >= n) sumC = 0;
        if (sumA + sumB + sumC < sum) return false;
    }
    return true;
}

inline bool checkThird() {
    return postFix[1] == (n-1)*2;
}

inline bool checkFourth() {
    if (n == 1) return true; 
    for (int i = 1; i<=n; i++) {
        if (arr[i] <= 0) return false;
    }
    return true;
}

inline void check() {
    bool A = checkFirst();
    bool B = checkSecond();
    bool C = checkThird();
    bool D = checkFourth();
    // debug(C);
    if (A) printf("YES");
    else printf("NO");
    ln;
    if (A&&B) printf("YES");
    else printf("NO");       
    ln;
    if (A&&B&&C&&D) printf("YES");
    else printf("NO");    
    ln;
}

inline bool cmp(int a, int b) {
    return a>b;
}
inline void solution() {
    n = read();
    // scanf("%lld",&n);
    for (int i = 1; i <= n; i++) {
        arr[i] = read(); 
        // scanf("%lld", &arr[i]);    
    }
    sort(arr+1, arr+n+1, cmp);
    postFix[n] = arr[n];
    for (int i = n - 1; i > 0 ; i--) {
        postFix[i] = arr[i] + postFix[i+1];
    }
    check();
}

signed main() {
    solution();
    Please AC;
}
