#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <time.h>
#define random(a, b) rand()%(b-a+1) + a
#define ll long long

#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
#define pii pair<int, int>
#define N (int)500000
#define U 2147483648
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug false
#define ln putchar('\n');

string filename = ".vscode/oi/in.txt";

inline void creatData() {
    srand(time(0));
	fstream file(filename.c_str(), ios::out);
    int n = random(1,N);
	n = 500000;
	file << n << endl;
	for (int i = 0; i < n; ++i) {
	    int m = random(1,U);
        file << m << ' ';
	}
}

signed main()
{
	    creatData();
}
