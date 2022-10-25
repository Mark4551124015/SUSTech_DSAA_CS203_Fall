#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#pragma G++ optimize("O2")
#define ll int
using namespace std;
ll n, k, q, tmp;

// Fast I/O
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline char readAlpha() {
	char c = getchar();
	while (!isalpha(c)) {
		c = getchar();
	}
	return c;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}
inline void DoubleWrite(double a) {
    ll mi = 0, s2[100];
    if (a == 0)
        putchar('0');
    while (a != (long long)a)
    {
        a *= 10, mi++;
    }
    long long k = a, len = 0;
    while (k != 0)
    {
        s2[len] = k % 10, len++, k /= 10;
    }
    for (len -= 1;len >= 0;len--)
    {
        if (len == mi - 1)
            putchar('.');
        putchar(s2[len] + '0');
    }
}

//A Node is set in both Queue and Tree
struct Node
{
	ll data, index;
}N[100010];

int minQueue[100010];

int main() {
	n = read();
	k = read();
    q = read();
    ll head = 0, tail = -1, tmp;
    
    //init queue
    for (int i = 0; i < n; ++i) {
        tmp = read();
        while ((head <= tail) && (N[tail].data <= tmp)) {
            --tail;
        }
        N[++tail].data = tmp;
        N[tail].index = i;
        while ((head < tail) && (N[head].index) <= i-k) {
            ++head;
        }
        minQueue[i] = N[head].data;
    }
    for (; q > 0; --q) {
        tmp = read();
        Write(minQueue[tmp+k-2]);
        putchar('\n');
    }
}
/*
<------------------Notes here------------------>
    Build a Queue to store numbers in queue
    put Node into a 

*/