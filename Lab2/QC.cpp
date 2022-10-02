#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll n, index_small=0, index_big, input[1000000], temp[1000000];
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
inline void ArrWrite(ll arr[], ll len) {
    for (ll i = 0; i < len; i++) {
        IntegerWrite(arr[i]);
        putchar(' ');
    }
}

//Merge Sort
inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
    ll j = left;       //index for left arr
    ll k = mid+1;      //index for right arr
    ll index = left;   //index for tempArr
    while (j <= mid && k <= right) {
        if (arr[j] < arr[k]) {
            tempArr[index++] = arr[j++];
        } else {
            tempArr[index++] = arr[k++];
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
    ll tempArr[1000000];
    mS(arr, tempArr, 0, len-1);
}


int main()
{
	n = read();
    for (ll i = 0; i < n; i++) {
        input[i] = read();
    }
    mergeSort(input, n);
    ll rem = n % 3ll;
    ll min = n / 3;
    index_big = min;
    for (ll i = 0; i < n && index_big < n; i++) {
        if (i % 3 == 0 && index_small < min) {
            temp[i] = input[index_small++];
        } else {
            temp[i] = input[index_big++];
        }
    }
    IntegerWrite(input[min]);
    putchar('\n');
    ArrWrite(temp, n);
    
}
