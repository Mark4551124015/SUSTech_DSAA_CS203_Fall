#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#pragma G++ optimize(2)
#define ll int
#define Please return
#define AC 0
using namespace std;
ll T, n, solution[300], sollen;
struct Node
{
    char str[100];
    ll len, tag;
}dic[10], text;

// Fast I/O
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void readNode(Node * node) {
    char c;
    c= getchar();
    ll i = 0;
	while (c == ' ' || c == '\n') {
	    c = getchar();
	}
    while (c != ' ' && c != '\n') {
        node->str[i++] = c;
        c = getchar();
    }
    node->len = i;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

//cmp
bool cmp(Node a, Node b) {
    return a.len >= b.len;
}

//index start by 0
bool match(Node text, char str[], ll len, ll index) {
    for (int i = 0; i < len; i++) {
        if (str[i]!=text.str[index+i]) {
            return false;
        }
    }
    return true;
}

int solve(Node text, Node dic[], ll left, ll solIndex, ll cnt) {
    if (left == text.len) {
        sollen = solIndex;
        return cnt;
    }
    ll maxLen = dic[0].len;
    ll canAdd = maxLen < text.len - left ? maxLen : text.len - left;
    for (int i = 0; i < n && canAdd; i++) {
        if (dic[i].len<canAdd) {
            canAdd--;
            i=-1;
            continue;
        }
        ll startP = left + (canAdd - dic[i].len);
        if (startP < 0) {
            continue;
        }
        if (match(text,dic[i].str,dic[i].len, startP)) {
            solution[solIndex++]=dic[i].tag;
            solution[solIndex++]=startP+1;
            return solve(text, dic, left+canAdd,solIndex,++cnt);
        }
        if (i == n-1 && canAdd) {
            canAdd--;
            i=-1;
            continue;
        }
    }
    return -1;
}

int main() {
    T = read();
    for (; T > 0; T--) {
        //read Text and Dictionary
        readNode(&text);
        n = read();
        for (ll i = 0; i < n; i++) {
            readNode(&dic[i]);
            dic[i].tag = i+1;
        }
        //sorted by length
        sort(dic,dic+n,cmp);
        sollen = 0;
        ll output = solve(text,dic, 0, 0, 0);
        if (output) {
            Write(output);
            putchar('\n');
            for (int i = 0; i < sollen; i++) {
                Write(solution[i++]);
                putchar(' ');
                Write(solution[i]);
                putchar('\n');
            }
        } else {
            Write(-1);
            putchar('\n');
        }
    }
    Please AC;
}

/*
<------------------Notes here------------------>
*/