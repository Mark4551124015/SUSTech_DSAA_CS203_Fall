#include <cstdio>
#include <vector>
#include<iostream>
#define ll long long
#define N (ll)500100
#pragma G++ optimize(2)
using namespace std;
#define Please return
#define AC 0
ll n, num, cnt, u,v,w;
//Fast RW
inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
inline void read(int& a)
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	a = s * w;
}
inline void Write(ll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        Write(x/10);
    putchar(x%10+'0');
}

struct Node {
    vector<ll> child;
    vector<ll> weight;
}Nodes[N];

inline void insertNode(ll u1, ll v1, ll w1){
    Nodes[u1].child.push_back(v1);
    Nodes[u1].weight.push_back(w1);
    Nodes[v1].child.push_back(u1);
    Nodes[v1].weight.push_back(w1);
}

inline void deepSearch(ll node, ll weight, ll lastNode) {
    if (Nodes[node].child.size()==1) {
        if (weight == num) {
            cnt++;
            return;
        }
    }
    for (ll i = 0; i < Nodes[node].child.size(); i++) {
        if (Nodes[node].child.at(i) == lastNode) {
            continue;
        }
        deepSearch(Nodes[node].child.at(i), weight + Nodes[node].weight.at(i), node);
    }
}

inline void solution(){
    scanf("%lld%lld", &n, &num);
    for(; n > 1; n--) {
        scanf("%lld%lld%lld", &u,&v,&w);
        insertNode(u,v,w);
    }
    deepSearch(1,0,0);
    Write(cnt);
}

int main(){
    solution();
    Please AC;
}
