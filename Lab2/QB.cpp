#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll cases, n, cnt, input[100005];
//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void FloatWrite(double a)
{
    ll mi = 0, s2[100];
    if (a == 0)
        putchar('0');
    while (a != (long long)a)
    {
        a *= 10, mi++;
    }
    long long k = a, len = 0;
    while (k != 0)
    {
        s2[len] = k % 10, len++, k /= 10;
    }
    for (len -= 1;len >= 0;len--)
    {
        if (len == mi - 1)
            putchar('.');
        putchar(s2[len] + '0');
    }
}
inline void IntegerWrite(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        IntegerWrite(x/10);
    putchar(x%10+'0');
}

//Merge Sort
inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
    ll j = left;       //index for left arr
    ll k = mid+1;      //index for right arr
    ll index = left;   //index for tempArr
    while (j <= mid && k <= right) {
        if (arr[j] <= arr[k]) {
            tempArr[index++] = arr[j++];
        } else {
            tempArr[index++] = arr[k++];
            cnt+=mid-j+1;
        }
    }
    //merge left and right
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
inline void mS(ll arr[], ll tempArr[], ll left, ll right ){
    if (left < right) {
        //spit then merge
        ll mid = (left+right)/2;
        mS(arr, tempArr, left, mid);
        mS(arr, tempArr, mid+1, right);
        merge(arr, tempArr, left, mid ,right);
    }
}
inline void mergeSort(ll arr[], ll len) {
    ll tempArr[100005];
    mS(arr, tempArr, 0, len-1);
}

int main()
{
	cases = read();
    for (int i = 0; i < cases; i++) {
        n = read();
        for (int index = 0; index < n; index++) {
            input[index] = read();    
        }
        cnt=0;
        mergeSort(input,n);
        IntegerWrite(cnt);
        putchar('\n');
    }
	return 0;
}