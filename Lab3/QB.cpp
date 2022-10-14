#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll n, m, cnt=0, tmp=0, storeCnt=0, totalPrice = 0;

//Fast I/O
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar();}
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

struct LinkNode {
    ll data;
    LinkNode* n;
    LinkNode* p;
    LinkNode (ll input, LinkNode* inputPre, LinkNode* inputNext) {
        data = input;
        p = inputPre;
        n = inputNext;
    }
};

inline void doMods() {
    cnt += storeCnt*(m/totalPrice);
    m=m%totalPrice;
}

int main() {
    n = read();
    m = read();
    tmp = read();
    storeCnt = n;
    totalPrice = tmp;
    LinkNode* headA = new LinkNode (tmp, NULL, NULL);
    LinkNode* index = headA; 
    
    for (int i = 1; i < n; i++) {
        tmp = read();
        LinkNode* newNode = new LinkNode (tmp, index, NULL);
        totalPrice += tmp;
        //setting p and n
        index->n = newNode;
        newNode->p = index;
        //move on
        index = index->n;
    }

    //make a loop
    headA->p = index;
    index->n = headA;

    //reset index to start
    index = headA;
    doMods();
    //before deleting all the stores
    while (true) {
        //delete current shop if we don't have enough money
        if (m < index->data) {
            //if nothing else can be deleted break();
            if (index->n == index) {
                break;
            }
            //delete store
            index->p->n = index->n;
            index->n->p = index->p;
            storeCnt--;
            totalPrice -= index->data;
            //do mods
            doMods();
        } else {
            m -= index->data;
            cnt++;
        }
        //return to the starting
        index = index->n;
    }
    Write(cnt);
}