#include <stdio.h>
#include <iostream>
#pragma G++ optimize(2)
using namespace std;
int main() {
    int num, problems;
    scanf("%d %d", &num, &problems);
    int input[num];
    int fir, sec;
    for (int i = 0; i < num; i++) {
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < problems; i++) {
        scanf("%d %d", &fir, &sec);
        int max = num - 1;
        int min = 0;
        int lower = 0, upper = max + 1;
        int index;
        if (fir >= input[min]) {
            index = max/2;
            while (true){
                if (input[index] > fir) {
                    max = index;
                    index = min + (index - min)/2;
                    continue;
                } else {
                    if (input[index+1] > fir || index == max)
                    {
                        lower = index+1;
                        break;
                    }
                    min = index;
                    index = index + (max - index + 1)/2;
                    continue;
                }
            }
        }
        max = num - 1;
        min = lower;
        if(sec <= input[max]) {
            index = max / 2;
            while (true) {
                if (input[index] < sec) {
                    min = index;
                    index = index + (max - index + 1) / 2;
                    continue;
                } else {
                    if (input[index - 1] < sec || index == min) {
                        upper = index;
                        break;
                    }
                    max = index;
                    index = min + (index - min) / 2;
                    continue;
                }
            }
        }
        int out = upper - lower;
        if (out <= 0) {
            printf("NO c\n");
        } else {
            printf("YES %d\n", out);
        }
    }
}