#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#pragma G++ optimize(2)
#define ull unsigned long long
#define ll long long
#define maxData (ull)3e5+10
#define Please return
#define AC 0
#define scale 13ull
#define startP 97ull

using namespace std;
ull lenFir, lenSec, lenHushPal, lenOdd, lenEven;
ull ans, oddMax, evenMax, mx, mn, mid;
ull hushFir[maxData], hushRevFir[maxData], hushSec[maxData], hushPal[maxData];
ull power[maxData], odd[maxData], even[maxData];
char fir[maxData], sec[maxData];
//Fast I/O
inline ull readStr(char str[]) {
    char c;
    c = getchar();
    str[0] = ' ';
    ull i = 1;
    while (!isalpha(c)) {
        c = getchar();
    }
    while (isalpha(c)) {
        str[i++] = c;
        c = getchar();
    }
    return i;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}
inline void printArr(ull arr[], ull len) {
    if (len < 1) {
        return;
    }
    for (ull i = 0; i < len; i++) {
        printf("%llu ",arr[i]);
    }
    putchar('\n');
}

inline bool find(ull arr[], ull len, ull target) {
    ull max = len - 1, min = 0, index;
    while (max >= min && max <= maxData) {
        index = (max+min)/2;
        if (arr[index] > target) {
            max = index-1;
        } else if (arr[index] < target) {
            min = index+1;
        } else {
            return true;
        }
    }
    return false;
}
inline ull getHush(ull arr[], ull l,ull r) {
    return arr[r]-arr[l-1]*power[r-l+1];
}
inline ull getRevHush(ull arr[], ull l,ull r) {
    return arr[l]-arr[r+1]*power[r-l+1];
}

inline ull locate(ull len) {
    //find Palindrome in Fir
    lenHushPal = 0;
    for (ull i = 1,tmp; i <= lenFir - len; i++) {
        tmp = getHush(hushFir,i,i+len-1);
        if (tmp == getRevHush(hushRevFir,i,i+len-1) ) {
            hushPal[lenHushPal++] = tmp;
        }
    }
    sort(hushPal, hushPal + lenHushPal);
    for (ull i = 1,tmp; i <= lenSec - len; i++) {
        tmp = getHush(hushSec,i,i+len-1);
        if (find(hushPal, lenHushPal, tmp) ) {
            return len;
        }
    }
    return 0;
}

int main() {
    lenFir = readStr(fir);
    lenSec = readStr(sec);
    //fir should be shorter
    if (lenFir>lenSec) {
        swap(fir,sec);
        swap(lenFir,lenSec);
    }
    //build odd and even arr
    for (ull i = 1; i <= lenFir; i++) {
        if (i&1) {
            odd[lenOdd++] = i;
        } else {
            even[lenEven++] = i;
        }
    }
    power[0]=1;
    hushFir[0] = 0;
    hushRevFir[lenFir] = 0;
    hushSec[0] = 0;
    //build hush set
    for (ull i = 1; i < lenSec;i++) {
        power[i]=power[i-1]*scale;
        if (i < lenFir) {
            hushFir[i] = hushFir[i-1]*scale+fir[i]-startP;
            hushRevFir[lenFir-i] = hushRevFir[lenFir-i+1]*scale+fir[lenFir-i]-startP;
        }
        hushSec[i] = hushSec[i-1]*scale+sec[i]-startP;
    } 
    //find odd
    if (lenOdd > 0) {
        mx = lenOdd-1;
        mn = 0;
        while (mx >= mn && mx <= maxData) {
            mid = (mx+mn)/2;
            if (locate(odd[mid])) {
                oddMax = odd[mid];
                mn = mid+1;
            } else {
                mx = mid-1;
            }
        }
    }
    //find even
    if (lenEven > 0) {
        mx = lenEven-1;
        mn = 0;
        while (mx >= mn && mx <= maxData) {
            mid = (mx+mn)/2;
            if (locate(even[mid])) {
                evenMax = even[mid];
                mn = mid+1;
            } else {
                mx = mid-1;
            }
        }
    }
    ans = max(evenMax, oddMax);
    if (ans > 0) {
        Write(ans);
    } else {
        Write(-1);
    }
    Please AC;
}
