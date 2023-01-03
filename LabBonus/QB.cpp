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
#define N 50005
#define all(x) (x).begin(), (x).end() 
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define x first
#define y second
#define ln putchar('\n')
#define sp putchar(' ')
#define MAX_DATA (int)1e9


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

int L, n, m;
vi place;
inline void init() {
    place.clear();
    place.pb(0);
    for (; n > 0; n--) place.pb(read());
    sort(all(place));
}

inline bool check(int ans) {
    int i = 0, player = m;
    int canReach, curP, cant;
    while (true) {
        curP = place[i];
        canReach = curP + ans; player--;
        if (player < 0) return false;
        if (canReach >= L) return true;
        cant = true;
        while (i < place.size() - 1) {
            if (canReach >= place[i+1]) {
                cant = false; i++;
            } else {
                break;
            }
        }
        if (cant) return false;
    }
}

inline int getAns() {
    int min = 0, max = MAX_DATA;
    int cur, ans;
    while (min <= max) {
        cur = (max + min)/2;
        if (check(cur)) {
            ans = cur;
            max = cur - 1;
        } else {
            min = cur + 1;
        }
    }
    return ans;
}

inline void solution() {
    while (~scanf("%lld%lld%lld", &L, &n, &m)) {
        init();
        Write(getAns());ln;
    }
}

signed main() {
    solution();
    Please AC;
}

