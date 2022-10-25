#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#pragma G++ optimize(2)
#define ll int
#define RI register int
#define size 1000000
#define MOD 514329
using namespace std;

ll ans, cnt = 0;
bool isPlus = false;
string input;
char tmp;
// Fast I/O
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline char readSign() {
	char c = getchar();
	while (c != '(' && c != ')' && c!= '\n') {
		c = getchar();
	}
	return c;
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
 
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

struct stack{
	ll arr[1000010];
	ll index;
	void push(double data) {
		arr[++index] = data;
	}
	ll pop() {
		return arr[index--];
	}
}S;

int main() {
	input.resize(1000010);
	scanf("%s", &input[0]);
	RI index = -1;
	while (input[index+1] == ')' || input[index+1] == '(') {
		tmp = input[++index];
		if (tmp == '(') {
			S.push(0);
			isPlus = true;
		} else if (tmp == ')') {
			if (isPlus) {
				S.push(1);
				S.push((ll)(S.pop()+S.pop()) % MOD);
				isPlus = false;
			} else {
				S.push((ll)((S.pop() * 2)+S.pop()) % MOD);
			}
			if (S.index > 0 && S.arr[S.index-1] != 0) {
				S.push((ll)(S.pop()+S.pop()) % MOD);
			}
		}
	}
	Write((ll)S.pop());
}