#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll n, m, k, A, temp, extra, discount, len_cnt,  //n, m, km temp Number, extra and discount value every round, length of numbers temp;
tmp[(ll)2e5],                                   //store origin Array to sort
input[(ll)2e5][(ll)1e9],                        //store number witch is reversed in array
length[(ll)2e5],                                //length of number stored in input
index_j=0, index_k=0, index_i=0, temp_extra, swap_cnt;                //index for swapping, swap cnt
int number;                                     //number we got
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
    ll tempArr[200000];
    mS(arr, tempArr, 0, len-1);
}

int main(){
    n = read();
    m = read();
    k = read();
    A=0;
    for (ll i = 0; i < n; i++) {
        tmp[i] = read();
        A+=tmp[i];
    }
    mergeSort(tmp, n);
    for (ll i = 0; i < n; i++) {
        temp = tmp[i];
        len_cnt = 0;
        while (temp >= 1) {
            number = temp%10;
            input[i][len_cnt++] = number;
            temp /= 10;
        }
        length[i] = len_cnt;
    }
    discount = 0;
    extra = 0;
    swap_cnt = 0;
    while (extra >= discount && swap_cnt <= m) {
        A+=extra;
        A-=discount;
        swap(input[index_i],index_j, index_k);  //update A and Array
        swap_cnt+=1;
        //find the best swap
        for (int i = 0; i < n; i++) {
            ll min_index;
            for (int temp_j = 0; temp_j < length[i]; temp_j++) {
                min_index = temp_j;
                for (int temp_k = temp_j; temp_k < length[i]; temp_k++) {
                    if (input[i][temp_k] < input[i][temp_j] && input[i][temp_k] < input[i][min_index]) {
                        min_index = temp_k;
                    }
                }
                if (min_index != temp_j) {
                    temp_extra = (input[i][temp_j] - input[i][min_index] )*powl(10,min_index)  +  (input[i][min_index] - input[i][temp_j] )*powl(10,temp_j);
                    if (temp_extra > extra) {
                        extra = temp_extra;
                        index_j = temp_j;
                        index_k = min_index;
                    }
                    break;
                }
            }
        }

        discount = swap_cnt * k;




    }





    // IntegerWrite(sum);
}