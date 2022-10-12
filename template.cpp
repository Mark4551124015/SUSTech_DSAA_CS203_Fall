#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
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
//Tools
inline void swap(ll arr[], ll a, ll b) {
    ll c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}
//Merge Sort
//inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
//    ll j = left;       //index for left arr
//    ll k = mid+1;      //index for right arr
//    ll index = left;   //index for tempArr
//    while (j <= mid && k <= right) {
//        if (arr[j] < arr[k]) {
//            tempArr[index++] = arr[j++];
//        } else {
//            tempArr[index++] = arr[k++];
//        }
//    }
//    //merge left and right
//    while (j <= mid) {
//        tempArr[index++] = arr[j++];
//    }
//    while (k <= right) {
//        tempArr[index++] = arr[k++];
//    }
//    while (left <= right) {
//        arr[left] = tempArr[left];
//        left++;
//    }
//}
//inline void mS(ll arr[], ll tempArr[], ll left, ll right ){
//    if (left < right) {
//        //spit then merge
//        ll mid = (left+right)/2;
//        mS(arr, tempArr, left, mid);
//        mS(arr, tempArr, mid+1, right);
//        merge(arr, tempArr, left, mid ,right);
//    }
//}
//inline void mergeSort(ll arr[], ll len) {
//    ll tempArr[200000];
//    mS(arr, tempArr, 0, len-1);
//}

//Heap Sort
inline void hp(ll arr[], ll len, ll index){
    int temp, j;
    temp = arr[index];
    for (j = 2 * index + 1; j < len; j = 2 * j + 1 ) {
        if (j < len - 1 && arr[j] < arr[j+1]) {
            j++;
        }
        if (temp >= arr[j]){
            break;
        }
        arr[index] = arr[j];
        index = j;
    }
    arr[index] = temp;
}
inline void HeapSort(ll arr[], ll length) {
    int i;
    for (i = length / 2 - 1; i >= 0; i--) {
        hp(arr, length, i);
    }
    for (i = length - 1; i > 0; i--) {
        swap(arr, 0, i);
        hp(arr, i, 0);
    }
}


//Merge Sort
inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
    ll j=left, k=mid + 1;
    ll index = left;
    while (j <= mid && k <= right) {
        if (arr[j] <= arr[k]) {
            tempArr[index++] = arr[j++];
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
inline void mS(ll arr[], ll tempArr[], ll left, ll right) {
    if (left < right) {
        ll mid = (left + right)/2;
        mS(arr, tempArr, left, mid);
        mS(arr, tempArr, mid, right);
        merge(arr,tempArr,left,mid,right);
    }
}
inline void mergeSort(ll arr[], ll len) {
    ll tempArr[100000];
    mS(arr,tempArr,0,len-1);
}



int main(){
    ll arr[] = {7,2,72,62,14,35};
    ll len = (int) sizeof(arr)/sizeof(*arr);
    HeapSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%lld ", arr[i]);
    }
}