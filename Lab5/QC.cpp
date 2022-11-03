#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define maxData (int)1e5+1
#define ll int
#define size 26
#define Please
#define AC
using namespace std;
ll x, len;
ll arr[maxData][size];
char str[maxData];

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

inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

inline int getID (char input) {
	return input - 97;
}

inline void FSA () {
	for (ll i = 0; i < size; i++) {
		if (i == getID(str[0])) {
			arr[0][i] = 1;
		}
	}
	x = 0;
	for (ll i = 1; i < len; i++) {  					//all  str
		for (ll j = 0; j < size; j++) {					//all char
			if (getID(str[i]) == j) { 					//match
				arr[i][j] = i+1;						//jump to i+1
			} else {									//not match
				arr[i][j] = arr[x][j];					//jump to last x
			}
		}
		x = arr[x][getID(str[i])];
	}
}

inline void print(){
	for (ll i = 0; i < len; i++) {
		for (ll j = 0; j < size; j++) {
			Write(arr[i][j]);
			putchar(' ');
		}
		putchar('\n');	
	}
}

int main() {
	len = readStr(str);
	FSA();
	print();
	Please AC;
}





