#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define maxArray 80100
#define maxBlock 283
#define ll int
using namespace std;
ll n, m, cntBlock = 0 , MaxNum = 0, idMap[maxArray];
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

struct Node{
	ll left, right;
	ll array[maxBlock*2+10],cntS[maxArray/maxBlock+5],cnt[maxArray],size;
	void InsertBlock();
}B[maxArray/maxBlock],SB;

inline void InsertBlock(ll index) {
	cntBlock++;
	B[cntBlock].right = B[index].right;
	B[B[index].right].left = cntBlock;
	B[index].right = cntBlock;
	B[cntBlock].left = index;
}

inline void printBlock(Node b) {
	for (ll i = 0; i < b.size; i++) {
		Write(b.array[i]);
		putchar(' ');
	}
	putchar('\n');
}

inline void goToBlock(ll *index, ll *pos) {
	*index = 1;
	while (*pos > B[*index].size) {
		*pos -= B[*index].size;
		*index = B[*index].right;
	}
}

inline void split(ll index) {
	// insert a new block
	InsertBlock(index);
	// resize blocks
	B[cntBlock].size = maxBlock;
	B[index].size -= B[cntBlock].size;
	// copy arrays
	memcpy(B[cntBlock].array, B[index].array + B[index].size, maxBlock * sizeof(ll));
	memcpy(B[cntBlock].cntS, B[index].cntS, sizeof B[index].cntS);
	memcpy(B[cntBlock].cnt, B[index].cnt, sizeof B[index].cnt);
	
	// update arrays
	for (ll i = 0; i < maxBlock; i++) {
		B[index].cntS[idMap[B[cntBlock].array[i]]]--;
		B[index].cnt[B[cntBlock].array[i]]--;
	}
}

inline void Insert(ll pos, ll data) {
	// go to position and pushback data
	ll index;
	pos--;
	goToBlock(&index, &pos);
    for(ll i=B[index].size;i>pos;i--) { 
		B[index].array[i] = B[index].array[i-1];
	}
	B[index].array[pos] = data;
	// B has a bigger size
	B[index].size++;
	// array stuff
	for (ll i = index; i; i = B[i].right) {
		B[i].cntS[idMap[data]]++;
		B[i].cnt[data]++;
	}
	if (B[index].size >= 2 * maxBlock) {
		split(index);
	}
}

inline void Modify(ll pos, ll data) {
	ll index;
	goToBlock(&index, &pos);
	ll data_old = B[index].array[pos - 1];
	B[index].array[pos - 1] = data;
	while (index) {
		B[index].cntS[idMap[data_old]]--;
		B[index].cntS[idMap[data]]++;
		B[index].cnt[data_old]--;
		B[index].cnt[data]++;
		index = B[index].right;
	}
}

inline ll Query(ll l, ll r, ll k) {
	ll leftBlock=1,rightBlock=1;
	goToBlock(&leftBlock, &l);
	goToBlock(&rightBlock, &r);
	ll out = 0;
	// if l and r are in a same block
	if (leftBlock == rightBlock) {
		for (ll i = l - 1, j = r - 1, tmp;i <= j; i++) {
			tmp = B[leftBlock].array[i];
			SB.cntS[idMap[tmp]]++;
			SB.cnt[tmp]++;
		}
		for (ll i = 1; i <= idMap[maxArray - 1]; i++) {
			if (SB.cntS[i] >= k) {
				for (ll j = (i - 1) * maxBlock;;j++) {
					if (k <= SB.cnt[j]) {
						out = j;
						break;
					} else {
						k -= SB.cnt[j];
					}
				}
				break;
			} else {
				k -= SB.cntS[i];
			}
		}

		for (ll i = l - 1, j = r - 1, tmp;i <= j; i++) {
			tmp = B[leftBlock].array[i];
			SB.cntS[idMap[tmp]]--;
			SB.cnt[tmp]--;
		}

		return out;
	} else {
		//part in left bock
		for (ll i = l - 1, tmp; i < B[leftBlock].size; i++) {
			tmp = B[leftBlock].array[i];
			SB.cntS[idMap[tmp]]++;
			SB.cnt[tmp]++;
		}
		//part in right block
		for (ll i = 0, tmp; i < r; i++) {
			tmp = B[rightBlock].array[i];
			SB.cntS[idMap[tmp]]++;
			SB.cnt[tmp]++;
		}
		rightBlock = B[rightBlock].left;
		for (ll i = 1, tmp; i <= idMap[MaxNum]; i++) {
			tmp = B[rightBlock].cntS[i] - B[leftBlock].cntS[i] + SB.cntS[i];
			if (tmp >= k) {
				for (ll j = (i - 1) * maxBlock, res;;j++) {
					res =  B[rightBlock].cnt[j] - B[leftBlock].cnt[j] + SB.cnt[j];
					if (k <= res) {
						out = j;
						break;
					}
					else {
						k -= res;
					}	
				}
				break;
			} else {
				k -= tmp;
			}
		}
		rightBlock = B[rightBlock].right;
		for (ll i = l - 1, tmp; i < B[leftBlock].size; i++) {
			tmp = B[leftBlock].array[i];
			SB.cntS[idMap[tmp]]--;
			SB.cnt[tmp]--;
		}
		for (ll i = 0, tmp; i < r; i++) {
			tmp = B[rightBlock].array[i];
			SB.cntS[idMap[tmp]]--;
			SB.cnt[tmp]--;
		}
		return out;
	}
}

inline void init() {
    for(ll i=0;i<maxArray;i++) {
		idMap[i]=i/maxBlock+1;
	}
	cntBlock=idMap[n-1];
	for(ll i=0;i<n;i++){
		ll id = idMap[i], input;
		input = read();
		B[id].array[B[id].size] = input;
		B[id].cntS[idMap[input]]++;
		B[id].cnt[input]++;
		B[id].size++;
		MaxNum = MaxNum >= input ? MaxNum : input;
	}
	for(ll i=2;i<=cntBlock;i++)
	{
		B[i-1].right=i, B[i].left=i-1;
		for(ll j=0;j<=MaxNum;j++){
			B[i].cnt[j] += B[i-1].cnt[j];
			if(j==0 || idMap[j]!=idMap[j-1]) {
				B[i].cntS[idMap[j]] += B[i-1].cntS[idMap[j]];
			}
		}
	}
}

int main() {
	n = read();
	m = read();
	init();
	char op;
	int args[3];
	// process Operation
	for (int i = 0, tmp = 0; i < m; i++) {
		op = readAlpha();
		 if (op == 'Q') {
			args[0] = read();
			args[1] = read();
            args[2] = read();
			tmp = Query(args[0],args[1],args[2]);
			Write(tmp);
			putchar('\n');
		} else if (op == 'M') {
			args[0] = read();
			args[1] = read();
			MaxNum = MaxNum >= args[1] ? MaxNum : args[1];
			Modify(args[0], args[1]);
		} else if (op == 'I'){
			args[0] = read();
			args[1] = read();
			MaxNum = MaxNum >= args[1] ? MaxNum : args[1];
			Insert(args[0], args[1]);
		} else if (op == 'P') {
			int index = 0;
			for (int i = 0; i < cntBlock; i++) {
				printBlock(B[index]);
				index = B[index].right;
			}
		} else {
			printf("Wrong Operator: %c\n", op);
		}
	}
}