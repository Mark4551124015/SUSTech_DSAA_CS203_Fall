#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#pragma G++ optimize("O2")
#define ll int
using namespace std;
ll n, m;
char op;
// Fast I/O
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline char readAlpha() {
    char c = getchar();
    while (!isalpha(c)) {
        c = getchar();
    }
    return c;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}
inline void DoubleWrite(double a) {
    ll mi = 0, s2[100];
    if (a == 0)
        putchar('0');
    while (a != (long long)a)
    {
        a *= 10, mi++;
    }
    long long k = a, len = 0;
    while (k != 0)
    {
        s2[len] = k % 10, len++, k /= 10;
    }
    for (len -= 1;len >= 0;len--)
    {
        if (len == mi - 1)
            putchar('.');
        putchar(s2[len] + '0');
    }
}
 
typedef struct QNode
{
    QNode *next;
    ll data;
}QNode;
 
typedef struct Queue{
    QNode *head;
    QNode *tail;
}Queue;
 
inline void Init(Queue *queue) {
    queue -> head = queue ->tail = NULL;
}
 
inline void Push(Queue * queue, ll data) {
    QNode * newNode = (QNode*)malloc(sizeof(QNode));
    newNode -> data = data;
    newNode -> next = NULL;
    if (queue -> tail == NULL) {
        queue -> head = queue -> tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}
 
inline void Pop(Queue * queue) {
    queue->head = queue->head->next;
}
 
inline ll First(Queue * queue) {
    return queue->head->data;
}
 
int main() {
    n = read();
    Queue Q;
    Init(&Q);
    for (; n > 0; --n) {
        op = readAlpha();
        m = read();
        if (op == 'E') {
            Push(&Q, m);
        } else {
            for (; m > 0; --m) {
                Pop(&Q);
            }
            Write(First(&Q));
            putchar('\n');
        }
    }
     
}