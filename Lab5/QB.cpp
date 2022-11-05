#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#define ull unsigned long long
#define maxData (ull)3e5+1
#define Please return
#define AC 0
#define scale 3022
#define ullMax 1844674407370955161

using namespace std;
ull lenFir, lenSec, lenHushPal, lenOdd,lenEven;
ull ans=0u, oddMax, evenMax;
ull hushFir[maxData], hushRevFir[maxData], hushSec[maxData];
ull hushPal[maxData];
ull power[maxData];
ull odd[maxData], even[maxData];
char fir[maxData], sec[maxData];

//Fast I/O
inline ull readStr(char str[]) {
    char c;
    c = getchar();
    str[0] = ' ';
    ull i = 1u;
    while (!isalpha(c)) {
        c = getchar();
    }
    while (isalpha(c)) {
        str[i++] = c;
        c = getchar();
    }
    return i+1;
}
inline void Write(ull x)
{
    if(x<0u)
        putchar('-'),x=-x;
    if(x>9u)
        Write(x/10u);
    putchar(x%10u+'0');
}
inline void print(ull arr[], ull len) {
    if (len < 1) {
        return;
    }
    for (ull i = 0u; i < len; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

inline bool find(ull arr[], ull len, ull target) {
    ull max = len - 1u, min = 0u, index;
    while (max >= min && max < ullMax) {
        index = (max+min)/2u;
        if (arr[index] > target) {
            max = index-1u;
        } else if (arr[index] < target) {
            min = index+1u;
        } else {
            return true;
        }
    }
    return false;
}
inline ull getHush(ull arr[], ull l,ull r)
{
    return arr[r]-arr[l-1]*power[r-l+1];
}
inline ull getRevHush(ull arr[], ull l,ull r)
{
    return arr[l]-arr[r+1]*power[r-l+1];
}

inline ull locate(ull len) {
    //find Palindrome in Fir
    lenHushPal = 0u;
    for (ull i = 1u,tmp; i <= lenFir - len; i++) {
        tmp = getHush(hushFir,i,i+len-1);
        if (tmp == getRevHush(hushRevFir,i,i+len-1)) {
            hushPal[lenHushPal++] = tmp;
        }
    }

    sort(hushPal, hushPal + lenHushPal);
//    printf("number of 回文 for len %llu : %llu\n",len, lenHushPal);
    //find same hush in Sec
    for (ull i = 1u, tmp; i <= lenSec - len; i++) {
        tmp = getHush(hushSec,i,i+len-1);
        if (find(hushPal, lenHushPal, tmp)) {
            return len;
        }
    }

    return 0;
}
int main() {
    lenFir = readStr(fir);
    lenSec = readStr(sec);
    ull maxLen = max(lenFir,lenSec);
    ull mx = min(lenFir, lenSec);
    ull mn = 0u;
    ull mid;
    //build odd and even arr
    for (ull i = 1u; i <= mx; i++) {
        if (i&1u) {
            odd[lenOdd++] = i;
        } else {
            even[lenEven++] = i;
        }
    }
    power[0]=1;
    for (ull i = 1u; i < maxLen; i++) {
        power[i]=power[i-1]*scale;
    }

    hushFir[0] = 0;
    hushRevFir[lenFir] = 0;
    hushSec[0] = 0;
    for (ull i = 1u; i < lenFir;i++) {
        hushFir[i] = hushFir[i-1]*scale+fir[i]-97;
        hushRevFir[lenFir-i] = hushRevFir[lenFir-i+1]*scale+fir[lenFir-i]-97;
    }
    for (ull i = 1u; i < lenSec;i++) {
        hushSec[i] = hushSec[i-1]*scale+sec[i]-97;
    }


    //find odd
    if (lenOdd > 0) {
        mx = lenOdd-1u;
        while (mx >= mn && mx < ullMax) {
            mid = (mx+mn)/2u;
            if (locate(odd[mid])) {
                oddMax = odd[mid];
                mn = mid+1u;
            } else {
                mx = mid-1u;
            }
        }
    }

    //find even
    if (lenEven>0) {
        mx = lenEven-1u;
        mn = 0u;
        while (mx >= mn && mx < ullMax) {
            mid = (mx+mn)/2u;
            if (locate(even[mid])) {
                evenMax = even[mid];
                mn = mid+1u;
            } else {
                mx = mid-1u;
            }
        }
    }

    ans = max(evenMax, oddMax);
    Write(ans);
    Please AC;
}
