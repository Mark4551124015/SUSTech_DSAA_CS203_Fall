#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
inline int rd()
{
    int data = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0'&&ch <= '9')
    {
        data = (data<<3) + (data<<1) + ch - '0';
        ch = getchar();
    }
    return f * data; 
}
int a[2000010];
int min_que[2000010];
struct node
{
    int val;
    int pos;
}v[2000010];
void write(int x)
{
    if(x > 10)
        write(x/10);
    putchar(x%10 + '0');	
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        a[i] = rd();
    int head = 1,tail = 0;
    min_que[0] = 0;
    for(int i = 1;i < n;i++)
    {
        while((head <= tail)&&(v[tail].val >= a[i - 1]))
            tail--;
        v[++tail].val = a[i - 1];
        v[tail].pos = i - 1;
        while((head <= tail)&&(v[head].pos < i - m))
            head++;
        min_que[i] = v[head].val;
    }
    for(int i = 0;i < n;i++)
        printf("%d\n",min_que[i]);
}