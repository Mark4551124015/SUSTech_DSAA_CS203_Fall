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
#define N (int)400010
#define all(x) (x).begin(), (x).end() 
#define pb push_back
#define x first
#define y second
#define isDebug false
#define ln putchar('\n');


string filename = ".vscode/oi/in.txt";
vector<pair<pii,int>> query;


void creatData(int n) {
    srand(time(0));
	fstream file(filename.c_str(), ios::out);
	int *tree = new int [n];
	for (int i = 0; i < n; ++i) {
		tree[i] = i + 1;
	}
	int root = random(0, n - 1);
	swap(tree[root], tree[n - 1]);
	int nxt_idx = n - 2;
	queue<int> Que;
	file << n << endl;
	Que.push(tree[n - 1]);
	while (!Que.empty()) {
		int now = Que.front();
		Que.pop();
		int cnt = random(1, 3);
		for (int i = 0; i < cnt; ++i) {
			int tmp_idx = random(0, nxt_idx); 
			swap(tree[tmp_idx], tree[nxt_idx]);
			file << now << ' ' << tree[nxt_idx] << endl;
			Que.push(tree[nxt_idx]);
			nxt_idx--;
			if (nxt_idx == -1) break;
		}
		if (nxt_idx == -1) break;
	}

    for (int i = 0; i < n; i++) {
        int g = random(1,n);
        file << g << ' ';
    }
}

signed main()
{
	    creatData(10);
}
