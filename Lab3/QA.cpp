#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll cnt = 0;

//Fast RW
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


struct ListNode {
    ll data[2];
    ListNode* next;

    ListNode(ll input[], ListNode* inputNext){
        data[0] = input[0];
        data[1] = input[1];
        next = inputNext;
    }
};

void ListAddTail(ListNode** head, ll data[]) {
    ListNode* newNode = new ListNode(data, NULL);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* tail = *head;
        while(tail -> next != NULL) {
            tail = tail ->next;
        }
        tail -> next = newNode;
    }
}

void ListInsert(ListNode* Node,ListNode* nextNode) {
    nextNode -> next = Node -> next;
    Node -> next = nextNode;
}

void ListCombine(ListNode** headN, ListNode** headM, ListNode** headResult) {
    ListNode* j = *headN;
    ListNode* k = *headM;
    ll newdata[2] ={0,0};
    *headResult = new ListNode(newdata, NULL);
    ListNode* result = *headResult;
    while (j!= NULL && k != NULL) {
        if (j -> data[1] < k -> data[1]) {
            newdata[0] = j -> data[0];
            newdata[1] = j -> data[1];
            j = j -> next;
        } else if (j -> data[1] > k -> data[1]) {
            newdata[0] = k -> data[0];
            newdata[1] = k -> data[1];
            k = k -> next;
        } else {
            newdata[0] = j -> data[0] + k -> data[0];
            newdata[1] = j -> data[1];
            j = j -> next;
            k = k -> next;
        }
        result -> next = new ListNode(newdata, NULL);
        result = result -> next;
    }
    while (j!= NULL) {
        newdata[0] = j -> data[0];
        newdata[1] = j -> data[1];
        j = j -> next;
        result -> next = new ListNode(newdata, NULL);
        result = result -> next;
    }
    while (k!= NULL) {
        newdata[0] = k -> data[0];
        newdata[1] = k -> data[1];
        k = k -> next;
        result -> next = new ListNode(newdata, NULL);
        result = result -> next;
    }
}

void printList(ListNode** head) {
    ListNode* current = *head;
    while (current != NULL) {
        if (current -> data[0] != 0) {
            Write(current -> data[0]);
            printf(" ");
            Write(current -> data[1]);
            printf("\n");
        }
        current = current -> next;
    }
}

void readList(ListNode** phead, ll n) {
    ListNode* head = *phead;
    ll input[2];
    for (ll i = 0; i < n; i++) {
        input[0] = read();
        input[1] = read();
        head -> next  = new ListNode(input, NULL);
        head = head -> next;
    }

}
void CountList(ListNode** head) {
    ListNode* current = *head;
    while (current != NULL) {
        if (current -> data[0] != 0) {
            cnt++;
        }
        current = current -> next;
    }
}
int main(){
    ll n = read();
    ll m = read();
    ll thisdata[2] ={0,0};

    ListNode* headN = new ListNode(thisdata, NULL);
    ListNode* headM = new ListNode(thisdata, NULL);
    ListNode* headResult = NULL;
    readList(&headN, n);
    readList(&headM, m);
    ListCombine(&headN, &headM, &headResult);
    CountList(&headResult);
    Write(cnt);
    printf("\n");
    printList(&headResult);
}