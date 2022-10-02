#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
int n, m, discount, extra, P, //n, m, km temp Number, extra and discount value every round, length of numbers temp;
input[(int)2e5][(int)9], length[(int)2e5], profit[(int)2e6], number[(int)2e5];  //store origin Array to sort             
ll A;
//Fast RW
inline int read() {
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
inline void merge(int arr[], int tempArr[], int left, int mid, int right) {
    int j = left;       //index for left arr
    int k = mid+1;      //index for right arr
    int index = left;   //index for tempArr
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
inline void mS(int arr[], int tempArr[], int left, int right ){
    if (left < right) {
        //spit then merge
        int mid = (left+right)/2;
        mS(arr, tempArr, left, mid);
        mS(arr, tempArr, mid+1, right);
        merge(arr, tempArr, left, mid ,right);
    }
}
inline void mergeSort(int arr[], int len) {
    int tempArr[(int)2e6];
    mS(arr, tempArr, 0, len-1);
}

inline void update(int index, int extraNum){
    number[index] += extraNum;
    int len_cnt = 0;
    int temp = number[index];
    if (temp<0) {
        temp*=-1;
    }
    int thisNum;
    while (temp >= 1) {
        thisNum = temp%10;
        input[index][len_cnt++] = thisNum;
        temp /= 10;
    }
    length[index] = len_cnt;
}

inline void proccessNum(int index) {
    int len = length[index];
    int num = number[index];
    extra = 0;
    bool positive = true;
    if (num < 0) {
        positive = !positive;
    }
    for (int j = len -1; j >= 0; j--) {
        int maxIndex = j;
        for (int k = j; k >= 0; k--) {
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
        } else {
            break;
        }
    }
}

int main(){
    for (int times = 0; times < 500; times++) {
        n = read();
        m = read();
        discount = read();
        A=0;
        P=0;
        for (int i = 0; i < n; i++){
            number[i] = read();
            A+=number[i];
            update(i, 0);
        }

        for (int i = 0; i < n; i++) {
            proccessNum(i);
        }
        mergeSort(profit, P);
        for (int i = 0; i < P && i <= m; i++) {
            A += profit[i] - discount;
        }
        Write(A);
        printf("\n");
    }

}