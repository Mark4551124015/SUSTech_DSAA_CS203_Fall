#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define maxArray 80100
#define maxBlock 283
#define ll int
using namespace std;

ll n, m, cntBlock = 0 , MaxNum = 0, range[maxData];
        ll tmp;

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
	ll prev, next;
	ll array[maxBlock*2+5],cntS[maxData/maxBlock+5],cnt[maxData],size;
	void InsertBlock();
}B[maxData/maxBlock],temp;

inline void InsertBlock(ll index) {
	cntBlock++;
	B[cntBlock].next = B[index].next;
	B[B[index].next].left = cntBlock;
	B[index].next = cntBlock;
	B[cntBlock].left = index;
}

inline void goToBlock(ll *index, ll *pos) {
	*index = 1;
	while (*pos > B[*index].size) {
		*pos -= B[*index].size;
		*index = B[*index].right;
	}
}

inline void split(ll index) {
	InsertBlock(index);
	B[cntBlock].size = maxBlock;
	B[index].size -= B[cntBlock].size;
	memcpy(B[cntBlock].array, B[index].array + B[index].size, maxBlock * sizeof(ll));
	memcpy(B[cntBlock].cntS, B[index].cntS, sizeof B[index].cntS);
	memcpy(B[cntBlock].cnt, B[index].cnt, sizeof B[index].cnt);
	for (ll i = 0; i < maxBlock; i++) {
		B[index].cntS[range[B[cntBlock].array[i]]]--;
		B[index].cnt[B[cntBlock].array[i]]--;
	}
}

inline void Insert(ll pos, ll data) {
    ll index;
    goToBlock(&index,&pos);
    for (ll i = B[index].size; i > pos; i--) {
        B[index].array[i] = B[index].array[i-1];
    }
	B[index].array[pos] = data;
	B[index].size++;
	for (ll i = index; i; i = B[i].next) {
		B[i].cntS[range[data]]++;
		B[i].cnt[data]++;
	}
	if (B[index].size >= 2 * maxBlock) {
		split(index);
	}
}

inline void Modify(ll pos, ll data) {
    ll index;
    goToBlock(&index,&pos);
    ll old_data = B[index].array[pos];
	B[index].array[pos] = data;
	for (ll i = index; i; i = B[i].next) {
		B[i].cntS[range[data]]++;
		B[i].cnt[data]++;
        B[i].cntS[range[old_data]]--;
		B[i].cnt[old_data]--;
        index = B[index].next;
	}
}

inline void Query(ll l, ll r, ll k) {
	ll leftBlock=1,rightBlock=1;
	goToBlock(&leftBlock, &l);
	goToBlock(&rightBlock, &r);
	ll out = 0;
    if (leftBlock == rightBlock) {
        for (ll i = l - 1, j = r - 1, tmp;i <= j; i++) {
			tmp = B[leftBlock].array[i];
			temp.cntS[range[tmp]]++;
			temp.cnt[tmp]++;
		}
		for (ll i = 1; i <= range[maxData - 1]; i++) {
			if (temp.cntS[i] >= k) {
				for (ll j = (i - 1) * maxBlock;;j++) {
					if (k <= temp.cnt[j]) {
						out = j;
                        return out;
					} else {
						k -= temp.cnt[j];
					}
				}
				break;
			} else {
				k -= temp.cntS[i];
			}
		}
        for (ll i = l - 1, j = r - 1, tmp;i <= j; i++) {
			tmp = B[leftBlock].array[i];
			temp.cntS[range[tmp]]--;
			temp.cnt[tmp]--;
		}
    } else {
		for (ll i = l - 1; i < B[leftBlock].size; i++) {
			tmp = B[leftBlock].array[i];
			temp.cntS[range[tmp]]++;
			temp.cnt[tmp]++;
		}
		for (ll i = 0; i < r; i++) {
			tmp = B[rightBlock].array[i];
			temp.cntS[range[tmp]]++;
			temp.cnt[tmp]++;
		}

        for (ll i = 1; i <= range[MaxNum]; i++) {
			tmp = B[rightBlock].cntS[i] - B[leftBlock].cntS[i] + temp.cntS[i];
			if (tmp >= k) {
				for (ll j = (i - 1) * maxBlock, res;;j++) {
					res =  B[rightBlock].cnt[j] - B[leftBlock].cnt[j] + temp.cnt[j];
					if (k <= res) {
						out = j;
						return out;
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
        for (ll i = l - 1; i < B[leftBlock].size; i++) {
			tmp = B[leftBlock].array[i];
			temp.cntS[range[tmp]]--;
			temp.cnt[tmp]--;
		}
		for (ll i = 0; i < r; i++) {
			tmp = B[rightBlock].array[i];
			temp.cntS[range[tmp]]--;
			temp.cnt[tmp]--;
		}
    }
}







