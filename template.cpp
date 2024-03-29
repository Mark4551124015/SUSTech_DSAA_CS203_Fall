#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define ll long long
#define maxData (ll)3e5
#define RI register int
#pragma G++ optimize(2)
#define Please return
#define AC 0
#define isDebug true

ll arr[maxData][maxData];

//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
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
inline void debug(char a[]){
    if (isDebug) printf("%s ",a);
}
inline void debug(int a){
    if (isDebug) printf("%lld ",a);
}

//Tools
inline void swap(ll arr[], ll a, ll b) {
    ll c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}
//Merge Sort
inline void merge(ll arr[], ll tempArr[], ll left, ll mid, ll right) {
   ll j = left;       //index for left arr
   ll k = mid+1;      //index for right arr
   ll index = left;   //index for tempArr
   while (j <= mid && k <= right) {
       if (arr[j] < arr[k]) {
           tempArr[index++] = arr[j++];
       } else {
           tempArr[index++] = arr[k++];
       }
   }
   //merge left and right
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
inline void mS(ll arr[], ll tempArr[], ll left, ll right ){
   if (left < right) {
       //spit then merge
       ll mid = (left+right)/2;
       mS(arr, tempArr, left, mid);
       mS(arr, tempArr, mid+1, right);
       merge(arr, tempArr, left, mid ,right);
   }
}
inline void mergeSort(ll arr[], ll len) {
   ll tempArr[200000];
   mS(arr, tempArr, 0, len-1);
}

//Heap Sort
inline void hp(ll arr[], ll len, ll index){
    int temp, j;
    temp = arr[index];
    for (j = 2 * index + 1; j < len; j = 2 * j + 1 ) {
        if (j < len - 1 && arr[j] < arr[j+1]) {
            j++;
        }
        if (temp >= arr[j]){
            break;
        }
        arr[index] = arr[j];
        index = j;
    }
    arr[index] = temp;
}
inline void HeapSort(ll arr[], ll length) {
    int i;
    for (i = length / 2 - 1; i >= 0; i--) {
        hp(arr, length, i);
    }
    for (i = length - 1; i > 0; i--) {
        swap(arr, 0, i);
        hp(arr, i, 0);
    }
}

//Queue
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
inline void QueueDistory(Queue *queue) {
	QNode *index = queue->head;
	QNode *toBeFree;
	while (index) {
		toBeFree = index;
		index = index->next;
		free(toBeFree);
	}
	queue->head = queue->tail = NULL;
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
	QNode * toBeFree = queue->head;
	queue->head = queue->head->next;
	free(toBeFree);
}

//Link List
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

//FSA
inline int getID (char input) {
	return input - 97;
}
inline void FSA (char str[], ll size, ll len) {
	for (int i = 0; i < size; i++) {
		if (i == getID(str[0])) {
			arr[0][i] = 1;
		}
	}
	int x = 0;
	for (int i = 1, j; i < len; i++) {  					//all  str
		for (ll j = 0; j < size; j++) {					//all char
			if (getID(str[i]) == j) { 					//match
				arr[i][j] = i+1;						//jump to i+1
			} else {									//not match
				arr[i][j] = arr[x][j];					//jump to last x
			}
		}
		x = arr[x][getID(str[i])];
	}
}

//KMP
inline ll* getNext(char str[], ll len) {
    ll nxt[maxData];
    for (int i = 1, j; i++; i < len) {
        j = nxt[i-1];
        while (j && str[i]!=str[j]) {
            j = nxt[j-1];
        }
        if (str[i] == str[j]) {
            j++;
            nxt[i] = j;
        }
    }
    return nxt;
}
inline int matchKMP(int str[], int len, int dic[], int dicLen, int nxt[]) {
  for (int i = 0, j = 0; i < len; i++) {
    //j jump back till 0 or match
    while (j && str[i] != dic[j]) {
      j = nxt[j-1];
    }
    //keep doing match
    if (str[i] == dic[j]) {
      j++;
    }
    //matched
    if (j == len) {
      return i-j+1;
    }
  }
  return -1;
}



int main(){
    ll arr[] = {7,2,72,62,14,35};
    ll len = (int) sizeof(arr)/sizeof(*arr);
    HeapSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%lld ", arr[i]);
    }
    Please AC;
}