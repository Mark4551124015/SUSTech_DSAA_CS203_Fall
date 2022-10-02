#include <math.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#pragma G++ optimize(2)
using namespace std;

vector<long> vctSum(vector<long> a, vector<long> b, long c) {
    vector<long> out(2);
    out[0] = (a[0] + c*b[0]);
    out[1] = (a[1] + c*b[1]);
    return out;
}
int main()
{
    vector<long> CC(2), Robot(2), period(2,0);			// coordinate of CC and robot, a period can robot go
    long n, index, max, min;                              	        // number of steps, parameter for time counting
    scanf("%ld %ld %ld %ld", &Robot[0], &Robot[1], &CC[0],&CC[1]);	// input
    scanf("%ld", &n);
    vector<vector<long> > step(n,vector<long>(2));		    //steps of robot
    for (long i = 0; i < n; i++) { 									//store the steps, every step in a period stored as a vector
        char c;
        cin >> c;
        if (c == 'U') {
            period[1] += 1;
            step[i][0] = period[0];
            step[i][1] = period[1];
        } else if (c == 'D') {
            period[1] += -1;
            step[i][0] = period[0];
            step[i][1] = period[1];
        } else if (c == 'L') {
            period[0] += -1;
            step[i][0] = period[0];
            step[i][1] = period[1];
        } else if (c == 'R') {
            period[0] += 1;
            step[i][0] = period[0];
            step[i][1] = period[1];
        }
    }
    max = 1e17;
    min = 0;
    index = (max + min) / 2;
    while (max - min > 1) {
        vector<long> targetPos(2), parameter(2);
        long terms = (long)index/n;
        long rem = index % n;
        targetPos = vctSum(Robot, period, terms);
        if (rem) {
            targetPos = vctSum(targetPos, step[rem-1], 1);
        }
        long timeForCC = abs(targetPos[0]-CC[0]) + abs(targetPos[1] - CC[1]);
        if (timeForCC > index) {
            min = index;
        } else {
            max = index;
        }
        index = floor(max + min) / 2;
    }
    if (index < (int)1e17) {
        printf("%ld", index+1);
    } else {
        printf("%d", -1);
    }

}