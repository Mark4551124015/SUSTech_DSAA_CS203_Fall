#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define ll long long
#define maxData (ll)3e5
#define RI register int
#pragma G++ optimize(2)
#define Please return
#define AC 0
#define isDebug true
#define N 5
using namespace std;

char * dealer, * paul;
bool in;

signed main() {
    dealer = new char();
    paul = new char();
    cin >> dealer;
    for (int i = 0; i < 5; i++) {
        cin >> paul;
        if (paul[0] == dealer[0] || paul[1] == dealer[1]) {
            in = true;
            break;
        }
    }
    if (in) cout << "All in";
    else cout << "Fold";
    Please AC;
}