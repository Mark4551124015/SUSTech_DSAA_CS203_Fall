//
// Created by Mark455 on 2022/9/8.
//


#include<iostream>
using namespace std;

void tab(){
    cout << "" << endl;
}

void printCube(int a, int b, int c) {
    int col = 2*(a+b)+1;
    int row = 2*(b+c)+1;
    string cube[row][col];
    int dotCnt, revDotCnt;
    dotCnt = 2 * b ;
    revDotCnt = - 2 * c;

    for (int r = 0; r < row; r++) {
        int c = 0;
        if (dotCnt>0) {
            for (int i = 0; i < dotCnt; i++) {
                cube[r][c+i] = '.';
            }
            c += dotCnt;
        }

        for (int i = 0; i < 2 * a+1; i++) {
            if (i%2==0) {
                cube[r][c+i] = r%2==0 ? '+': dotCnt > 0 ? '/':'|';
            } else {
                cube[r][c+i] = r%2==0 ? '-':'.';
            }
        }
        c += (2*a + 1);

        for (int i = 0; i < (col - c - (revDotCnt > 0 ? revDotCnt : 0)); i++) {
            if (r%2==0) {
                cube[r][c+i] = i%2==0 ? '.' : '+';
            } else {
                if (dotCnt > 0) {
                    cube[r][c+i] = i%2==0 ? '|' : '/';

                } else {
                    cube[r][c+i] = i%2==0 ? '/' : '|';
                }
            }
        }
        c += (col - c - (revDotCnt > 0 ? revDotCnt : 0));


        if (revDotCnt>0) {
            for (int i = 0; i < revDotCnt; i++) {
                cube[r][c+i] = '.';
            }
        }
        ++revDotCnt;
        --dotCnt;
    }

    for (int n=0; n < row; n++) {
        for (int m=0;m < col; m++) {
            cout << cube[n][m];
        }
        if (n!=row-1) {
            tab();
        }
    }
}

int main(){
    int time = 0;
    cin >> time;
    int save[time][3];
    for (int i = 0; i < time; i++) {
        cin >> save[i][0] >> save[i][1] >> save[i][2];
    }
    for(int i = 0; i < time; i++){
        printCube(save[i][0],save[i][1],save[i][2]);
        if (i!=time-1) {
            tab();
        }
    }
}