#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#pragma G++ optimize(2)
#define maxDataRange 1000010
#define ll int
using namespace std;
ll n, output, minTag = maxDataRange+10, tmp;

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
struct Node
{
    ll data;
    ll tag;
};
Node *arr[maxDataRange], *tempArr[maxDataRange];
//Merge Sort for LinkNodes
inline void merge(Node *arr[], Node *tempArr[], ll left, ll mid, ll right) {
    ll j = left;       
    ll k = mid+1;      
    ll index = left;   
    while (j <= mid && k <= right) {
        if (arr[j]->data < arr[k]->data) {
            tempArr[index++] = arr[j++];
        } else if (arr[j]->data == arr[k]->data) {
            if (arr[j]->tag > arr[k]->data) {
                tempArr[index++] = arr[j++];
            } else {
                tempArr[index++] = arr[k++];
            }
        } else {
            tempArr[index++] = arr[k++];
        }
    }
    while (j <= mid) {
        tempArr[index++] = arr[j++];
    }
    while (k <= right) {
        tempArr[index++] = arr[k++];
    }
    while (left <= right) {
        arr[left] = tempArr[left];
        left++;
    }
}
inline void mS(Node *arr[], Node *tempArr[], ll left, ll right ){
    if (left < right) {
        //spit then merge
        ll mid = (left+right)/2;
        mS(arr, tempArr, left, mid);
        mS(arr, tempArr, mid+1, right);
        merge(arr, tempArr, left, mid ,right);
    }
}
inline void mergeSort(Node *arr[],ll startAt, ll len) {
    mS(arr, tempArr, startAt, len-1);
}
int main() {
	n = read();
    arr[0] = new Node();
    arr[0]->data = 0; arr[0]->tag = 0;
	for (ll i = 1; i <= n; i++) {
        arr[i] = new Node();
        arr[i]->data = read();
        arr[i]->data += arr[i-1]->data;
        arr[i]->tag = i;
    }
    mergeSort(arr, 0, n+1);
    for (ll i  = 0; i <= n; i++) {
        if (minTag < arr[i]->tag) {
            tmp = arr[i]->tag - minTag;
            output =  tmp > output ? tmp : output;
        } else {
            minTag = arr[i]->tag;
        }
    }
    Write(output);
}
/*
<------------------Notes here------------------>
    
*/