#include <cstdio>
#include <cmath>
#define ll long
#pragma G++ optimize(2)
ll n, m, discount, extra, P, //n, m, km temp Number, extra and discount value every round, length of numbers temp;
input[(ll)2e5][(ll)9], length[(ll)2e5], number[(ll)2e5];  //store origin Array to sort
ll profit[(ll)2e6];
ll A;
//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

//Merge Sort
inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
    ll j = left;       //index for left arr
    ll k = mid+1;      //index for right arr
    ll index = left;   //index for tempArr
    while (j <= mid && k <= right) {
        if (arr[j] > arr[k]) {
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
    ll tempArr[(ll)1800000];
    mS(arr, tempArr, 0, len-1);
}

inline void update(ll index, ll extraNum){
    number[index] += extraNum;
    ll len_cnt = 0;
    ll temp = number[index];
    if (temp<0) {
        temp*=-1;
    }
    ll thisNum;
    while (temp >= 1) {
        thisNum = temp%10;
        input[index][len_cnt++] = thisNum;
        temp /= 10;
    }
    length[index] = len_cnt;
}

inline void proccessNum(ll index) {
    ll len = length[index];
    ll num = number[index];
    extra = 0;
    bool positive = true;
    if (num < 0) {
        positive = !positive;
    }
    for (ll j = len -1; j >= 0; j--) {
        ll maxIndex = j;
        for (ll k = j; k >= 0; k--) {
            if (input[index][k] > input[index][maxIndex] && positive) {
                maxIndex = k;
            }
            if (input[index][k] < input[index][maxIndex] && !positive) {
                maxIndex = k;
            }
        }
        if (positive) {
            extra = ((input[index][j] - input[index][maxIndex])*powl(10,maxIndex))  +  ((input[index][maxIndex] - input[index][j] )*powl(10,j));
        } else {
            extra = ((input[index][maxIndex] - input[index][j])*powl(10,maxIndex))  +  ((input[index][j] - input[index][maxIndex])*powl(10,j));
        }
        if (extra > discount) {
            update(index, extra);
            profit[P++] = extra;
        }
    }
}

int main(){
    n = read();
    m = read();
    discount = read();
    A=0;
    P=0;
    for (ll i = 0; i < n; i++){
        number[i] = read();
        A+=number[i];
        update(i, 0);
    }

    for (ll i = 0; i < n; i++) {
        proccessNum(i);
    }
    mergeSort(profit, P);
    for (ll i = 0; i < P && i < m; i++) {
        A += profit[i] - discount;
        // printf("%ld ", profit[i]);
    }
    Write(A);
}