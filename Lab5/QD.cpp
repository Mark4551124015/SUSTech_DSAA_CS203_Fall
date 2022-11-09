#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#pragma G++ optimize(2)
#define maxData (int)2e6+10
#define ll int
#define size 4
using namespace std;
#define Please return
#define AC 0
ll n, x, len, com;
ll arr[maxData][size];
char str[maxData];

//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline int readStr(char str[], ll index) {
    char c;
    c= getchar();
    ll i = 0;
	while (!isalpha(c)) {
	    c = getchar();
	}
    while (isalpha(c)) {
        str[index+i++] = c;
        c = getchar();
    }
    return i;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}
inline void WriteStr(string input, ll i)
{
    if(!isalpha(input[i])) {
        return;
    }
    putchar(input[i]);
    WriteStr(input, i+1);
}
inline void WriteCharSet(char input[], ll i)
{
    if(!isalpha(input[i])) {
        return;
    }
    putchar(input[i]);
    WriteStr(input, i+1);
}

inline int getID (char input) {
    switch (input)
        {
        case 'W':
            return 0;
            break;
        case 'E':
            return 1;
            break;
        case 'N':
            return 2;
            break;
        case 'S':
            return 3;
            break;
        }
	return 4;
}

inline ll FSA () {
	for (ll i = 0; i < size; i++) {
		if (i == getID(str[0])) {
			arr[0][i] = 1;
		}
	}
	x = 0;
	for (ll i = 1; i < 2*len; i++) {  					//all  str
		for (ll j = 0; j < size; j++) {					//all char
			if (getID(str[i]) == j) { 					//match
				arr[i][j] = i+1;						//jump to i+1
			} else {									//not match
				arr[i][j] = arr[x][j];					//jump to last x
			}
		}
		x = arr[x][getID(str[i])];
	}
    return x;
}

inline void reverseAndOppside() {
    for (ll i = 0; i < len/2; i++) {
        swap(str[i],str[len-i-1]);
    }
    for (ll i = 0; i < len; i++) {
        switch (str[i])
        {
        case 'W':
            str[i] = 'E';
            break;
        case 'E':
            str[i] = 'W';
            break;
        case 'N':
            str[i] = 'S';
            break;
        case 'S':
            str[i] = 'N';
            break;
        }
    }
}

int main() {
    n = read();
    len = n-1;
    readStr(str, len);
    readStr(str, 0);
    reverseAndOppside();
	com = FSA();
    // WriteCharSet(str,0);
	if (com>0) {
        WriteStr("NO",0);
    } else {
        WriteStr("YES",0);
    }
	Please AC;
}





