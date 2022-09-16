#include <math.h>
#include <stdio.h>
#include <array>
#include <string>

#pragma G++ optimize(2)
using namespace std;

int main() {
	int x0, y0, x1, y1; //coordinate of CC and robot
	int n; //number of steps
	scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
	scanf("%d", &n);
	string step[n];
    scanf("%s",step);
    printf("%s", step);

}