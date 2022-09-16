#include <math.h>
#include <stdio.h>
#pragma G++ optimize(2)
using namespace std;

double maxSize,max,min;
int cakes, students, cakeCnt, temp;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

inline void DoubleWrite(double a)
{
    int mi = 0, s2[100];
    if (a == 0)
        putchar('0');
    while (a != (long long int)a)
    {
        a *= 10, mi++;
    }
    long long int k = a, len = 0;
    while (k != 0)
    {
        s2[len] = k % 10, len++, k /= 10;
    }
    for (len -= 1;len >= 7;len--)
    {
        if (len == mi - 1)
            putchar('.');
        putchar(s2[len] + '0');
    }
}

int main() {
    students = read();
    cakes = read();
    double cake[cakes];
    for (int i = 0; i < cakes; i++) {
        temp = read();
        cake[i] = M_PI * temp * temp;
        if (cake[i] > max) {
            max = cake[i];
        }
    }
    while (max - min > 1e-5) {
        maxSize = (max + min)/2;
        cakeCnt = 0;
        for (int i = 0; i < cakes; i++) {
            cakeCnt += (int)(cake[i]/maxSize);
        }
        if (cakeCnt >= students) {
            min = maxSize;
        } else {
            max = maxSize;
        }
    }
    DoubleWrite(maxSize);
}
