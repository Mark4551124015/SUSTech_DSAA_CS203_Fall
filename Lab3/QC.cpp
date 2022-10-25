#include <cstdio>
#include <cmath>
#define ll long long
#pragma G++ optimize(2)
ll n, m, cnt=0, tmp=0, storeCnt=0, totalPrice = 0;
ll output[(ll)2e6];
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

//Linked list
struct Node {
    ll data, tag;
    Node* n;
    Node* p;
    Node (ll inputData, ll inputTag, Node* inputPre, Node* inputNext) {
        data = inputData;
        tag = inputTag;
        p = inputPre;
        n = inputNext;
    }
    void remove() {
        if (this->p != NULL) {
            this->p->n = this->n;
        } 
        if ( this->n != NULL) {
            this->n->p = this->p;
        }
    }
};

//Merge Sort for LinkNodes
inline void merge(Node *arr[], Node *tempArr[], ll left, ll mid, ll right) {
    ll j = left;       
    ll k = mid+1;      
    ll index = left;   
    while (j <= mid && k <= right) {
        if (arr[j]->data < arr[k]->data) {
            tempArr[index++] = arr[j++];
        } else {
            tempArr[index++] = arr[k++];
        }
    }
    while (j <= mid) {
        tempArr[index++] = arr[j++];
    }
    while (k <= right) {
        tempArr[index++] = arr[k++];
    }
    while (left <= right) {
        arr[left] = tempArr[left];
        left++;
    }
}
inline void mS(Node *arr[], Node *tempArr[], ll left, ll right ){
    if (left < right) {
        //spit then merge
        ll mid = (left+right)/2;
        mS(arr, tempArr, left, mid);
        mS(arr, tempArr, mid+1, right);
        merge(arr, tempArr, left, mid ,right);
    }
}
inline void mergeSort(Node *arr[], ll len) {
    mS(arr, tempArr, 0, len-1);
}

Node *input[(ll)2e6], *tempArr[(ll)2e6], *sortArr[(ll)2e6];

//find min
ll finMin(Node *node) {
    Node *forward = node -> n;
    Node *backward = node -> p;
    if (forward != NULL && backward != NULL) {
        ll a = forward->data - node->data;
        ll b = node->data - backward->data;
        node->remove();
        return a < b ? a : b;
    } if (forward != NULL) {
        node->remove();
        return forward->data - node->data;
    } else if (backward != NULL){
        node->remove();
        return node->data - backward->data;
    } else {
        return -1;
    }
}

int main() {
    //Read
    n = read(); 
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(read(), i, NULL, NULL);
        input[i] = newNode;
        sortArr[i] = newNode;
    }
    
    //Sorting
    mergeSort(sortArr,n);

    //build link list
    Node *head = sortArr[0];
    for (int i = 1; i < n; i++) {
        head->n = sortArr[i];
        head->n->p = head;
        head = head->n;
    }

    //find
    for (int i = 0; i < n-1; i++) {
        Write(finMin(input[i]));
        putchar(' ');
    }
}
